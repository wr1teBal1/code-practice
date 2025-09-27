/*
 * @lc app=leetcode.cn id=225 lang=cpp
 *
 * [225] 用队列实现栈
 */

// @lc code=start
class MyStack {
public:
    queue<int> que1;
    queue<int> que2; // 辅助队列，用来备份

    MyStack() {
        
    }
    
    void push(int x) {
        que1.push(x);
    }
    
    int pop() {
        int size = que1.size();
        // 将que1的前size-1个元素导入que2
        for (int i = 0; i < size - 1; i++) {
            que2.push(que1.front());
            que1.pop();
        }
        int result = que1.front();// 记录下要弹出的元素
        que1.pop(); // 弹出栈顶元素
        que1 = que2; // 交换que1和que2
        while (!que2.empty()) {
            que2.pop();
        }
        return result;
    }
    
    int top() {
        int size = que1.size();
        for (int i = 0; i < size - 1; i++) {
            que2.push(que1.front());
            que1.pop();
        }

        int result = que1.front();// 记录下要弹出的元素
        que2.push(result); // 先将栈顶元素放入辅助队列
        que1.pop(); // 弹出栈顶元素
        que1 = que2; // 交换que1和que2
        while (!que2.empty()) {
            que2.pop();
        }
        return result;
    }
    
    bool empty() {
        return que1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end

