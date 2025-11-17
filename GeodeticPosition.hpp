#pragma once

#include <optional>
#include <variant>

namespace ogrp {
    /**
     * Geodetic position in latitude, longitude, and height.
     */

    using nlohmann::json;

    /**
     * Geodetic position in latitude, longitude, and height.
     */
    struct GeodeticPosition {
        /**
         * Altitude above mean sea level (geoid) in meters.
         */
        std::optional<double> altitude_msl;
        /**
         * Height above ellipsoid in meters.
         */
        double height;
        /**
         * Latitude relative to equator in degrees. Positive values are northward.
         */
        double latitude;
        /**
         * Longitude relative to prime meridian in degrees. Positive values are eastward.
         */
        double longitude;
    };
}
