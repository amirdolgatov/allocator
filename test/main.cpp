//
// Created by amir on 26.11.24.
//

#include<gtest/gtest.h>
#include"allocator.h"
#include<map>

uint64_t factorial(uint64_t n){
    if(n == 0)
        return 1;
    if(n == 1)
        return 1;
    return n * factorial(n - 1);
}

TEST(Alloc, STL){
    std::cout << "hello\n";

    custom_allocator<std::pair<int, int>> alloc;

    auto ptr = alloc.allocate(3);

    alloc.deallocate(ptr, 3);

    alloc.deallocate(ptr, 6);



//    std::cout << "hello\n";
//
//    std::map<int, int, std::less<int>, custom_allocator<std::pair<int, int>>> test_map;

//    for (int i = 0; i < 10; ++i) {
//        test_map.insert({i, factorial(i)});
//    }
//
//    for (auto& [key, val]: test_map) {
//        std::cout << key << " "  << val << std::endl;
//    }

 std::cout << "hello\n";
}

int main(){
    testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}