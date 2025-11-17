#pragma once

#include <optional>
#include <variant>

#include "CartesianVelocity.hpp"
#include "EastNorthUpVelocity.hpp"
#include "GroundAndVerticalVelocity.hpp"
#include "NorthEastDownVelocity.hpp"

namespace ogrp {
    /**
     * Velocity in various coordinate systems.
     */

    using nlohmann::json;

    /**
     * Velocity in various coordinate systems.
     */
    struct Velocity {
        std::optional<CartesianVelocity> cartesian_ecef;
        std::optional<EastNorthUpVelocity> enu;
        std::optional<GroundAndVerticalVelocity> ground_vertical;
        std::optional<NorthEastDownVelocity> ned;
    };
}
