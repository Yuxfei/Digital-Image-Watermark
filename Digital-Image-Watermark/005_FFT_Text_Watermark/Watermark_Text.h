#ifndef WATERMARK_TEXT_H
#define WATERMARK_TEXT_H

#include <iostream>
#include <opencv2/opencv.hpp>

class WaterMarkText
{
public:

	/******************************
	添加文字水印函数————处理单通道图像
	input: 输入单通道图像
	text: 添加水印文字
	*******************************/
	cv::Mat addTextWatermarkSingleChannel(const cv::Mat &input, const std::string &text);

	/******************************
	添加文字水印函数————处理彩色图像
	input: 输入彩色图像
	text: 添加水印文字
	*******************************/
	cv::Mat addTextWatermarkColorImage(const cv::Mat &inputImage, const std::string &text);

	/******************************
	提取出文字水印——处理灰度图像
	input: 输入图像
	*******************************/
	cv::Mat getWaterMarkSingleChannel(const cv::Mat &input);

	/******************************
	提取出文字水印——处理彩色图像
	input: 输入图像
	*******************************/
	cv::Mat getWatermarkColorImage(const cv::Mat &input);

	/******************************
	图像转置
	input: 输入图像
	*******************************/
	cv::Mat getTransposeImage(const cv::Mat &input);

private:

};

#endif