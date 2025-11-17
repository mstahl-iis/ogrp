#pragma once

#include <optional>
#include <variant>

namespace ogrp {
    /**
     * Normalized quaternion representation for orientation.
     */

    using nlohmann::json;

    /**
     * Normalized quaternion representation for orientation.
     */
    struct UnitQuaternion {
        /**
         * Scalar part
         */
        double w;
        /**
         * Vector part X
         */
        double x;
        /**
         * Vector part Y
         */
        double y;
        /**
         * Vector part Z
         */
        double z;
    };
}
