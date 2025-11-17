#pragma once

#include <optional>
#include <variant>

#include "ReferenceEllipsoid.hpp"

namespace ogrp {
    /**
     * A Geodetic Datum consists of a reference frame and optional definition of epoch and
     * ellipsoid.
     */

    using nlohmann::json;

    /**
     * A Geodetic Datum consists of a reference frame and optional definition of epoch and
     * ellipsoid.
     */
    struct GeodeticDatum {
        /**
         * Reference ellipsoid. If omitted, it is implied by reference frame (e.g., WGS84).
         */
        std::optional<ReferenceEllipsoid> ellipsoid;
        /**
         * Reference epoch of coordinates as decimal year (e.g., 2025.0). Required if the frame is
         * time-dependent.
         */
        std::optional<double> epoch;
        /**
         * Geodetic reference frame/datum (e.g., ITRF2020, WGS84, GTRF, PZ90, CGCS2000).
         */
        std::string frame;
    };
}
