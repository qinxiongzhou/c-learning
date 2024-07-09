/**
 * 语法：class derived-class: access-specifier base-class1, access-specifier
 * base-class2...
 */
#include <iostream>
using namespace std;
// 基类Shape
class Shape {
public:
  void setWidth(int w) { width = w; }
  void setHeight(int h) { height = h; }

protected:
  int width;
  int height;
};
// 基类PaintCost
class PaintCost {
public:
  int getCost(int area) { return area * 70; }
};
// 派生类Rectangle
class Rectangle : public Shape, public PaintCost {
public:
  int getArea() { return width * height; }
};
int main(void) {
  Rectangle rect;
  int area;

  rect.setHeight(7);
  rect.setWidth(5);

  area = rect.getArea();

  cout << "Total area: " << rect.getArea() << endl;
  cout << "Total paint cost: $" << rect.getCost(area) << endl;
}