//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     TimeValue.hpp data = nlohmann::json::parse(jsonString);

#pragma once

#include <optional>
#include <variant>
#include <nlohmann/json.hpp>
#include "helper.hpp"

namespace ogrp {
    struct GnssTime;
}

namespace ogrp {
    using nlohmann::json;

    using TimeValue = std::variant<GnssTime, std::string>;
}
