#include <iostream>
using namespace std;
class BankAccount {
private:
  double balance;

public:
  BankAccount(double initialBalance) : balance(initialBalance) {}

  double getBalance() const { // 不修改任何成员变量
    return balance;
  }

  void deposit(double amount) {
    if (amount > 0) {
      balance += amount; // 修改成员变量
    }
  }

  void withdraw(double amount) {
    if (amount > 0 && amount <= balance) {
      balance -= amount; // 修改成员变量
    }
  }
};

int main() {
  // const int LENGTH = 10;
  // const int WIDTH = 5;
  // const char NEWLINE = '\n';
  // int area;

  // area = LENGTH * WIDTH;
  // cout << area << NEWLINE;

  const BankAccount *bankAccount = new BankAccount(2);
  cout << "Current balance: $" << bankAccount->getBalance();
  // bankAccount->withdraw(1); // 编译错误：不能在const对象上调用非const成员函数
  return 0;
}