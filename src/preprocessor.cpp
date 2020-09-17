#include <iostream>
#include <opencv2/opencv.hpp>
#include "preprocessor.h"
#include<string>
using namespace std;
using namespace cv;

Mat Convert2GrayScale(Mat &image){
    Mat imageGray;
    cvtColor(image, imageGray, COLOR_BGR2GRAY);
    return imageGray;

}

void DisplayImage(std::string &message,Mat &image){
    std::string s = message + " - Press Enter to Close the Window";
    imshow(s,image);
    waitKey(0);
    destroyAllWindows();
}