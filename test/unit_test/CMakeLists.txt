if (${CMAKE_VERSION} VERSION_GREATER_EQUAL "3.24.0")
        cmake_policy(SET CMP0135 NEW)
endif ()
# see https://google.github.io/googletest/quickstart-cmake.html
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# 该宏定义需要到对应路径下的调用 `ctest` 命令, 而不是在构建的目录下.
enable_testing()

include(GoogleTest)

add_executable(
        disjoint_set_test
        disjoint_set_test.cpp
)
# 需要包含头文件路径, 因为这是一个 header only 的头文件.
target_include_directories(
        disjoint_set_test
        PUBLIC ${CMAKE_SOURCE_DIR}/example
)
target_link_libraries(
        disjoint_set_test
        PRIVATE gtest_main
)
gtest_discover_tests(
        disjoint_set_test
        DISCOVERY_TIMEOUT 120 # 指定超时时间.
)

add_executable(
        suffix_array_test
        suffix_array_test.cpp
)
target_link_libraries(
        suffix_array_test
        PRIVATE gtest_main suffix_array # 不需要为 suffix_array_test.h 中的头文件设置路径, 因为这里已经自动设置了.
)
gtest_discover_tests(
        suffix_array_test
        DISCOVERY_TIMEOUT 120 # 指定超时时间.
)