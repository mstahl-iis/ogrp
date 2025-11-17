//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     UnitQuaternion.hpp data = nlohmann::json::parse(jsonString);

#pragma once

#include <optional>
#include <variant>
#include <nlohmann/json.hpp>
#include "helper.hpp"

namespace ogrp {
    /**
     * Normalized quaternion representation for orientation.
     */

    using nlohmann::json;

    /**
     * Normalized quaternion representation for orientation.
     */
    struct UnitQuaternion {
        /**
         * Scalar part
         */
        double w;
        /**
         * Vector part X
         */
        double x;
        /**
         * Vector part Y
         */
        double y;
        /**
         * Vector part Z
         */
        double z;
    };
}
