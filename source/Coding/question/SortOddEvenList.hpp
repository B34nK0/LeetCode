
/*
����һ������λ����ż��λ���������������������

����: 1->8->3->6->5->4->7->2->NULL
���: 1->2->3->4->5->6->7->8->NULL
*/

#include "CommonStruct.h"


class SortOddEvenList {
public:
	static void Sort(ListNode* node) {
		//��ԭ��������桢ż��������
		tuple<ListNode*, ListNode*> res =  partition(node);
		//��תż����
		ListNode* evenHead = std::get<1>(res);
		evenHead = revers(evenHead);
		//�ϲ���������
		ListNode* oddHead = std::get<0>(res);
		node = merge(oddHead, evenHead);
	}

	static tuple<ListNode*, ListNode*> partition(ListNode* node) {
		ListNode* oddHead = nullptr, * evenHead = nullptr;
		ListNode* curOdd = nullptr, * curEven = nullptr;
		while (node) {
			//odd
			if (node->val % 2) {
				if (!oddHead) {
					oddHead = new ListNode(node->val);
					curOdd = oddHead;
				}
				else {
					curOdd->next = new ListNode(node->val);
					curOdd = curOdd->next;
				}
			}
			else {//even
				if (!evenHead) {
					evenHead = new ListNode(node->val);
					curEven = evenHead;
				}
				else {
					curEven->next =  new ListNode(node->val);
					curEven = curEven->next;
				}
				curEven->next = nullptr;
			}

			node = node->next;
		}

		return tuple<ListNode*, ListNode*>(oddHead, evenHead);
	}

	static ListNode* revers(ListNode* head) {
		ListNode* pre = nullptr, *next = nullptr;
		ListNode* cur = head;
		while (cur) {
			next = cur->next;
			cur->next = pre;
			pre = cur;
			cur = next;
		}
		return pre;
	}

	static ListNode* merge(ListNode* oddHead, ListNode* evenHead) {
		//����һ���սڵ�
		ListNode ans, *tail = &ans;

		while (oddHead && evenHead) {
			if (oddHead->val <= evenHead->val) {
				tail->next = oddHead;
				oddHead = oddHead->next;
			}
			else {
				tail->next = evenHead;
				evenHead = evenHead->next;
			}

			tail = tail->next;
		}

		oddHead ? tail->next = oddHead : tail->next = evenHead;

		return ans.next;
	}
};