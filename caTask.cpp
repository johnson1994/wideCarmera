#include <iostream>
#include "opencv2/highgui/highgui.hpp"  
#include "opencv2/stitching.hpp" 

#include "combine.h"
#include "config.h"
#include "caTask.h"


using namespace std;
using namespace cv;


/*初始化*/
int CaTask::init(){
	this->combine=new Combine(true,"result.jpg",this->winName);
	this->config=new Config();
	if(this->config->captureInit(0,1,2)!=0){
		return -1;	
	}
	namedWindow(this->winName,1);
	return 0;
}

/*开始全景摄像头拼接*/
int CaTask::start(){
	char key;

	while(true){
		this->config->takeCapture();
		this->config->resize();

		this->combine->setImgs(this->config->getImgs());
		this->combine->doCombine();

		key=waitKey(1);
		if(key == 27) break;
	}

	return 0;
}

