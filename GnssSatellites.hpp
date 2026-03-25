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

#include "BeiDouSignals.hpp"
#include "GalileoSignals.hpp"
#include "GlonassSignals.hpp"
#include "GpsSignals.hpp"
#include "NavIcIrnssSignals.hpp"
#include "QzssSignals.hpp"
#include "SbasSignals.hpp"

namespace ogrp {
    /**
     * GNSS signals used for position, velocity, and time computation.
     */

    using nlohmann::json;

    /**
     * GNSS signals used for position, velocity, and time computation.
     */
    struct GnssSatellites {
        std::optional<BeiDouSignals> beidou;
        std::optional<GalileoSignals> galileo;
        std::optional<GlonassSignals> glonass;
        std::optional<GpsSignals> gps;
        std::optional<NavIcIrnssSignals> navic;
        std::optional<QzssSignals> qzss;
        std::optional<SbasSignals> sbas;
    };
}
