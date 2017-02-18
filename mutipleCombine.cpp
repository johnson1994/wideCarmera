#include <iostream>
#include <sstream>
#include "opencv2/highgui/highgui.hpp"  
#include "opencv2/stitching.hpp" 

#include "combine.h"
#include "config.h"
#include "mutipleCombine.h"

using namespace std;
using namespace cv;


vector<Mat> CarmeraConfig::getImgs(){
	return this->imgs;
}


void CarmeraConfig::setImgs(vector<Mat> imgVector){
	this->imgs=imgVector;
}

/*摄像头检查*/
int CarmeraConfig::captureCheck(){
	for(int i=0;i<this->imgs.size();i++){
		string indexStr;
		std::stringstream sstr;
		sstr << i;
		sstr >> indexStr;
		imshow(indexStr,imgs[i]);	
	}
	return 0;
}

/*摄像头检查任务*/
int CarmeraConfig::captureCheckTask(){
	char key;
	
	Config* config=new Config();
	config->captureInit(0,1,2);

	while(true){
		config->takeCapture();
		this->setImgs(config->getImgs());
		this->captureCheck();

		key=waitKey(1);
		if(key == 27) break;
	}


	delete config;
	return 0;
}

/*本地图片循环拼接测试*/
int CarmeraConfig::picCombineTest(){
	int i=0;
	char key;

	string winName="result";
	namedWindow(winName,1);

	Combine* combine=new Combine(false,"result.jpg",winName);
	Config* config=new Config();

	while(true){
		combine->init();

//		if(i=0){
			i++;
			combine->takeImg("a.png");
			combine->takeImg("b.png");
			combine->takeImg("c.png");
/*		}else{
			i=0;
			combine->takeImg("d.png");
			combine->takeImg("e.png");
			combine->takeImg("f.png");
		}*/

		config->setImgs(combine->getImgs());
		config->resize();
		combine->setImgs(config->getImgs());

		combine->doCombine();
		key=waitKey(1);
		if(key == 27) break;
	}

	delete combine;
	delete config;
	return 0;
}

