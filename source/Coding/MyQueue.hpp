/*
leetCode 232 ��ջʵ�ֶ���
ʹ������ջ  ����ջ�����ջ ��
*/
#include <stack>
class MyQueue {
    std::stack<int> input;
    std::stack<int> output;
public:
    MyQueue() {

    }

    void push(int x) {
        input.push(x);
    }

    int pop() {
        //������ջ��ǰΪ�գ���ô������ջ������ת�Ƶ����ջ��ʵ������ջ�������ջ��ջ��
        //�����ջջ����ʼ��ȡ���ݼ�ʵ�ֶ��е��Ƚ��ȳ�����
        if (output.empty()) {
            while (!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        }
        int ans = output.top();
        output.pop();
        return ans;
    }

    int peek() {
        if (output.empty()) {
            while (!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        }
        return output.top();
    }

    bool empty() {
        return output.empty() ? input.empty() : false;
    }
};