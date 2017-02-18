#include <iostream>
#include "caTask.h"
#include "mutipleCombine.h"
#include "config.h"
#include "combine.h"

using namespace std;
using namespace cv;

int select(){
	int selectedNum;
	cout << "-------------MENU-------------" << endl;
	cout << "1. 本地图片图片拼接测试" << endl;
	cout << "2. 摄像头测试" << endl;
	cout << "3. 全景摄像头" << endl;
	cout << "0. 退出 ctrl+c" << endl;
	cout << "------------------------------" << endl;
	cout << "请选择：";
	cin >> selectedNum;
	return selectedNum;
}

int main(){
	int selectedNum;
	while(true){
		selectedNum=select();
		switch(selectedNum){
			case 1:
				/*本地图片测试*/
				CarmeraConfig* carmrea;
				carmrea=new CarmeraConfig();
				carmrea->picCombineTest();
				delete carmrea;
				break;
			case 2:
				/*摄像头测试*/
				CarmeraConfig* carmreaCheck;
				carmreaCheck=new CarmeraConfig();
				carmreaCheck->captureCheckTask();
				delete carmreaCheck;
				break;
			case 3:
				/*全景摄像头*/
				CaTask* task;
				task=new CaTask("全景摄像头");
				if(task->init()!=0) break;
				task->start();
				delete task;
				break;
			case 0:
				break;
			default:
				cout << "输入错误！" << endl;
		}
	}

	return 0;
}

