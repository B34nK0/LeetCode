
/*
leetCode 8 �ַ���ת������ atoi

ȥ���ַ���ǰ��ո���'+ -'��ʾ����ֵ��û��ʱĬ��Ϊ��ֵ
�����������ַ�ʱ����
��Χ��-2^31 ~ 2^31-1

��������״̬��dfa���н��
*/

#include <string>
#include <ctype.h> //����isspace\isdigit�ж��Ƿ�Ϊ�ո�������
#include <unordered_map>
#include <vector>
using namespace std;

class Automaton {
private:
	string state = "start";//״̬����ʼ״̬
	//ĳ��״̬�¶�Ӧ�ĺ���״̬
	unordered_map < string, vector<string>> stateMap = {
		{"start",{"start", "signed", "in_number", "end"}},
		{"signed", {"end", "end", "in_number", "end"}},
		{"in_number", {"end", "end","in_number", "end"}},
		{"end", {"end", "end", "end", "end"}}
	};

	//��Ӧ״̬����
	int getNextState(char c) {
		if (isspace(c)) return 0;
		else if (c == '+' || c == '-') return 1;
		else if (isdigit(c)) return 2;
		return 3;
	}

public:
	int sign = 1;//Ĭ����ֵ
	long long ans = 0; //����������ֵ

	void Parse(char c) {
		state = stateMap[state][getNextState(c)];
		if (state == "in_number") {
			ans = ans * 10 + c - '0';
			//ע��ans�ķ�Χ
			//-1 * INI_MIN�ᳬ��INT��������Ҫlong long�洢
			ans = sign == 1 ? min(ans, (long long)INT_MAX) : min(ans, (long long)-1*INT_MIN);
		}
		else if (state == "signed") {
			sign = c == '+' ? 1 : -1;
		}
	}

	int GetNumber() {
		return sign * ans;
	}
};


class MyAtoi {
public:
	int AtoiConvert(string str) {
		Automaton automaton;
		for (char c : str) {
			automaton.Parse(c);
		}
		return automaton.GetNumber();
	}
};