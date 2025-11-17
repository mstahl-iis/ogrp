#pragma once

#include <optional>
#include <variant>

#include "Covariance.hpp"
#include "GeodeticDatum.hpp"
#include "DilutionOfPrecision.hpp"
#include "Orientation.hpp"
#include "Position.hpp"
#include "GnssSignals.hpp"
#include "TimeValue.hpp"
#include "GnssTime.hpp"
#include "Velocity.hpp"

namespace ogrp {
    /**
     * Reliable position, navigation, and timing including sensors, algorithms,
     * integrity/continuity/availability, and policies.
     */

    using nlohmann::json;

    /**
     * Reliable position, navigation, and timing including sensors, algorithms,
     * integrity/continuity/availability, and policies.
     */
    struct PositionNavigationTimingPnt {
        std::optional<std::string> algorithm;
        std::optional<Covariance> covariance;
        GeodeticDatum datum;
        std::optional<DilutionOfPrecision> dop;
        std::string fix;
        std::optional<Orientation> orientation;
        Position position;
        std::optional<GnssSignals> signals;
        std::map<std::string, TimeValue> time;
        Velocity velocity;
    };
}
