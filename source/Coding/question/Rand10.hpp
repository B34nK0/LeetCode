
/*
leetCode 470��rand7ʵ��rand10
������ȸ��ʵ�10����
*/

int rand7() {
	
}

class Rand10 {
public:
	int rand10() {
        int row, col, idx;
        do {
            row = rand7();
            col = rand7();
            idx = col + (row - 1) * 7;
            //ȡ49����������ǰ40����
        } while (idx > 40);
        return 1 + (idx - 1) % 10;
	}
};