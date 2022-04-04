/*
leetCode 460 LFU ����
����ʹ�û������ set����Ƶ������set����Ϊ�����
��ͨ��map��ϣ������¼key-value
Ϊʵ��set������Ҫ����ڵ��>������
*/

#include <unordered_map>
#include <set>

using namespace std;

struct LFUNode {

	int _key;
	int _value;
	int _time;
	int _count;


	LFUNode(int key,int value,int time,int count):_key(key), _value(value), _time(time), _count(count) {

	}

	bool operator < (const LFUNode& node) const {
		return _count == node._count ? _time < node._time : _count < node._count;
	}
};

class LFUCache {
	unordered_map<int, LFUNode> _keyTable;
	set<LFUNode> _data;
	int _capacity;
	int _time;
public:
	LFUCache(int capacity):_capacity(capacity) {
		_time = 0;
		_keyTable.clear();
		_data.clear();
	}

	void Put(int key, int value) {
		if (_capacity == 0) return;
		auto itr = _keyTable.find(key);
		if (itr == _keyTable.end()) {
			//����Ѿ��ﵽ����ʱ����Ҫɾ������ʹ�õĽڵ㣬���ڷ����½ڵ�
			if (_data.size() == _capacity) {
				//ɾ������ʹ�õĽڵ�
				_keyTable.erase(_data.begin()->_key);
				_data.erase(_data.begin());
			}
			else {
				LFUNode data(key, value, 0, 1);
				_keyTable.insert(make_pair(key, data));
				_data.insert(data);
			}
		} else {
			LFUNode data = itr->second;
			//�Ӻ����ɾ���ɽڵ�
			_data.erase(data);
			//�����½ڵ�Ƶ��
			data._count++;
			data._time++;
			//�Żغ����
			_data.insert(data);
			itr->second = data;
		}
	}

	int Get(int key) {
		if (_capacity == 0) return -1;
		auto itr = _keyTable.find(key);
		if (itr == _keyTable.end()) {
			return -1;
		}
		LFUNode data = itr->second;
		//�Ӻ����ɾ���ɽڵ�
		_data.erase(data);
		//�����½ڵ�Ƶ��
		data._count++;
		data._time++;
		//�Żغ����
		_data.insert(data);
		itr->second = data;
		return data._value;
	}
};
