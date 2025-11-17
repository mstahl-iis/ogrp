//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     CovarianceMatrixNed.hpp data = nlohmann::json::parse(jsonString);

#pragma once

#include <optional>
#include <variant>
#include <nlohmann/json.hpp>
#include "helper.hpp"

namespace ogrp {
    /**
     * Upper-triangular elements of a symmetric 4×4 covariance matrix for variables {t, north,
     * east, down}. Units must match the associated state components.
     */

    using nlohmann::json;

    /**
     * Upper-triangular elements of a symmetric 4×4 covariance matrix for variables {t, north,
     * east, down}. Units must match the associated state components.
     */
    struct CovarianceMatrixNed {
        /**
         * Variance (down)
         */
        double dd;
        /**
         * Covariance (down
         */
        double dt;
        /**
         * Covariance (east
         */
        double ed;
        /**
         * Variance (east)
         */
        double ee;
        /**
         * Covariance (east
         */
        double et;
        /**
         * Covariance (north
         */
        double nd;
        /**
         * Covariance (north
         */
        double ne;
        /**
         * Variance (north)
         */
        double nn;
        /**
         * Covariance (north
         */
        double nt;
        /**
         * Variance (t)
         */
        double tt;
    };
}
