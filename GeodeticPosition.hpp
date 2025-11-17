//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     GeodeticPosition.hpp data = nlohmann::json::parse(jsonString);

#pragma once

#include <optional>
#include <variant>
#include <nlohmann/json.hpp>
#include "helper.hpp"

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
