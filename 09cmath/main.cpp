#include <iostream>
#include <cmath>
using namespace std;
int main(){
  // 数字定义
  short s = 10;
  int i = -1000;
  long l = 100000;
  float f = 230.47f;
  double d = 200.374;

  // 数学运算
  cout << "sin(d) : " << sin(d) << endl;
  cout << "abs(i) : " << abs(i) << endl;
  cout << "sqrt(f) : " << sqrt(f) << endl;
  cout << "floor(d) :"  << floor(d) << endl;
  cout << "pow( d, 2) : " << pow(d, 2) << endl;
  return 0;
}