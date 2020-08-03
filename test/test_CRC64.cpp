#include "pch.h"

TEST(CRC64, ECMA182) {
	CRC64::ECMA182 crc;
	ASSERT_EQ_CRC(crc, text, 0x290DD3CAB490DCFB);
	ASSERT_EQ_CRC(crc, bytes_array, 0xA28E1F425FE0F667);
}

TEST(CRC64, GO_ISO) {
	CRC64::GO_ISO crc;
	ASSERT_EQ_CRC(crc, text, 0xF90AC7C8A161E502);
	ASSERT_EQ_CRC(crc, bytes_array, 0x497CFE1769961F1F);
}

TEST(CRC64, WE) {
	CRC64::WE crc;
	ASSERT_EQ_CRC(crc, text, 0xD88996D4C8427E89);
	ASSERT_EQ_CRC(crc, bytes_array, 0xAC2299FEA50D752A);
}

TEST(CRC64, XZ) {
	CRC64::XZ crc;
	ASSERT_EQ_CRC(crc, text, 0xB224C3C1A88A8F64);
	ASSERT_EQ_CRC(crc, bytes_array, 0x8AEF66FC32518D1E);

	auto ptr = crc.table();
}