#ifndef PREOROCESSOR_H
#define PREPROCESSOR_H

#include <opencv2/opencv.hpp>
#include<string>
using namespace cv;
Mat Convert2GrayScale(Mat &image);
//void DisplayImage(Mat &image);
void DisplayImage(std::string &message,Mat &image);
#endif