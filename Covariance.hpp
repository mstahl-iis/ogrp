#pragma once

#include <optional>
#include <variant>

#include "CovarianceMatrix.hpp"
#include "VelocityCovarianceMatrix.hpp"
#include "CovarianceMatrixNed.hpp"

namespace ogrp {
    /**
     * Covariance matrices for position, velocity, and time.
     */

    using nlohmann::json;

    /**
     * Covariance matrices for position, velocity, and time.
     */
    struct Covariance {
        std::optional<CovarianceMatrix> global_position;
        std::optional<VelocityCovarianceMatrix> global_velocity;
        std::optional<CovarianceMatrixNed> local_position;
    };
}
