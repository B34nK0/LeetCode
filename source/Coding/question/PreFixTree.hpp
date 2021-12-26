/*
ǰ׺�� Ҳ���ֵ�����������ѹ���ֵ�����
*/

#include <string>
using namespace std;

class PreFixTree {
	struct Node {
		//��Ҫȷ���ַ����ݲ�����26����ĸ
		Node* child[26];
		bool isWord;
		//��ʼ���ӽڵ�Ϊnullptr
		Node() {
			for (int i = 0; i < 26; i++) {
				child[i] = nullptr;
			}
			isWord = false;
		}
	};

	Node* root;
public:
	PreFixTree() {
		root = new Node();
	}

	void Insert(string word) {
		Node* curr = root;
		for (auto ch : word) {
			int index = ch - 'a';
			//�Ѵ�����ͬ�ַ��Ľڵ㣬��������
			if (curr->child[index]) {
				curr = curr->child[index];
				continue;
			}
			//�½��ڵ�
			curr->child[index] = new Node;
			curr = curr->child[index];
		}
		curr->isWord = true;
	}

	bool Search(string word) {
		Node* curr = root;

		for (auto ch : word) {
			int index = ch - 'a';
			//�����ڽڵ�
			if (!curr->child[index]) {
				return false;
			}
			curr = curr->child[index];
		}
		return curr->isWord ? true : false;
	}
};