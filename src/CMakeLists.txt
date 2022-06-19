# 与只有头文件的不同, 我们在这里将其编译为二进制, 在单元测试中进行链接

add_library(
    suffix_array
    STATIC
)

# 后面再定义库的生成方法, 因为目标不需要包含头文件, 所以不用设置 `target_include_directories` 了
target_sources(
    suffix_array
    PRIVATE suffix_array.cpp
    PUBLIC suffix_array.h
)
