/**
 * C++ 信号处理库提供了 signal 函数，用来捕获突发事件。以下是 signal()函数的语法
 * void (*signal (int sig, void (*func)(int)))(int);
 * 这个函数接收两个参数：第一个参数是一个整数，代表了信号的编号；第二个参数是一个指向信号处理函数的指针。
 */
#include <csignal>
#include <iostream>
#include <unistd.h>
using namespace std;
void signalHandler(int signum) {
  cout << "Interrupt signal (" << signum << ") received.\n";
  // 清理并关闭
  // 终止程序
  exit(signum);
}
int main() {
  // 注册信号 SIGINT 和信号处理程序
  signal(SIGINT, signalHandler);
  while (1) {
    cout << "Going to sleep...." << endl;
    sleep(1);
  }
  return 0;
}
// 运行结果：按Ctrl+C来中断程序，您会看到程序捕获信号，程序打印如下内容并退出：
/**
[root@VM-77-182-tencentos 31singal]# ./output
Going to sleep....
Going to sleep....
^CInterrupt signal (2) received.
 */