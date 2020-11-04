#include<iostream>
#include<opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int edgeThresh = 1;
Mat dstMat;
Mat srcMat;
Mat gryMat;
string window_name = "dstMat";

void onTrackbar(int, void*)
{
	Canny(gryMat, dstMat, edgeThresh, edgeThresh, 3);
	imshow(window_name, dstMat);
}

int main()
{
	srcMat = imread("C:/Users/admin/Desktop/messi.jpg");
	cvtColor(srcMat, gryMat, CV_BGR2GRAY);
	createTrackbar("edgeThresh", window_name, &edgeThresh, 255, onTrackbar);
	waitKey(0);

	return 0;
}