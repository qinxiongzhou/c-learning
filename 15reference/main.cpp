/**
 * 引用变量是一个别名，也就是说它是已存在变量的另一个名字。创建时必须被初始化
 * 
 * 引用和指针的三个主要不同
 * 1、不存在空引用。引用必须连接到一块合法的内存。
 * 2、一旦引用被初始化指向一个对象，就不能被指向到另一个对象。指针可以在任何时候指向到另一个对象。
 * 3、引用必须在创建时被初始化。指针可以在任何时间被初始化。
 */
#include <iostream>
using namespace std;
int main(){
  // 声明简单的变量
  int i;
  double d;

  // 声明引用变量
  int& r = i;
  double& s = d;

  i = 5;
  cout << "Value of i : " << i << endl;
  cout << "Value of i reference : " << r << endl;

  r = 6;
  cout << "Value of i : " << i << endl;
  cout << "Value of i reference : " << r << endl;

  d = 11.7;
  cout << "Value of d : " << d << endl;
  cout << "Value of d reference : " << s << endl;
  
  return 0;
}