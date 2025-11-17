#pragma once

namespace ogrp {
    /**
     * The OGRP message is the base schema for all OGRP messages.
     */

    using nlohmann::json;

    /**
     * The OGRP message is the base schema for all OGRP messages.
     */
    struct Message {
        /**
         * Either UUIDv1 or UUIDv6 according to RFC9562. The Node ID should be the MAC address of
         * the GNSS receiver.
         */
        std::string epoch;
        /**
         * The schema of this OGRP message.
         */
        std::string schema;
    };
}
