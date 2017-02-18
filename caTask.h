#ifndef caTask_h
#define caTask_h

#include <iostream>
#include "opencv2/highgui/highgui.hpp"  
#include "opencv2/stitching.hpp" 

#include "combine.h"
#include "config.h"

using namespace std;
using namespace cv;

class CaTask{
	public:
		CaTask(string name){
			winName=name;
		}
		~CaTask(){
			if(combine!=NULL)
			  delete combine;
			if(config!=NULL)
			  delete config;
		}

		/*初始化*/
		int init();
		/*开始全景摄像头拼接*/
		int start();

	private:
		Combine* combine;
		Config* config;
		string winName;

};


#endif

