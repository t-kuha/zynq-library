#!/bin/bash -e


usage() {
  echo "Usage: $(basename "$0") [-c]"
  echo "-c Clean before building protobuf for target"
  echo "\"PETALINUX\" should be defined as an environment variable."
  exit 1
}


# debug options
while getopts "c" opt_name; do
  case "$opt_name" in
    c) clean=true;;
    *) usage;;
  esac
done
shift $((OPTIND - 1))


SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
GENDIR="$(pwd)/tensorflow/contrib/makefile/gen/protobuf"
HOST_GENDIR="$(pwd)/tensorflow/contrib/makefile/gen/protobuf-host"
mkdir -p "${GENDIR}"
#ln -s "${GENDIR}" "${HOST_GENDIR}"

if [[ ! -f "tensorflow/contrib/makefile/downloads/protobuf/autogen.sh" ]]; then
    echo "You need to download dependencies before running this script." 1>&2
    echo "tensorflow/contrib/makefile/download_dependencies.sh" 1>&2
    exit 1
fi
source "${SCRIPT_DIR}"/build_helper.subr
JOB_COUNT="${JOB_COUNT:-$(get_job_count)}"

#echo "Job Count:" ${JOB_COUNT}

cd tensorflow/contrib/makefile/downloads/protobuf


# Generate protoc for host
PROTOC_PATH="${HOST_GENDIR}/bin/protoc"
if [[ ! -f "${PROTOC_PATH}" || ${clean} == true ]]; then
  # Try building compatible protoc first on host
  echo "protoc not found at ${PROTOC_PATH}. Build it first."
  make_host_protoc "${HOST_GENDIR}"
else
  echo "protoc found. Skip building host tools."
fi

# Clean outputs for host
make clean

# 
bin_prefix="arm-linux-gnueabihf"

export CC="${bin_prefix}-gcc"
export CXX="${bin_prefix}-g++"

./autogen.sh
if [ $? -ne 0 ]
then
  echo "./autogen.sh command failed."
  exit 1
fi


./configure --prefix="${GENDIR}" \
--host="${bin_prefix}" \
--disable-shared \
--enable-cross-compile \
--with-protoc="${PROTOC_PATH}"
# \
#--with-sysroot="${SYSROOT}" \

if [ $? -ne 0 ]
then
  echo "./configure command failed."
  exit 1
fi


if [[ ${clean} == true ]]; then
  echo "clean before build"
  make clean
fi

make -j"${JOB_COUNT}"
if [ $? -ne 0 ]
then
  echo "make command failed."
  exit 1
fi

make install

echo "$(basename $0) finished successfully!!!"


