#include "pch.h"

TEST(CRC32, DEFAULT) {
	CRC32::DEFAULT crc;
	ASSERT_EQ_CRC(crc, text, 0x173DA037);
	ASSERT_EQ_CRC(crc, bytes_array, 0xDE82F70E);
}

TEST(CRC32, BZIP2) {
	CRC32::BZIP2 crc;
	ASSERT_EQ_CRC(crc, text, 0xB145D482);
	ASSERT_EQ_CRC(crc, bytes_array, 0xCA86570C);
}

TEST(CRC32, C) {
	CRC32::C crc;
	ASSERT_EQ_CRC(crc, text, 0xDE40F63C);
	ASSERT_EQ_CRC(crc, bytes_array, 0x723B9302);
}

TEST(CRC32, D) {
	CRC32::D crc;
	ASSERT_EQ_CRC(crc, text, 0x0C1CE14F);
	ASSERT_EQ_CRC(crc, bytes_array, 0x53CDFE16);
}

TEST(CRC32, MPEG2) {
	CRC32::MPEG2 crc;
	ASSERT_EQ_CRC(crc, text, 0x4EBA2B7D);
	ASSERT_EQ_CRC(crc, bytes_array, 0x3579A8F3);
}

TEST(CRC32, POSIX) {
	CRC32::POSIX crc;
	ASSERT_EQ_CRC(crc, text, 0x4937BF68);
	ASSERT_EQ_CRC(crc, bytes_array, 0x40513894);
}

TEST(CRC32, Q) {
	CRC32::Q crc;
	ASSERT_EQ_CRC(crc, text, 0xE00B0A7C);
	ASSERT_EQ_CRC(crc, bytes_array, 0x4643E222);
}

TEST(CRC32, JAMCRC) {
	CRC32::JAMCRC crc;
	ASSERT_EQ_CRC(crc, text, 0xE8C25FC8);
	ASSERT_EQ_CRC(crc, bytes_array, 0x217D08F1);
}

TEST(CRC32, XFER) {
	CRC32::XFER crc;
	ASSERT_EQ_CRC(crc, text, 0x9BC158BC);
	ASSERT_EQ_CRC(crc, bytes_array, 0x145D1EF0);
}