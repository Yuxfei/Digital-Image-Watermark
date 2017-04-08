#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

/*
功能：在空域应用速记式加密
参数：aFrontImage:原始照片
参数：aHiddenImage:需要隐藏的水印照片
*/
Mat steganograph(Mat aFrontImage, Mat aHiddenImage)
{
	// 检测输入图像的类型是否一致
	CV_Assert(aFrontImage.type() == aHiddenImage.type() && aFrontImage.size() == aHiddenImage.size());

	// 如果照片的大小不一致
	if (aFrontImage.size() != aHiddenImage.size())
	{
		// 把灰度图像放在左上角，在右边和下边扩展图像，扩展部分填充为0；
		copyMakeBorder(aHiddenImage, aHiddenImage, 0, aFrontImage.rows - aHiddenImage.rows, 0, aFrontImage.cols - aHiddenImage.cols, BORDER_CONSTANT, Scalar::all(0));
	}

	// 存储结果图像
	Mat aStegedImage(aFrontImage.rows, aFrontImage.cols, aFrontImage.type());
	// 临时变量
	Mat tFront_image, tHidden_image;

	// 检测是否要处理彩色图像
	if (aFrontImage.channels() == 3)
	{
		// 掩模矩阵填充在二进制值0xF0或11110000
		Mat front_mask(aFrontImage.rows, aFrontImage.cols, aFrontImage.type(), Scalar(0xF0, 0xF0, 0xF0));
		Mat hidden_mask(aHiddenImage.rows, aHiddenImage.cols, aHiddenImage.type(), Scalar(0xF0, 0xF0, 0xF0));

		// 进行按位与操作，存储到临时图像里面
		bitwise_and(aFrontImage, front_mask, tFront_image);
		bitwise_and(aHiddenImage, hidden_mask, tHidden_image);

		for (int j = 0; j < aHiddenImage.rows; j++)
			for (int i = 0; i < aHiddenImage.cols; i++)
			{
				// 矩阵右移4位，前四位由零填充
				tHidden_image.at<Vec3b>(j, i)[0] = tHidden_image.at<Vec3b>(j, i)[0] >> 4;
				tHidden_image.at<Vec3b>(j, i)[1] = tHidden_image.at<Vec3b>(j, i)[1] >> 4;
				tHidden_image.at<Vec3b>(j, i)[2] = tHidden_image.at<Vec3b>(j, i)[2] >> 4;
			}
	}
	// 如果处理灰度图像
	else if (aFrontImage.channels() == 1)
	{
		Mat front_mask(aFrontImage.rows, aFrontImage.cols, aFrontImage.type(), Scalar(0xF0));
		Mat hidden_mask(aHiddenImage.rows, aHiddenImage.cols, aHiddenImage.type(), Scalar(0xF0));

		bitwise_and(aFrontImage, front_mask, tFront_image);
		bitwise_and(aHiddenImage, hidden_mask, tHidden_image);

		for (int j = 0; j < aHiddenImage.rows; j++)
			for (int i = 0; i < aHiddenImage.cols; i++)
			{
				tHidden_image.at<uchar>(j, i) = tHidden_image.at<uchar>(j, i) >> 4;
			}
	}

	// 执行按位或操作，结果存储到 aStegedImage
	bitwise_or(tFront_image, tHidden_image, aStegedImage);
	return aStegedImage;
}

// 获取水印图像
Mat deSteganograph(Mat &aStegedImage)
{
	// 存储原始图像
	Mat aFrontImage(aStegedImage.rows, aStegedImage.cols, aStegedImage.type());
	// 存储水印图像
	Mat aHiddenImage(aStegedImage.rows, aStegedImage.cols, aStegedImage.type());

	if (aFrontImage.channels() == 3)
	{
		Mat front_mask(aStegedImage.rows, aStegedImage.cols, aStegedImage.type(), Scalar(0xF0, 0xF0, 0xF0));
		Mat hidden_mask(aStegedImage.rows, aStegedImage.cols, aStegedImage.type(), Scalar(0x0F, 0x0F, 0x0F));

		bitwise_and(aStegedImage, front_mask, aFrontImage);
		bitwise_and(aStegedImage, hidden_mask, aHiddenImage);

		for (int j = 0; j < aHiddenImage.rows; j++)
			for (int i = 0; i < aHiddenImage.cols; i++)
			{
				aHiddenImage.at<Vec3b>(j, i)[0] = aHiddenImage.at<Vec3b>(j, i)[0] << 4;
				aHiddenImage.at<Vec3b>(j, i)[1] = aHiddenImage.at<Vec3b>(j, i)[1] << 4;
				aHiddenImage.at<Vec3b>(j, i)[2] = aHiddenImage.at<Vec3b>(j, i)[2] << 4;
			}
	}
	else if (aFrontImage.channels() == 1)
	{
		Mat front_mask(aStegedImage.rows, aStegedImage.cols, aStegedImage.type(), Scalar(0xF0));
		Mat hidden_mask(aStegedImage.rows, aStegedImage.cols, aStegedImage.type(), Scalar(0x0F));

		bitwise_and(aStegedImage, front_mask, aFrontImage);
		bitwise_and(aStegedImage, hidden_mask, aHiddenImage);

		for (int j = 0; j < aHiddenImage.rows; j++)
			for (int i = 0; i < aHiddenImage.cols; i++)
			{
				aHiddenImage.at<uchar>(j, i) = aHiddenImage.at<uchar>(j, i) << 4;
			}
	}

	return aHiddenImage;
}

int main()
{
	Mat img1 = imread("./image/lena.png");
	Mat img2 = imread("./image/baboon.png");

	imshow("原始照片", img1);
	imshow("水印照片", img2);

	if (img1.empty() || !img1.data)
	{
		cerr << "Problem loading first image!" << endl;
		return -1;
	}
	if (img2.empty() || !img2.data)
	{
		cerr << "Problem loading second image!" << endl;
		return -1;
	}

	Mat result = steganograph(img1, img2);
	imshow("结果图像", result);

	// 实验一
	imwrite("./image/result1.bmp", result);
	Mat img3 = imread("./image/result1.bmp");
	Mat test1 = deSteganograph(img3);
	imshow("实验一", test1);
	imwrite("./image/test1.bmp", test1);

	// 实验二
	imwrite("./image/result2.jpg", result);
	Mat img4 = imread("./image/result2.jpg");
	Mat test2 = deSteganograph(img4);
	imshow("实验二", test2);
	imwrite("./image/test2.jpg", test2);

	waitKey();
	return 0;
}