set(CMAKE_CXX_STANDARD 14)

add_subdirectory(./lib/googletest)
set(gtest_SOURCE_DIR, ./lib/googletest/)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(TEST_SOURCE_FILES runAllTests.cpp
        ActivityTest.cpp
)
add_executable(runActivityRegisterTests ${TEST_SOURCE_FILES})
target_link_libraries(runActivityRegisterTests gtest gtest_main)