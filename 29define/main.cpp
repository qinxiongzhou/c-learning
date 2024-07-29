/**
 * #define 预处理指令用于创建符号常量，改符号常量通常称为宏，指令的一般形式为：
 * #define macro-name replacement-text
 *
 * 当这一行代码出现在一个文件中时，在该文件中后续出现的所有宏都将会在程序编译之前被替换为replacement-text。
 */
#include <iostream>
using namespace std;
// #define PI 3.14159
// int main() {
//   cout << "Value of PI :" << PI << endl;
//   return 0;
// }

#define CALL_WITH_MAX(a, b) ((a) > (b) ? (a) : (b))
int main() {
  int a = 5, b = 0;
  CALL_WITH_MAX(++a, b);
  std::cout << "Value of a after macro call: " << a << std::endl;
  CALL_WITH_MAX(++a, b + 10);
  std::cout << "Value of a after macro call: " << a << std::endl;
  return 0;
}