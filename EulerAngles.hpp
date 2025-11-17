//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     EulerAngles.hpp data = nlohmann::json::parse(jsonString);

#pragma once

#include <optional>
#include <variant>
#include <nlohmann/json.hpp>
#include "helper.hpp"

namespace ogrp {
    /**
     * Euler angles representation (roll, pitch, yaw) in degrees relative to the earth surface.
     */

    using nlohmann::json;

    /**
     * Euler angles representation (roll, pitch, yaw) in degrees relative to the earth surface.
     */
    struct EulerAngles {
        /**
         * Pitch angle in degrees
         */
        double pitch;
        /**
         * Roll angle in degrees
         */
        double roll;
        /**
         * Yaw angle in degrees
         */
        double yaw;
    };
}
