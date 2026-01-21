//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     Message.cpp data = nlohmann::json::parse(jsonString);

#pragma once

#include <optional>
#include <variant>
#include <nlohmann/json.hpp>
#include "helper.hpp"

#include "CovarianceMatrix.hpp"
#include "VelocityCovarianceMatrix.hpp"
#include "CovarianceMatrixNed.hpp"
#include "Covariance.hpp"
#include "ReferenceEllipsoid.hpp"
#include "GeodeticDatum.hpp"
#include "DilutionOfPrecision.hpp"
#include "UnitQuaternion.hpp"
#include "EulerAngles.hpp"
#include "Orientation.hpp"
#include "CartesianPosition.hpp"
#include "GeodeticPosition.hpp"
#include "Position.hpp"
#include "GnssSatelliteSignals.hpp"
#include "GnssSatellites.hpp"
#include "GnssTime.hpp"
#include "TimeValue.hpp"
#include "CartesianVelocity.hpp"
#include "EastNorthUpVelocity.hpp"
#include "GroundAndVerticalVelocity.hpp"
#include "NorthEastDownVelocity.hpp"
#include "Velocity.hpp"
#include "PositionNavigationTimingPnt.hpp"
#include "CovarianceMatrices.hpp"
#include "Time.hpp"
#include "PositionVelocityTimePvt.hpp"
#include "Message.hpp"
namespace ogrp {
}
