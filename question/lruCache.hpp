#include <list>
#include <unordered_map>

using namespace std;

class LruCache {
private :
	//pair->first ��Ӧmap��key
	//pair->second ��Ӧmap��value
	list<pair<int, int>> _values;

	unordered_map<int, list<pair<int,int>>::iterator> _container;

	int _capacity;

public:
	LruCache(int capacity) {
		_capacity = capacity;
	}

	int Get(int key) {
		auto value = _container.find(key);
		if (_container.end() == value) {
			return -1;
		}
		//����ϣ��keyָ���list�ڵ�Ǩ�Ƶ�����ı�ͷ
		_values.splice(_values.begin(), _values, value->second);

		return value->second->second;
	}

	void Put(int key, int value) {
		auto oldValue = _container.find(key);
		if (_container.end() != oldValue) {
			//���»�������
			oldValue->second->second = value;
			//����ϣ��keyָ���list�ڵ�Ǩ�Ƶ�����ı�ͷ
			_values.splice(_values.begin(), _values, oldValue->second);
			return;
		}

		if (_container.size() == _capacity) {
			//��ȡ����β�ڵ㣬�ͷ���λ�÷���������
			auto oldValue = _values.back();
			//ɾ����ϣ������
			_container.erase(oldValue.first);
			//ɾ������ָ������
			_values.pop_back();
		}

		_values.emplace_front(key, value);
		_container[key] = _values.begin();
	}
};