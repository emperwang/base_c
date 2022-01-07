## 1. 基本使用
decltype的语法是:
```c++
decltype (expression)
```
这里的括号是必不可少的, decltype的作用是"查询表示大的类型", 因此,上面语句的效果是, 返回expression
表达式的类型. 注意, decltype仅仅"查询" 表达式额类型, 并不会对表达式进行"求值".

### 1.1 推导出表达式类型
```c++
int i = 4;
decltype(i) a; // 推导出结果为int, a的类型为int.
```

### 1.2 与using/typedef 合用, 用于定义类型
```c++
using size_t = decltype(sizeof(0)); // sizeof(0) 返回值类型为size_t 类型
using ptrdiff_t = decltype((int*)0- (int*)0); 
using nullptr_t = decltype(nullptr);

vector<int> vec;
typdef decltype(vec.begin()) vectype;
for(vectype i = vec.begin(); i != vec.end(); i++){}
```
类似于auto, 也提高了代码的可读性.

### 1.3 重用匿名类型
在c++中,我们有时候会遇上一些匿名类型,如:
```c++
struct {
    int d;
    double f;  
} anon_s;
```
借助于decltype, 我们可以重新使用这个匿名的结构体:
```c++
decltype(anon_s) as;  // 定义了一个上面匿名的结构体
```

### 1.4 泛型编程中结构auto, 用于追踪函数的返回值类型
这也是decltype最大的用途了
```c++
template <typename T>
auto multiply(T x, T y) -> decltype(x*y){
    return x*y;
}
```
