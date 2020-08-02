#pragma once
#include <gtest/gtest.h>
#include <../crc.hpp>

#define ASSERT_EQ_CRC(crc, input, result) {				\
	ASSERT_EQ(crc(input.begin(), input.end()), result); \
}

inline const std::string text("Some string 1234567890");
inline const std::vector<uint8_t> bytes_array({ 0x10, 0x38, 0x24, 0x13, 0x75, 0x63, 0x1, 0x0, 0x58 });