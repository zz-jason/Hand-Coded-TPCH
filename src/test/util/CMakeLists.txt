include_directories("${PROJECT_BINARY_DIR}/thirdpart-libs/gtest/googletest/include")
include_directories("${PROJECT_SOURCE_DIR}")

add_executable(csv-reader-test csv-reader-test.cc)
target_link_libraries(csv-reader-test
    gtest_main
    utils
)
add_test(csv-reader-test csv-reader-test)

add_executable(memory-manager-test memory-manager-test.cc)
target_link_libraries(memory-manager-test
    gtest_main
    utils
)
add_test(memory-manager-test memory-manager-test)
