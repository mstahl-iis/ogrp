//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     Position.hpp data = nlohmann::json::parse(jsonString);

#pragma once

#include <optional>
#include <variant>
#include <nlohmann/json.hpp>
#include "helper.hpp"

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
