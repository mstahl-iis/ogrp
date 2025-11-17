//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     DilutionOfPrecision.hpp data = nlohmann::json::parse(jsonString);

#pragma once

#include <optional>
#include <variant>
#include <nlohmann/json.hpp>
#include "helper.hpp"

namespace ogrp {
    /**
     * Unitless DOP metrics derived from satellite geometry; lower is better. Rough accuracy
     * guide assumes open-sky code positioning with UERE ≈ 3–5 m, where position_sigma ≈ DOP ×
     * UERE. Carrier-phase (RTK/PPP) have much smaller UERE and therefore much better accuracy.
     */

    using nlohmann::json;

    /**
     * Unitless DOP metrics derived from satellite geometry; lower is better. Rough accuracy
     * guide assumes open-sky code positioning with UERE ≈ 3–5 m, where position_sigma ≈ DOP ×
     * UERE. Carrier-phase (RTK/PPP) have much smaller UERE and therefore much better accuracy.
     */
    struct DilutionOfPrecision {
        /**
         * Geometric DOP
         */
        double gdop;
        /**
         * Horizontal DOP
         */
        double hdop;
        /**
         * Position DOP
         */
        double pdop;
        /**
         * Time DOP
         */
        double tdop;
        /**
         * Vertical DOP
         */
        double vdop;
    };
}
