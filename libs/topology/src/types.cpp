#include "topology/types.h"

#include <stdexcept>

namespace railsig::topology {

    Length::Length(double meters) : meters_(meters) {
        if (meters_ < 0.0) {
            throw std::invalid_argument("Track length cannot be negative");
        }
    }

} // namespace railsig::topology