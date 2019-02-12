#!/bin/sh

set -e

# Create destination directory
DST=_download
mkdir -p ${DST}

# for "dl-framework"
#   TensorFlow (tflite)
wget -o ${DST}/tensorflow-v1.12.0.tar.gz  https://github.com/tensorflow/tensorflow/archive/v1.12.0.tar.gz &

#   Caffe dependency
wget -o ${DST}/OpenBLAS-v0.3.4.tar.gz     https://github.com/xianyi/OpenBLAS/archive/v0.3.4.tar.gz &
#wget https://github.com/xianyi/OpenBLAS/archive/v0.3.5.tar.gz
wget -o ${DST}/protobuf-v3.6.1.tar.gz     https://github.com/protocolbuffers/protobuf/archive/v3.6.1.tar.gz &
wget -o ${DST}/boost_1_68_0.tar.bz2       https://dl.bintray.com/boostorg/release/1.68.0/source/boost_1_68_0.tar.bz2 &
wget -o ${DST}/gflags-v2.2.2.tar.gz       https://github.com/gflags/gflags/archive/v2.2.2.tar.gz &
wget -o ${DST}/glog-v0.3.5.tar.gz         https://github.com/google/glog/archive/v0.3.5.tar.gz &
wget -o ${DST}/LMDB_0.9.23.tar.gz         https://github.com/LMDB/lmdb/archive/LMDB_0.9.23.tar.gz &
wget -o ${DST}/leveldb-v1.20.tar.gz       https://github.com/google/leveldb/archive/v1.20.tar.gz &
wget -o ${DST}/snappy-1.1.7.tar.gz        https://github.com/google/snappy/archive/1.1.7.tar.gz &
wget -o ${DST}/hdf5-1.10.4.tar.bz2        https://s3.amazonaws.com/hdf-wordpress-1/wp-content/uploads/manual/HDF5/HDF5_1_10_4/hdf5-1.10.4.tar.bz2 &
wget -o ${DST}/opencv-3.4.5.tar.gz        https://github.com/opencv/opencv/archive/3.4.5.tar.gz &
# wget https://support.hdfgroup.org/ftp/HDF5/releases/hdf5-1.8/hdf5-1.8.21/src/hdf5-1.8.21.tar.bz2

#   ChainerX
wget -o ${DST}/chainer-v6.0.0b2.tar.gz    https://github.com/chainer/chainer/archive/v6.0.0b2.tar.gz &

# for "imaging"
wget -o ${DST}/FreeImage3180.zip          http://downloads.sourceforge.net/freeimage/FreeImage3180.zip &
wget -o ${DST}/ffmpeg-4.0.3.tar.xz        https://www.ffmpeg.org/releases/ffmpeg-4.0.3.tar.xz &
wget -o ${DST}/opencv-4.0.1.tar.gz        https://github.com/opencv/opencv/archive/4.0.1.tar.gz &

# Execute in parallel
wait
