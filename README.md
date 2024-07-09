## 1、编译运行

文档链接：https://edu.aliyun.com/course/313633/lesson/341136727
[helloworld 代码](01helloworld/main.cpp)  
编译命令：

```shell
  g++ main.cpp -o main
```

## 2、vscode 运行和 debug 程序

### 安装 c/c++ 插件

![c/c++插件](image/vscode_c++_plugin.png)

### debug 程序

#### step 1:添加调试配置

选择要 debug 的文件，右键后选择“添加调试配置”
![debug设置](image/debug_setting01.png)

#### step 2:查看.vscode 文件夹下的 launch.json 和 tasks.json 文件

![debug设置](image/debug_setting02.png)  
这两个文件是 Visual Studio Code 的配置文件，用于设置 C++的编译和调试环境。它们通常位于项目的`.vscode`目录下。

`launch.json`文件定义了如何启动调试器。在这个文件中，定义了一个配置，名为"C/C++: g++ 生成和调试活动文件"。这个配置的类型是`cppdbg`，表示使用 C++的调试器。`request`字段为`launch`，表示启动一个新的程序进行调试。`program`字段指定了要调试的程序的路径，这里使用了`${fileDirname}/${fileBasenameNoExtension}`，表示当前编辑的文件（不包括扩展名）所在的目录。`MIMode`字段为`gdb`，表示使用 GNU 调试器。`preLaunchTask`字段为"C/C++: g++ 生成活动文件"，表示在启动调试器之前，先执行这个任务。

`tasks.json`文件定义了一系列的任务，这些任务可以在 VS Code 中执行。在这个文件中，定义了一个任务，名为"C/C++: g++ 生成活动文件"。这个任务的类型是`cppbuild`，表示这是一个 C++的构建任务。`command`字段为`/usr/local/bin/g++`，表示使用 g++编译器。`args`字段定义了编译器的参数，这里包括了`-g`（生成调试信息）和`-o`（指定输出文件的名称）。`cwd`字段指定了工作目录，这里使用了`${fileDirname}`，表示当前编辑的文件所在的目录。

总的来说，这两个文件定义了如何编译和调试 C++代码。当你在 VS Code 中启动调试时，首先会执行`tasks.json`中的"C/C++: g++ 生成活动文件"任务，编译当前的 C++文件。然后，会启动`launch.json`中的"C/C++: g++ 生成和调试活动文件"配置，使用 gdb 调试器启动并调试编译后的程序。

#### step 3:debug 程序

![debug设置](image/debug_setting03.png)

#### step 4:涉及多 cpp 文件的调试

修改 tasks.json 文件，将 `args` 字段设置为 ["-g", "*.cpp", "-o", "\${fileDirname}/output"]  
修改 launch.json 文件，将 `program` 字段设置为 ${fileDirname}/output

### 格式化插件

安装 clang-format 插件  
![clang-format插件](image/plugin_clang_format.png)
在 setting.json 文件中，设置文件保存后自动格式化
`"editor.formatOnSave": true`

## 4、static 的使用

`const` 和 `static` 是 C++ 中用于声明变量的关键字，它们有不同的作用和行为。

1. `const`：`const` 是常量修饰符，用于声明一个不可修改的变量。一旦变量被声明为 `const`，其值在声明后就不能再被修改。`const` 变量必须在声明时进行初始化，并且不能在程序的执行过程中修改其值。`const` 变量通常用于表示不可变的常量，例如数学常数或程序中的固定值。

2. `static`：`static` 是静态修饰符，用于声明静态变量。静态变量在程序的生命周期内只被初始化一次，并且在整个程序执行期间都存在。静态变量在声明它的作用域内是持久的，即使超出了其声明的作用域，它的值也会保持不变。静态变量可以在函数内部或全局范围内声明，具体的作用域和可见性取决于其声明的位置。

区别：

- `const` 变量是不可修改的，而 `static` 变量可以被修改。
- `const` 变量必须在声明时进行初始化，而 `static` 变量可以在声明时初始化，也可以在后续的代码中进行初始化。
- `const` 变量的作用域和可见性与普通变量相同，而 `static` 变量的作用域和可见性取决于其声明的位置。
- `const` 变量在每次使用时都会重新计算其值，而 `static` 变量只在第一次使用时进行初始化，后续使用时保持其值不变。

需要注意的是，`const` 和 `static` 可以同时用于变量的声明，例如 `static const int num = 10;`，这样的变量既是静态的，又是不可修改的。

[static 代码](07static/main.cpp)

## 5、lambda 表达式

```shell
[capture](parameters)->return-type{body}
```

例如：

```c++
[](int x, int y) -> int { int z = x + y; return z + x; }
```

[lambda thread 代码](08lambda/main.cpp)  
编译时，需要加入-pthread 选项，确保正确链接 pthread 库

```shell
g++ -pthread main.cpp
```

## 6、指针

[指针代码](14pointer/main.cpp)

```c++
/**
 * 指针 type *var-name;
 */
#include <iostream>
using namespace std;
int main(){
  int var = 20;   // 实际变量的声明
  int *ip;        // 指针变量的声明

  ip = &var;      // 在指针变量中存储 var 的地址
  cout << "Value of var variable: ";
  cout << var << endl;

  // 输出在指针变量中存储的地址
  cout << "Address stored in ip variable: ";
  cout << ip << endl;

  // 访问指针中地址的值
  cout << "Value of *ip variable: ";
  cout << *ip << endl;
  return 0;
}
```

## 7、引用

[引用代码](15reference/main.cpp)

```c++
/**
 * 引用变量是一个别名，也就是说它是已存在变量的另一个名字。创建时必须被初始化
 *
 * 引用和指针的三个主要不同
 * 1、不存在空引用。引用必须连接到一块合法的内存。
 * 2、一旦引用被初始化指向一个对象，就不能被指向到另一个对象。指针可以在任何时候指向到另一个对象。
 * 3、引用必须在创建时被初始化。指针可以在任何时间被初始化。
 */
#include <iostream>
using namespace std;
int main(){
  // 声明简单的变量
  int i;
  double d;

  // 声明引用变量
  int& r = i;
  double& s = d;

  i = 5;
  cout << "Value of i : " << i << endl;
  cout << "Value of i reference : " << r << endl;

  r = 6;
  cout << "Value of i : " << i << endl;
  cout << "Value of i reference : " << r << endl;

  d = 11.7;
  cout << "Value of d : " << d << endl;
  cout << "Value of d reference : " << s << endl;

  return 0;
}
```

## 8、时间

[时间代码](16time/main.cpp)

```c++
#include <iostream>
#include <ctime>
using namespace std;
int main(){
  // 基于当前系统的当前日期/时间
  time_t now = time(0);
  cout << "当前时间："<< now << endl;

  // 把 now 转换为字符串形式
  char* dt = ctime(&now);
  cout << "本地日期和时间：" << dt << endl;

  // 把 now 转换为 tm 结构：
  tm *ltm = localtime(&now);
  cout << "年："<< 1900 + ltm->tm_year << endl;
  cout << "月："<< 1 + ltm->tm_mon << endl;
  cout << "日："<<  ltm->tm_mday << endl;
  cout << "时间："<< ltm->tm_hour << ":";
  cout << ltm->tm_min << ":";
  cout << ltm->tm_sec << endl;
}
```

## 9、结构体

[结构体代码](17struct/main.cpp)

```c++
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
```

## 10、class 类

[类代码](18class/main.cpp)

```c++
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
```

## 11、继承

[继承代码](19extend/main.cpp)

- 语法：class derived-class: access-specifier base-class1, access-specifier

访问控制和继承

| 访问     | public | protected | private |
| -------- | ------ | --------- | ------- |
| 同一个类 | yes    | yes       | yes     |
| 派生类   | yes    | yes       | no      |
| 外部的类 | yes    | no        | no      |

```c++
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
```
