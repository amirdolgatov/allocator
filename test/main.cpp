//
// Created by amir on 26.11.24.
//

#include <gtest/gtest.h>
#include "allocator.h"
#include "list_simple.h"
#include <map>
#include <numbers>
#include <numeric>

uint64_t factorial(uint64_t n){
    if(n == 0)
        return 1;
    if(n == 1)
        return 1;
    return n * factorial(n - 1);
}


/*!
 * Тестируем кастомный аалокатор с контейнером STL
 */
TEST(Alloc, STL){

    std::map<int, int, std::less<int>, custom_allocator<std::pair<int, int>>> test_map;

    for (int i = 0; i < 10; ++i) {
        test_map.insert({i, factorial(i)});
    }

    for (auto& [key, val]: test_map) {
        std::cout << key << " "  << val << std::endl;
    }
    SUCCEED();
}

/*!
 * Тестируем кастомный аллокатор с простой имитацией std::forward_list
 */
TEST(Alloc, List){

    list_simple<uint64_t> list;

    for (uint64_t i = 0; i < 10; ++i) {
        list.push_back(factorial(i));
    }

    uint64_t i = 0;
    for (auto x: list) {
        ASSERT_EQ(x, factorial(i++));
    }

}

/*!
 * Тестируем работу итератора контейнера list_simple
 */
TEST(Iter, STL){

    list_simple<int> list;
    int sum_1 = 0;
    int sum_2 = 0;

    for (int i = 0; i < 10; ++i) {
        auto tmp = factorial(i);
        list.push_back(tmp);
        sum_1 += tmp;
    }

    sum_2 = std::accumulate(list.begin(), list.end(), 0);

    EXPECT_EQ(sum_2, sum_1);
}


int main(){
    testing::InitGoogleTest();
//    testing::GTEST_FLAG(filter) = "**";
    return RUN_ALL_TESTS();
}