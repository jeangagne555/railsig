#pragma once

#include <compare>

namespace railsig::common {

    struct Length {
        double value { 0.0 };

        explicit constexpr Length(const double value) noexcept : value(value) {}

        constexpr Length() noexcept = default;

        friend constexpr auto operator<=>(const Length&, const Length&) noexcept = default;
        friend constexpr bool operator==(const Length&, const Length&) noexcept = default;

        friend constexpr Length operator+(const Length lhs, const Length rhs) noexcept {
            return Length(lhs.value + rhs.value);
        }
    };
}
