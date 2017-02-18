#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>  
#include "opencv2/highgui/highgui.hpp"  
#include "opencv2/stitching.hpp"  

#include "config.h"


using namespace std;
using namespace cv;


/*摄像头初始化*/
int Config::captureInit(int index1,int index2,int index3){
	this->capture1=new VideoCapture(index1);
	if(!capture1->isOpened()){
		cout << "open carmera1 failed" << endl;
		return -1;
	}
	this->capture2=new VideoCapture(index2);
	if(!capture2->isOpened()){
		cout << "open carmera2 failed" << endl;
		return -1;
	}
	this->capture3=new VideoCapture(index3);
	if(!capture3->isOpened()){
		cout << "open carmera3 failed" << endl;
		return -1;
	}
	return 0;
}

/*销毁摄像头*/
void Config::captureDestory(){
	delete this->capture1;
	delete this->capture2;
	delete this->capture3;
}

/*图像*/
vector<Mat> Config::getImgs(){
	return this->imgs;
}

/*设置所有图像*/
void Config::setImgs(vector<Mat> imgVector){
	this->imgs=imgVector;
}

/*清空*/
void Config::clear(){
	this->imgs.clear();
}

/*从摄像头获得图像*/
int Config::takeCapture(){
	Mat edge1,edge2,edge3;
	this->clear();
	*this->capture1 >> edge1;
	imgs.push_back(edge1);
	*this->capture2 >> edge2;
	imgs.push_back(edge2);
	*this->capture3 >> edge3;
	imgs.push_back(edge3);

	return 0;
}

/*缩小所有图像*/
int Config::resize(){
	vector<Mat> newImgs;

	for(int i=0;i<imgs.size();i++){
		Mat image2;
		cv::resize(imgs[i], image2, Size(this->size_w,this->size_h));
		newImgs.push_back(image2);
	}
	this->setImgs(newImgs);
	return 0;
}

