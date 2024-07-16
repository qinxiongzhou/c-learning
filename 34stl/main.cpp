#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
int main() {
  // vector 的使用
  vector<int> v;
  v.push_back(1);
  v.push_back(2);

  for (const auto &i : v) {
    cout << i << endl;
  }

  // map 的使用
  map<string, int> m;
  m["one"] = 1;
  m["two"] = 2;

  for (const auto &i : m) {
    cout << i.first << " " << i.second << endl;
  }

  for (auto &[key, value] : m) {
    cout << key << " " << value << endl;
  }
}