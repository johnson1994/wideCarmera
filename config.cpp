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
	this->clear();
	this->imgs=imgVector;
}

/*清空*/
void Config::clear(){
	this->imgs.clear();
}

/*从摄像头获得图像*/
int Config::takeCapture(){
	this->clear();
	*this->capture1 >> this->edge1;
	imgs.push_back(this->edge1);
	*this->capture2 >> this->edge2;
	imgs.push_back(this->edge2);
	*this->capture3 >> this->edge3;
	imgs.push_back(this->edge3);

	return 0;
}

/*缩小所有图像*/
int Config::resize(){
	for(int i=0;i<this->imgs.size();i++){
		cv::resize(this->imgs[i], this->imgs[i], Size(this->size_w,this->size_h));
	}
	return 0;
}

