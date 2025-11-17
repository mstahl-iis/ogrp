#pragma once

#include <optional>
#include <variant>

#include "CovarianceMatrices.hpp"
#include "GeodeticDatum.hpp"
#include "CartesianPosition.hpp"
#include "Time.hpp"
#include "CartesianVelocity.hpp"

namespace ogrp {
    /**
     * Position and velocity refer to earth-centered, earth-fixed cartesian coordinate system
     * defined by `datum`.
     */

    using nlohmann::json;

    /**
     * Position and velocity refer to earth-centered, earth-fixed cartesian coordinate system
     * defined by `datum`.
     */
    struct PositionVelocityTimePvt {
        std::optional<std::string> algorithm;
        std::optional<CovarianceMatrices> covariance;
        GeodeticDatum datum;
        std::string fix;
        CartesianPosition position;
        Time time;
        std::optional<CartesianVelocity> velocity;
    };
}
