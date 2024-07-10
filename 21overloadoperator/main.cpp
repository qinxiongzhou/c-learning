#include <iostream>
using namespace std;
class Box {
public:
  double getVolume() { return length * breadth * height; }
  void setLength(double len) { length = len; }
  void setBreadth(double bre) { breadth = bre; }
  void setHeight(double hei) { height = hei; }
  Box operator+(const Box &b) { // 参数是引用，为了增加效率同时防止修改
    Box box;
    box.length = this->length + b.length;
    box.breadth = this->breadth + b.breadth;
    box.height = this->height + b.height;
    return box;
  }

private:
  double length;  // 长度
  double breadth; // 宽度
  double height;  // 高度
};

int main(void) {
  Box box1; // 声明 box1，类型为 Box
  Box box2; // 声明 box2，类型为 Box
  Box box3; // 声明 box3，类型为 Box

  double volumn = 0.0; // 定义体积变量

  // box1 详述
  box1.setHeight(5.0);
  box1.setBreadth(7.0);
  box1.setLength(6.0);

  // box2 详述
  box2.setHeight(12.0);
  box2.setBreadth(13.0);
  box2.setLength(10.0);

  volumn = box1.getVolume(); // 返回 box1 的体积
  cout << "box1 的体积：" << volumn << endl;
  volumn = box2.getVolume(); // 返回 box2 的体积
  cout << "box2 的体积：" << volumn << endl;

  box3 = box1 + box2;        // 将两个 box 相加
  volumn = box3.getVolume(); // 返回 box3 的体积
  cout << "box3 的体积：" << volumn << endl;

  return 0;
}