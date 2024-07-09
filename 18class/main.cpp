#include <iostream>
using namespace std;
class Box {
public:
  double length;  // 长度
  double breadth; // 宽度
  double height;  // 高度
  double getVolume(void) { return length * breadth * height; }
};
int main() {
  Box box1; // 声明 box1，类型为 Box
  box1.length = 5.0;
  box1.breadth = 4.0;
  box1.height = 6.0;

  cout << "box1 的体积：" << box1.getVolume() << endl;
  return 0;
}