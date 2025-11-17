#pragma once

#include <optional>
#include <variant>

namespace ogrp {
    /**
     * Cartesian coordinates in meters.
     */

    using nlohmann::json;

    /**
     * Cartesian coordinates in meters.
     */
    struct CartesianPosition {
        /**
         * X coordinate in meters.
         */
        double x;
        /**
         * Y coordinate in meters.
         */
        double y;
        /**
         * Z coordinate in meters.
         */
        double z;
    };
}
