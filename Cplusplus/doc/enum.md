C++ 标准中引起了枚举类(enum class)
可以较好的解决上述的问题.
* 新的enum的作用域不在是全局的
* 不能隐式转换为其他类型
* 可以指定使用特定的类型类存储enum
```c++
// 等价于: enum class Color2:int
enum class Color2{
    RED = 2,
    YELLOW,
    BLUE
};

Color2 c2 = Color2::RED;
std::cout << static_cast<int>(c2) <<std::endl; // 必须转

// 指定特定类型来存储
enum class Color3:char ; // 前向声明

enum class Color3:char{
    RED='r',
    BLUE
};
char c3 = static_cast<char>(Color3::RED);
```
