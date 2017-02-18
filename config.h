#ifndef config_h
#define config_h

#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp> 
#include "opencv2/highgui/highgui.hpp"  
#include "opencv2/stitching.hpp"  

using namespace std;
using namespace cv;

class Config{
	public:
		Config(){
			size_w=400;
			size_h=300;
		}
		~Config(){
			this->captureDestory();
		}
		
		/*返回所有摄像头图像*/
		vector<Mat> getImgs();
		/*设置所有摄像头图像*/
		void setImgs(vector<Mat> imgVector);
		/*清空*/
		void clear();
		/*摄像头初始化*/
		int captureInit(int index1,int index2,int index3);
		/*获得摄像头图像*/
		int takeCapture();
		/*缩放摄像头图像*/
		int resize();
		/*销毁摄像头*/
		void captureDestory();

	private:
		/*所有摄像头图像*/
		vector<Mat> imgs;
		/*图像高度*/
		int size_w;
		/*图像宽度*/
		int size_h;

		/*摄像头1*/
		VideoCapture* capture1;
		/*摄像头2*/
		VideoCapture* capture2;
		/*摄像头3*/
		VideoCapture* capture3;
		Mat edge1,edge2,edge3;

};

#endif


