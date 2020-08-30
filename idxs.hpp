#include "stdafx.h"

namespace idxs
{
	template<class T = size_t>
	struct dvbs2
	{
		using value_type = typename T;
		static constexpr T period{ 188 };
		static constexpr T len{ 2 };
		static constexpr T rows{ 9 };
		static constexpr T cols{ period };
		static constexpr auto get()noexcept
		{
			std::array<std::array<std::array<T, len>, rows>, cols> out{};
			for (T cols{}; auto && d2 : out)
			{
				for (T init{ cols }; auto && d1 : d2)
				{
					for (T idx{ init }; T & elm : d1)
					{
						elm = idx++;
					}
					init += period;
				}
				++cols;
			}
			return out;
		}
	};
}