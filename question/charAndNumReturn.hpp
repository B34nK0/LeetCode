#include <string>
#include <queue>
//
//����һ������������ĸ���������ּ��ո���ַ���
//ʵ����ĸ������˳������ְ�С����������ĸ��

using namespace std;
class charAndNumReturn {
public :
	static string getCharAndNumReturn(string content) {
		priority_queue<char,vector<char>, greater<char>> numbers;
		string result;
		for (char s : content) {
			if (s == ' ') {
				continue;
			}
			if (s >= '0' && s <= '9') {
				numbers.push(s);
				continue;
			}
			result.push_back(s);
		}

		while (!numbers.empty()) {
			char i = numbers.top();
			result.push_back(i);
			numbers.pop();
		}

		return result;
	}
};