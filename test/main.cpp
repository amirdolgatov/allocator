//
// Created by amir on 26.11.24.
//

#include<gtest/gtest.h>
#include"allocator.h"
#include"list_simple.h"
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
    std::map<int, int, std::less<int>, custom_allocator<std::pair<int, int>>> test_map;

    for (int i = 0; i < 10; ++i) {
        test_map.insert({i, factorial(i)});
    }

    for (auto& [key, val]: test_map) {
        std::cout << key << " "  << val << std::endl;
    }

 std::cout << "hello\n";
}

class Logger{

public:

    Logger(){
        ++id;
        id_ = id;
        std::cout << "default " << id_ << std::endl;
    }

    Logger(Logger& other){
        ++id;
        id_ = id;
        std::cout << "copy " << id_ << " from " << other.id_  << std::endl;
    }

    Logger(Logger&& other){
        ++id;
        id_ = id;
        std::cout << "move " << id_ << " from " << other.id_ << std::endl;
    }

    Logger& operator=(Logger& other){
        ++id;
        id_ = id;
        std::cout << "assign " << id_ << " from " << other.id_ << std::endl;
        return other;
    }

    inline static int id = 0;
    int id_ = 0;

};

TEST(Alloc, List){

    list_simple<Logger> list;

    Logger a;

    list.push_back(a);
    list.push_back(Logger());



}

int main(){
    testing::InitGoogleTest();
    testing::GTEST_FLAG(filter) = "*List*";
    return RUN_ALL_TESTS();
}