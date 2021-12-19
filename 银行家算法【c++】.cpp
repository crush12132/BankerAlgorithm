#include <iostream>
#include <vector>
#include<ctime>
using namespace std;
clock_t startTime, endTime; //计时器
int p;  // 进 程
vector<int> R;  //资源数组
vector<vector<int>> ER, EC;  //有向图邻接矩阵  ER为分配  EC为请求

void resourceDistribution() //根据分配资源矩阵 分配资源
{         
   
}

int getIndependentProcess() {          //获取独立的进程编号 ，没有返回-1

	return -1;
}

void releaseProcessResource(int pt) {          //释放进程资源

}

bool hasRequest() {
	return false;
}

int main() {
	
	cout << "请输入进程个数：" << endl;
	cin >> p ;            //进程输入
	
	cout << "请按顺序输入每个资源包含的数量（以-1结束）：" << endl;
	int temp;
	R.push_back(0);
	while (cin >> temp) {
		if (temp<0) {
			break;
		}
		R.push_back(temp);                  //资源 输入
	}
	ER.resize(R.size() + 1);
	EC.resize(R.size() + 1);
	ER[0].push_back(0);
	EC[0].push_back(0);	

	for (int i = 1; i < R.size(); i++) {
		
		EC[i].push_back(0);
		for (int j = 1; j <= p; j++) {
			cout << "请输入进程P" << i << "向资源R" << j << "请求的资源数量:" << endl; 
			cin >> temp;
			EC[i].push_back(temp);                                                        //请求的资源
		
		}
	}
	for (int i = 1; i < R.size(); i++) {
		ER[i].push_back(0);
		for (int j = 1; j <= p; j++) {
			cout << "请输入资源R" << j << "向进程P" << i << "分配的资源数量:" << endl;
			cin >> temp;
			ER[i].push_back(temp);                                                     //分配的资源
		}
	}

	/*         test 查看输入对不对         */
	cout << endl;
	cout << "进程个数为：" << p<<endl;
	cout << "资源数量为：" << endl;
	for (int i = 1; i < R.size(); i++) {
		cout << R[i]<<" ";
	}
	cout << endl << "请求矩阵" << endl;
	for (int i = 0; i < EC.size(); i++) {
		for (int j = 0; j < EC[i].size(); j++) {
			cout << EC[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl << "资源分配矩阵" << endl;
	for (int i = 0; i < ER.size(); i++) {
		for (int j = 0; j < ER[i].size(); j++) {
			cout << ER[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	/*         test          */

	// 算法开始运行
	cout << "--------------begin--------------" << endl;
	startTime = clock();                  //计时器开始计时         给优化做准备
	resourceDistribution();  //资源分配
	bool dealLockFlag = true;   //表示是否死锁
	while (true) {
		int pTemp = getIndependentProcess();  //找到一个不阻塞的进程
		if (pTemp == -1) {
			cout << "死锁" << endl;
			break;
		}
		releaseProcessResource(pTemp);

		if (!hasRequest) {    //判断是否还有请求
			cout << "不死锁" << endl;
			break;
		}
	}
	endTime = clock();                        //计时器结束计时
	cout << "--------------endl--------------" << endl;	
	//算法结束
	cout<<"程序耗时" << (double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
}
