# CppND-Panorama-Stitching-Capstone-Project
Panorama Stitching Capstone Project


<img src="images/sample_output.jpg"/>

## Overview
This is the capstone project for the [Udacity C++ Nanodegree Program](https://www.udacity.com/course/c-plus-plus-nanodegree--nd213). I implemented an object detection model using OpenCV. The program read an image file and then performs object detection on it. Finally, it gives an output image which is the original image with bounding boxes over the detected objects in the image. The bounding boxes also have an overlay of the detected class and the confidence value. This program is modular in the sense that it can be used for various Deep Neural Network Models (but it has only been tested with [yolov3](https://pjreddie.com/darknet/yolo/) and [yolov3-tiny](https://pjreddie.com/darknet/yolo/)). By default, the scripts will load the yolov3-tiny model (it needs less computation compared to other yolo models at the expense of performance). The program is run through the command line and takes in various options and input parameters.


## File Structure

This repository contains:
- `data/` : Contains sample input image data that may be used for the program.



- `images` : images folders containssome example images that used for panorama stitching. 


- `src` : Source folder Contains the `Panorama_Stitching.cpp files.

- `CMakeLists.txt` : cmake configuration file

- `README.md` : Contains directions for downloading the repository and executing the files


## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* OpenCV >= 4.1.x
  * The OpenCV 4.1.0 source code can be found [here](https://github.com/opencv/opencv/master)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

  **! This repository has been successfully built and tested on Ubuntu 18.08 with OpenCV 4.1 running C++14.**

## Build Instructions

1. Clone this repo using `git clone https://github.com/BV-Pradeep/CppND-Panorama-Stitching-Capstone-Project.git`

2. Enter the root directory of the repository using `cd CppND-Panorama-Stitching-Capstone-Project`
3. Remove build directory using `rm -rf build`
4. Create a new build directory using `mkdir build && cd build`
5. Compile the program in build directory using `cmake .. & make`
6.  Once Program is succesfully compiled, to run the Panorama Stitcher execute in build directory`./Panorama_Stitching`


The executable(`objectdetector`) is created in the current directory(`build`).




## Reference

[1] https://github.com/opencv/opencv/blob/master/samples/dnn/object_detection.cpp
