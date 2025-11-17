#pragma once

#include <optional>
#include <variant>

#include "CartesianPosition.hpp"
#include "GeodeticPosition.hpp"

namespace ogrp {
    /**
     * Position in various coordinate systems.
     */

    using nlohmann::json;

    /**
     * Position in various coordinate systems.
     */
    struct Position {
        std::optional<CartesianPosition> cartesian_ecef;
        std::optional<GeodeticPosition> geodetic_ecef;
    };
}
