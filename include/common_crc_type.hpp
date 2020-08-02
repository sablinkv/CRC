#include <cstdint>
#include <limits>
#include <type_traits>

template<std::size_t Bits>
struct common_crc_type {
	using type = std::conditional_t <(Bits > std::numeric_limits<uint32_t>::digits), std::uint64_t,
		std::conditional_t<(Bits > std::numeric_limits<uint16_t>::digits), std::uint32_t,
		std::conditional_t<(Bits > std::numeric_limits<uint8_t>::digits), std::uint16_t, std::uint8_t>>>;
};

template<std::size_t Bits>
using common_crc_t = typename common_crc_type<Bits>::type;