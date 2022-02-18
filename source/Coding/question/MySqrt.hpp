/// <summary>
/// leetCode 69 X��ƽ����
/// 
/// ���ֻ���� �������� ��С�����ֽ��� ��ȥ
/// </summary>
class MySqrt {
public:
	static int sqrt(int x) {
		if (x < 2) return x;
		//ƽ�����ķ�Χ
		int lo = 0, hi = x / 2;
		//���ڴ洢ƽ������ƽ��ֵ������int�����Ҫ����64λ�洢
		long long tmp;
		while (lo <= hi) {
			//���ֲ��ң���lo�Ļ����ϴ�ƫ�������л���
			int mid = lo + (hi - lo) / 2;
			//����պ�Ϊƽ����ֵ����ô����
			tmp = (long long)mid * mid;
			if (tmp == x) return mid;
			//���ƽ������ֵ����x����Ϊ��ȥС����Ե�ʣ�ƽ������ֵ��mid���
			else if (tmp > x) hi = mid - 1;
			else lo = mid + 1;
		}

		return hi;
	}
};