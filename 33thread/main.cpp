#include <iostream>
#include <thread>
#include <vector>
using namespace std;
// 线程的工作函数
void threadFunc(int n) {
  cout << "thread " << n << " is starting" << endl;
  // 模拟一些工作
  this_thread::sleep_for(chrono::seconds(1));
  cout << "thread " << n << " is over" << endl;
}

int main() {
  const int numThreads = 5;
  vector<thread> threads;
  for (int i = 0; i < numThreads; ++i) {
    threads.push_back(thread(threadFunc, i));
  }

  // 等待所有线程执行完毕
  for (auto &th : threads) {
    th.join();
  }
  cout << "all threads are over" << endl;
  return 0;
}
