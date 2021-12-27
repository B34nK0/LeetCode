#pragma once

class ListNode {
public:
	ListNode* next = nullptr;
};

/// <summary>
/// �Ƴ�������������n���ڵ�
/// ������������ָ�룬p1 p2 ��p2��p1��ǰ��n���ڵ㣬Ȼ��ͬʱ�ƶ�p1,p2
/// ��p2�ȵ�����βʱ��˵��p1���ڵ�����n���ڵ���
/// </summary>
class RemoveNthFromEnd {
public:
	static ListNode* Remove(ListNode* head, int n) {
		ListNode* p1, * p2, * prev;
		prev = p1 = p2 = head;
		while (n--) {
			p2 = p2->next;
		}

		while (p2) {
			prev = p1;
			p1 = p1->next;
			p2 = p2->next;
		}

		//�Ƴ�������n���ڵ�
		prev->next = p1->next;

		return head;
	}
};