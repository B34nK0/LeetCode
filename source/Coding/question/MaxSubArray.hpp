/*
* leetCode 53 ����������
* 
* ����һ������nums������������ĺ�
* 
* -2,1,-3,4,-1,2,1,-5,4
* 
* ������� 4,-1,2,1 ��Ϊ 6
*/

#include <vector>
using namespace std;

class MaxSubArray {
public:

	/*
	����һ����̬�滮
	*/
	int GetMaximum(vector<int>& nums) {
		if (nums.empty()) {
			return 0;
		}
		int ans = nums[0];
		int pre = 0;
		//����ÿ��Ԫ�أ���ǰԪ�ص�����ϵ���ǰ��ϼ��ϵ�ǰֵ
		for (auto& num : nums) {
			//���ǰ�����Ϊ���ģ���ôӦ���Ե�ǰֵ������Ϊ�µ�����
			pre = max(pre + num, num);
			ans = max(ans, pre);
		}
		return ans;
	}

	/*
	�����������η�
	*/
	//���е�m���� [l,r]����Ϊ��������
	struct Status {
		//lsum ������Ӷκ�
		//rsum ������Ӷκ�
		//msum ��������Ӷκ�
		//isum �����
		int lSum, rSum, mSum, iSum;

		Status(int lSum, int rSum, int mSum, int iSum) {
			this->lSum = lSum;
			this->rSum = rSum;
			this->mSum = mSum;
			this->iSum = iSum;
		}
	};


	Status pushUp(Status l, Status r) {
		//����� ��������������� ���ܺ�
		int iSum = l.iSum + r.iSum;
		//������к���������һ����
		//�����������ֶκ� ���� max(�������������Ӷκͣ�������������+�������������ֶκ�)
		int lSum = max(l.lSum, l.iSum + r.lSum);
		//������к���������һ����
		//�����������ֶκ� ���� max(������������ֶκͣ� �������+�������������ֶκ�)
		int rSum = max(r.rSum, r.iSum + l.rSum);
		//����ֶκ� �����������
		//����ֶκ� = max( max(����������Ӷκͣ� ����������Ӷκ�) ,  �������������ֶκ� )
		int mSum = max(max(l.mSum, r.mSum), l.rSum + r.lSum);
		return Status(lSum, rSum, mSum, iSum);
	};


	Status get(vector<int>& nums, int l, int r) {
		if (l == r) {
			return Status{ nums[l], nums[l], nums[l], nums[l] };
		}
		//����һλ�൱��/2
		int m = (l + r) >> 1;
		//�ֱ����������������������͵���Ϣ
		Status left = get(nums, l, m);
		Status right = get(nums, m + 1, r);
		return pushUp(left, right);
	}

	int GetRes(vector<int>& nums) {
		if (nums.empty()) return 0;

		return get(nums, 0, nums.size()-1).mSum;
	}
};