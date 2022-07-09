#include "suffix_array.h"
#include <gtest/gtest.h>
#include <string>
#include <vector>

TEST(suffix_array, BasicTest) {
    std::string s("mississippi"); // 美国密西西比州
    EXPECT_EQ(test::suffix_array(s), std::vector<int>({10, 7, 4, 1, 0, 9, 8, 6, 3, 5, 2}));
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}