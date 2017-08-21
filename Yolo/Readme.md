# Darknet Installation (Yolo v2)

Inside Yolo folder running the following commands

```sh
git clone https://github.com/pjreddie/darknet.git
cd darknet
make
```

### To test the installation run :

```sh
./darknet
```

You should get the output:

```sh
usage: ./darknet <function>
```

Darknet is installed.

## To make he installation support OpenCv :

I had `Opencv 3.2` already installed hence skiping the step of installing OpenCV.

In darknet folder change the 2nd line of `Makefile` to

```vim
OPENCV=1
```

Nore Re-make the darknet installation using `make` command in darnket folder.

### To test the installation run :

```sh
./darknet imtest data/eagle.jpg
```

If you are obtaining multiple images of eagle then the installation is completed.

## Downloading Weights :

In darknet/cfg folder run :

```sh
wget https://pjreddie.com/media/files/yolo.weights
```

This shall download the weights for pretrained Yolo model

# References :

1.	https://pjreddie.com/darknet/install/
2. https://pjreddie.com/darknet/yolo/

