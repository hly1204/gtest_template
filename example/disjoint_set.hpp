/// \file     disjoint_set.hpp

#ifndef DISJOINT_SET_HPP
#define DISJOINT_SET_HPP

#include <numeric>
#include <vector>

namespace test {

/// \brief 并查集抽象类.
class DisjointSet {
public:
    /// \brief 构造一个 `n` 个节点的森林.
    /// \remarks 节点编号从 `0` 到 `n - 1`.
    explicit DisjointSet(int n) : parent_(n) { std::iota(parent_.begin(), parent_.end(), 0); }

    /// \brief 析构函数.
    /// \remarks 强制实现.
    virtual ~DisjointSet() = 0;

    /// \brief 寻找节点在森林中的 leader.
    /// \returns leader.
    virtual int find(int) const = 0;

    /// \brief 连接两个节点.
    /// \returns leader.
    virtual int unite(int, int) = 0;

protected:
    mutable std::vector<int> parent_; ///< parent 数组.
};

DisjointSet::~DisjointSet() = default;

/// \brief 并查集.
class DisjointSetPathCompression : public DisjointSet {
public:
    /// \brief 构造一个 `n` 个节点的森林.
    /// \remarks 节点编号从 `0` 到 `n - 1`.
    explicit DisjointSetPathCompression(int n) : DisjointSet(n) {}
    ~DisjointSetPathCompression() override = default;

    /// \brief 寻找节点在森林中的 leader.
    /// \returns leader.
    [[nodiscard]] int find(int u) const override {
        if (parent_[u] == u) return u;
        return parent_[u] = find(parent_[u]);
    }

    /// \brief 连接两个节点.
    /// \returns leader.
    int unite(int u, int v) override {
        int uu = find(u), vv = find(v);
        if (uu == vv) return uu;
        return parent_[uu] = vv;
    }
};

} // namespace test

#endif // DISJOINT_SET_HPP
