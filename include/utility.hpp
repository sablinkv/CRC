#pragma once
#include <limits>
#define NODISCARD [[nodiscard]]

#define DISABLE_COPY(Class)				\
	Class(Class&) = delete;				\
	Class& operator=(Class&) = delete;	\

#define DISABLE_MOVE(Class)					\
	Class(Class&& ) = delete;				\
	Class& operator=(Class&& ) = delete;	\

template<class T>
struct bit_reverse
{
	using value_type = T;
	using limits = std::numeric_limits<value_type>;

	constexpr value_type operator()(const value_type& Value) noexcept {
		value_type Result = 0;
		for (size_t i = 0; i < limits::digits; ++i)
			if (Value & (static_cast<value_type>(1) << i))
				Result |= (static_cast<value_type>(1) << (limits::digits - 1 - i));

		return Result;
	}
};