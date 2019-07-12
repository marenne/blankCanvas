
add_executable(testProjectExe ${PROJECT_SOURCE_DIR}/app/main.cpp)
target_link_libraries(testProjectExe PUBLIC utils)
install(TARGETS testProjectExe DESTINATION bin)
