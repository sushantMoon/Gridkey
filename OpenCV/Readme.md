# Open CV Installation Procedure


## Dependencies :

```sh
sudo apt-get update
sudo apt-get upgrade
sudo apt-get install build-essential cmake pkg-config
sudo apt-get install libjpeg8-dev libtiff5-dev libjasper-dev libpng12-dev
sudo apt-get install libavcodec-dev libavformat-dev libswscale-dev libv4l-dev
sudo apt-get install libxvidcore-dev libx264-dev
sudo apt-get install libgtk-3-dev
sudo apt-get install libatlas-base-dev gfortran
sudo apt-get install gcc-multilib
sudo apt-get install python2.7-dev python3.5-dev
sudo apt-get install ffmpeg libopencv-dev libdc1394-22 libdc1394-22-dev libxine2-dev libgstreamer1.0-dev libgstreamer-plugins-base1.0-dev libtbb-dev qtbase5-dev libfaac-dev libmp3lame-dev libopencore-amrnb-dev libopencore-amrwb-dev libtheora-dev libvorbis-dev x264 v4l-utils unzip
sudo apt install libgphoto2-dev libavresample-dev
sudo apt-get install checkinstall
```

Update GNU GCC (and Anaconda's version if you have any) :

```sh
sudo apt install gcc g++
conda install libgcc
```

### Intell TBB/IPP (Improves Parallel Processing) :

After downloading the Intell TBB File from the link mentioned in the Reference Section, un-compress the file and run `./install_GUI.sh` present inside.

Due to limitations in network bandwidth, I installed Intell TBB, and had selected GUI method.

## Downloading the zip files :

```sh
mkdir /media/feliz/Safira/GitHub/GridKey/OpenCV
cd /media/feliz/Safira/GitHub/GridKey/OpenCV
```

## Python Env :

```sh
mkvirtualenv gridkey
pip install numpy
```

#### If Going for OpenCV Version 3.2.0 :

```sh
wget -O opencv.zip https://github.com/Itseez/opencv/archive/3.2.0.zip
unzip opencv.zip
mv opencv-3.2.0 opencv

wget -O opencv_contrib.zip https://github.com/Itseez/opencv_contrib/archive/3.2.0.zip
unzip opencv_contrib.zip
mv opencv_contrib-3.2.0 opencv_contrib
```

#### If installing OpenCV Version 3.3.0 :

```sh
wget -O opencv-3.3.0.tar.gz https://github.com/opencv/opencv/archive/3.3.0.tar.gz
tar -zxvf opencv-3.3.0.tar.gz
mv opencv-3.3.0 opencv

wget -O opencv_contrib-3.3.0.tar.gz https://github.com/opencv/opencv_contrib/archive/3.3.0.tar.gz
tar -zxvf opencv_contrib-3.3.0.tar.gz
mv opencv_contrib-3.3.0 opencv_contrib
```

## Namespace Defination added for handling Tesseract -

Hopefully This shall be addressed in the future updates on Tesseract/OpenCV_contrib and would be not needed. 

Based On :

[OpenCV Contrib Pull Request 1337](https://github.com/opencv/opencv_contrib/pull/1337/files)
[OpenCV Contrib Issues 1324](https://github.com/opencv/opencv_contrib/issues/1324)
[Tesseract Pull Request 1082](https://github.com/tesseract-ocr/tesseract/pull/1082)

File to be edited in the Repository/Downloaded Folder:

`opencv_contrib/modules/text/src/precomp.hpp`

[After Line 50 add the following lines](https://github.com/opencv/opencv_contrib/pull/1337/files) :
Following Piece of code to be added after `#ifdef HAVE_TESSERACT`

```vim
#if !defined(USE_STD_NAMESPACE)
#define USE_STD_NAMESPACE
#endif
```

## Building OpenCV :

```sh
cd /media/feliz/Safira/GitHub/Gridkey/OpenCV/opencv/
mkdir build
cd build
cmake -DCMAKE_CXX_FLAGS=-std=c++14 \
    -DCMAKE_BUILD_TYPE=RELEASE \
    -DCMAKE_INSTALL_PREFIX=/usr/local \
    -DBUILD_EXAMPLES=OFF \
    -DBUILD_DOCS=OFF \
    -DBUILD_PERF_TESTS=OFF \
    -DBUILD_TESTS=OFF \
    -DINSTALL_C_EXAMPLES=OFF \
    -DENABLE_PRECOMPILED_HEADERS=OFF \
    -DWITH_OPENMP=ON \
    -DWITH_V4L=ON \
    -DWITH_TBB=ON \
    -DWITH_QT=ON \
    -DWITH_OPENGL=ON \
    -DWITH_JPEG=ON \
    -DWITH_FFMPEG=ON \
    -DWITH_GSTREAMER=ON \
    -DWITH_OPENCL=ON \
    -DWITH_GPHOTO2=ON \
    -DWITH_LIBV4L=ON \
    -DINSTALL_PYTHON_EXAMPLES=ON \
    -DBUILD_SHARED_LIBS=ON \
    -DENABLE_CXX11=ON \
    -DOPENCV_EXTRA_MODULES_PATH=/media/feliz/Safira/GitHub/Gridkey/OpenCV/opencv_contrib/modules \
    -DPYTHON_EXECUTABLE=/home/feliz/.envs/gridkey/bin/python ..
```

Check for any errors in this `cmake`

Note:  any one of the above 2 versions can be installed at any given time.

Then :

```sh
make -j4
```

Check for errors in make command, if it fails try with single core in place of 4, 

```sh
make clean
make
```

If everthings correct then proceed, 
(Requires checkinstall to be installed previously)
```sh
sudo checkinstall
```

If the above command isnot to your liking, then another alternative is 

```sh
sudo make install
``` 

Then Run :

```sh
sudo ldconfig
```

The Final Compiled `.so` for this system is placed at 

```sh
 ls -l /usr/local/lib/python2.7/site-packages/
```

This compiled `.so` is to be placed inside the virtual environment file.

```sh
cd ~/.envs/gridkey/lib/python2.7/site-packages/
ln -s /usr/local/lib/python2.7/site-packages/cv2.so cv2.so
```

Now Opencv is all set for this environment


# Reference 

* http://www.pyimagesearch.com/2016/10/24/ubuntu-16-04-how-to-install-opencv/
* https://codeyarns.com/2013/10/04/how-to-install-intel-ipp-on-ubuntu/
* [Intell TBB and Some Intell stuff for Optimization](http://software.intel.com/en-us/intel-ipp) : It improves on the compile and runtime time
* [Some Useful/Useless CFlags During Cmake](http://amritamaz.net/blog/opencv-config)
* [Error of libstd++.so.6](https://github.com/tensorflow/tensorflow/issues/5017)
