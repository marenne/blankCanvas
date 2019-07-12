
add_executable(testCases ${PROJECT_SOURCE_DIR}/test/main.cpp ${PROJECT_SOURCE_DIR}/test/cases.cpp)

target_link_libraries(testCases PUBLIC GTest::GTest utils)

install(TARGETS testCases DESTINATION bin)

gtest_discover_tests(testCases)
add_test(testNameSomehow testCases)