#include <iostream>
#include <vector>
#include <mutex>
#include <thread>
using namespace std;
int main(){
  std::vector<int> numbers = {1,2,3,4,5,6,7,8,9,10};
  std::mutex mtx;

  // 使用 lambda 表达式定义线程的执行体
  std::thread t([&numbers, &mtx](){
    std::lock_guard<mutex> lck(mtx);
    for(int i:numbers){
      cout << i << " ";
    }
  });

  t.join(); // 等待线程完成
}