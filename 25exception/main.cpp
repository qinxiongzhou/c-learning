/**
 * 如果有一个块抛出一个异常，捕获异常的方法会使用 try 和 catch 关键字。try
 块中放置可能抛出异常的代码，try 块中的代码被称为保护代码。使用 try/catch
 语句的语法如下所示：
 * try{
   // 保护代码
   }catch( ExceptionName e1 ){
   // catch 块
   }catch( ExceptionName e2 ){
   // catch 块
   }catch( ExceptionName eN ){
   // catch 块}
 */
#include <exception>
#include <iostream>
#include <string>
using namespace std;
struct MyException : public exception {
  string message; // 用于存储错误信息的字符串
  // 构造函数，将错误信息保存到成员变量中
  MyException(const string &message) : message(message) {}
  const char *what() const throw() { return message.c_str(); }
};
int main() {
  try {
    /* code */
    throw MyException("Custom C++ Exception with parameters");
  } catch (const MyException &e) {
    cout << "MyException caught" << '\n';
    cout << e.what() << '\n';
  } catch (const std::exception &e) {
    std::cerr << e.what() << '\n';
  }
}