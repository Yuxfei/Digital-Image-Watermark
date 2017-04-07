#include <iostream>
#include <opencv2/opencv.hpp>
#include <string>

using namespace std;
using namespace cv;

int main()
{
	Mat img = imread("./image/wallhaven-4895.jpg");
	imshow("原始图像", img);

	Mat logo = imread("./image/timg.jpg");
	imshow("水印图像", logo);

	Mat mask = imread("./image/mask.jpg",0);
	imshow("掩模图像", mask);

	Mat result;
	Point center(100, 450);
	seamlessClone(logo, img, mask, center, result, NORMAL_CLONE);
	imshow("结果图像", result);
	imwrite("./image/wallhaven-4895-watermark.jpg", result);

	waitKey(0);
	return 0;
}