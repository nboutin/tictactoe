
#pragma once

#include <iostream>
#include <vector>

inline std::ostream& operator<<(std::ostream& oss, const std::vector<int>& v)
{
    for(auto i : v)
        oss << i << ",";
    return oss;
}
