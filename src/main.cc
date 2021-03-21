#include <iostream>
#include <vector>
#include "formatter.h"
#include "t01.h"
#include "t02.h"

using std::vector;

int main(int argc, char const *argv[])
{
    std::cout << "Exec 01:" << std::endl;

    vector<int> arr = { 3, 2, 4 };
    vector<int> result = t01::twoSum(arr, 9);

    std::cout << result << std::endl;

    std::cout << "Exec 02:" << std::endl;


    /* code */
    return 0;
}

/**
 * CMake 也还遗留探索的点
 * - Test
 * - 编译模式：Debug & Release
 * - 引入其他依赖
 */
