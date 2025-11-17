#pragma once

#include <optional>
#include <variant>

namespace ogrp {
    struct GnssTime;
}

namespace ogrp {
    using nlohmann::json;

    using TimeValue = std::variant<GnssTime, std::string>;
}
