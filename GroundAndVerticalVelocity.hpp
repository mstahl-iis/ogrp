#pragma once

#include <optional>
#include <variant>

namespace ogrp {
    using nlohmann::json;

    struct GroundAndVerticalVelocity {
        /**
         * Climb rate in meters per second. Positive values indicate ascending.
         */
        std::optional<double> climb_rate;
        /**
         * Heading relative to true north in degrees.
         */
        double course_over_ground;
        /**
         * Heading relative to magnetic north in degrees.
         */
        std::optional<double> heading_magnetic;
        /**
         * Speed over ground in meters per second.
         */
        double speed_over_ground;
    };
}
