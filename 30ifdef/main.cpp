/**
 * 通过#define #ifndef #ifdef #endif 可以实现条件
 * 有选择地对部分程序源代码进行编译
 *
 * 在命令行中操作宏定义，现在源代码中注释掉 #define DEBUG
 * 使用 -DDEBUG 选项来定义 DEBUG 宏
 */
#include <iostream>
using namespace std;
#define DEBUG
#define MIN(a, b) ((a) < (b) ? (a) : (b))
int main() {
  int i, j;
  i = 100;
  j = 30;
#ifdef DEBUG
  cerr << "Trace: Inside main function" << endl;
#endif

#if 0
    /* 这是注释部分 */
   cout << MKSTR(HELLO C++) << endl;
#endif
  cout << "The minimum is " << MIN(i, j) << endl;
#ifdef DEBUG
  cerr << "Trace: Coming out of main function" << endl;
#endif
}