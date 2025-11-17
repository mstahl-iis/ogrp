#pragma once

#include <optional>
#include <variant>

namespace ogrp {
    /**
     * Reference ellipsoid. If omitted, it is implied by reference frame (e.g., WGS84).
     */

    using nlohmann::json;

    /**
     * Reference ellipsoid. If omitted, it is implied by reference frame (e.g., WGS84).
     */
    struct ReferenceEllipsoid {
        /**
         * Semi-major axis a, meters.
         */
        double a;
        /**
         * Flattening f (unitless).
         */
        double f;
        /**
         * e.g., WGS84, GRS80
         */
        std::string name;
    };
}
