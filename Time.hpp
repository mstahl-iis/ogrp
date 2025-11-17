#pragma once

#include <optional>
#include <variant>

#include "GnssTime.hpp"

namespace ogrp {
    /**
     * GNSS system time representations.
     */

    using nlohmann::json;

    /**
     * GNSS system time representations.
     */
    struct Time {
        /**
         * BeiDou Time (strictly monotonic)
         */
        std::optional<GnssTime> bdt;
        /**
         * GLONASS Time (UTC-like)
         */
        std::optional<std::string> glonasst;
        /**
         * GPS Time (strictly monotonic)
         */
        std::optional<GnssTime> gpst;
        /**
         * Galileo System Time (strictly monotonic)
         */
        std::optional<GnssTime> gst;
        /**
         * International Atomic Time (strictly monotonic)
         */
        std::optional<std::string> tai;
    };
}
