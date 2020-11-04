#include<iostream>
#include<opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
	Mat dstMat, graMat;
	Mat srcMat = imread("lena.jpg");
	if (srcMat.empty())
		return -1;
	cvtColor(srcMat, graMat, COLOR_BGR2GRAY);
	Point2f point1, point2, point3,point4;
	for (int i = 0; i < srcMat.cols; i++)
	{
		if (srcMat.at<Vec3b>(0, i)[1] < 240)
		{
			point1 = Point2f(i, 0);
		}
	}
	for (int i = 0; i < srcMat.rows; i++)
	{
		if (srcMat.at<Vec3b>(i, 0)[1] < 240)
		{
			point2 = Point2f(0, i);
		}
	}
	//for (int i = 0; i < srcMat.rows; i++)
	//{
	//	if (srcMat.at<Vec3b>(i, srcMat.rows)[1] < 240)
	//	{
	//		point3 = Point2f(srcMat.rows, i);
	//	}
	//}
	for (int a = 0; a < srcMat.cols; a++)
	{
		if (srcMat.at<Vec3b>(srcMat.cols, a)[1] < 240)
		{
			point4 = Point2f(a, srcMat.cols);
		}
	}
	//cout << srcMat.rows << endl;
	//cout << srcMat.cols << endl;s
	//cout << point1 << endl;
	//cout << point2 << endl;
	//cout << point3 << endl;
	const Point2f src_pt[] = {
		point1,point2/*,point3*/,point4
	};
	const Point2f dst_pt[] = {
		Point2f(0,0),Point2f(0,srcMat.rows - 1)/*,Point2f(srcMat.cols - 1,0)*/,Point2f(srcMat.cols - 1,srcMat.rows - 1)
	};
	const Mat affine_matrix = getAffineTransform(src_pt, dst_pt);
	warpAffine(srcMat, dstMat, affine_matrix, srcMat.size());
//	const Mat perspevtive_matrix = getPerspectiveTransform(src_pt, dst_pt);
//	warpPerspective(srcMat, dstMat, perspevtive_matrix, srcMat.size());
	imshow("src", srcMat);
	imshow("dst", dstMat);
	waitKey(0);
}
