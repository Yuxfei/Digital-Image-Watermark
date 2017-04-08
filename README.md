# Digital-Image-Watermark
Serveral digital image watermark algorithms implement with C++/OpenCV

## 一、项目简介

### 1、开发语言：C++
### 2、开发工具：Visual Studio 2013
### 3、第三方库：OpenCV（Version:3.2）

## 二、项目模块

### 0、直接写文字的水印（文字水印）

简介：基于OpenCV的内置函数：putText()的显式数字图像水印

原图与水印照片对比：

原始图像：

![Alt text](/Digital-Image-Watermark/001_Direct_Text_Watermark/image/wallhaven-21738.jpg "原始图像")

水印图像：

![Alt text](/Digital-Image-Watermark/001_Direct_Text_Watermark/image/wallhaven-21738-watermark.jpg "水印图像")

    
    
### 1、基于Alpha Mix的显示水印添加（图片水印——彩色图像）

    简介：基于图像Alpha混合的显式数字图像水印

原图与水印照片对比：

原始图像：

![Alt text](/Digital-Image-Watermark/002_Alpha_Mix_Image_Watermark/image/wallhaven-205542.jpg "原始图像")

水印图像：

![Alt text](/Digital-Image-Watermark/002_Alpha_Mix_Image_Watermark/image/One_Piece_72_pix.png "水印图像")

结果图像：

![Alt text](/Digital-Image-Watermark/002_Alpha_Mix_Image_Watermark/image/wallhaven-205542-watermark.jpg "结果图像")
    
### 2、基于泊松融合的显示数字图像水印（图片水印——彩色图像）

    简介：混合梯度算法——基于梯度域图像融合的显式数字图像水印

原图与水印照片对比：

原始图像：

![Alt text](/Digital-Image-Watermark/003_Possion_Fuse_Image_Watermark/image/wallhaven-4895.jpg "原始图像")

水印图像：

![Alt text](/Digital-Image-Watermark/003_Possion_Fuse_Image_Watermark/image/watermark.jpg "水印图像")

掩模图像：

![Alt text](/Digital-Image-Watermark/003_Possion_Fuse_Image_Watermark/image/mask.jpg "掩模图像")

结果图像：

![Alt text](/Digital-Image-Watermark/003_Possion_Fuse_Image_Watermark/image/wallhaven-4895-watermark.jpg "结果图像")
    
### 3、基于LSB的图像水印添加（图片水印——彩色图像）
    
    简介：水印信息存储在最低有效位，生成添加水印后的图像效果不好（会观察到水印图像的残影），并且该方法对JPEG压缩具有较差的鲁棒性，下面将通过实验验证。

原始图像：

![Alt text](/Digital-Image-Watermark/004_LSB_Image_Watermark/image/lena.png "原始图像")

水印图像：

![Alt text](/Digital-Image-Watermark/004_LSB_Image_Watermark/image/baboon.png "水印图像")

结果图像一（以BMP格式存储结果图像）：

![Alt text](/Digital-Image-Watermark/004_LSB_Image_Watermark/image/result1.bmp "结果图像一")

结果图像一提取水印：

![Alt text](/Digital-Image-Watermark/004_LSB_Image_Watermark/image/test1.bmp "结果图像一")

结果图像二（以JPG格式存储结果图像）：

![Alt text](/Digital-Image-Watermark/004_LSB_Image_Watermark/image/result2.jpg "结果图像二")

结果图像二提取水印：水印图像已经被严重破坏（JPEG压缩导致）

![Alt text](/Digital-Image-Watermark/004_LSB_Image_Watermark/image/test2.jpg "结果图像二")


### 4、基于FFT的数字图像水印算法（文字水印）

    简介：生成添加水印后的图片效果好，但是算法抗JPEG压缩效果差，导致水印提取不理想，使用BMP格式效果好（图片质量太好，存储空间太大）

### 5、基于DCT的数字图像水印（图片水印——二值图像）

   简介：生成添加水印后的图片效果好，抗几何攻击效果差（旋转，翻转，缩放，裁剪）

#### 5.1、全局DCT数字图像水印

#### 5.2、分块DCT数字图像水印
