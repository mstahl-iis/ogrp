//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     Covariance.hpp data = nlohmann::json::parse(jsonString);

#pragma once

#include <optional>
#include <variant>
#include <nlohmann/json.hpp>
#include "helper.hpp"

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
