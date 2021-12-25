/*
ͬ������
���ڽ����̳߳ش��������񣬲�����������ʵ���߳�ͨ�ţ�������Ϊ��ʱ�ȴ�����Ϊ��ʱ֪ͨ�߳�ȥ����

*/
#include<list>
#include<mutex>
#include<condition_variable>

using namespace std;

template<typename T>
class SyncQueue {
private:
	list<T> _queue;			//��������������
	int _maxSize;	//�������񻺴���
	bool _needStop;	//��������
	mutex _mutex;	//��������
	condition_variable _notEmpty;	//����Ϊ��ʱ֪ͨ
	condition_variable _notFull;	//û����ʱ֪ͨ


public:

	SyncQueue(int size) : _maxSize(size), _needStop(false) {

	}

	void Put(const T& x) {
		Add(x);
	}

	void Put(T&& x) {
		Add(forward<T>(x));
	}

	//���п����߳�ʱ����ȡ���񣬲�������һ�����ã�����������������д���
	//��ʱ�����õĻ�Ҳ��������������õ��󲿷ֺ�ʱ������ô�ᵼ��ĳ���߳�ͻȻ��æµ�������߳�ȴ����
	//Ҳ����ͨ��������ȡ�ķ�ʽ���ÿ��е��߳�ȥ��ȡæµ�̵߳�������Ҫ����ȫ��������н���ά��
	void Take(list<T>& list) {
		unique_lock<mutex> locker(_mutex);
		//������waiting״̬���̱߳�notify_one �� notify_allʱ����ȡ��mutex��Ȼ���жϵ����Ƿ����㣬�������������ִ�У����������ͷ�mutex�����ȴ�
		_notEmpty.wait(locker, [this] {return _needStop || notEmpty(); });
		
		if (_needStop) {
			return;
		}
		//�ƶ�����
		list = move(_queue);
		//֪ͨ�ȴ����������߳�
		_notFull.notify_one();
	}

	void Take(T& t) {
		unique_lock<mutex> locker(_mutex);
		//������waiting״̬���̱߳�notify_one �� notify_allʱ����ȡ��mutex��Ȼ���жϵ����Ƿ����㣬�������������ִ�У����������ͷ�mutex�����ȴ�
		_notEmpty.wait(locker, [this] {return _needStop || notEmpty(); });

		if (_needStop) {
			return;
		}
		//�ƶ�����
		t = _queue.front();
		_queue.pop_front();
		//֪ͨ�ȴ����������߳�
		_notFull.notify_one();
	}

	void Stop() {
		{
			unique_lock<mutex> locker(_mutex);
			_needStop = true;
		}
		//�������еȴ����̣߳�����locker�����Ƚ����Ż�
		_notEmpty.notify_all();
		_notFull.notify_all();
	}

	bool Empty() {
		lock_guard<mutex> locker(_mutex);
		return _queue.empty();
	}

	bool Full() {
		lock_guard<mutex> locker(_mutex);
		return _queue.size() == _maxSize : true : false;
	}

	size_t Size() {
		lock_guard<mutex> locker(_mutex);
		return _queue.size();
	}
private:

	bool notEmpty() {
		return _queue.size() > 0 : true : false;
	}

	bool notFull() {
		return _queue.size() < _maxSize : true : false;
	}

	template<typename F>
	void Add(F&& x) {
		unique_lock<mutex> locker(_mutex);
		//��������ʱ�ȴ����ȴ�֪ͨ
		_notFull.wait(locker, [this] {return _needStop || notFull(); });

		if (_needStop) {
			return;
		}

		//����&& Ϊ��ֵ���ã���������ת��
		_queue.push_back(forward<F>(x));
		//֪ͨ�ȴ���ȡ������߳�
		_notEmpty.notify_one();
	}
};