#pragma once

#include <optional>
#include <variant>

#include "UnitQuaternion.hpp"
#include "EulerAngles.hpp"

namespace ogrp {
    /**
     * Orientation in various representations.
     */

    using nlohmann::json;

    /**
     * Orientation in various representations.
     */
    struct Orientation {
        std::optional<UnitQuaternion> global;
        std::optional<EulerAngles> local;
    };
}
