#include "pch.h"

TEST(CRC8, DEFAULT) {
	CRC8::DEFAULT crc;
	ASSERT_EQ_CRC(crc, text, 0x97);
	ASSERT_EQ_CRC(crc, bytes_array, 0x8D);
}

TEST(CRC8, SAE_J1850) {
	CRC8::SAE_J1850 crc;
	ASSERT_EQ_CRC(crc, text, 0xB0);
	ASSERT_EQ_CRC(crc, bytes_array, 0x7C);
}

TEST(CRC8, SAE_J1850_ZERO) {
	CRC8::SAE_J1850_ZERO crc;
	ASSERT_EQ_CRC(crc, text, 0x96);
	ASSERT_EQ_CRC(crc, bytes_array, 0x0);
}

TEST(CRC8, H2F) {
	CRC8::H2F crc;
	ASSERT_EQ_CRC(crc, text, 0x38);
	ASSERT_EQ_CRC(crc, bytes_array, 0x4E);
}

TEST(CRC8, CDMA2000) {
	CRC8::CDMA2000 crc;
	ASSERT_EQ_CRC(crc, text, 0x45);
	ASSERT_EQ_CRC(crc, bytes_array, 0xE2);
}

TEST(CRC8, DARC) {
	CRC8::DARC crc;
	ASSERT_EQ_CRC(crc, text, 0x76);
	ASSERT_EQ_CRC(crc, bytes_array, 0x92);
}

TEST(CRC8, DVB_S2) {
	CRC8::DVB_S2 crc;
	ASSERT_EQ_CRC(crc, text, 0xBF);
	ASSERT_EQ_CRC(crc, bytes_array, 0x9A);
}

TEST(CRC8, EBU) {
	CRC8::EBU crc;
	ASSERT_EQ_CRC(crc, text, 0xAA);
	ASSERT_EQ_CRC(crc, bytes_array, 0x95);
}

TEST(CRC8, ICODE) {
	CRC8::ICODE crc;
	ASSERT_EQ_CRC(crc, text, 0x94);
	ASSERT_EQ_CRC(crc, bytes_array, 0x49);
}

TEST(CRC8, ITU) {
	CRC8::ITU crc;
	ASSERT_EQ_CRC(crc, text, 0xC2);
	ASSERT_EQ_CRC(crc, bytes_array, 0xD8);
}

TEST(CRC8, MAXIM) {
	CRC8::MAXIM crc;
	ASSERT_EQ_CRC(crc, text, 0x79);
	ASSERT_EQ_CRC(crc, bytes_array, 0x60);
}

TEST(CRC8, ROHC) {
	CRC8::ROHC crc;
	ASSERT_EQ_CRC(crc, text, 0x8A);
	ASSERT_EQ_CRC(crc, bytes_array, 0x78);
}

TEST(CRC8, WCDMA) {
	CRC8::WCDMA crc;
	ASSERT_EQ_CRC(crc, text, 0xB0);
	ASSERT_EQ_CRC(crc, bytes_array, 0x0);
}