#include <iostream>
#include <string>
using namespace std;
struct Book{
  string title;
  string author;
  string subject;
  int book_id;
  void printBook(){
    cout << "Book title : " << title <<endl;
    cout << "Book author : " << author <<endl;
    cout << "Book subject : " << subject <<endl;
    cout << "Book book_id : " << book_id <<endl;
  }
};

int main(){
  Book book;
  book.title = "C++ 教程";
  book.author = "Runoob";
  book.subject = "编程语言";
  book.book_id = 12345;
  book.printBook();
  return 0;
}