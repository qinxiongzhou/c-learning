/**
 * 使用函数 raise() 生成信号，该函数带有一个整数信号编号作为参数，语法如下：
 * int raise (signal sig);
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
  int i = 0;
  // 注册信号 SIGINT 和信号处理程序
  signal(SIGINT, signalHandler);

  while (++i) {
    cout << "Going to sleep...." << endl;
    if (i == 3) {
      raise(SIGINT);
    }
    sleep(1);
  }
  return 0;
}