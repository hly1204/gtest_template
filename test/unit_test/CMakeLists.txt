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
target_include_directories(
        disjoint_set_test
        PUBLIC ../../src
)
target_link_libraries(
        disjoint_set_test
        gtest_main
)
gtest_discover_tests(disjoint_set_test)