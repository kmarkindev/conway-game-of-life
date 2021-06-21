if(NOT BUILD_GOOGLE_TESTS)
    message("Google Tests will not be builded")
    return()
else()
    message("Google Tests will be builded")
endif()

add_executable(GoogleTests)

target_link_libraries(GoogleTests PRIVATE gtest gtest_main APP_TARGET_INTERFACE)
target_include_directories(GoogleTests PRIVATE "${CMAKE_SOURCE_DIR}/src")
target_sources(GoogleTests PRIVATE FieldTests.cpp)