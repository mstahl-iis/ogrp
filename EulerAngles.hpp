#pragma once

#include <optional>
#include <variant>

namespace ogrp {
    /**
     * Euler angles representation (roll, pitch, yaw) in degrees relative to the earth surface.
     */

    using nlohmann::json;

    /**
     * Euler angles representation (roll, pitch, yaw) in degrees relative to the earth surface.
     */
    struct EulerAngles {
        /**
         * Pitch angle in degrees
         */
        double pitch;
        /**
         * Roll angle in degrees
         */
        double roll;
        /**
         * Yaw angle in degrees
         */
        double yaw;
    };
}
