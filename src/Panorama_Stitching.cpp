#include <iostream>
#include <opencv2/opencv.hpp>
#include "preprocessor.h"

using namespace std;
using namespace cv;

int main(int argc, char** argv) 
{ 

if( argc < 3 ){
        cout << "Not enough Arguments, Exiting the Program \n";
        return 0;
} 
int MAX_FEATURES = 500;
float GOOD_MATCH_PERCENT = 0.15f;

// Reading of image files. 
std::string filename;   
std::string image1File = argv[1];
std::cout <<"Image 1 File Path" << image1File << "\n";
Mat im1 = imread(image1File);
std::cout << "Displaying image 1, Press enter to close the window. \n";
filename = "First Image";
DisplayImage(filename,im1);

std::string image2File = argv[2];
std::cout <<"Image 2 File Path" <<image2File << "\n";
Mat im2 = imread(image2File);
std::cout << "Displaying image 2, Press enter to close the window. \n";
filename = "Second Image";
DisplayImage(filename,im2);
       

Mat im1Gray, im2Gray;
im1Gray = Convert2GrayScale(im1);
im2Gray = Convert2GrayScale(im2);


// Variables to store keypoints and descriptors
std::vector<KeyPoint> keypoints1, keypoints2;
Mat descriptors1, descriptors2;

// Detect ORB features and compute descriptors.
Ptr<Feature2D> orb = ORB::create(MAX_FEATURES);
orb->detectAndCompute(im1Gray, Mat(), keypoints1, descriptors1);
orb->detectAndCompute(im2Gray, Mat(), keypoints2, descriptors2);

Mat im1Keypoints;
drawKeypoints(im1,keypoints1,im1Keypoints,Scalar(0,0,255),DrawMatchesFlags::DEFAULT);
//cout << "Saving Image with Keypoints"; // For Debugging
imwrite("keypoints.jpg", im1Keypoints);

//imshow("Keypoints obtained from the ORB detector",im1Keypoints);
//waitKey(0); //For Debugging only


// Match features.
std::vector<DMatch> matches;
Ptr<DescriptorMatcher> matcher = DescriptorMatcher::create("BruteForce-Hamming");
matcher->match(descriptors1, descriptors2, matches, Mat());

// Sort matches by score
std::sort(matches.begin(), matches.end());

// Remove not so good matches
const int numGoodMatches = matches.size() * GOOD_MATCH_PERCENT;
matches.erase(matches.begin()+numGoodMatches, matches.end());


// Draw top matches
Mat imMatches;
drawMatches(im1, keypoints1, im2, keypoints2, matches, imMatches);

//imshow("Matchings obtained from the descriptor matcher", imMatches);
//waitKey(0); //For debugging only

// Extract location of good matches
std::vector<Point2f> points1, points2;

for( size_t i = 0; i < matches.size(); i++ )
{
    points1.push_back( keypoints1[ matches[i].queryIdx ].pt );
    points2.push_back( keypoints2[ matches[i].trainIdx ].pt );
}

// Find homography
Mat h = findHomography( points2, points1, RANSAC );

//cout << "Homography Matrix:\n" << h; /For Debugging only

// Use homography to warp image
int im1Height = im1.rows; int im1Width = im1.cols;
int im2Height = im2.rows; int im2Width = im2.cols;
Mat im2Aligned;
warpPerspective(im2, im2Aligned, h, Size(im2Width + im1Width, im2Height));

//imshow("Second image aligned to first image obtained using homography and warping",im2Aligned);
//waitKey(0);//For Debugging only


Mat stitchedImage = im2Aligned.clone();

Rect roi (0,0,im1.cols,im1.rows);
im1.copyTo(stitchedImage(roi));

filename = "Panoramic Stitched Image";
DisplayImage( filename,stitchedImage);

return 0;
}
