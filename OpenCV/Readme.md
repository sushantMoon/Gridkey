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
sudo apt-get install python2.7-dev python3.5-dev
```

## Downloading the zip files :

```sh
mkdir /media/feliz/Safira/GitHub/GridKey/OpenCV
cd /media/feliz/Safira/GitHub/GridKey/OpenCV
```

```sh
wget -O opencv.zip https://github.com/Itseez/opencv/archive/3.2.0.zip
unzip opencv.zip

wget -O opencv_contrib.zip https://github.com/Itseez/opencv_contrib/archive/3.2.0.zip
unzip opencv_contrib.zip
```

## Python Env :

```sh
mkvirtualenv gridkey
pip install numpy
```

## Building OpenCV :

```sh
cd /media/feliz/Safira/GitHub/GridKey/OpenCV/opencv-3.2.0/
mkdir build
cd build
cmake -D CMAKE_BUILD_TYPE=RELEASE \
   -D CMAKE_INSTALL_PREFIX=/usr/local \
   -D INSTALL_PYTHON_EXAMPLES=ON \
   -D INSTALL_C_EXAMPLES=OFF \
   -D OPENCV_EXTRA_MODULES_PATH=/media/feliz/Safira/GitHub/GridKey/OpenCV/opencv_contrib-3.2.0/modules \
   -D PYTHON_EXECUTABLE=/home/feliz/.envs/gridkey/bin/python \
   -D BUILD_EXAMPLES=ON ..
```

Check for any errors in this `cmake`

```sh
make -j4
```

Check for errors in make command, if it fails try with single core in place of 4, 

```sh
make clean
make
```

If everthings correct then proceed

```sh
sudo make install
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

Now Opencv is all seet for this environment


# Reference 

* http://www.pyimagesearch.com/2016/10/24/ubuntu-16-04-how-to-install-opencv/



