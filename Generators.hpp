//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     Generators.hpp data = nlohmann::json::parse(jsonString);

#pragma once

#include <optional>
#include <variant>
#include <nlohmann/json.hpp>
#include "helper.hpp"

#include "Message.hpp"
#include "PositionVelocityTimePvt.hpp"
#include "Time.hpp"
#include "CovarianceMatrices.hpp"
#include "PositionNavigationTimingPnt.hpp"
#include "Velocity.hpp"
#include "NorthEastDownVelocity.hpp"
#include "GroundAndVerticalVelocity.hpp"
#include "EastNorthUpVelocity.hpp"
#include "CartesianVelocity.hpp"
#include "TimeValue.hpp"
#include "GnssTime.hpp"
#include "GnssSignals.hpp"
#include "Position.hpp"
#include "GeodeticPosition.hpp"
#include "CartesianPosition.hpp"
#include "Orientation.hpp"
#include "EulerAngles.hpp"
#include "UnitQuaternion.hpp"
#include "DilutionOfPrecision.hpp"
#include "GeodeticDatum.hpp"
#include "ReferenceEllipsoid.hpp"
#include "Covariance.hpp"
#include "CovarianceMatrixNed.hpp"
#include "VelocityCovarianceMatrix.hpp"
#include "CovarianceMatrix.hpp"

namespace ogrp {
void from_json(const json & j, CovarianceMatrix & x);
void to_json(json & j, const CovarianceMatrix & x);

void from_json(const json & j, VelocityCovarianceMatrix & x);
void to_json(json & j, const VelocityCovarianceMatrix & x);

void from_json(const json & j, CovarianceMatrixNed & x);
void to_json(json & j, const CovarianceMatrixNed & x);

void from_json(const json & j, Covariance & x);
void to_json(json & j, const Covariance & x);

void from_json(const json & j, ReferenceEllipsoid & x);
void to_json(json & j, const ReferenceEllipsoid & x);

void from_json(const json & j, GeodeticDatum & x);
void to_json(json & j, const GeodeticDatum & x);

void from_json(const json & j, DilutionOfPrecision & x);
void to_json(json & j, const DilutionOfPrecision & x);

void from_json(const json & j, UnitQuaternion & x);
void to_json(json & j, const UnitQuaternion & x);

void from_json(const json & j, EulerAngles & x);
void to_json(json & j, const EulerAngles & x);

void from_json(const json & j, Orientation & x);
void to_json(json & j, const Orientation & x);

void from_json(const json & j, CartesianPosition & x);
void to_json(json & j, const CartesianPosition & x);

void from_json(const json & j, GeodeticPosition & x);
void to_json(json & j, const GeodeticPosition & x);

void from_json(const json & j, Position & x);
void to_json(json & j, const Position & x);

void from_json(const json & j, GnssSignals & x);
void to_json(json & j, const GnssSignals & x);

void from_json(const json & j, GnssTime & x);
void to_json(json & j, const GnssTime & x);

void from_json(const json & j, CartesianVelocity & x);
void to_json(json & j, const CartesianVelocity & x);

void from_json(const json & j, EastNorthUpVelocity & x);
void to_json(json & j, const EastNorthUpVelocity & x);

void from_json(const json & j, GroundAndVerticalVelocity & x);
void to_json(json & j, const GroundAndVerticalVelocity & x);

void from_json(const json & j, NorthEastDownVelocity & x);
void to_json(json & j, const NorthEastDownVelocity & x);

void from_json(const json & j, Velocity & x);
void to_json(json & j, const Velocity & x);

void from_json(const json & j, PositionNavigationTimingPnt & x);
void to_json(json & j, const PositionNavigationTimingPnt & x);

void from_json(const json & j, CovarianceMatrices & x);
void to_json(json & j, const CovarianceMatrices & x);

void from_json(const json & j, Time & x);
void to_json(json & j, const Time & x);

void from_json(const json & j, PositionVelocityTimePvt & x);
void to_json(json & j, const PositionVelocityTimePvt & x);

void from_json(const json & j, Message & x);
void to_json(json & j, const Message & x);
}
namespace nlohmann {
template <>
struct adl_serializer<std::variant<ogrp::GnssTime, std::string>> {
    static void from_json(const json & j, std::variant<ogrp::GnssTime, std::string> & x);
    static void to_json(json & j, const std::variant<ogrp::GnssTime, std::string> & x);
};
}
namespace ogrp {
    inline void from_json(const json & j, CovarianceMatrix& x) {
        x.tt = j.at("tt").get<double>();
        x.xt = j.at("xt").get<double>();
        x.xx = j.at("xx").get<double>();
        x.xy = j.at("xy").get<double>();
        x.xz = j.at("xz").get<double>();
        x.yt = j.at("yt").get<double>();
        x.yy = j.at("yy").get<double>();
        x.yz = j.at("yz").get<double>();
        x.zt = j.at("zt").get<double>();
        x.zz = j.at("zz").get<double>();
    }

    inline void to_json(json & j, const CovarianceMatrix & x) {
        j = json::object();
        j["tt"] = x.tt;
        j["xt"] = x.xt;
        j["xx"] = x.xx;
        j["xy"] = x.xy;
        j["xz"] = x.xz;
        j["yt"] = x.yt;
        j["yy"] = x.yy;
        j["yz"] = x.yz;
        j["zt"] = x.zt;
        j["zz"] = x.zz;
    }

    inline void from_json(const json & j, VelocityCovarianceMatrix& x) {
        x.dtdt = j.at("dtdt").get<double>();
        x.vxdt = j.at("vxdt").get<double>();
        x.vxvx = j.at("vxvx").get<double>();
        x.vxvy = j.at("vxvy").get<double>();
        x.vxvz = j.at("vxvz").get<double>();
        x.vydt = j.at("vydt").get<double>();
        x.vyvy = j.at("vyvy").get<double>();
        x.vyvz = j.at("vyvz").get<double>();
        x.vzdt = j.at("vzdt").get<double>();
        x.vzvz = j.at("vzvz").get<double>();
    }

    inline void to_json(json & j, const VelocityCovarianceMatrix & x) {
        j = json::object();
        j["dtdt"] = x.dtdt;
        j["vxdt"] = x.vxdt;
        j["vxvx"] = x.vxvx;
        j["vxvy"] = x.vxvy;
        j["vxvz"] = x.vxvz;
        j["vydt"] = x.vydt;
        j["vyvy"] = x.vyvy;
        j["vyvz"] = x.vyvz;
        j["vzdt"] = x.vzdt;
        j["vzvz"] = x.vzvz;
    }

    inline void from_json(const json & j, CovarianceMatrixNed& x) {
        x.dd = j.at("dd").get<double>();
        x.dt = j.at("dt").get<double>();
        x.ed = j.at("ed").get<double>();
        x.ee = j.at("ee").get<double>();
        x.et = j.at("et").get<double>();
        x.nd = j.at("nd").get<double>();
        x.ne = j.at("ne").get<double>();
        x.nn = j.at("nn").get<double>();
        x.nt = j.at("nt").get<double>();
        x.tt = j.at("tt").get<double>();
    }

    inline void to_json(json & j, const CovarianceMatrixNed & x) {
        j = json::object();
        j["dd"] = x.dd;
        j["dt"] = x.dt;
        j["ed"] = x.ed;
        j["ee"] = x.ee;
        j["et"] = x.et;
        j["nd"] = x.nd;
        j["ne"] = x.ne;
        j["nn"] = x.nn;
        j["nt"] = x.nt;
        j["tt"] = x.tt;
    }

    inline void from_json(const json & j, Covariance& x) {
        x.global_position = get_stack_optional<CovarianceMatrix>(j, "global_position");
        x.global_velocity = get_stack_optional<VelocityCovarianceMatrix>(j, "global_velocity");
        x.local_position = get_stack_optional<CovarianceMatrixNed>(j, "local_position");
    }

    inline void to_json(json & j, const Covariance & x) {
        j = json::object();
        if (x.global_position) {
            j["global_position"] = x.global_position;
        }
        if (x.global_velocity) {
            j["global_velocity"] = x.global_velocity;
        }
        if (x.local_position) {
            j["local_position"] = x.local_position;
        }
    }

    inline void from_json(const json & j, ReferenceEllipsoid& x) {
        x.a = j.at("a").get<double>();
        x.f = j.at("f").get<double>();
        x.name = j.at("name").get<std::string>();
    }

    inline void to_json(json & j, const ReferenceEllipsoid & x) {
        j = json::object();
        j["a"] = x.a;
        j["f"] = x.f;
        j["name"] = x.name;
    }

    inline void from_json(const json & j, GeodeticDatum& x) {
        x.ellipsoid = get_stack_optional<ReferenceEllipsoid>(j, "ellipsoid");
        x.epoch = get_stack_optional<double>(j, "epoch");
        x.frame = j.at("frame").get<std::string>();
    }

    inline void to_json(json & j, const GeodeticDatum & x) {
        j = json::object();
        if (x.ellipsoid) {
            j["ellipsoid"] = x.ellipsoid;
        }
        if (x.epoch) {
            j["epoch"] = x.epoch;
        }
        j["frame"] = x.frame;
    }

    inline void from_json(const json & j, DilutionOfPrecision& x) {
        x.gdop = j.at("gdop").get<double>();
        x.hdop = j.at("hdop").get<double>();
        x.pdop = j.at("pdop").get<double>();
        x.tdop = j.at("tdop").get<double>();
        x.vdop = j.at("vdop").get<double>();
    }

    inline void to_json(json & j, const DilutionOfPrecision & x) {
        j = json::object();
        j["gdop"] = x.gdop;
        j["hdop"] = x.hdop;
        j["pdop"] = x.pdop;
        j["tdop"] = x.tdop;
        j["vdop"] = x.vdop;
    }

    inline void from_json(const json & j, UnitQuaternion& x) {
        x.w = j.at("w").get<double>();
        x.x = j.at("x").get<double>();
        x.y = j.at("y").get<double>();
        x.z = j.at("z").get<double>();
    }

    inline void to_json(json & j, const UnitQuaternion & x) {
        j = json::object();
        j["w"] = x.w;
        j["x"] = x.x;
        j["y"] = x.y;
        j["z"] = x.z;
    }

    inline void from_json(const json & j, EulerAngles& x) {
        x.pitch = j.at("pitch").get<double>();
        x.roll = j.at("roll").get<double>();
        x.yaw = j.at("yaw").get<double>();
    }

    inline void to_json(json & j, const EulerAngles & x) {
        j = json::object();
        j["pitch"] = x.pitch;
        j["roll"] = x.roll;
        j["yaw"] = x.yaw;
    }

    inline void from_json(const json & j, Orientation& x) {
        x.global = get_stack_optional<UnitQuaternion>(j, "global");
        x.local = get_stack_optional<EulerAngles>(j, "local");
    }

    inline void to_json(json & j, const Orientation & x) {
        j = json::object();
        if (x.global) {
            j["global"] = x.global;
        }
        if (x.local) {
            j["local"] = x.local;
        }
    }

    inline void from_json(const json & j, CartesianPosition& x) {
        x.x = j.at("x").get<double>();
        x.y = j.at("y").get<double>();
        x.z = j.at("z").get<double>();
    }

    inline void to_json(json & j, const CartesianPosition & x) {
        j = json::object();
        j["x"] = x.x;
        j["y"] = x.y;
        j["z"] = x.z;
    }

    inline void from_json(const json & j, GeodeticPosition& x) {
        x.altitude_msl = get_stack_optional<double>(j, "altitude_msl");
        x.height = j.at("height").get<double>();
        x.latitude = j.at("latitude").get<double>();
        x.longitude = j.at("longitude").get<double>();
    }

    inline void to_json(json & j, const GeodeticPosition & x) {
        j = json::object();
        if (x.altitude_msl) {
            j["altitude_msl"] = x.altitude_msl;
        }
        j["height"] = x.height;
        j["latitude"] = x.latitude;
        j["longitude"] = x.longitude;
    }

    inline void from_json(const json & j, Position& x) {
        x.cartesian_ecef = get_stack_optional<CartesianPosition>(j, "cartesian_ecef");
        x.geodetic_ecef = get_stack_optional<GeodeticPosition>(j, "geodetic_ecef");
    }

    inline void to_json(json & j, const Position & x) {
        j = json::object();
        if (x.cartesian_ecef) {
            j["cartesian_ecef"] = x.cartesian_ecef;
        }
        if (x.geodetic_ecef) {
            j["geodetic_ecef"] = x.geodetic_ecef;
        }
    }

    inline void from_json(const json & j, GnssSignals& x) {
        x.beidou = get_stack_optional<std::map<std::string, int64_t>>(j, "beidou");
        x.galileo = get_stack_optional<std::map<std::string, int64_t>>(j, "galileo");
        x.glonass = get_stack_optional<std::map<std::string, int64_t>>(j, "glonass");
        x.gps = get_stack_optional<std::map<std::string, int64_t>>(j, "gps");
        x.navic = get_stack_optional<std::map<std::string, int64_t>>(j, "navic");
        x.qzss = get_stack_optional<std::map<std::string, int64_t>>(j, "qzss");
        x.sbas = get_stack_optional<std::map<std::string, int64_t>>(j, "sbas");
    }

    inline void to_json(json & j, const GnssSignals & x) {
        j = json::object();
        if (x.beidou) {
            j["beidou"] = x.beidou;
        }
        if (x.galileo) {
            j["galileo"] = x.galileo;
        }
        if (x.glonass) {
            j["glonass"] = x.glonass;
        }
        if (x.gps) {
            j["gps"] = x.gps;
        }
        if (x.navic) {
            j["navic"] = x.navic;
        }
        if (x.qzss) {
            j["qzss"] = x.qzss;
        }
        if (x.sbas) {
            j["sbas"] = x.sbas;
        }
    }

    inline void from_json(const json & j, GnssTime& x) {
        x.drift_ns_per_s = get_stack_optional<double>(j, "drift_ns_per_s");
        x.leap_seconds_utc = get_stack_optional<int64_t>(j, "leap_seconds_utc");
        x.offset_ns = get_stack_optional<double>(j, "offset_ns");
        x.rollovers = get_stack_optional<int64_t>(j, "rollovers");
        x.tow_ms = j.at("tow_ms").get<int64_t>();
        x.week = j.at("week").get<int64_t>();
    }

    inline void to_json(json & j, const GnssTime & x) {
        j = json::object();
        if (x.drift_ns_per_s) {
            j["drift_ns_per_s"] = x.drift_ns_per_s;
        }
        if (x.leap_seconds_utc) {
            j["leap_seconds_utc"] = x.leap_seconds_utc;
        }
        if (x.offset_ns) {
            j["offset_ns"] = x.offset_ns;
        }
        if (x.rollovers) {
            j["rollovers"] = x.rollovers;
        }
        j["tow_ms"] = x.tow_ms;
        j["week"] = x.week;
    }

    inline void from_json(const json & j, CartesianVelocity& x) {
        x.vx = j.at("vx").get<double>();
        x.vy = j.at("vy").get<double>();
        x.vz = j.at("vz").get<double>();
    }

    inline void to_json(json & j, const CartesianVelocity & x) {
        j = json::object();
        j["vx"] = x.vx;
        j["vy"] = x.vy;
        j["vz"] = x.vz;
    }

    inline void from_json(const json & j, EastNorthUpVelocity& x) {
        x.east = j.at("east").get<double>();
        x.north = j.at("north").get<double>();
        x.up = j.at("up").get<double>();
    }

    inline void to_json(json & j, const EastNorthUpVelocity & x) {
        j = json::object();
        j["east"] = x.east;
        j["north"] = x.north;
        j["up"] = x.up;
    }

    inline void from_json(const json & j, GroundAndVerticalVelocity& x) {
        x.climb_rate = get_stack_optional<double>(j, "climb_rate");
        x.course_over_ground = j.at("course_over_ground").get<double>();
        x.heading_magnetic = get_stack_optional<double>(j, "heading_magnetic");
        x.speed_over_ground = j.at("speed_over_ground").get<double>();
    }

    inline void to_json(json & j, const GroundAndVerticalVelocity & x) {
        j = json::object();
        if (x.climb_rate) {
            j["climb_rate"] = x.climb_rate;
        }
        j["course_over_ground"] = x.course_over_ground;
        if (x.heading_magnetic) {
            j["heading_magnetic"] = x.heading_magnetic;
        }
        j["speed_over_ground"] = x.speed_over_ground;
    }

    inline void from_json(const json & j, NorthEastDownVelocity& x) {
        x.down = j.at("down").get<double>();
        x.east = j.at("east").get<double>();
        x.north = j.at("north").get<double>();
    }

    inline void to_json(json & j, const NorthEastDownVelocity & x) {
        j = json::object();
        j["down"] = x.down;
        j["east"] = x.east;
        j["north"] = x.north;
    }

    inline void from_json(const json & j, Velocity& x) {
        x.cartesian_ecef = get_stack_optional<CartesianVelocity>(j, "cartesian_ecef");
        x.enu = get_stack_optional<EastNorthUpVelocity>(j, "enu");
        x.ground_vertical = get_stack_optional<GroundAndVerticalVelocity>(j, "ground_vertical");
        x.ned = get_stack_optional<NorthEastDownVelocity>(j, "ned");
    }

    inline void to_json(json & j, const Velocity & x) {
        j = json::object();
        if (x.cartesian_ecef) {
            j["cartesian_ecef"] = x.cartesian_ecef;
        }
        if (x.enu) {
            j["enu"] = x.enu;
        }
        if (x.ground_vertical) {
            j["ground_vertical"] = x.ground_vertical;
        }
        if (x.ned) {
            j["ned"] = x.ned;
        }
    }

    inline void from_json(const json & j, PositionNavigationTimingPnt& x) {
        x.algorithm = get_stack_optional<std::string>(j, "algorithm");
        x.covariance = get_stack_optional<Covariance>(j, "covariance");
        x.datum = j.at("datum").get<GeodeticDatum>();
        x.dop = get_stack_optional<DilutionOfPrecision>(j, "dop");
        x.fix = j.at("fix").get<std::string>();
        x.orientation = get_stack_optional<Orientation>(j, "orientation");
        x.position = j.at("position").get<Position>();
        x.signals = get_stack_optional<GnssSignals>(j, "signals");
        x.time = j.at("time").get<std::map<std::string, TimeValue>>();
        x.velocity = j.at("velocity").get<Velocity>();
    }

    inline void to_json(json & j, const PositionNavigationTimingPnt & x) {
        j = json::object();
        if (x.algorithm) {
            j["algorithm"] = x.algorithm;
        }
        if (x.covariance) {
            j["covariance"] = x.covariance;
        }
        j["datum"] = x.datum;
        if (x.dop) {
            j["dop"] = x.dop;
        }
        j["fix"] = x.fix;
        if (x.orientation) {
            j["orientation"] = x.orientation;
        }
        j["position"] = x.position;
        if (x.signals) {
            j["signals"] = x.signals;
        }
        j["time"] = x.time;
        j["velocity"] = x.velocity;
    }

    inline void from_json(const json & j, CovarianceMatrices& x) {
        x.position = j.at("position").get<CovarianceMatrix>();
        x.velocity = get_stack_optional<VelocityCovarianceMatrix>(j, "velocity");
    }

    inline void to_json(json & j, const CovarianceMatrices & x) {
        j = json::object();
        j["position"] = x.position;
        if (x.velocity) {
            j["velocity"] = x.velocity;
        }
    }

    inline void from_json(const json & j, Time& x) {
        x.bdt = get_stack_optional<GnssTime>(j, "bdt");
        x.glonasst = get_stack_optional<std::string>(j, "glonasst");
        x.gpst = get_stack_optional<GnssTime>(j, "gpst");
        x.gst = get_stack_optional<GnssTime>(j, "gst");
        x.tai = get_stack_optional<std::string>(j, "tai");
    }

    inline void to_json(json & j, const Time & x) {
        j = json::object();
        if (x.bdt) {
            j["bdt"] = x.bdt;
        }
        if (x.glonasst) {
            j["glonasst"] = x.glonasst;
        }
        if (x.gpst) {
            j["gpst"] = x.gpst;
        }
        if (x.gst) {
            j["gst"] = x.gst;
        }
        if (x.tai) {
            j["tai"] = x.tai;
        }
    }

    inline void from_json(const json & j, PositionVelocityTimePvt& x) {
        x.algorithm = get_stack_optional<std::string>(j, "algorithm");
        x.covariance = get_stack_optional<CovarianceMatrices>(j, "covariance");
        x.datum = j.at("datum").get<GeodeticDatum>();
        x.fix = j.at("fix").get<std::string>();
        x.position = j.at("position").get<CartesianPosition>();
        x.time = j.at("time").get<Time>();
        x.velocity = get_stack_optional<CartesianVelocity>(j, "velocity");
    }

    inline void to_json(json & j, const PositionVelocityTimePvt & x) {
        j = json::object();
        if (x.algorithm) {
            j["algorithm"] = x.algorithm;
        }
        if (x.covariance) {
            j["covariance"] = x.covariance;
        }
        j["datum"] = x.datum;
        j["fix"] = x.fix;
        j["position"] = x.position;
        j["time"] = x.time;
        if (x.velocity) {
            j["velocity"] = x.velocity;
        }
    }

    inline void from_json(const json & j, Message& x) {
        x.pnt = get_stack_optional<PositionNavigationTimingPnt>(j, "pnt");
        x.pvt = get_stack_optional<PositionVelocityTimePvt>(j, "pvt");
        x.epoch = j.at("$epoch").get<std::string>();
        x.schema = j.at("$schema").get<std::string>();
    }

    inline void to_json(json & j, const Message & x) {
        j = json::object();
        if (x.pnt) {
            j["pnt"] = x.pnt;
        }
        if (x.pvt) {
            j["pvt"] = x.pvt;
        }
        j["$epoch"] = x.epoch;
        j["$schema"] = x.schema;
    }
}
namespace nlohmann {
    inline void adl_serializer<std::variant<ogrp::GnssTime, std::string>>::from_json(const json & j, std::variant<ogrp::GnssTime, std::string> & x) {
        if (j.is_string())
            x = j.get<std::string>();
        else if (j.is_object())
            x = j.get<ogrp::GnssTime>();
        else throw std::runtime_error("Could not deserialise!");
    }

    inline void adl_serializer<std::variant<ogrp::GnssTime, std::string>>::to_json(json & j, const std::variant<ogrp::GnssTime, std::string> & x) {
        switch (x.index()) {
            case 0:
                j = std::get<ogrp::GnssTime>(x);
                break;
            case 1:
                j = std::get<std::string>(x);
                break;
            default: throw std::runtime_error("Input JSON does not conform to schema!");
        }
    }
}
