#pragma once

/// <summary>
/// leetCode �ϲ�k����������
/// </summary>
/// 
#include "CommonStruct.h"
#include <vector>

using namespace std;

class MergeKLists {
public:
	//�ϲ���������ʱ��Ҫ��������
	static ListNode* mergeTwoList(ListNode* leftList, ListNode* rightList) {
		//��һ����Ϊ�գ� ��ô���ز�Ϊ�յ�������
		if (!leftList || !rightList) {
			return leftList ? leftList : rightList;
		}
		//head.next�νӽڵ㣬 tail.next���ڱ䶯 ����tail��ʼָ��head�������ڷ��ر�ͷ
		ListNode head, *tail = &head, *pa = leftList, *pb = rightList;
		//ָ��˫����ǰ�ڵ㣬�����ж����߽ڵ��С
		while (pa && pb) {
			if (pa->val < pb->val) {
				tail->next = pa;
				pa = pa->next;
			}
			else {
				tail->next = pb;
				pb = pb->next;
			}
			tail = tail->next;
		}
		//��pa\pbʣ��Ľӵ�������
		tail->next = (pa ? pa : pb);

		return head.next;
	}

	static ListNode* merge(vector<ListNode*>& lists, int l , int r) {
		//���õݹ�ķ�ʽ�ֶ���֮�ϲ�����������l����rʱ������
		if (l > r) return nullptr;
		//��l����rʱ��ֻ��һ������
		if (l == r) return lists[l];
		//�����е㷽ʽ
		int mid = (l + r) >> 1; //����1�൱�ڳ�2������nλ�൱�ڳ�2��n�η�
		//����mid�±�
		return mergeTwoList(merge(lists, l , mid), merge(lists, mid+1, r));
	}

	static ListNode* GetResult(vector<ListNode*>& lists) {
		return merge(lists, 0, lists.size() - 1);
	}
};