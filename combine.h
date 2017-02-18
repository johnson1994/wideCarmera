#ifndef combine_h
#define combine_h

#include<iostream>
#include<ctime>
#include "opencv2/highgui/highgui.hpp"  
#include "opencv2/stitching.hpp" 

using namespace std;
using namespace cv;

class Combine{
	public:
		Combine(bool gpu,string name,string win){
			try_use_gpu=gpu;
			result_name=name;
			winName=win;
		}

		/*初始化*/
		int init();
		/*读本地图像（仅用于测试）*/
		int takeImg(string address);
		/*返回所有摄像头图像*/
		vector<Mat> getImgs();
		/*设置所有摄像头图像*/
		void setImgs(vector<Mat> imgVector);
		/*拼接图像*/
		int doCombine();
		/*清空*/
		void clearImgs();

	private:
		/*是否使用GPU*/
		bool try_use_gpu;
		/*图片保存名称（仅用于测试）*/
		string result_name;
		/*所有摄像头图像*/
		vector<Mat> imgs;

		/*窗口名称*/
		string winName;

		/*计算时间*/
		clock_t start,finish;
		double duration;
};

#endif


