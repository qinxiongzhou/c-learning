/**
 * 当您有多个文件且定义了一个可以在其他文件中使用的全局变量或函数时，可以在其他文件中使用 extern 来得到已定义的变量或函数的引用
 */
#include <iostream>
int count;
extern void write_extern();
int main(){
  count = 5;
  write_extern();
}