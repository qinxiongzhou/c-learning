#include <iostream>
#include <iomanip>
using namespace std;
int main(){
  int n[10];

  for (int i = 0; i < 10; i++){
    n[i] = i + 100;
  }

  cout << "Element" << setw(13) << "Value" << endl;

  // 输出数组中每个元素的值
  for (int j = 0; j < 10; j++)
  {
    /* code */
    cout << setw(7) << j << setw(13) << n[j] << endl;
  }
  return 0;
}