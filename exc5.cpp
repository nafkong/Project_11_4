#include<iostream>
#include<opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
	Mat dstMat;
	Mat srcMat = imread("lena.jpg", 1);
	if (srcMat.empty())
		return -1;
	Point2f point1,point2,point3;
	for (int i=0; i < srcMat.cols; i++)
	{
		if(srcMat.at<uchar>(0,i)<200)
		{
			point1 = Point2f(i, 0);
		}
	}
	for (int i=0; i < srcMat.rows; i++)
	{
		if (srcMat.at<uchar>(i, 0) < 220)
		{
			point2 = Point2f(0, i);
		}
	}
	for (int i=0; i < srcMat.cols; i++)
	{
		if (srcMat.at<uchar>(i, srcMat.rows) < 220)
		{
			point3 = Point2f(srcMat.rows, i);
		}
	}
	//cout << srcMat.rows << endl;
	//cout << srcMat.cols << endl;
	//cout << point1 << endl;
	//cout << point2 << endl;
	//cout << point3 << endl;
	const Point2f src_pt[] = {
		point1,point2,point3
	};
	const Point2f dst_pt[] = {
		Point2f(0,0),Point2f(0,srcMat.cols),Point2f(srcMat.rows,srcMat.rows)
	};
	const Mat affine_matrix = getAffineTransform(src_pt, dst_pt);
	warpAffine(srcMat, dstMat, affine_matrix, srcMat.size());
	imshow("src", srcMat);
	imshow("dst", dstMat);
	waitKey(0);
}