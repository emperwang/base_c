//
// Created by Sparks on 2021/8/24.
//

#include <vector>
#include <iostream>

namespace decltype_demo {
/*
 * 泛型编程中结合 auto,用于追踪函数的返回值类型
 */
    template<typename T>
    auto multype(T x, T y) -> decltype(x*y){
        return x*y;
    }

    void test_decltype_function(){
        int nums[] = {1,2,3,4};
        std::vector<int> vec(nums,nums+4);

        std::vector<int>::iterator  it;
        for (it=vec.begin(); it != vec.end(); it++){
            std::cout << "value : "<<*it ;
        }
        std::cout <<std::endl;

        using nullptr_t = decltype(nullptr);
        nullptr_t  nu;

        int *p = NULL;
        if (p == nu) {
            std::cout << "null " <<std::endl;
        }

    }

}