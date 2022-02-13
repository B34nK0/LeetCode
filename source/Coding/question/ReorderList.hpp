
//leetCode 143 ��������
//ԭ l1 - l2 - l3 - l4 - l5
//�� l1 - l5 - l2 - l4 - l3

#include "CommonStruct.h"

class ReorderList {
public:
	static void GetReorderList(ListNode* head) {
		if (nullptr == head) {
			return;
		}
		//���ҳ������е�
		ListNode* mid = getMidNode(head);
		//��������е�ֳ�������������
		ListNode* left = head;
		ListNode* right = mid->next;
		mid->next = nullptr;
		//����������з�ת
		right = reverseList(right);
		//�ϲ���������
		mergeList(left, right);
	}

	static ListNode* getMidNode(ListNode* head) {
		//����˫ָ�뷽ʽ��p1ÿ����һ���� p2ÿ������������p2Ϊnullptrʱ��p1��Ϊ�м�ڵ�
		ListNode* slow = head, *fast = head;
		while (fast->next && fast->next->next) {
			slow = slow->next;
			fast = fast->next->next;
		}

		return slow;
	}

	static ListNode* reverseList(ListNode* head) {
		ListNode* prev = nullptr,*next = nullptr;
		ListNode* cur = head;
		while (cur) {
			next = cur->next;
			cur->next = prev;
			prev = cur;
			cur = next;
		}

		return prev;
	}

	static void mergeList(ListNode* left, ListNode* right) {
		while (left && right) {
			ListNode* leftTmp = left->next;
			ListNode* rightTmp = right->next;

			left->next = right;
			left = leftTmp;

			right->next = left;
			right = rightTmp;
		}
	}
};