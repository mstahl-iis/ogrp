//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     GnssSatellites.hpp data = nlohmann::json::parse(jsonString);

#pragma once

#include <optional>
#include <variant>
#include <nlohmann/json.hpp>
#include "helper.hpp"

#include "GnssSatelliteSignals.hpp"

namespace ogrp {
    /**
     * GNSS signals used for position, velocity, and time computation.
     */

    using nlohmann::json;

    /**
     * GNSS signals used for position, velocity, and time computation.
     */
    struct GnssSatellites {
        std::optional<GnssSatelliteSignals> beidou;
        std::optional<GnssSatelliteSignals> galileo;
        std::optional<GnssSatelliteSignals> glonass;
        std::optional<GnssSatelliteSignals> gps;
        std::optional<GnssSatelliteSignals> navic;
        std::optional<GnssSatelliteSignals> qzss;
        std::optional<GnssSatelliteSignals> sbas;
    };
}
