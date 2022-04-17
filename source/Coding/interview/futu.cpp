/*
leetCode 24 �������������еĽڵ�

��;һ��
*/

#include <string>

#include "CommonStruct.h"
class SwapPairs {
public:
	ListNode* TestSwapPairs(ListNode* head) {
		if (head == nullptr) {
			return nullptr;
		}

		//����սڵ㣬���ڷ���
		ListNode* pre = new ListNode();
		//ָ��ǰͷ���
		pre->next = head;
		//0->1->2->
		ListNode* tmp = pre;

		//�����ڵ㽻��
		//1->2
		while (tmp->next != nullptr && tmp->next->next != nullptr) {
			//1
			ListNode* first = tmp->next;
			//2
			ListNode* second = tmp->next->next;
			//0->2
			tmp->next = second;
			//1->3
			first->next = second->next;
			//2->1
			second->next = first;
			//cur = 3
			tmp = first->next;
		}

		return pre->next;
	}
};

//ѹ���ַ����ո񲢷��ؿո�����
class DelStringSpace {
public:
	int ReturnSpaceCount(std::string& content) {

		if (content.empty()) {
			return 0;
		}

		int count = 0;

		int begin = 0;
		for (int i = 0; i < content.length(); ++i) {
			if (content[i] == ' ') {
				count++;
				begin = i;
			}
			else if (begin != i) {
				content[begin] = content[i];
				begin++;
			}
		}

		int remind = content.length() - count;
		//ͨ��resize�Զ��ü�����
		content.resize(remind);

		return count;
	}
};

/*
mysql

ͳ��

1��where\having ������
where ��һ��Լ���������ڲ�ѯ���ݿ�Ľ������֮ǰ�����ݿ��еĲ�ѯ�������Լ��
having ��һ�������������ڲ�ѯ���֮������ݽ���ɸѡ�����ڽ������֮�������ã�having֮�����ʹ�þۺϺ����������������ѯ group by��
����ͳ��ѡ������������ѧ��
select Sno from dbsc group by Sno having count(*)>3;

2��sqlִ�к�ʱ���ܱȽϳ���ԭ����ô�Ż�


3���������к󻹺���


4��������֮�����޷�����


5��mysqlΪʲô��Ҫһ������



���ݽṹ

6��hashmap ɢ�б�

7�����hash��ͻ����
rehash��



��Ϣ����

8��rabbitmq��α�֤��Ϣ����ʧ

9���ݵ���

10����������֤��Ϣ����ʧ

*/