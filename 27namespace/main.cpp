/**
 * 命名空间：可作为附加信息来区分不同库中相同名称的函数、类、变量等。
 * 本质上，命名空间就是定义了一个范围。
 * namespace namespace_name {// 代码声明}
 *
 * 命名空间可以定义在几个不同的部分中，因此命名空间是由几个单独定义的部分组成的。一个命名空间的各个组成部分可以分散在多个文件中
 * 命名空间可以嵌套，您可以在一个命名空间中定义另一个命名空间，如下所示：
 * namespace namespace_name1 {
 * // 代码声明
 *  namespace namespace_name2 {
 *   // 代码声明
 * }}
 */
#include <iostream>
using namespace std;
// 第一个命名空间
namespace first_space {
void func() { cout << "Inside first_space" << endl; }
} // namespace first_space
// 第二个命名空间
namespace second_space {
void func() { cout << "Inside second_space" << endl; }
} // namespace second_space

using namespace first_space;
int main() {
  func();
  return 0;
}