#include "disjoint_set.hpp"
#include <gtest/gtest.h>

// 一般将类/函数名作为第一个参数, 后跟随测试的类型
TEST(DisjointSetPathCompression, SmallTest) {
    test::DisjointSet *d = new test::DisjointSetPathCompression(2);
    EXPECT_NE(d->find(0), d->find(1));
    d->unite(0, 1);
    EXPECT_EQ(d->find(0), d->find(1));
    delete d;
}

TEST(DisjointSetPathCompression, BigTest) {
    test::DisjointSet *d = new test::DisjointSetPathCompression(200);
    for (int i = 0; i != 100; ++i) {
        EXPECT_NE(d->find(i), d->find(i + 100));
        d->unite(i, i + 100);
    }
    for (int i = 0; i != 100; ++i) EXPECT_EQ(d->find(i), d->find(i + 100));
    delete d;
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}