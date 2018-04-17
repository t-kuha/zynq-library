## How to build


#### Prerequisite
- Install cmake
```bash
$ sudo apt-get install cmake
```

- Source petalinux tools (cross compiler):
```bash
$ source <petalinux root>/settings.sh
```
  

#### FreeImage
- w/o libraw support (because of compilation error...)
    - Note: Need to remove libraw-related & mips-related file entries from Makefile.src

```bash
$ CC=arm-linux-gnueabihf-gcc CXX=arm-linux-gnueabihf-g++ make -j`nproc`
$ sudo DESTDIR=. make install
$ cp -R ./usr/* <Install Dir> 
```


#### ffmpeg
- References
  - https://trac.ffmpeg.org/wiki/CompilationGuide/RaspberryPi
  
```bash
$ ./configure \
> --prefix=<Installation path> \
> --enable-cross-compile \
> --cross-prefix=arm-linux-gnueabihf- \
> --enable-shared \
> --enable-gpl \
> --arch=armv7-a
$ make -j`nproc`
$ make install
```


#### OpenCV
- With ffmpeg functions
    - If ffmpeg is not needed, remove _PKG\_CONFIG\_PATH=..._

```shell
$ mkdir _zynq
$ cd _zynq
$ PKG_CONFIG_PATH=<Path to ffmpeg pkgconfig dir> \
> cmake \
> -D CMAKE_TOOLCHAIN_FILE=<Path to toolchain.make> \
> -D CMAKE_INSTALL_PREFIX=<Installation path> \
> -D CMAKE_CONFIGURATION_TYPES=Release \
> -D BUILD_WITH_DEBUG_INFO=OFF \
> -D BUILD_opencv_nonfree=OFF \
> -D BUILD_opencv_apps:BOOL=OFF \
> -D BUILD_PERF_TESTS:BOOL=OFF \
> -D BUILD_TESTS=OFF \
> -D WITH_FFMPEG=ON \
> -D WITH_GSTREAMER=OFF \
> -D WITH_LAPACK=OFF \
> -D WITH_MATLAB=OFF \
> -D WITH_OPENCL=OFF \
> -D WITH_OPENCLAMDBLAS=OFF \
> -D WITH_OPENCLAMDFFT=OFF \
> -D WITH_CUDA=OFF \
> -D WITH_1394=OFF \
> -D WITH_GTK=OFF \
> -D WITH_V4L=OFF \
> -D WITH_CUFFT=OFF \
> -D BUILD_ZLIB=ON \
> -D BUILD_JPEG=ON \
> -D BUILD_TIFF=ON \
> -D BUILD_OPENEXR=ON \
> -D BUILD_PNG=ON \
> ..
$ cmake --build . --config Release --target install -- -j`nproc`
```
