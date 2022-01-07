//
// Created by Sparks on 2021/8/20.
//
/*
 * 此变量可在其他文件内使用
 * 非 const 变量默认为extern.
 * */
int no_const_int=5;

/*
 * const 对象默认为文件局部变量
 * 如果要使const变量能够在其他文件中访问，必须在文件中显示的指定它为extern
 */

extern const int const_int_var = 100;
