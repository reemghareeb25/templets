/*
If you want to get the minimum or maximum in every sliding window of size k:
mono_queue mq;
for(int i = 0; i < n; i++){
    mq.push(a[i]);
    if(i >= k - 1){
        cout << mq.get_min() << " ";
        mq.pop();  // Remove the element that slides out of the window
    }
}

For minimum: use the code below as is.
For maximum: modify the `push` method condition as follows:
  while (!min_queue.empty() && x > min_queue.back())
*/

struct mono_queue {
private:
  queue<int> main_queue;
  deque<int> min_queue;
public:
  void push(int x) {
    main_queue.push(x);
    while (!min_queue.empty() && x < min_queue.back()) {
      min_queue.pop_back();
    }
    min_queue.push_back(x);
  }

  int pop() {
    int n = main_queue.front();
    if (n == min_queue.front()) {
      min_queue.pop_front();
    }
    main_queue.pop();
    return n;
  }

  int get_min() { return min_queue.front(); }

  int front() { return main_queue.front(); }

  int size() { return main_queue.size(); }
};
