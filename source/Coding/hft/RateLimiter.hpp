/*
���û������ڷ�ʽ�������㷨�����ڹ̶�ʱ���ڣ�ֻ��Ҫ���ٸ�����
ʵ�ֶ������ص�����
���� n��t��������
��ʾ��t�����ڣ�ֻ����n��order
*/

#include <deque>

class RateLimiter {
private:
	//���崰�ڶ��У����ն�����ʱ���
	std::deque<uint64_t> _dq;
	int _numMsgs;
	int _timeWindow;

public:
	RateLimiter(int n, int t) : _numMsgs(n), _timeWindow(t) {

	}

	/// <summary>
	/// �ж϶����Ƿ�ɱ�����
	/// </summary>
	/// <param name="ts">������ʱ���</param>
	/// <returns></returns>
	bool IsRateLimiterOK(uint64_t ts) {
		if (_dq.empty()) {
			_dq.push_front(ts);
			return true;
		}

		// ���µĶ���ʱ����ڶ�ͷ����β�Ķ���������¶�����ʱ���������ʱ�䴰�ڣ���ô���Ե�����ʣ��ı�ʾ��ʱ�䴰�����Ѵ���Ķ���
		while (!_dq.empty() && (ts - _dq.back() >= _timeWindow)) {
			_dq.pop_back();
		}

		// �ѳ���������С�ڱ������������˵���¶����ɱ�������¼��ʱ���������true
		if (_dq.size() < _numMsgs) {
			_dq.push_front(ts);
			return true;
		}

		return false;
	}

	int GetCountInWindow() {
		return _dq.size();
	}
};