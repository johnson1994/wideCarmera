#ifndef mutipleCombine_h
#define mutipleCombine_h

#include <iostream>
#include <sstream>
#include "opencv2/highgui/highgui.hpp"  
#include "opencv2/stitching.hpp"

using namespace std;
using namespace cv;

class CarmeraConfig{
	public:
		CarmeraConfig(){

		}

		/*获得所有摄像头图像*/
		vector<Mat> getImgs();
		/*设置所有摄像头图像*/
		void setImgs(vector<Mat> imgVector);
		/*摄像头检查*/
		int captureCheck();
		/*摄像头检查任务*/
		int captureCheckTask();


		/*本地图片循环拼接测试*/
		int picCombineTest();
	
	private:
		/*所有摄像头图像*/
		vector<Mat> imgs;

};



#endif

