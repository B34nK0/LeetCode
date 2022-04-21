
/*
* leetCode 322
coins�����ʾӲ�ҵĽ�amount��ʾĿ����
�������Ϊamount�����ٸ�Ӳ����

���ö�̬�滮�ķ�ʽ

���Թٵ�Ҫ���Ƚ���˼·

{1, 2, 5, 7} target = 14
�����Ϊ14ʱ��targetNums[14-7]+1 = 2
targetNums[7-7]+1 = 1


[1,2,5]  target = 11
���3����ʾ 5 + 5 + 1

target = 11ʱ
targetNums[11-6]+1 = 3

target = 6ʱ
targetNums[6-5] + 1 = 2

target = 1ʱ
targetNums[1-1]+1 = 1
*/

#include <vector>
class solution {
public:
	int GetCoinsNums(std::vector<int> coins, int target) {
		//ÿ���������Ҫ������Ӳ����
		std::vector<int> targetNums(target + 1, target);
		//���Ϊ0ʱ������Ϊ0
		targetNums[0] = 0;
		//2
		for (int i = 1; i <= target; ++i) {
			//1, 2
			for (int j = 0; j < coins.size(); ++j) {
				//1
				if (coins[j] <= i) {
					//Ŀ�����ȥ��ǰӲ�ҽ��
					targetNums[i] = std::min(targetNums[i], targetNums[i-coins[j]] + 1);
				}
			}
		}

		return targetNums[target] > target ? -1 : targetNums[target];
	}
};

/*

�����㷨��

©Ͱ�㷨��©����������Ͱ�㷨���������㷨

©Ͱ�㷨��
1���̶�������Ͱ
2�����չ̶��������������󣬲�֧�ֲ���


����Ͱ�㷨��
��©Ͱ�㷨�Ĳ���
1����һ�������������Ʒŵ�Ͱ�������
2������Ͱ����ʱ�����ɵ����ƿ��Զ���
3����������ʱ�����Ի�ȡͰ�ڵ����ƽ������ѣ�������Ʋ���ʱ�ɵȴ����߾ܾ�����

������©Ͱ������Ͱ֧�ֲ�����ֻ���ܻ�ȡ�����Ƽ��������ͨ��

�������㷨��
1������һ��ʱ����ֻ��ͨ��һ������������
*/
#include <time.h>
class LeakBucketLimiter {
	//�������ʣ�ÿ��2������ 
	int _rate;
	//����
	int _capacity;
	//ʣ���ˮ��
	int _water;
	//����һ������ʱ��
	time_t _lastRequestTime;
public:
	LeakBucketLimiter(int rate, int capacity, int water) {
		_rate = rate;
		_capacity = capacity;
		_water = water;
		time(&_lastRequestTime);
	}

	bool IsRateLimiterOK() {
		//ͰΪ��ʱ��������������Ĭ�ϲ���Ϊ0������ˮ����������
		if (_water == 0) {
			_water++;
			return false;
		}

		//ִ��©ˮ
		time_t timestamp;
		time(&timestamp);
		//�������������̶����ʼ�ÿ��ֻ��ִ����������
		int waterLeaked = (timestamp - _lastRequestTime) / 1000 * _rate;
		//������1��ʱ,waterLeakedΪ0
		int waterLeft = _water - waterLeaked;
		_water = std::max(0, waterLeft);
		//��������ʱ��
		_lastRequestTime = timestamp;


		//�����Լ�ˮ����������
		if (_water < _capacity) {
			_water++;
			return true;
		}
		//��������������
		return false;
	}
};
class TokenBucketLimiter {
	//��������Ч��
	int _rate;
	//����
	int _capacity;
	//��ǰ������
	int _token;
	//����һ������ʱ��
	time_t _lastRequestTime;
public:
	TokenBucketLimiter(int rate, int capacity) {
		_rate = rate;
		_capacity = capacity;
		_token = 0;
		time(&_lastRequestTime);
	}

	bool IsRateLimiterOK() {
		//��ǰ������������
		time_t now;
		time(&now);
		int produceToken = (now - _lastRequestTime) / 1000 * _rate;
		//
		int allToken = produceToken + _token;
		//ֻ����������������������������
		_token = std::min(_capacity, allToken);

		//����һ������
		if (_token > 0) {
			_token--;
			time(&_lastRequestTime);
			return true;
		}

		return false;
	}
};
/*
redis

redisΪʲô�������죿

1���ڴ����ݿ⡣Redis�ļ�ֵ�����ǻ����ڴ�ģ��ڴ�ķ����ٶȺܿ졣
2����Ч�ĵײ����ݽṹ��Redis�ײ���õ�ѹ���б�������ϣ������ݽṹ��
3��������IOģ�͡�Redisʹ�û��ڶ�·���õĸ�����IOģ�͡�

�䵥�߳�ģʽ�����¼��ַ������õ��̣߳����ײ����Reactorģʽ��������IO

redist�����򼯺ϼ�����ziplist��skiplilst֮һʵ��

ʲôʱ����ziplist��skiplist��

�����򼯰�����Ԫ�������Ƚ϶࣬�ֻ���Ԫ�صĳ�Աʱ�Ƚϳ����ַ���ʱ��redis����zset�����������ײ�ʵ�֣�
�����������ѹ���б�ziplist��zset����һ��dict+һ��skiplist
dict������ѯ���ݵ�����(score)�Ķ�Ӧ��ϵ����skiplist�������ݷ�����ѯ���ݣ������Ƿ�Χ���ң���


skiplist��ƽ��������ϣ��ĶԱȣ�
1��skiplist����Ч����ƽ����һ��O(logN)����hashtable�ڱ��ֵڳ�ͻ�ʵ�����£�O(1)
2��skiplist����ڵ�ֻӰ��ǰ��ڵ㣬��ƽ������Ҫ����������
3��skiplistʵ�ֱ�ƽ������
4��skiplist����ʵ�ַ�Χ��ѯ����ƽ������Ҫ���ҵ�Сֵ�Ľڵ�����������Ҳ�������ֵ�Ľڵ㣬���߶�ƽ�����������mysql��b+tree������ǰ��ָ��

redis skiplist���ص�
skiplist֧��ƽ��O(logN)���O(N)���ӶȵĽڵ����

skiplist�����ڵ�ʱ��������������ķ�ʽ��ֻ��Ҫ�޸Ĳ���ڵ�ǰ���ָ�뼴�ɣ�����Ҫ�������ڵ���е�������ƽ��������ʱ�ĵ���Ҫ�١�
һ���ڵ���i+1��ĸ���Ϊp��redis��p����Ϊ1/4�� ������Ϊ32��

�ڵ�ṹ
typedef struct zskiplistNode{
	//����ָ��
	struct zskiplistNode *backward;

	//��ֵ
	double score;

	//��Ա����
	rboj *obj;

	//��
	struct zskipllistLevel {
		//ǰ��ָ��
		struct zskiplistNode *forward;
		//���
		unsigned int span;
	} level[];

}zskiplistNode;

1��������ڼ�¼�����ڵ�֮��ľ��룬����ĳ���ڵ�����У�����;���ʹ��Ŀ���ۼ������������õ�Ŀ��ڵ��������е���λ
2��forward���ڵ���
3��ÿ���ڵ�ķ�ֵʱһ��double�ĸ��������������򣬶���Ա����objָ��һ���ַ�������SDS������ͬ��ֵ�Ķ��󰴶����С���򣨶�Ӧ������dict�е�����

ѹ���б�ziplistΪ�˽�Լ�ڴ濪������һϵ���������������ڴ����ɵ�˳���ͣ�sequential�����ݽṹ���������������ڵ㣨entry����ɣ�ÿ���ڵ���Ա���һ���ֽ������һ������ֵ


hash�ṹ�������ݣ�
redis���ֵ��������hashtale���洢���ݣ�ht[0] ht[1],һ������� ֻʹ��ht[0], ht[1]����rehash��
rehash���̲��ý���ʽ��ʽ��������Ϊrehash�����з����ǲ����õģ����һ����rehash�Ļ����������󣬻ᵼ�³�ʱ�䲻����
redis�����ڼ�ֵ��ɾ�Ĳ���ʱ�������ǰ����rehash״̬����ô������ֵ��ֱ�Ӳ�����ht[1]������ǲ��ҵĻ������Ȳ���ht[0],
��ht[0]�ļ�ֵ���ᵽht[1]���ͷ�ht[0]����ht[1]����Ϊht[0]������ht[1]���´���һ��hashtable

ѩ���㷨��k8s���𻷾�����α�֤Ψһ�ԣ�
ͨ�������ip��ȡ��Ӧ��workid


�������̵�������ʱ

�ֲ�ʽraftЭ��ʵ������ֿ������һ����

�߿��ø�һ����
AP��CP��BASE

*/

/*
mysql

mvcc���ƣ���汾��������
ͨ������ĳ��ʱ�������ݿ�����ʵ�ֲ������ƣ����������ݵ���ʷ�汾����ȡ����ʱ����Ҫ������ֻ��Ҫͨ���汾�ĺ���������
��������ִ�ж೤ʱ�䣬�����ڲ������������ǲ�����������Ӱ��ģ���������ʼ��ʱ�䲻ͬ��ÿ�������ͬһ�ű�ͬһʱ�̿��������ݿ����ǲ�һ���ġ�

�б��۲������ƺ��ֹ۲�����������
innoDb��MVCC�����ֹ���ģʽ����ȡ����ʱ������Ҫ����������д������Ҳֻ������Ҫ���С�


���������ֹ���
�����������۵���Ϊÿ�β������ݵ�ʱ�������˳�ͻ�������Ҫ�õ����Ų���
�ֹ������ֹ���Ϊ�ڸ�������ʱ���˲�����£���˲�����������ʱ�ж��ڴ��ڼ��Ƿ������޸��ˣ�����޸��˼�������Ч���ʺ϶���д�ٵĳ���
mvcc���õ����ֹ���ģʽ����Ȼ�������������ø���ʱ�汾�ŵı仯��ȷ���Ƿ��ѱ��޸�

����
MySQL��������ͨ���������صģ�Ҳ����˵�������Ǽ���������Ӧ�����ϵģ�
Ҫ�Ƕ�Ӧ��SQL���û�������������ȫ��ɨ�裬�������޷�ʵ�֣�ȡ����֮���Ǳ�������ʱ���������޷��Ե�ǰ����и��»���������
*/

/*
����ϵͳ

��ȡ�����ļ�Ȼ���ͳ�ȥ���������ο�����4�ο���  
���̻��������ں˻��������ں˻��������ڴ滺������  �ڴ滺�������ں˻��������ں˻�������IO������

ͨ��read�Ӵ����ļ���ȡ����ʱ��
1�����̿������������ݵ������ڲ���������֮������ж��źţ�
2��cpu�����̻��������ݿ����Ĵ�����Ȼ��ѼĴ������ݿ������ڴ�
writeдioʱ
3���ڴ�д�뵽cpu�Ĵ�����cpu���Ĵ������ݿ�����io������
*/

/*
����

����� 2018 ��2046

����������������һ���������ҵ� TCP ���ӣ��ס���ѡ��ĳ�ʼ���кŷֱ�Ϊ 2018 �� 2046������������� TCP �ε�ȷ�����к���2047
����syn��ȷ��


https�������ӹ���
1���ͻ��˷���https�������ӣ�ͨ��dns��ȡ��url��Ӧ��ip��ַ������ip��Ӧ��443�˿ڣ�ͬʱ���Ϳͻ���֧�ֵļ����㷨
2�������ͨ���ͻ���֧�ֵļ����㷨��ȷ�Ϸ���CA��������������Կ����Ч�ڡ�ǩ���㷨��ǩ��hash�㷨��
3���ͻ�����֤����˵�֤��
	1��֤��Ϸ���
	2���÷���˷��͹����Ĺ�Կ���������
	3����֤���е�ǩ��hash�㷨ȡ������Ϣ��hashֵ��Ȼ�������ɵ��������[������Ϣ��������Ϣ��hashֵ]���м��ܣ�Ȼ���ù�Կ����������м��ܺ�һ���͸�����ˡ�
4��������յ��ͻ��˵�����������ܵ���Ϣ��
	1������˽Կ���ܳ������
	2�������������������Ϣ���鿴�Ƿ񱻴۸ģ���ȡ������Ϣ��������Ϣ��hashֵ�������Լ����͵�������Ϣ��hashֵ����ͻ��˴������Ľ��жԱ���֤��
	3��ͬ��ʹ������ַ�������������Ϣ��������Ϣhashֵ���ظ����ͻ���
5���ͻ����յ�����˷��͹�����������Ϣ���ÿ�ʼ�Լ����ɵ���������н��ܣ���֤����������ܵ�������Ϣ��������Ϣhashֵ��


tcpipЭ��ջ time_wait����β�����
���������ڽ��յ������������fin֮�����time_wait���򱻶�������ack
*/

template<typename DataType>
//DataType��ģ���������������������������� ����
class QuickSortTemp
{
public:
	QuickSortTemp() {}
	~QuickSortTemp() {}
public:
	// ���������ʵ�֣�Array��Ҫ�������ݵ����飬nLower��nUpper��Χ��0 ~ �����ܸ���-1 ���� 
	static void QuickSort(DataType* Array, int nLower, int nUpper) {
		// �����Ƿ�������� ���� 
		if (nLower < nUpper) {
			// �ֽ�ͷֱ�������� ���� 
			int nSplit = Partition(Array, nLower, nUpper);//�����з�Ϊ�������� ���� 
			QuickSort(Array, nLower, nSplit - 1);//��벿�ֵݹ����� ���� 
			QuickSort(Array, nSplit + 1, nUpper);//�Ұ벿�ֵݹ����� ���� 
		}
	}
	static int Partition(DataType* Array, int nLower, int nUpper) { 
		int nLeft = nLower + 1;
		DataType Pivot = Array[nLower];
		int nRight = nUpper;
		DataType Swap;
		while (nLeft <= nRight) {
			//��ֵ�����Ӧ�ñ���ֵС
			while (nLeft <= nRight && Array[nLeft].CompareTo(Pivot) <= 0)
				nLeft = nLeft + 1;
			//��ֵ���ұ�Ӧ�ñ���ֵ��
			while (nLeft <= nRight && Array[nRight].CompareTo(Pivot) > 0)
				nRight = nRight - 1;
			//����������ֵ
			if (nLeft < nRight) { 
				Swap = Array[nLeft];
				Array[nLeft] = Array[nRight];
				Array[nRight] = Swap;
				nLeft = nLeft + 1;
				nRight = nRight - 1;
			}
		}
		//��ֵλ��
		Swap = Array[nLower];
		Array[nLower] = Array[nRight];
		Array[nRight] = Swap;
		return nRight;
	}
};