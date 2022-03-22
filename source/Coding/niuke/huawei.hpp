
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

//��Ϊ����1 �ж����һ���ַ����ĳ���
static int HJ1() {
	cout << "HJ1" << endl;

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

static char toLower(char c) {
	if (c >= 'A' && c <= 'Z') {
		c = c - 'A' + 'a';
	}
	return c;
}

//��Ϊ����2 ����һ���ַ����������ַ�����ȡ�ַ����ַ����г��ֵĴ���
static int HJ2() {
	cout << "HJ2" << endl;

	unordered_map<char, int> mp;
	char c;
	while ((c = getchar()) != '\n') {
		c = toLower(c);
		mp[c]++;
	}

	char target;
	cin >> target;
	target = toLower(target);
	cout << mp[target] << endl;
	return mp[target];
}