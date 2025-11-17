//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     EastNorthUpVelocity.hpp data = nlohmann::json::parse(jsonString);

#pragma once

#include <optional>
#include <variant>
#include <nlohmann/json.hpp>
#include "helper.hpp"

namespace ogrp {
    /**
     * Velocity in east, north, and up directions (ENU).
     */

    using nlohmann::json;

    /**
     * Velocity in east, north, and up directions (ENU).
     */
    struct EastNorthUpVelocity {
        /**
         * Meters per second
         */
        double east;
        /**
         * Meters per second
         */
        double north;
        /**
         * Meters per second
         */
        double up;
    };
}
