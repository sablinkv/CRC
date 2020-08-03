add_executable(Test main.cpp)
target_sources(Test
    PRIVATE
        test_CRC8.cpp
        test_CRC16.cpp
        test_CRC32.cpp
        test_CRC64.cpp
        pch.h
)

target_link_libraries(Test
    PRIVATE
        crc
        gtest
)

target_include_directories(Test PRIVATE ${PROJECT_SOURCE_DIR}/include)

add_test(
    NAME Test
    COMMAND test
)
