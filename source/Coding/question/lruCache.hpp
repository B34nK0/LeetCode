/*
leetCode 146LRU����
LRUҲ�����ʹ�ù�Least Recently Used
������ʵ�ֻ�����̭���ƣ���Ԥ����������

ʹ���������洢��ֵ��
1����������ʱ��������ڻ����У���ô�����ݽڵ���µ���ͷ
2�����ݲ��ڻ�����ʱ������������㣬�򽫱�β������̭��ͬʱ�����ݽڵ���ñ�ͷ
3����ȡ����ʱ������ڻ����У��������ݽڵ��ƶ�����ͷ
���ڻ���ʱ����-1

ʹ��unordered_map����¼key������ڵ�pair��ӳ��
*/

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
		//splice���������ڽӺ���������
		//��value->second��������ָԪ�ؽӺ���_values.begin()��ָλ��֮ǰ
		_values.splice(_values.begin(), _values, value->second);
		//���ؽڵ�ֵ
		return value->second->second;
	}

	void Put(int key, int value) {
		//�жϻ������Ƿ��������
		auto oldValue = _container.find(key);
		if (_container.end() != oldValue) {
			//���»�������
			oldValue->second->second = value;
			//����ϣ��keyָ���list�ڵ�Ǩ�Ƶ�����ı�ͷ
			_values.splice(_values.begin(), _values, oldValue->second);
			return;
		}
		//���治����ʱ���ж������Ƿ��㹻
		if (_container.size() == _capacity) {
			//��ȡ����β�ڵ㣬�ͷ���λ�÷���������
			auto oldValue = _values.back();
			//ɾ����ϣ������
			_container.erase(oldValue.first);
			//ɾ������ָ������
			_values.pop_back();
		}

		_values.emplace_front(key, value);
		//��kv�������еĵ������ŵ�unordered_map����������
		_container[key] = _values.begin();
	}
};