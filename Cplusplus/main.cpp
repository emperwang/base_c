#include <iostream>
#include "hello.h"
#include "const_num.h"
#include "Apple.h"
#include "static_var.h"
#include "Human.h"
#include "Inline_A.h"
#include "jksizeof.h"
#include "func_pointer.h"
#include "abstruct.h"
#include "vptr.h"
#include "virtual.h"
#include "volatile.h"
#include "Assert_demo.h"
#include "bitfield.h"
#include "struct_demo.h"
#include "union.h"
#include "explicit.h"
#include "friend.h"
#include "defineheader.h"
#include "enum_header.h"
#include "operator.h"
#include "template.h"
#include "exception.h"
#include "container.h"
#include "encapsulation.h"
#include "FileHeader.h"

void const_test_func();
void apple_class_test();
void test_sizeof_func();
void test_func_pointer_main();

int main(){
    //sayHi();

    //test_static_variable_function();
    //test_static_variable_class();
    //test_static_class_scope();
    //test_static_func_in_class();
    //test_this_pointer();
    // test_inline_virtual_func();
    //test_func_pointer();

    //abstruct_test_impl1();
    //abstruct_test_virtual_deconstructor();

    //vircon::test_virtual_contructor();
    //copycon::test_copy_constructot();
    //virdecon::test_virtual_deconstruct();
    //virdecon::test_no_virtual_deconstruct();
    //virutalfunc::test_private_virtual_func();
    //virutalfunc::test_public_parent_virtual_func();
    //inlinevirtual::test_inline_virtual();
    //rtti::test_dynamic_case();

    //volatile_name::test_modify_volatile_val();
    //volatile_name::test_modify_no_volatile_val();

    //test_assert::test_assert();
    //test_assert::test_ignore_assert();

    //bit_field::test_bit_field();

    //struct_demo::test_struct_extend();

    //test_union_function();

    //explicit_demo::test_explicit_function();


    //friend_func::test_friend_func();
    //friend_class::test_friend_class();

    //test_define_function();

    //test_enum_class_function();

    //bracketoverrid::test_salary_manager_function();

    //clockoper::test_clock_function();
    //clockoper::test_convert_function();
    //clockoper::test_parentheses_function();

    //template_ns::test_template_function();
    //template_ns::test_var_array();
    //template_ns::test_template_class_function();
    //template_ns::test_partial_spec_function();

    //encapsulation::test_extend_function();

    //file_handle::test_file_write_function();

    //test_catch_exception_function();
    //test_vptr_table();
    //std::cout << "hello cplusplus "<<std::endl;
    std::cout << "cplusplus version: " << __cplusplus << std::endl;
    return 0;
}

void test_func_pointer_main(){
    test_func_pointer();
}

void test_sizeof_func(){
    get_black_class_size();
    get_static_mem_size_class();
    get_virtual_func_size_class();
    get_base_a_size();
    get_base_b_size();
    get_base_c_wrapper_a();
    get_virtual_impl_C();
    get_virtual_extend_size();
}
void const_test_func(){
    const_num_test();
    const_function_param(5);
    use_other_no_const_var();
    use_other_const_var();
    point_const();
}

void apple_class_test(){
    // create class
    Apple a(100);
    std::cout << "Apple getCount " <<  a.getCount() << std::endl;
    // 表示调用的是 没有const修饰的add, 因为a对象不是一个常量对象
    a.add(10);

    const Apple aa(200);
    aa.add(20);

}

