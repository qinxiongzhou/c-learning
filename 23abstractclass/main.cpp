/**
 * 如果类中至少有一个函数被声明为纯虚函数，则这个类就是抽象类。纯虚函数是通过在声明中使用
 * "= 0" 来指定的。
 * 接口可以被视为一个特殊的抽象类，没有成员变量和实现的函数（全部都是纯虚函数）。而抽象类可以有成员变量和和提供默认实现的普通虚函数
 */
#include <iostream>
using namespace std;
// 抽象类
class Shape {
public:
  // 纯虚函数
  virtual int getArea() = 0;
  void setWidth(int w) { width = w; }
  void setHeight(int h) { height = h; }

protected:
  int width, height;
};
// 派生类
class Rectangle : public Shape {
public:
  int getArea() { return (width * height); }
};
class Triangle : public Shape {
public:
  int getArea() { return (width * height / 2); }
};
int main() {
  Rectangle rect;
  Triangle tri;

  rect.setWidth(5);
  rect.setHeight(7);
  // 输出对象的面积
  cout << "Total Rectangle area: " << rect.getArea() << endl;

  tri.setWidth(5);
  tri.setHeight(7);
  // 输出对象的面积
  cout << "Total Triangle area: " << tri.getArea() << endl;

  return 0;
}