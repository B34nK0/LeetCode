#include <vector>

/// <summary>
/// ʹ��Ħ��ͶƱ��ʽ���ҳ������г���һ��� n/2����
/// </summary>
class MajorityElement {
public:

	static int FindElement(std::vector<int> numbers) {
		if (numbers.empty()) {
			return 0;
		}

		int result = numbers[0];
		int count = 1;
		for (int i = 1; i < numbers.size(); ++i) {
			if (result == numbers[i]) {
				count++;
			}
			else if (result != numbers[i]) {
				count--;
			}
			else if (count == 0) {
				result = numbers[i];
				count = 1;
			}
		}

		return result;
	}
};