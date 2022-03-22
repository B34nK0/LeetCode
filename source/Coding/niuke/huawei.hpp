
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

//��Ϊ����3 ����n���������ȥ���ظ�����ֻ����һ���������򷵻�
//��һ������ ��ʾn������� �����б�ʾ�����ֵ
// 3
// 2
// 2
// 1
// ��� 1�� 2
static void HJ3() {
	cout << "HJ3" << endl;

	int count;
	cin >> count;
	vector<int> allNums(count);
	//�������������
	for (int i = 0; i < count; ++i) {
		cin >> allNums[i];
	}
	sort(allNums.begin(), allNums.end());
	for (int i = 0; 0 < count; ++i) {
		//ȥ�����
		if (i != 0 && allNums[i] == allNums[i - 1]) {
			continue;
		}
		cout << allNums[i] << endl;
	}
}