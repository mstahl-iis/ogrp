#pragma once

#include <optional>
#include <variant>

namespace ogrp {
    /**
     * Cartesian velocity in meters per second.
     */

    using nlohmann::json;

    /**
     * Cartesian velocity in meters per second.
     */
    struct CartesianVelocity {
        /**
         * X velocity in meters per second.
         */
        double vx;
        /**
         * Y velocity in meters per second.
         */
        double vy;
        /**
         * Z velocity in meters per second.
         */
        double vz;
    };
}
