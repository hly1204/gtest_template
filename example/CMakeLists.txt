# 与只有头文件的不同, 我们在这里将其编译为二进制, 在单元测试中进行链接.

#[[
add_library(
    suffix_array
    STATIC
)

target_sources(
    suffix_array
    PRIVATE suffix_array.cpp
)
]]

add_library(
    suffix_array
    STATIC
    suffix_array.cpp
)

# 将头文件所在的路径设置为 `PUBLIC` 属性, 后面只需要链接这个库自动回复包含这个路径.
target_include_directories(
    suffix_array
    PUBLIC ${CMAKE_SOURCE_DIR}/example
)