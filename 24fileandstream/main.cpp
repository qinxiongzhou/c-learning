/**
 * 要在 C++ 中进行文件处理，必须在 C++ 源代码文件中包含头文件 <iostream> 和
 * <fstream>。 在从文件读取信息或者向文件写入信息之前，必须先打开文件。ofstream
 * 和 fstream
 * 对象都可以用来打开文件进行写操作，如果只需要打开文件进行读操作，则使用
 * ifstream 对象。下面是 open() 函数的标准语法，open() 函数是 fstream、ifstream
 * 和 ofstream 对象的一个成员
 *
 */
#include <fstream>
#include <iostream>
using namespace std;
int main() {
  char data[100];

  // 以写模式打开文件
  ofstream outfile;
  outfile.open("afile.txt");

  cout << "Writing to the file" << endl;
  cout << "Enter your name: ";
  cin.getline(data, 100);

  // 向文件写入用户输入的数据
  outfile << data << endl;
  cout << "Enter your age: ";
  cin >> data;
  cin.ignore();

  // 再次向文件写入用户输入的数据
  outfile << data << endl;

  // 关闭打开的文件
  outfile.close();

  // 以读模式打开文件
  ifstream infile;
  infile.open("afile.txt");

  cout << "Reading from the file" << endl;
  infile >> data;

  // 在屏幕上写入数据
  cout << data << endl;

  // 再次从文件读取数据，并显示它
  infile >> data;
  cout << data << endl;

  // 关闭打开的文件
  infile.close();

  return 0;
}