#pragma once

#include <optional>
#include <variant>

#include "CovarianceMatrix.hpp"
#include "VelocityCovarianceMatrix.hpp"

namespace ogrp {
    /**
     * Covariance matrices for position + time and velocity + time drift.
     */

    using nlohmann::json;

    /**
     * Covariance matrices for position + time and velocity + time drift.
     */
    struct CovarianceMatrices {
        CovarianceMatrix position;
        std::optional<VelocityCovarianceMatrix> velocity;
    };
}
