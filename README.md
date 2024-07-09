## 1、编译运行
文档链接：https://edu.aliyun.com/course/313633/lesson/341136727
[helloworld代码](01helloworld/main.cpp)    
编译命令：
```shell
  g++ main.cpp -o main
```

## 2、vscode 运行和debug程序
#### 安装 c/c++ 插件    
![c/c++插件](image/vscode_c++_plugin.png)    
#### debug程序    
##### step 1:添加调试配置    
选择要 debug 的文件，右键后选择“添加调试配置”
![debug设置](image/debug_setting01.png)    

##### step 2:查看.vscode 文件夹下的 launch.json 和 tasks.json 文件    
![debug设置](image/debug_setting02.png)    
这两个文件是Visual Studio Code的配置文件，用于设置C++的编译和调试环境。它们通常位于项目的`.vscode`目录下。

`launch.json`文件定义了如何启动调试器。在这个文件中，定义了一个配置，名为"C/C++: g++ 生成和调试活动文件"。这个配置的类型是`cppdbg`，表示使用C++的调试器。`request`字段为`launch`，表示启动一个新的程序进行调试。`program`字段指定了要调试的程序的路径，这里使用了`${fileDirname}/${fileBasenameNoExtension}`，表示当前编辑的文件（不包括扩展名）所在的目录。`MIMode`字段为`gdb`，表示使用GNU调试器。`preLaunchTask`字段为"C/C++: g++ 生成活动文件"，表示在启动调试器之前，先执行这个任务。

`tasks.json`文件定义了一系列的任务，这些任务可以在VS Code中执行。在这个文件中，定义了一个任务，名为"C/C++: g++ 生成活动文件"。这个任务的类型是`cppbuild`，表示这是一个C++的构建任务。`command`字段为`/usr/local/bin/g++`，表示使用g++编译器。`args`字段定义了编译器的参数，这里包括了`-g`（生成调试信息）和`-o`（指定输出文件的名称）。`cwd`字段指定了工作目录，这里使用了`${fileDirname}`，表示当前编辑的文件所在的目录。

总的来说，这两个文件定义了如何编译和调试C++代码。当你在VS Code中启动调试时，首先会执行`tasks.json`中的"C/C++: g++ 生成活动文件"任务，编译当前的C++文件。然后，会启动`launch.json`中的"C/C++: g++ 生成和调试活动文件"配置，使用gdb调试器启动并调试编译后的程序。

##### step 3:debug程序
![debug设置](image/debug_setting03.png)   

##### step 4:涉及多 cpp 文件的调试
修改 tasks.json 文件，将 `args` 字段设置为 ["-g", "*.cpp", "-o", "\${fileDirname}/output"]     
修改 launch.json 文件，将 `program` 字段设置为 ${fileDirname}/output

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

[static代码](07static/main.cpp) 

## 5、lambda 表达式
```shell
[capture](parameters)->return-type{body}
```
例如：    
```c++
[](int x, int y) -> int { int z = x + y; return z + x; }
```
[lambda thread 代码](08lambda/main.cpp)     
编译时，需要加入-pthread选项，确保正确链接 pthread 库     
```shell
g++ -pthread main.cpp
```

