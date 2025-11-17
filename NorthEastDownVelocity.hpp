#pragma once

#include <optional>
#include <variant>

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
