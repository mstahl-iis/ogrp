//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     NorthEastDownVelocity.hpp data = nlohmann::json::parse(jsonString);

#pragma once

#include <optional>
#include <variant>
#include <nlohmann/json.hpp>
#include "helper.hpp"

namespace ogrp {
    /**
     * Velocity in north, east, and down directions (NED).
     */

    using nlohmann::json;

    /**
     * Velocity in north, east, and down directions (NED).
     */
    struct NorthEastDownVelocity {
        /**
         * Meters per second
         */
        double down;
        /**
         * Meters per second
         */
        double east;
        /**
         * Meters per second
         */
        double north;
    };
}
