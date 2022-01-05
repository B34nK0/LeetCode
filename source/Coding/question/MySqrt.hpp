class MySqrt {
public:
	static int sqrt(int x) {
		if (x < 2) return x;
		int lo = 0, hi = x / 2;
		//���ڴ洢ƽ������ƽ��ֵ������int�����Ҫ����64λ�洢
		long long tmp;
		while (lo <= hi) {
			//���ֲ���
			int mid = lo + (hi - lo) / 2;
			tmp = (long long)mid * mid;
			if (tmp == x) return mid;
			else if (tmp > x) hi = mid - 1;
			else lo = mid + 1;
		}

		return hi;
	}
};