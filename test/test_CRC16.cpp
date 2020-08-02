#include "pch.h"

TEST(CRC16, CCIT_ZERO) {
	CRC16::CCIT_ZERO crc;
	ASSERT_EQ_CRC(crc, text, 0x58DB);
	ASSERT_EQ_CRC(crc, bytes_array, 0x60BE);
}

TEST(CRC16, ARC) {
	CRC16::ARC crc;
	ASSERT_EQ_CRC(crc, text, 0xEF17);
	ASSERT_EQ_CRC(crc, bytes_array, 0x666A);
}

TEST(CRC16, AUG_CCIT) {
	CRC16::AUG_CCIT crc;
	ASSERT_EQ_CRC(crc, text, 0xB751);
	ASSERT_EQ_CRC(crc, bytes_array, 0xB4B1);
}

TEST(CRC16, BUYPASS) {
	CRC16::BUYPASS crc;
	ASSERT_EQ_CRC(crc, text, 0xCA43);
	ASSERT_EQ_CRC(crc, bytes_array, 0xE205);
}

TEST(CRC16, CCITT_FFFF) {
	CRC16::CCITT_FFFF crc;
	ASSERT_EQ_CRC(crc, text, 0xC76F);
	ASSERT_EQ_CRC(crc, bytes_array, 0x78CC);
}

TEST(CRC16, CDMA2000) {
	CRC16::CDMA2000 crc;
	ASSERT_EQ_CRC(crc, text, 0xC9AF);
	ASSERT_EQ_CRC(crc, bytes_array, 0x9B9);
}

TEST(CRC16, DSS110) {
	CRC16::DSS110 crc;
	ASSERT_EQ_CRC(crc, text, 0x94AC);
	ASSERT_EQ_CRC(crc, bytes_array, 0x8222);
}

TEST(CRC16, DECTR) {
	CRC16::DECTR crc;
	ASSERT_EQ_CRC(crc, text, 0x2A4F);
	ASSERT_EQ_CRC(crc, bytes_array, 0x29AA);
}

TEST(CRC16, DECTX) {
	CRC16::DECTX crc;
	ASSERT_EQ_CRC(crc, text, 0x2A4E);
	ASSERT_EQ_CRC(crc, bytes_array, 0x29AB);
}

TEST(CRC16, DNP) {
	CRC16::DNP crc;
	ASSERT_EQ_CRC(crc, text, 0x943A);
	ASSERT_EQ_CRC(crc, bytes_array, 0x27AC);
}

TEST(CRC16, EN13757) {
	CRC16::EN13757 crc;
	ASSERT_EQ_CRC(crc, text, 0x19D2);
	ASSERT_EQ_CRC(crc, bytes_array, 0x613E);
}

TEST(CRC16, GENIBUS) {
	CRC16::GENIBUS crc;
	ASSERT_EQ_CRC(crc, text, 0x3890);
	ASSERT_EQ_CRC(crc, bytes_array, 0x8733);
}

TEST(CRC16, MAXIM) {
	CRC16::MAXIM crc;
	ASSERT_EQ_CRC(crc, text, 0x10E8);
	ASSERT_EQ_CRC(crc, bytes_array, 0x9995);
}

TEST(CRC16, MCRF4XX) {
	CRC16::MCRF4XX crc;
	ASSERT_EQ_CRC(crc, text, 0x5ED2);
	ASSERT_EQ_CRC(crc, bytes_array, 0x381F);
}

TEST(CRC16, RIELLO) {
	CRC16::RIELLO crc;
	ASSERT_EQ_CRC(crc, text, 0x37B4);
	ASSERT_EQ_CRC(crc, bytes_array, 0x345E);
}

TEST(CRC16, T10DIF) {
	CRC16::T10DIF crc;
	ASSERT_EQ_CRC(crc, text, 0x715F);
	ASSERT_EQ_CRC(crc, bytes_array, 0x9619);
}

TEST(CRC16, TELEDISK) {
	CRC16::TELEDISK crc;
	ASSERT_EQ_CRC(crc, text, 0x4251);
	ASSERT_EQ_CRC(crc, bytes_array, 0xE73A);
}

TEST(CRC16, TMS37157) {
	CRC16::TMS37157 crc;
	ASSERT_EQ_CRC(crc, text, 0x33AB);
	ASSERT_EQ_CRC(crc, bytes_array, 0x713F);
}

TEST(CRC16, USB) {
	CRC16::USB crc;
	ASSERT_EQ_CRC(crc, text, 0x1BB3);
	ASSERT_EQ_CRC(crc, bytes_array, 0x699F);
}

TEST(CRC16, A) {
	CRC16::A crc;
	ASSERT_EQ_CRC(crc, text, 0x386C);
	ASSERT_EQ_CRC(crc, bytes_array, 0xE88B);
}

TEST(CRC16, KERMIT) {
	CRC16::KERMIT crc;
	ASSERT_EQ_CRC(crc, text, 0x732B);
	ASSERT_EQ_CRC(crc, bytes_array, 0x7607);
}

TEST(CRC16, MODBUS) {
	CRC16::MODBUS crc;
	ASSERT_EQ_CRC(crc, text, 0xE44C);
	ASSERT_EQ_CRC(crc, bytes_array, 0x9660);
}

TEST(CRC16, X25) {
	CRC16::X25 crc;
	ASSERT_EQ_CRC(crc, text, 0xA12D);
	ASSERT_EQ_CRC(crc, bytes_array, 0xC7E0);
}

TEST(CRC16, XMODEM) {
	CRC16::XMODEM crc;
	ASSERT_EQ_CRC(crc, text, 0x58DB);
	ASSERT_EQ_CRC(crc, bytes_array, 0x60BE);
}
