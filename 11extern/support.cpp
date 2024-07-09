#include <iostream>
extern int count;
void write_extern(){
  std::cout << "count is " << count << std::endl;
}