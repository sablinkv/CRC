#pragma once
#include "common_crc_type.hpp"
#include "utility.hpp"
#include <array>
#include <cassert>

enum class ByteOrder : uint8_t {
	MSB = 0,
	LSB
};

template<size_t Bits, uint64_t Polynom, uint64_t XorIn = 0, uint64_t XorOut = 0,
	ByteOrder RefIn = ByteOrder::MSB, ByteOrder RefOut = ByteOrder::MSB
>class CRC {
public:
	using value_type = common_crc_t<Bits>;
	using table_type = std::array<value_type, 256>;
	using const_pointer = const value_type*;
	using size_type = std::size_t;
	using limits = std::numeric_limits<value_type>;

	constexpr static value_type polynom = (RefIn == ByteOrder::LSB) ? bit_reverse<value_type>()(Polynom) : Polynom;
	constexpr static value_type xor_in = (RefIn == ByteOrder::LSB) ? bit_reverse<value_type>()(XorIn) : XorIn;
	constexpr static value_type xor_out = XorOut;
	constexpr static ByteOrder reflect_in = RefIn;
	constexpr static ByteOrder reflect_out = RefOut;

private:
	void Init_table() noexcept {
		std::generate(_table.begin(), _table.end(),
			[&, TopBit = Bitwise(1, limits::digits - 1, 0), Index = 0]() mutable {
			value_type Result = Bitwise(Index++, limits::digits - CHAR_BIT, 0);
			for (int i = 0; i < CHAR_BIT; ++i) {
				const auto Temp = Bitwise(Result, 1, 1);
				Result = (Result & TopBit) ? (Temp ^ polynom) : Temp;
			}
			return Result;
		});
	}

	inline value_type Bitwise(const value_type& Value, size_type LeftOffset, size_type RightOffset) const noexcept {
		if constexpr (RefIn == ByteOrder::LSB)
			return Value >> RightOffset;
		else
			return Value << LeftOffset;
	}

	inline uint8_t Get_index(value_type Value, uint8_t Byte) const noexcept {
		if constexpr (RefIn == ByteOrder::MSB)
			Value = Value >> (limits::digits - CHAR_BIT);
		return (Value ^ Byte) & std::numeric_limits<uint8_t>::max();
	}

	value_type Hash(value_type Value, uint8_t Byte) const noexcept {
		uint8_t Index = Get_index(Value, Byte);
		if constexpr (RefOut == ByteOrder::LSB)
			Value >>= CHAR_BIT;
		else
			Value <<= CHAR_BIT;

		return Value ^ _table[Index];
	}

	template<class Iterator>
	value_type Check_sum(Iterator First, Iterator Last) const {
		value_type Result = xor_in;
		for (; First != Last; ++First)
			Result = Hash(Result, *First);
		return (Result ^ xor_out);
	}

public:
	constexpr CRC() {
		Init_table();
	}

	DISABLE_COPY(CRC);
	DISABLE_MOVE(CRC);
	
	template<class Iterator, class = std::enable_if_t<std::_Is_input_iter_v<Iterator>>>
	NODISCARD value_type operator()(Iterator First, Iterator Last) const noexcept {
		return Check_sum(First, Last);
	}

	NODISCARD value_type operator()(const uint8_t* Buffer, size_t Length) const noexcept {
		return Check_sum(Buffer, Buffer + Length);
	}

	NODISCARD const_pointer table() const noexcept {
		return _table.data();
	}
private:
	table_type _table;
};

namespace CRC8 {
	using DEFAULT = CRC<8, 0x07, 0x00, 0x00, ByteOrder::MSB, ByteOrder::MSB>;
	using SAE_J1850 = CRC<8, 0x1D, 0xFF, 0xFF, ByteOrder::MSB, ByteOrder::MSB>;
	using SAE_J1850_ZERO = CRC<8, 0x1D, 0x0, 0x0, ByteOrder::MSB, ByteOrder::MSB>;
	using H2F = CRC<8, 0x2F, 0xFF, 0xFF, ByteOrder::MSB, ByteOrder::MSB>;
	using CDMA2000 = CRC<8, 0x9B, 0xFF, 0x0, ByteOrder::MSB, ByteOrder::MSB>;
	using DARC = CRC<8, 0x39, 0x0, 0x0, ByteOrder::LSB, ByteOrder::LSB>;
	using DVB_S2 = CRC<8, 0xD5, 0x0, 0x0, ByteOrder::MSB, ByteOrder::MSB>;
	using EBU = CRC<8, 0x1D, 0xFF, 0x0, ByteOrder::LSB, ByteOrder::LSB>;
	using ICODE = CRC<8, 0x1D, 0xFD, 0x0, ByteOrder::MSB, ByteOrder::MSB>;
	using ITU = CRC<8, 0x7, 0x0, 0x55, ByteOrder::MSB, ByteOrder::MSB>;
	using MAXIM = CRC<8, 0x31, 0x0, 0x0, ByteOrder::LSB, ByteOrder::LSB>;
	using ROHC = CRC<8, 0x7, 0xFF, 0x0, ByteOrder::LSB, ByteOrder::LSB>;
	using WCDMA = CRC<8, 0x9B, 0x0, 0x0, ByteOrder::LSB, ByteOrder::LSB>;
}

namespace CRC16 {
	using CCIT_ZERO = CRC<16, 0x1021u, 0x0u, 0x0u, ByteOrder::MSB, ByteOrder::MSB>;
	using ARC = CRC<16, 0x8005u, 0x0u, 0x0u, ByteOrder::LSB, ByteOrder::LSB>;
	using AUG_CCIT = CRC<16, 0x1021u, 0x1D0Fu, 0x0u, ByteOrder::MSB, ByteOrder::MSB>;
	using BUYPASS = CRC<16, 0x8005u, 0x0u, 0x0u, ByteOrder::MSB, ByteOrder::MSB>;
	using CCITT_FFFF = CRC<16, 0x1021u, 0xFFFFu, 0x0u, ByteOrder::MSB, ByteOrder::MSB>;
	using CDMA2000 = CRC<16, 0xC867u, 0xFFFFu, 0x0u, ByteOrder::MSB, ByteOrder::MSB>;
	using DSS110 = CRC<16, 0x8005u, 0x800Du, 0x0u, ByteOrder::MSB, ByteOrder::MSB>;
	using DECTR = CRC<16, 0x589u, 0x0u, 0x1u, ByteOrder::MSB, ByteOrder::MSB>;
	using DECTX = CRC<16, 0x589u, 0x0u, 0x0u, ByteOrder::MSB, ByteOrder::MSB>;
	using DNP = CRC<16, 0x3D65u, 0x0u, 0xFFFFu, ByteOrder::LSB, ByteOrder::LSB>;
	using EN13757 = CRC<16, 0x3D65, 0x0u, 0xFFFFu, ByteOrder::MSB, ByteOrder::MSB>;
	using GENIBUS = CRC<16, 0x1021u, 0xFFFFu, 0xFFFFu, ByteOrder::MSB, ByteOrder::MSB>;
	using MAXIM = CRC<16, 0x8005u, 0x0u, 0xFFFFu, ByteOrder::LSB, ByteOrder::LSB>;
	using MCRF4XX = CRC<16, 0x1021u, 0xFFFFu, 0x0u, ByteOrder::LSB, ByteOrder::LSB>;
	using RIELLO = CRC<16, 0x1021u, 0xB2AAu, 0x0000u, ByteOrder::LSB, ByteOrder::LSB>;
	using TMS37157 = CRC<16, 0x1021u, 0x89ECu, 0x0u, ByteOrder::LSB, ByteOrder::LSB>;
	using A = CRC<16, 0x1021u, 0xC6C6u, 0x0u, ByteOrder::LSB, ByteOrder::LSB>;
	using T10DIF = CRC<16, 0x8BB7u, 0x0u, 0x0u, ByteOrder::MSB, ByteOrder::MSB>;
	using TELEDISK = CRC<16, 0xA097u, 0x0u, 0x0u, ByteOrder::MSB, ByteOrder::MSB>;
	using USB = CRC<16, 0x8005u, 0xFFFFu, 0xFFFFu, ByteOrder::LSB, ByteOrder::LSB>;
	using KERMIT = CRC<16, 0x1021u, 0x0u, 0x0u, ByteOrder::LSB, ByteOrder::LSB>;
	using MODBUS = CRC<16, 0x8005u, 0xFFFFu, 0x0000u, ByteOrder::LSB, ByteOrder::LSB>;
	using X25 = CRC<16, 0x1021u, 0xFFFFu, 0xFFFFu, ByteOrder::LSB, ByteOrder::LSB>;
	using XMODEM = CRC<16, 0x1021u, 0x0000u, 0x0000u, ByteOrder::MSB, ByteOrder::MSB>;
}

namespace CRC32 {
	using DEFAULT = CRC<32, 0x4C11DB7u, 0xFFFFFFFFu, 0xFFFFFFFFu, ByteOrder::LSB, ByteOrder::LSB>;
	using BZIP2 = CRC<32, 0x04C11DB7u, 0xFFFFFFFFu, 0xFFFFFFFFu, ByteOrder::MSB, ByteOrder::MSB>;
	using C = CRC<32, 0x1EDC6F41u, 0xFFFFFFFFu, 0xFFFFFFFFu, ByteOrder::LSB, ByteOrder::LSB>;
	using D = CRC<32, 0xA833982Bu, 0xFFFFFFFFu, 0xFFFFFFFFu, ByteOrder::LSB, ByteOrder::LSB>;
	using MPEG2 = CRC<32, 0x04C11DB7u, 0xFFFFFFFFu, 0x0u, ByteOrder::MSB, ByteOrder::MSB>;
	using POSIX = CRC<32, 0x04C11DB7u, 0x0u, 0xFFFFFFFFu, ByteOrder::MSB, ByteOrder::MSB>;
	using Q = CRC<32, 0x814141ABu, 0x0u, 0x0u, ByteOrder::MSB, ByteOrder::MSB>;
	using JAMCRC = CRC<32, 0x04C11DB7u, 0xFFFFFFFFu, 0x0u, ByteOrder::LSB, ByteOrder::LSB>;
	using XFER = CRC<32, 0x000000AFu, 0x0u, 0x0u, ByteOrder::MSB, ByteOrder::MSB>;
}

namespace CRC64
{
	using ECMA182 = CRC<64, 0x42F0E1EBA9EA3693, 0x0000000000000000, 0x0000000000000000, ByteOrder::MSB, ByteOrder::MSB>;
	using GO_ISO = CRC<64, 0x000000000000001B, 0xFFFFFFFFFFFFFFFF, 0xFFFFFFFFFFFFFFFF, ByteOrder::LSB, ByteOrder::LSB>;
	using WE = CRC<64, 0x42F0E1EBA9EA3693, 0xFFFFFFFFFFFFFFFF, 0xFFFFFFFFFFFFFFFF, ByteOrder::MSB, ByteOrder::MSB>;
	using XZ = CRC<64, 0x42F0E1EBA9EA3693, 0xFFFFFFFFFFFFFFFF, 0xFFFFFFFFFFFFFFFF, ByteOrder::LSB, ByteOrder::LSB>;
}