# zynq-library (2018.3)

Library files for Zynq-7000 (32bit ARM CPU)

## arm: ARM conpute library & NN SDK

- computelibrary: ARM compute library

- nnsdk: ARM NNSDK

- boost & flatbuffers: dependency for ARM NNSDK

## dl-framework: Deep learning frameworks

- caffe: Caffe 1.0

- caffe-dependency: Libraries for building Caffe 1.0 & Caffe2

  - boost: 1.68.0
  - gflags: v2.2.2
  - glog: v0.3.5
  - leveldb: v1.20
  - lmdb: v0.9.23
  - HDF5: 1.10.4
  - OpenBLAS: v0.3.4
    - Note: v0.3.5 causes compilation error
  - protobuf: v3.6.1
  - snappy: v1.1.7

- chainerx: ChainerX (v6.0.0)

- tflite: TensorFlow Lite ver. 1.12.0

## imaging: Library for image I/O and manipulation

- ffmpeg: FFMPEG ver. 4.1

- freeimage: FreeImage ver. 3.18.0

- opencv: OpenCV ver. 4.0.0

***

- See [wiki](https://github.com/t-kuha/zynq-library/wiki) for how to build these libraries from source
