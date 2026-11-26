#pragma once

#include <compare>
#include <cstdint>

namespace railsig::topology {
    
    struct NodeId {
        std::uint64_t value{};
        auto operator<=>(const NodeId&) const = default;
    };

    class Length {
    public:
        explicit Length(double meters);

        [[nodiscard]] double meters() const noexcept { return meters_; }
        auto operator<=>(const Length&) const = default;

    private:
        double meters_{0.0};
    };

} // namespace railsig::topology