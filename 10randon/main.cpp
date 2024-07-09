#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
/**
 * 关于随机数生成器，有两个相关的函数。一个是 rand()，该函数只返回一个伪随机数。生成随机数之前必须先调用 srand() 函数。
 * 下面是一个关于生成随机数的简单实例。实例中使用了 time() 函数来获取系统时间的秒数，通过调用 rand() 函数来生成随机数
 */
int main(){
  int i,j;

  // 设置种子
  srand((unsigned)time(NULL));

  /// 生成 0 - 9 之间的随机数
  for(i = 0;i < 10;i++ ){
    // 生成随机数
    j = rand() % 10;
    cout << j << endl;
  }
}