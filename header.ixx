
module;

// This named module expects to be built with classic headers, not header units.
#define _BUILD_STD_MODULE


export module header;

#include <algorithm>
#include <numeric>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <map>
#include <queue>
#include <stack>
#include <format>
#include <utility>

export template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec)
{
    os << "[";
    for (auto&& v : vec) {
        os << v << " ";
    }
    os << "]";
    return os;
}

export template <typename T1, typename T2>
void EXPECT_EQ(const T1& var1, const T2& var2)
{
    if (var1 == var2) {
        std::cout << "ok" << std::endl;
    } else {
        std::cout << "Not equal, (var1, var2):\n" << var1 << "\n" << var2 << std::endl;
    }
}


export void EXPECT_TRUE(bool var)
{
    EXPECT_EQ(var, true);
}

export void EXPECT_FALSE(bool var)
{
    EXPECT_TRUE(!var);
}