
#include <iostream>
#include <string>
#include <unordered_map>
#include <sstream>

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
	for (int i = 0; i < count; ++i) {
		//ȥ�����
		if (i != 0 && allNums[i] == allNums[i - 1]) {
			continue;
		}
		cout << allNums[i] << endl;
	}
}

/*
* �ж�ip������
*/
bool checkMask(string mask) {
	istringstream iss(mask);
	string seg;
	unsigned b = 0;
	while (getline(iss, seg, '.')) {
		b = (b << 8) + stoi(seg);
	}
	if (!b) return false;
	b = ~b + 1;
	if (b == 1) return false;
	if ((b & (b - 1)) == 0) return true;
	return false;
}

bool checkIp(string ip) {
	int j = 0;
	istringstream iss(ip);
	string seg;
	while (getline(iss, seg, '.'))
		if (++j > 4 || seg.empty() || stoi(seg) > 255)
			return false;
	return j == 4;
}

bool checkPrivate(string ip) {
	istringstream iss(ip);
	string seg;
	vector<int> v;
	while (getline(iss, seg, '.')) v.push_back(stoi(seg));
	if (v[0] == 10) return true;
	if (v[0] == 172 && (v[1] >= 16 && v[1] <= 31)) return true;
	if (v[0] == 192 && v[1] == 168) return true;
	return false;
}

static void HJ18() {
	cout << "HJ18" << endl;

	int errCount = 0, a = 0, b = 0, c = 0, d = 0, e = 0, privateCount = 0;

	string input;
	//��ȡÿ������
	while (cin >> input) {
		istringstream is(input);
		string add;
		vector<string> v;
		//ͨ��istringstream
		while (getline(is, add, '~')) {
			v.push_back(add);
		}
		//�������������󣬼�������ip
		string ip = v[0], mask = v[1];
		if (!checkMask(mask)) {
			errCount++;
			continue;
		}

		if (checkIp(ip)) {
			//����Ƿ�˽��
			if (checkPrivate(ip)) {
				privateCount++;
			}

			//��ip���з���
			//��ȡip��ǰ��λֵ
			int first = stoi(ip.substr(0, ip.find_first_of('.')));
			if (first > 0 && first < 127) {
				a++;
			}
			else if (first > 127 && first < 192) {
				b++;
			}
			else if (first > 191 && first < 224) {
				c++;
			}
			else if (first > 223 && first < 240) {
				d++;
			}
			else if (first > 239 && first < 256) {
				e++;
			}
		}
		else {
			errCount++;
		}
	}

	cout << a << " " << b << " " << c << " " << d << " " << e << " " << errCount << " " << privateCount << endl;
}