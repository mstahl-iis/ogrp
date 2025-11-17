//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     Velocity.hpp data = nlohmann::json::parse(jsonString);

#pragma once

#include <optional>
#include <variant>
#include <nlohmann/json.hpp>
#include "helper.hpp"

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
