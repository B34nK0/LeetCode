//��Ϊ����1 �ж����һ���ַ����ĳ���

#include <iostream>
#include <string>
using namespace std;

static int HJ1() {
	string str;
	getline(cin, str);

	int length = str.length();
	int tmp = -1;
	for (int i = 0; i < length; ++i) {
		if (str[i] == ' ') {
			//��¼���ַ�������ʼλ��
			tmp = i;
		}
	}

	//�ַ������� - �ַ�����ʼǰһ��λ��ʱ ��Ҫ�ټ�һ
	return length - tmp - 1;
}