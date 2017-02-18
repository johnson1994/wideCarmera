#include<iostream>
#include<ctime>
#include "opencv2/highgui/highgui.hpp"  
#include "opencv2/stitching.hpp" 
#include "combine.h"


using namespace std;
using namespace cv;


void Combine::clearImgs(){
	this->imgs.clear();
}

/*初始化*/
int Combine::init(){
	this->clearImgs();
	return 0;
}

vector<Mat> Combine::getImgs(){
	return this->imgs;
}

void Combine::setImgs(vector<Mat> imgVector){
	this->imgs=imgVector;
}

/*插入图片*/
int Combine::takeImg(string address){
	Mat img = imread(address);  
	if (img.empty()){  
		cout << "Can't read image '" << address << "'\n";  
		return -1;  
	}  
	this->imgs.push_back(img);  
	//	imshow(address, img);  
}

/*全景拼接 --先调用init()*/
int Combine::doCombine(){
	this->start=clock();

	Mat pano;  
	/*创建一个stitcher对象*/  
	Stitcher stitcher = Stitcher::createDefault(this->try_use_gpu);

	/*设置生成结果图为:平面*/  
	PlaneWarper* cw = new PlaneWarper();  
	stitcher.setWarper(cw);  

	/*使用Surf算法来寻找特征点*/  
	detail::SurfFeaturesFinder *featureFinder = new detail::SurfFeaturesFinder();  
	stitcher.setFeaturesFinder(featureFinder);  

	/*匹配给定的图像和估计相机的旋转*/  
	Stitcher::Status status = stitcher.estimateTransform(this->imgs);  
	if (status != Stitcher::OK)  
	{  
		cout << "Can't stitch images, error code = " << int(status) << endl;  
		return -1;  
	}  

	/*生成全景图像*/  
	status = stitcher.composePanorama(pano);  
	if (status != Stitcher::OK)  
	{  
		cout << "Can't stitch images, error code = " << int(status) << endl;  
		return -1;  
	} 

	this->finish=clock();
	this->duration = (double)(this->finish - this->start) / CLOCKS_PER_SEC;
	cout << "take time:" << this->duration << endl;

	//	imwrite(this->result_name, pano);  
	imshow(this->winName, pano);  
	//	cv::waitKey(0);  
	return 0;  

}

