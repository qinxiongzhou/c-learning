/**
 * C++ 多态意味着调用成员函数时，会根据调用函数的对象的类型来执行不同的函数。
 * 虚函数 是在基类中使用关键字 virtual
 * 声明的函数。在派生类中重新定义基类中定义的虚函数时，会告诉编译器不要静态链接到该函数。
 * 我们想要的是在程序中任意点可以根据所调用的对象类型来选择调用的函数，这种操作被称为动态链接，或后期绑定。
 */
#include <iostream>
using namespace std;
class Shape {
protected:
  int width, height;

public:
  Shape(int a, int b) {
    width = a;
    height = b;
  };
  virtual int area() {
    cout << "parent class area :" << endl;
    return 0;
  }
};
class Rectangle : public Shape {
public:
  Rectangle(int a = 0, int b = 0) : Shape(a, b){};
  int area() {
    cout << "Rectangle class area :" << endl;
    return width * height;
  }
};
class Triangle : public Shape {
public:
  Triangle(int a = 0, int b = 0) : Shape(a, b){};
  int area() {
    cout << "Triangle class area :" << endl;
    return width * height / 2;
  }
};
int main() {
  Shape *shape;
  Rectangle rectangle(10, 7);
  Triangle triangle(10, 5);
  shape = &rectangle;
  shape->area();
  shape = &triangle;
  shape->area();
  return 0;
}