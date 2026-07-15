#include <stack>

using namespace std;

class MyQueue {
public:
  stack<int> i;
  stack<int> o;
  MyQueue() {

  }
  
  void push(int x) {
    i.push(x);
  }
  void _trans(){
    if (o.empty()) {
      while (!i.empty()) {
        o.push(i.top());
        i.pop();
      }
    }
  }
  int pop() {
    this->_trans();
    int x = o.top();
    o.pop();
    return x;
  }
  
  int peek() {
    this->_trans();
    return o.top();
  }
  
  bool empty() {
    return o.empty() && i.empty();
  }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */