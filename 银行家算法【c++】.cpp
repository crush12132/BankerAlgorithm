#include <iostream>
#include <vector>
#include<ctime>
using namespace std;
clock_t startTime, endTime; //��ʱ��
int p;  // �� ��
vector<int> R;  //��Դ����
vector<vector<int>> ER, EC;  //����ͼ�ڽӾ���  ERΪ����  ECΪ����

void resourceDistribution() //���ݷ�����Դ���� ������Դ
{         
   
}

int getIndependentProcess() {          //��ȡ�����Ľ��̱�� ��û�з���-1

	return -1;
}

void releaseProcessResource(int pt) {          //�ͷŽ�����Դ

}

bool hasRequest() {
	return false;
}

int main() {
	
	cout << "��������̸�����" << endl;
	cin >> p ;            //��������
	
	cout << "�밴˳������ÿ����Դ��������������-1��������" << endl;
	int temp;
	R.push_back(0);
	while (cin >> temp) {
		if (temp<0) {
			break;
		}
		R.push_back(temp);                  //��Դ ����
	}
	ER.resize(R.size() + 1);
	EC.resize(R.size() + 1);
	ER[0].push_back(0);
	EC[0].push_back(0);	

	for (int i = 1; i < R.size(); i++) {
		
		EC[i].push_back(0);
		for (int j = 1; j <= p; j++) {
			cout << "���������P" << i << "����ԴR" << j << "�������Դ����:" << endl; 
			cin >> temp;
			EC[i].push_back(temp);                                                        //�������Դ
		
		}
	}
	for (int i = 1; i < R.size(); i++) {
		ER[i].push_back(0);
		for (int j = 1; j <= p; j++) {
			cout << "��������ԴR" << j << "�����P" << i << "�������Դ����:" << endl;
			cin >> temp;
			ER[i].push_back(temp);                                                     //�������Դ
		}
	}

	/*         test �鿴����Բ���         */
	cout << endl;
	cout << "���̸���Ϊ��" << p<<endl;
	cout << "��Դ����Ϊ��" << endl;
	for (int i = 1; i < R.size(); i++) {
		cout << R[i]<<" ";
	}
	cout << endl << "�������" << endl;
	for (int i = 0; i < EC.size(); i++) {
		for (int j = 0; j < EC[i].size(); j++) {
			cout << EC[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl << "��Դ�������" << endl;
	for (int i = 0; i < ER.size(); i++) {
		for (int j = 0; j < ER[i].size(); j++) {
			cout << ER[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	/*         test          */

	// �㷨��ʼ����
	cout << "--------------begin--------------" << endl;
	startTime = clock();                  //��ʱ����ʼ��ʱ         ���Ż���׼��
	resourceDistribution();  //��Դ����
	bool dealLockFlag = true;   //��ʾ�Ƿ�����
	while (true) {
		int pTemp = getIndependentProcess();  //�ҵ�һ���������Ľ���
		if (pTemp == -1) {
			cout << "����" << endl;
			break;
		}
		releaseProcessResource(pTemp);

		if (!hasRequest) {    //�ж��Ƿ�������
			cout << "������" << endl;
			break;
		}
	}
	endTime = clock();                        //��ʱ��������ʱ
	cout << "--------------endl--------------" << endl;	
	//�㷨����
	cout<<"�����ʱ" << (double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
}
