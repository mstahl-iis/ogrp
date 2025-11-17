//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     GnssSignals.hpp data = nlohmann::json::parse(jsonString);

#pragma once

#include <optional>
#include <variant>
#include <nlohmann/json.hpp>
#include "helper.hpp"

namespace ogrp {
    /**
     * GNSS signals used for position, velocity, and time computation.
     */

    using nlohmann::json;

    /**
     * GNSS signals used for position, velocity, and time computation.
     */
    struct GnssSignals {
        /**
         * Number of signals used per frequency band. E.g. { "b1c": 3, "b2a": 2, "b3": 5 }.
         */
        std::optional<std::map<std::string, int64_t>> beidou;
        /**
         * Number of signals used per frequency band. E.g. { "e1b": 3, "e5a": 2, "e6a": 5 }.
         */
        std::optional<std::map<std::string, int64_t>> galileo;
        /**
         * Number of signals used per frequency band. E.g. { "l1": 3, "l2": 2 }.
         */
        std::optional<std::map<std::string, int64_t>> glonass;
        /**
         * Number of signals used per frequency band. E.g. { "l1ca": 3, "l2c": 2 }.
         */
        std::optional<std::map<std::string, int64_t>> gps;
        /**
         * Number of signals used per frequency band. E.g. { "l5": 3, "s": 2 }.
         */
        std::optional<std::map<std::string, int64_t>> navic;
        /**
         * Number of signals used per frequency band. E.g. { "l1ca": 3, "l2cm": 2, "l5i": 5,
         * "l6lex": 1 }.
         */
        std::optional<std::map<std::string, int64_t>> qzss;
        /**
         * Number of signals used per frequency band. E.g. { "l1egnos": 3, "l5waas": 2 }.
         */
        std::optional<std::map<std::string, int64_t>> sbas;
    };
}
