## Bit field是什么
"位域" 或 "位段" 是一种数据结构, 可以吧数据以位的形式紧凑的存储,并允许程序员对此结构的位进行操作.
这种数据结构的一个好处是它可以使数据单元节省存储空间,当程序需要成千上万个数据单元时,这种方法就显得
尤为重要. 第二个好处是位段可以很方便的访问一个整数值的部分内容从而可以简化程序源代码. 而这种数据结构
的缺点在于,位段实现依赖于具体的机器和系统, 在不同的平台可能会有不同的结果,这导致了位段在本质上是不可
移植的.
* 位域在内存中的布局是与机器有关的
* 位域的类型必须是整型或枚举类型,带符号类型中的位域的行为将因具体实现而定
* 取地址运算符(&) 不能作用域位域, 任何指针都无法指向类的位域
## 位域的使用
```c++
struct bit_field_name{
    type member_name: width;
};
```

| Elements       | Description                                                  |
| -------------- | ------------------------------------------------------------ |
|  bie_field_name| 位域结构名                                                   |
|    type        |  位域成员的类型,必须为int,signed int或unsigned int           |
|    member_name | 位域成员名                                                  |
|  width        |   规定成员所占的位数                                        |

如:
```c++
struct _PROCE{
    unsigned int code1:2;
    unsigned int code2:2;
    unsigned int code3:8;
};
struct _PROCE prode;
```
此定义包含2个2 bits位域和1个8bits位域. 可以使用结构体的成员运算符对其进行赋值:
```c++
prode.code1 = 0;
prode.code2 = 3;
prode.code3 = 12;
```
赋值时要主要值的大小不能超过位域成员的容量,如:prode.code3为8bits的位域成员,容量为 2^8=256,即
赋值范围为[0,255].

## 位域的大小和对齐
### 位域的大小
```c++
struct box {
    unsigned int a:1;
    unsigned int : 3;
    unsigned int b:4; 
};
```
该位域结构中间有一个未命名的位于,占2bits, 仅起填充作用.并无实际意义. 填充使得该结构总共使用了8bits.
但C语言使用unsigned  int作为位域的基本单位,即使一个结构的唯一成员为1bit的位域, 该结构大小也和
一个unsigned int大小相同. 有些系统中, unsigned int为16bits, 在x86系统中为32bits.

### 位域的对齐
一个位域成员不允许跨越两个unsigned int的边界, 如果成员声明的总位数超过了一个unsigned int的大小,
那么编译器会自动移位位域成员, 使其按照unsigned int的边界对齐.
如:
```c++
struct stuff{
    unsigned int field1 :30;
    unsigned int field2 :4;
    unsigned int field3 :4;
};
```
field1+field2=34bits, 超过了32bits, 编译器将field2移位至下一个unsigned int单元存放. **stuff.field和
stuff.field2之间会留下一个2bits的空隙**. stuff.field3紧跟在stuff.field2之后. 该结构现在大小为2*32=64bits.
**这个空洞可以使用之前提到的未命名的位域成员填充, 我们也可以使用一个宽度为0的未命名的位域成员令下一
位域成员与下一个整数对齐.**
```c++
struct stuff{
    unsigned int field1:30;
    unsigned int       :2;
    unsigned int field2:4;
    unsigned int       :0;
    unsigned int field3:3;
};
```
这里stuff.field1与stuff.field2之间有一个2bits的空隙, stuff.field3则存储在下一个unsigned int中,
该结构现在大小为3*32=96bits;

## 位域的初始化和位的重映射
### 初始化
位域的初始化和普通的结构体初始化的方法系统, 如:
```c++
// 初始化方法1
struct stuff s1 = {20,8,6};

// 初始化2, 单独为位域成员赋值
struct stuff s2;
s2.field1 = 20;
s2.field2 = 8;
s2.field3 = 4;
```

### 位域的重映射
声明一个大小为32bits的位域
```c++
struct box {
    unsigned int ready : 2;
    unsigned int error: 2;
    unsigned int command : 4;
    unsigned int sector_no:24; 
};
```
#### 利用重映射将位域归零
```c++
struct box b1;
int *p = (int *)&b1; // 将结构体的地址,映射至 整型(int*) 的地址
*p = 0;  // 清除, 将各成员归零
```

#### 利用联合(union) 将32bits位域重映射至 unsigned int型

```c++
union u_box {
    struct box st_box;
    unsigned int ui_box;
};
```
x86系统中unsigned int和box都为32bits, 通过该联合使得st_box 和 ui_box共享一块内存.
具体位域中哪一位与unsigned int哪一位相对应, 取决于编译器和硬件.
利用联合将位域归零
```c++
union u_box u;
u.ui_box = 0; 
```















