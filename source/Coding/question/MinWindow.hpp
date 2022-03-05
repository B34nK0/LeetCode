
/*
leetCode 76 ��С�����Ӵ�

�����ַ���s��t���� s�и���t�����ַ�����С�Ӵ�
abaacbab  , abc  => acb
*/

#include <string>
#include <unordered_map>

using namespace std;
class MinWindow {
public:
	//��¼t�ַ���ÿ���ַ���Ҫ������
	unordered_map<char, int> _t_count;
	//��ǰ������t�ַ�������
	unordered_map<char, int> _w_count;

	//��ⴰ�����Ƿ���������ַ�
	bool check() {
		//����t�ַ���ϣ��
		for (const auto& p : _t_count) {
			//��ⴰ����ĳ�ַ�������С��t�ַ�������ַ�������ʱ ����false
			if (_w_count[p.first] < p.second) {
				return false;
			}
		}
		return true;
	}

	string GetRes(string s, string t) {
		//��¼t�ַ�������ϣ��
		for (auto& c : t) {
			++_t_count[c];
		}

		//���ڵ�����ָ��
		int l = 0, r = -1;

		//
		int len = INT_MAX, ansL = -1;

		//���ڻ�δ����
		while (r < int(s.size())) {
			//��¼�������ַ�����

			//��ǰ�ַ���t�ַ���Ҫ�ģ������ڼ�¼
			if (_t_count.find(s[++r]) != _t_count.end()) {
				++_w_count[s[r]];
			}

			//��������Ѱ��������ַ� �� ���ڴ�С��ֵ��������
			while (check() && l <= r) {

				//��ȡ��ǰ����l��λ���Լ�����
				if (r - l + 1 < len) {
					len = r - l + 1;
					ansL = l;
				}
				//l���ƵĻ���Ҫȥ����������ַ���
				if (_t_count.find(s[l]) != _t_count.end()) {
					--_w_count[s[l]];
				}
				
				++l;
			}
		}

		return ansL >= 0 ? s.substr(ansL, len) : "";
	}
};