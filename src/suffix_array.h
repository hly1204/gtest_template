#ifndef SUFFIX_ARRAY_H
#define SUFFIX_ARRAY_H

#include <string>
#include <vector>

namespace test {

/// \brief 获取后缀数组.
/// \param s 为字符串.
std::vector<int> suffix_array(const std::string &s);

/// \brief 获取后缀数组.
/// \param s 为字符串数组, 其中字符都大于零.
std::vector<int> suffix_array(const std::vector<int> &s);

} // namespace test

#endif // SUFFIX_ARRAY_H