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
�����ż��������ô���������綶����Ӧ�ñ��ֻ���Զ�̣���������redo���ˣ���ҳ��Ҫ����ˢ�̣����ߴ������˵���ˢ��ʧ��lockס�ˣ����Ի���������
����ǳ�ʱ����������sql������⣬�Ƿ�������where�Ƿ�����˺���������������������������ȫ���ѯ

3���������к󻹺���


4��������֮�����޷�����


5��mysqlΪʲô��Ҫһ������������Ӧ�����޶���Innodb�¡�
InnoDB����ײ�����ݽṹ��B+����������ʽ����B+����ʵ�ֿ���������logN����һ�����ж��ٸ������ͻ��ж��ٿ�����
mysql�е����ݰ�˳��洢��Ҷ�ӽڵ��ϡ�

����˳���Ŀ�ģ�
��߷�Χ��ѯЧ�ʡ���������Ч�ʡ����ɨ��������

mysql�ײ�������ҳ��16k�������Զ��壩Ϊ��λ���д洢�����һ��ҳ��������ȻҪ����һ���µ�����ҳ���洢���ݡ�
������������ʱ��д��һ��ҳֱ������һ���µ�ҳ����д
�����������Ϊ��ȷ����������mysql��Ҫ����������ݷŵ����ʵ�λ�ã����д�������Ұ���һҳ�Ĳ�������Ǩ�Ƶ��µ�����ҳ��������ҳ���ѡ�

��չ��
���û���Զ�������ʱ��mysql����÷ǿ�Ψһ����������������û�зǿ�Ψһ����ʱ�����6�ֽڵ�����Ϊ����������

���ݽṹ

6��map hash_map ����
map���ú������Ϊ�ײ�ṹ�������Ч��ΪO(logN)
hash_map��hashtableΪ�ײ�ṹ��ʱ�临�Ӷ�O(1)

map������hash_map���� ���������Ԫ�غ�����ţ�ʼ�ձ�������


7�����hash��ͻ����
����̽�⣨linear probing��������̽�⣨quadratic probing����������separate chaining��

����̽�⣺ѭ��Ѱ�ң��������㹻�󣬵��ҵ�λ����Ԫ��ʱ������һ�����ÿռ䣨��ʽ������ȡԪ��ʱͬ���ҵ�Ԫ�ز�Ϊ��ʱ�ж�key�Ƿ�Ϊ���ҵ�key����������������ҡ�
��ɾ��Ԫ��ʱ�����ö���ɾ����ʽ���ȱ��Ԫ�أ��ȵ�rehash����ʱ��ɾ����
ȱ���������ÿ��Ԫ�ز����������������±�λ�ñ�ռ��ʱ��һֱ�ҵ����ʵ�λ��

����̽�⣺

����������ÿ�����Ԫ����ά��һ��list


��Ϣ����

8��rabbitmq��α�֤��Ϣ����ʧ

9���ݵ���

10����������֤��Ϣ����ʧ

*/

//����

/*
* leetCode 459 �ظ������ַ���
����һ���ǿյ��ַ��� s ������Ƿ����ͨ��������һ���Ӵ��ظ���ι��ɡ�

���Բ���KMPģʽƥ�䣺 checkKMP(s+s, s),kmp���ѣ����õڶ���˼·
�ַ��� s������ ����n�������ĳ���Ӵ� s' ��ɣ���ô s'�ĳ���n'Ϊn��������
s'ǰ׺��sһ��������ƥ��s[i] = s[i-n'],����i��ֵ
*/
class RepeatedSubstringPattern {
public:
	static bool CheckIsRepeated(std::string str) {
		if (str.empty()) {
			return false;
		}

		//
		int n = str.size();
		//������Ӵ���ɣ���ô������2��
		for (int i = 1; i * 2 <= n; ++i) {

			//����i��n��ֻ��iλ�����ַ��������γ�������ʱ��ֹͣ
			if (n % i == 0) {
				bool match = true;
				for (int j = i; j < n; ++j) {
					if (str[j] != str[j - i]) {
						match = false;
						break;
					}
				}

				if (match) {
					return true;
				}
			}

		}
	}
};


/*
*
����x��50%���ʷ���0��1
ʵ�ֺ���y���ȸ��ʷ���0��9����
*/
class RandY {
public:

	static int RandX() {
		return rand() % 2;
	}

	static int GetRandNum() {

		int num = 0;
		do {
			num = RandX() << 3;
			num += RandX() << 2;
			num += RandX() << 1;
			num += RandX();
		} while (num > 9);
		
		return num;
	}
};