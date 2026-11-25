#include <catch2/catch_test_macros.hpp>
#include "topology/types.h"

using railsig::topology::Length;
using railsig::topology::NodeId;

TEST_CASE("NodeId supports equality and ordering", "[topology][types]") {
    const NodeId a{1};
    const NodeId b{2};

    REQUIRE(a == NodeId{1});
    REQUIRE(a < b);
}

TEST_CASE("Length enforces non-negative invariant", "[topology][types]") {
    REQUIRE(Length{250.0}.meters() == 250.0);
    REQUIRE_THROWS_AS(Length{-1.0}, std::invalid_argument);
}