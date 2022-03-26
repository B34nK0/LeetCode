
#include <iostream>
#include <string>
#include <unordered_map>
#include <sstream>
#include <map>
#include <deque>

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


/*
������°˸�����������ظ���ͳ�ƴ���
*/
static void HJ19() {
	cout << "HJ19" << endl;
	string str;
	map<string, int> result;

	deque<string>deq;
	while (getline(cin, str)) {
		//�ļ���
		str = str.substr(str.find_last_of('\\') + 1);
		int pos = str.find_last_of(' ');
		if (pos > 16) {
			str = str.substr(pos - 16);
		}

		if (result.find(str) == result.end()) {
			deq.push_back(str);
		}
		++result[str];
		if (deq.size() > 8) {
			deq.pop_front();
		}
	}
	for (auto x : deq) {
		cout << x << " " << result[x] << endl;
	}
}

/*
�ϳ�����
����n��ѧ��
Ҫ���õ�k��ѧ���γɶ���
��������и������ߵݼ�
���õ����ٵ�k
*/
static void HJ24() {
	cout << "HJ24" << endl;
	int studentCount = 0;
	while (cin >> studentCount) {
		vector<int> studentHights(studentCount);
		for (auto& student : studentHights) {
			cin >> student;
		}

		//��ÿ��λ�õ���������
		vector<int> indexL(studentCount);
		for (int i = 0; i < studentCount; ++i) {
			for (int j = 0; j < i; ++j) {
				if (studentHights[i] > studentHights[j]) {
					indexL[i] = max(indexL[i], indexL[j]);
				}
			}
			indexL[i] = indexL[i] + 1;
		}
		vector<int> indexR(studentCount);
		for (int i = studentCount - 1; i >= 0; --i) {
			for (int j = studentCount - 1; j > i; --j) {
				if (studentHights[i] > studentHights[j]) {
					indexR[i] = max(indexR[i], indexR[j]);
				}
			}
			indexR[i] = indexR[i] + 1;
		}

		int max = 0;
		for (int i = 0; i < studentCount; ++i) {
			int maxK = indexL[i] + indexR[i] - 1;
			max = maxK > max ? maxK: max;
		}

		cout << studentCount - max << endl;
	}
}

/*
0326 ��Ϊod
����һ�����������飬����������Ƿ�������������������
���� A = B + 2C

��������:

��һ����������Ԫ�ظ�����
������һ�������������Ԫ�أ��ÿո������
�������:

�����������Ҫ���������ͬһ�����������������A/B/C��ȡֵ���ÿո������
��������ڣ����0��
*/
static void HJTest1() {
	cout << "HJTest1" << endl;

	int count = 0;
	//����ĸ���
	cin >> count;

	vector<int> nums(count);
	//ͨ�����õķ�ʽ�������飬����ĸ���Ӧ���������countһ�£���Ȼ��Խ�磬������Ŀ���췶��
	for (auto& num : nums) {
		cin >> num;
	}

	//�������
	for (int i = 0; i < count; ++i) {
		for (int j = 0; j < count; ++j) {
			for (int k = 0; k < count; ++k) {
				//�����ظ�ʹ����ֵ����Ҫ�ж�i!=j!=k
				if (i != j && j != k && nums[i] == nums[j] + 2 * nums[k]) {
					cout << nums[i] << ' ' << nums[j] << ' ' << nums[k];
					return ;
				}
			}
		}
	}

	cout << 0 << endl;
	return;
}