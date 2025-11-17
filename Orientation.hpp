//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     Orientation.hpp data = nlohmann::json::parse(jsonString);

#pragma once

#include <optional>
#include <variant>
#include <nlohmann/json.hpp>
#include "helper.hpp"

#include "UnitQuaternion.hpp"
#include "EulerAngles.hpp"

namespace ogrp {
    /**
     * Orientation in various representations.
     */

    using nlohmann::json;

    /**
     * Orientation in various representations.
     */
    struct Orientation {
        std::optional<UnitQuaternion> global;
        std::optional<EulerAngles> local;
    };
}
