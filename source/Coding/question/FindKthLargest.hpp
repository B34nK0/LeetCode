#pragma once
#include <vector>
#include <time.h>
#include <queue>

/*
* leetCode 215. �����еĵ�K�����Ԫ��
������������ nums ������ k���뷵�������е� k ������Ԫ�ء�
*/

using namespace std;
class FindKthLargest {
public:

	/*
	����һ������С���ѣ�ջ��ֵʱ������С�ģ�������k-1�������ջ����ֵ���ǵ�k�����Ԫ��
	//1�����Խ������ȶ���
	2���Լ�������
	*/
	int byPriorityQueue(vector<int>& nums, int k) {
		priority_queue<int, vector<int>, greater<int>> minHeap(nums.begin(), nums.begin() + k);
		for (size_t i = k; k < nums.size(); ++i) {
			//��ǰֵ����ջ��ֵʱ��˵��ջ��һ������k�����Ԫ�����һ��
			if (nums[i] > minHeap.top()) {
				minHeap.pop();
				//���ȶ��л����Ȩֵ���¹�����
				minHeap.push(nums[i]);
			}
		}
		return minHeap.top();
	}

	//���������С���ѵĹ���
	void buildMaxHeap(vector<int>& a, int heapSize) {
		for (int i = heapSize >> 1; i >= 0; --i) {
			maxHeapify(a, i, heapSize);
		}
	}

	void maxHeapify(vector<int>& a, int i, int heapSize) {
		int l = i * 2 + 1, r = i * 2 + 2, largest = i;
		if (l < heapSize && a[l] > a[largest]) {
			largest = l;
		}
		if (r < heapSize && a[r] > a[largest]) {
			largest = r;
		}
		if (largest != i) {
			swap(a[i], a[largest]);
			maxHeapify(a, largest, heapSize);
		}
	}

	void maxHeapify2(vector<int>& a,int i, int heapSize) {
		for (; (i << 1) + 1 <= heapSize;) {
			int lson = (i << 1) + 1;
			int rson = (i << 1) + 2;
			int largest;
			if (lson <= heapSize && a[lson] > a[i]) {
				largest = lson;
			}
			else {
				largest = i;
			}
			if (rson <= heapSize && a[rson] > a[largest]) {
				largest = rson;
			}
			if (largest != i) {
				swap(a[i], a[largest]);
				i = largest;
			}
			else {
				break;
			}
		}
	}

	int quickSelect(vector<int>& nums, int left, int right, int k) {
		//������ֵ��λ��
		int kindex = findKindex(nums, left, right);
		if (kindex == k) {
			return nums[kindex];
		}
		//ʹ�ÿ���ȷ����ֵ��k�Ĺ�ϵ�������ֵ�ڵ�ǰ�����λ��С��k��ֵ��˵����k���ֵ����ֵ�ұ�
	//���λ�ô���kֵ��˵����k���ֵ����ֵ���
		return kindex < k ? quickSelect(nums, kindex + 1, right, k) : quickSelect(nums, left, kindex - 1, k);
	}

	int partition_select_index(vector<int>& nums, int left, int right) {
		//��ǰ��ֵ
		int pivot = nums[right];

		int i = left;
		for (int j = left; j < right; ++j) {
			if (nums[j] <= pivot) {
				std::swap(nums[i], nums[j]);
				i = i + 1;
			}
		}
		std::swap(nums[i], nums[right]);
		return i;
	}

	int findKindex(vector<int>& nums, int left, int right) {
		int index = rand() % (right - left + 1) + left;
		swap(nums[index], nums[right]);
		return partition_select_index(nums, left, right);
	}

	int FindKthLargestNum(vector<int>& nums, int k) {
	
		srand((unsigned int)time(NULL));
		return quickSelect(nums, 0, nums.size() - 1, nums.size() - k);
	}
};