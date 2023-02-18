

// TC: pop->O(n), push->O(1), top->O(1),  SC: O(n) all element in the queue

class MyStack {
queue<int> q1;
public:
    MyStack() {
    }
    
    void push(int x) {
      q1.push(x);
    }
    
    int pop() {
      for (int i=0; i < q1.size()-1; i++) {
        q1.push(q1.front());
        q1.pop();
      }
      int top = q1.front();
      q1.pop();
      return top;
    
    }
    int top() {
      if (q1.empty()) return -1;
      return q1.back();
    }
    
    bool empty() {
      return q1.empty();
    }
};