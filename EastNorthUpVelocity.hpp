#pragma once

#include <optional>
#include <variant>

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
