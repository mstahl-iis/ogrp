from dataclasses import dataclass
from typing import Any, Optional, Dict, Union, TypeVar, Type, cast, Callable
from datetime import datetime
from uuid import UUID
import dateutil.parser


T = TypeVar("T")


def from_float(x: Any) -> float:
    assert isinstance(x, (float, int)) and not isinstance(x, bool)
    return float(x)


def to_float(x: Any) -> float:
    assert isinstance(x, (int, float))
    return x


def from_none(x: Any) -> Any:
    assert x is None
    return x


def from_union(fs, x):
    for f in fs:
        try:
            return f(x)
        except:
            pass
    assert False


def to_class(c: Type[T], x: Any) -> dict:
    assert isinstance(x, c)
    return cast(Any, x).to_dict()


def from_str(x: Any) -> str:
    assert isinstance(x, str)
    return x


def from_dict(f: Callable[[Any], T], x: Any) -> Dict[str, T]:
    assert isinstance(x, dict)
    return { k: f(v) for (k, v) in x.items() }


def from_int(x: Any) -> int:
    assert isinstance(x, int) and not isinstance(x, bool)
    return x


def from_datetime(x: Any) -> datetime:
    return dateutil.parser.parse(x)


@dataclass
class CovarianceMatrix:
    """Upper-triangular elements of a symmetric 4×4 covariance matrix for variables {t, x, y,
    z}. Units must match the associated state components.
    """
    tt: float
    """Variance (t)"""

    xt: float
    """Covariance (x, t)"""

    xx: float
    """Variance (x)"""

    xy: float
    """Covariance (x, y)"""

    xz: float
    """Covariance (x, z)"""

    yt: float
    """Covariance (y, t)"""

    yy: float
    """Variance (y)"""

    yz: float
    """Covariance (y, z)"""

    zt: float
    """Covariance (z, t)"""

    zz: float
    """Variance (z)"""

    @staticmethod
    def from_dict(obj: Any) -> 'CovarianceMatrix':
        assert isinstance(obj, dict)
        tt = from_float(obj.get("tt"))
        xt = from_float(obj.get("xt"))
        xx = from_float(obj.get("xx"))
        xy = from_float(obj.get("xy"))
        xz = from_float(obj.get("xz"))
        yt = from_float(obj.get("yt"))
        yy = from_float(obj.get("yy"))
        yz = from_float(obj.get("yz"))
        zt = from_float(obj.get("zt"))
        zz = from_float(obj.get("zz"))
        return CovarianceMatrix(tt, xt, xx, xy, xz, yt, yy, yz, zt, zz)

    def to_dict(self) -> dict:
        result: dict = {}
        result["tt"] = to_float(self.tt)
        result["xt"] = to_float(self.xt)
        result["xx"] = to_float(self.xx)
        result["xy"] = to_float(self.xy)
        result["xz"] = to_float(self.xz)
        result["yt"] = to_float(self.yt)
        result["yy"] = to_float(self.yy)
        result["yz"] = to_float(self.yz)
        result["zt"] = to_float(self.zt)
        result["zz"] = to_float(self.zz)
        return result


@dataclass
class VelocityCovarianceMatrix:
    """Upper-triangular elements of a symmetric 4×4 covariance matrix for variables {dt, vx, vy,
    vz}. Units must match the associated state components.
    """
    dtdt: float
    """Variance (dt)"""

    vxdt: float
    """Covariance (vx, dt)"""

    vxvx: float
    """Variance (vx)"""

    vxvy: float
    """Covariance (vx, vy)"""

    vxvz: float
    """Covariance (vx, vz)"""

    vydt: float
    """Covariance (vy, dt)"""

    vyvy: float
    """Variance (vy)"""

    vyvz: float
    """Covariance (vy, vz)"""

    vzdt: float
    """Covariance (vz, dt)"""

    vzvz: float
    """Variance (vz)"""

    @staticmethod
    def from_dict(obj: Any) -> 'VelocityCovarianceMatrix':
        assert isinstance(obj, dict)
        dtdt = from_float(obj.get("dtdt"))
        vxdt = from_float(obj.get("vxdt"))
        vxvx = from_float(obj.get("vxvx"))
        vxvy = from_float(obj.get("vxvy"))
        vxvz = from_float(obj.get("vxvz"))
        vydt = from_float(obj.get("vydt"))
        vyvy = from_float(obj.get("vyvy"))
        vyvz = from_float(obj.get("vyvz"))
        vzdt = from_float(obj.get("vzdt"))
        vzvz = from_float(obj.get("vzvz"))
        return VelocityCovarianceMatrix(dtdt, vxdt, vxvx, vxvy, vxvz, vydt, vyvy, vyvz, vzdt, vzvz)

    def to_dict(self) -> dict:
        result: dict = {}
        result["dtdt"] = to_float(self.dtdt)
        result["vxdt"] = to_float(self.vxdt)
        result["vxvx"] = to_float(self.vxvx)
        result["vxvy"] = to_float(self.vxvy)
        result["vxvz"] = to_float(self.vxvz)
        result["vydt"] = to_float(self.vydt)
        result["vyvy"] = to_float(self.vyvy)
        result["vyvz"] = to_float(self.vyvz)
        result["vzdt"] = to_float(self.vzdt)
        result["vzvz"] = to_float(self.vzvz)
        return result


@dataclass
class CovarianceMatrixNED:
    """Upper-triangular elements of a symmetric 4×4 covariance matrix for variables {t, north,
    east, down}. Units must match the associated state components.
    """
    dd: float
    """Variance (down)"""

    dt: float
    """Covariance (down"""

    ed: float
    """Covariance (east"""

    ee: float
    """Variance (east)"""

    et: float
    """Covariance (east"""

    nd: float
    """Covariance (north"""

    ne: float
    """Covariance (north"""

    nn: float
    """Variance (north)"""

    nt: float
    """Covariance (north"""

    tt: float
    """Variance (t)"""

    @staticmethod
    def from_dict(obj: Any) -> 'CovarianceMatrixNED':
        assert isinstance(obj, dict)
        dd = from_float(obj.get("dd"))
        dt = from_float(obj.get("dt"))
        ed = from_float(obj.get("ed"))
        ee = from_float(obj.get("ee"))
        et = from_float(obj.get("et"))
        nd = from_float(obj.get("nd"))
        ne = from_float(obj.get("ne"))
        nn = from_float(obj.get("nn"))
        nt = from_float(obj.get("nt"))
        tt = from_float(obj.get("tt"))
        return CovarianceMatrixNED(dd, dt, ed, ee, et, nd, ne, nn, nt, tt)

    def to_dict(self) -> dict:
        result: dict = {}
        result["dd"] = to_float(self.dd)
        result["dt"] = to_float(self.dt)
        result["ed"] = to_float(self.ed)
        result["ee"] = to_float(self.ee)
        result["et"] = to_float(self.et)
        result["nd"] = to_float(self.nd)
        result["ne"] = to_float(self.ne)
        result["nn"] = to_float(self.nn)
        result["nt"] = to_float(self.nt)
        result["tt"] = to_float(self.tt)
        return result


@dataclass
class Covariance:
    """Covariance matrices for position, velocity, and time."""

    global_position: Optional[CovarianceMatrix] = None
    global_velocity: Optional[VelocityCovarianceMatrix] = None
    local_position: Optional[CovarianceMatrixNED] = None

    @staticmethod
    def from_dict(obj: Any) -> 'Covariance':
        assert isinstance(obj, dict)
        global_position = from_union([CovarianceMatrix.from_dict, from_none], obj.get("global_position"))
        global_velocity = from_union([VelocityCovarianceMatrix.from_dict, from_none], obj.get("global_velocity"))
        local_position = from_union([CovarianceMatrixNED.from_dict, from_none], obj.get("local_position"))
        return Covariance(global_position, global_velocity, local_position)

    def to_dict(self) -> dict:
        result: dict = {}
        if self.global_position is not None:
            result["global_position"] = from_union([lambda x: to_class(CovarianceMatrix, x), from_none], self.global_position)
        if self.global_velocity is not None:
            result["global_velocity"] = from_union([lambda x: to_class(VelocityCovarianceMatrix, x), from_none], self.global_velocity)
        if self.local_position is not None:
            result["local_position"] = from_union([lambda x: to_class(CovarianceMatrixNED, x), from_none], self.local_position)
        return result


@dataclass
class ReferenceEllipsoid:
    """Reference ellipsoid. If omitted, it is implied by reference frame (e.g., WGS84)."""

    a: float
    """Semi-major axis a, meters."""

    f: float
    """Flattening f (unitless)."""

    name: str
    """e.g., WGS84, GRS80"""

    @staticmethod
    def from_dict(obj: Any) -> 'ReferenceEllipsoid':
        assert isinstance(obj, dict)
        a = from_float(obj.get("a"))
        f = from_float(obj.get("f"))
        name = from_str(obj.get("name"))
        return ReferenceEllipsoid(a, f, name)

    def to_dict(self) -> dict:
        result: dict = {}
        result["a"] = to_float(self.a)
        result["f"] = to_float(self.f)
        result["name"] = from_str(self.name)
        return result


@dataclass
class GeodeticDatum:
    """A Geodetic Datum consists of a reference frame and optional definition of epoch and
    ellipsoid.
    """
    frame: str
    """Geodetic reference frame/datum (e.g., ITRF2020, WGS84, GTRF, PZ90, CGCS2000)."""

    ellipsoid: Optional[ReferenceEllipsoid] = None
    """Reference ellipsoid. If omitted, it is implied by reference frame (e.g., WGS84)."""

    epoch: Optional[float] = None
    """Reference epoch of coordinates as decimal year (e.g., 2025.0). Required if the frame is
    time-dependent.
    """

    @staticmethod
    def from_dict(obj: Any) -> 'GeodeticDatum':
        assert isinstance(obj, dict)
        frame = from_str(obj.get("frame"))
        ellipsoid = from_union([ReferenceEllipsoid.from_dict, from_none], obj.get("ellipsoid"))
        epoch = from_union([from_float, from_none], obj.get("epoch"))
        return GeodeticDatum(frame, ellipsoid, epoch)

    def to_dict(self) -> dict:
        result: dict = {}
        result["frame"] = from_str(self.frame)
        if self.ellipsoid is not None:
            result["ellipsoid"] = from_union([lambda x: to_class(ReferenceEllipsoid, x), from_none], self.ellipsoid)
        if self.epoch is not None:
            result["epoch"] = from_union([to_float, from_none], self.epoch)
        return result


@dataclass
class DilutionOfPrecision:
    """Unitless DOP metrics derived from satellite geometry; lower is better. Rough accuracy
    guide assumes open-sky code positioning with UERE ≈ 3–5 m, where position_sigma ≈ DOP ×
    UERE. Carrier-phase (RTK/PPP) have much smaller UERE and therefore much better accuracy.
    """
    gdop: float
    """Geometric DOP"""

    hdop: float
    """Horizontal DOP"""

    pdop: float
    """Position DOP"""

    tdop: float
    """Time DOP"""

    vdop: float
    """Vertical DOP"""

    @staticmethod
    def from_dict(obj: Any) -> 'DilutionOfPrecision':
        assert isinstance(obj, dict)
        gdop = from_float(obj.get("gdop"))
        hdop = from_float(obj.get("hdop"))
        pdop = from_float(obj.get("pdop"))
        tdop = from_float(obj.get("tdop"))
        vdop = from_float(obj.get("vdop"))
        return DilutionOfPrecision(gdop, hdop, pdop, tdop, vdop)

    def to_dict(self) -> dict:
        result: dict = {}
        result["gdop"] = to_float(self.gdop)
        result["hdop"] = to_float(self.hdop)
        result["pdop"] = to_float(self.pdop)
        result["tdop"] = to_float(self.tdop)
        result["vdop"] = to_float(self.vdop)
        return result


@dataclass
class EulerAngles:
    """Euler angles representation (roll, pitch, yaw) in degrees relative to the earth surface."""

    pitch: float
    """Pitch angle in degrees"""

    roll: float
    """Roll angle in degrees"""

    yaw: float
    """Yaw angle in degrees"""

    @staticmethod
    def from_dict(obj: Any) -> 'EulerAngles':
        assert isinstance(obj, dict)
        pitch = from_float(obj.get("pitch"))
        roll = from_float(obj.get("roll"))
        yaw = from_float(obj.get("yaw"))
        return EulerAngles(pitch, roll, yaw)

    def to_dict(self) -> dict:
        result: dict = {}
        result["pitch"] = to_float(self.pitch)
        result["roll"] = to_float(self.roll)
        result["yaw"] = to_float(self.yaw)
        return result


@dataclass
class UnitQuaternion:
    """Normalized quaternion representation for orientation."""

    w: float
    """Scalar part"""

    x: float
    """Vector part X"""

    y: float
    """Vector part Y"""

    z: float
    """Vector part Z"""

    @staticmethod
    def from_dict(obj: Any) -> 'UnitQuaternion':
        assert isinstance(obj, dict)
        w = from_float(obj.get("w"))
        x = from_float(obj.get("x"))
        y = from_float(obj.get("y"))
        z = from_float(obj.get("z"))
        return UnitQuaternion(w, x, y, z)

    def to_dict(self) -> dict:
        result: dict = {}
        result["w"] = to_float(self.w)
        result["x"] = to_float(self.x)
        result["y"] = to_float(self.y)
        result["z"] = to_float(self.z)
        return result


@dataclass
class Orientation:
    """Orientation in various representations."""

    orientation_global: Optional[UnitQuaternion] = None
    local: Optional[EulerAngles] = None

    @staticmethod
    def from_dict(obj: Any) -> 'Orientation':
        assert isinstance(obj, dict)
        orientation_global = from_union([UnitQuaternion.from_dict, from_none], obj.get("global"))
        local = from_union([EulerAngles.from_dict, from_none], obj.get("local"))
        return Orientation(orientation_global, local)

    def to_dict(self) -> dict:
        result: dict = {}
        if self.orientation_global is not None:
            result["global"] = from_union([lambda x: to_class(UnitQuaternion, x), from_none], self.orientation_global)
        if self.local is not None:
            result["local"] = from_union([lambda x: to_class(EulerAngles, x), from_none], self.local)
        return result


@dataclass
class CartesianPosition:
    """Cartesian coordinates in meters."""

    x: float
    """X coordinate in meters."""

    y: float
    """Y coordinate in meters."""

    z: float
    """Z coordinate in meters."""

    @staticmethod
    def from_dict(obj: Any) -> 'CartesianPosition':
        assert isinstance(obj, dict)
        x = from_float(obj.get("x"))
        y = from_float(obj.get("y"))
        z = from_float(obj.get("z"))
        return CartesianPosition(x, y, z)

    def to_dict(self) -> dict:
        result: dict = {}
        result["x"] = to_float(self.x)
        result["y"] = to_float(self.y)
        result["z"] = to_float(self.z)
        return result


@dataclass
class GeodeticPosition:
    """Geodetic position in latitude, longitude, and height."""

    height: float
    """Height above ellipsoid in meters."""

    latitude: float
    """Latitude relative to equator in degrees. Positive values are northward."""

    longitude: float
    """Longitude relative to prime meridian in degrees. Positive values are eastward."""

    altitude_msl: Optional[float] = None
    """Altitude above mean sea level (geoid) in meters."""

    @staticmethod
    def from_dict(obj: Any) -> 'GeodeticPosition':
        assert isinstance(obj, dict)
        height = from_float(obj.get("height"))
        latitude = from_float(obj.get("latitude"))
        longitude = from_float(obj.get("longitude"))
        altitude_msl = from_union([from_float, from_none], obj.get("altitude_msl"))
        return GeodeticPosition(height, latitude, longitude, altitude_msl)

    def to_dict(self) -> dict:
        result: dict = {}
        result["height"] = to_float(self.height)
        result["latitude"] = to_float(self.latitude)
        result["longitude"] = to_float(self.longitude)
        if self.altitude_msl is not None:
            result["altitude_msl"] = from_union([to_float, from_none], self.altitude_msl)
        return result


@dataclass
class Position:
    """Position in various coordinate systems."""

    cartesian_ecef: Optional[CartesianPosition] = None
    geodetic_ecef: Optional[GeodeticPosition] = None

    @staticmethod
    def from_dict(obj: Any) -> 'Position':
        assert isinstance(obj, dict)
        cartesian_ecef = from_union([CartesianPosition.from_dict, from_none], obj.get("cartesian_ecef"))
        geodetic_ecef = from_union([GeodeticPosition.from_dict, from_none], obj.get("geodetic_ecef"))
        return Position(cartesian_ecef, geodetic_ecef)

    def to_dict(self) -> dict:
        result: dict = {}
        if self.cartesian_ecef is not None:
            result["cartesian_ecef"] = from_union([lambda x: to_class(CartesianPosition, x), from_none], self.cartesian_ecef)
        if self.geodetic_ecef is not None:
            result["geodetic_ecef"] = from_union([lambda x: to_class(GeodeticPosition, x), from_none], self.geodetic_ecef)
        return result


@dataclass
class GNSSSignals:
    """GNSS signals used for position, velocity, and time computation."""

    beidou: Optional[Dict[str, int]] = None
    """Number of signals used per frequency band. E.g. { "b1c": 3, "b2a": 2, "b3": 5 }."""

    galileo: Optional[Dict[str, int]] = None
    """Number of signals used per frequency band. E.g. { "e1b": 3, "e5a": 2, "e6a": 5 }."""

    glonass: Optional[Dict[str, int]] = None
    """Number of signals used per frequency band. E.g. { "l1": 3, "l2": 2 }."""

    gps: Optional[Dict[str, int]] = None
    """Number of signals used per frequency band. E.g. { "l1ca": 3, "l2c": 2 }."""

    navic: Optional[Dict[str, int]] = None
    """Number of signals used per frequency band. E.g. { "l5": 3, "s": 2 }."""

    qzss: Optional[Dict[str, int]] = None
    """Number of signals used per frequency band. E.g. { "l1ca": 3, "l2cm": 2, "l5i": 5,
    "l6lex": 1 }.
    """
    sbas: Optional[Dict[str, int]] = None
    """Number of signals used per frequency band. E.g. { "l1egnos": 3, "l5waas": 2 }."""

    @staticmethod
    def from_dict(obj: Any) -> 'GNSSSignals':
        assert isinstance(obj, dict)
        beidou = from_union([lambda x: from_dict(from_int, x), from_none], obj.get("beidou"))
        galileo = from_union([lambda x: from_dict(from_int, x), from_none], obj.get("galileo"))
        glonass = from_union([lambda x: from_dict(from_int, x), from_none], obj.get("glonass"))
        gps = from_union([lambda x: from_dict(from_int, x), from_none], obj.get("gps"))
        navic = from_union([lambda x: from_dict(from_int, x), from_none], obj.get("navic"))
        qzss = from_union([lambda x: from_dict(from_int, x), from_none], obj.get("qzss"))
        sbas = from_union([lambda x: from_dict(from_int, x), from_none], obj.get("sbas"))
        return GNSSSignals(beidou, galileo, glonass, gps, navic, qzss, sbas)

    def to_dict(self) -> dict:
        result: dict = {}
        if self.beidou is not None:
            result["beidou"] = from_union([lambda x: from_dict(from_int, x), from_none], self.beidou)
        if self.galileo is not None:
            result["galileo"] = from_union([lambda x: from_dict(from_int, x), from_none], self.galileo)
        if self.glonass is not None:
            result["glonass"] = from_union([lambda x: from_dict(from_int, x), from_none], self.glonass)
        if self.gps is not None:
            result["gps"] = from_union([lambda x: from_dict(from_int, x), from_none], self.gps)
        if self.navic is not None:
            result["navic"] = from_union([lambda x: from_dict(from_int, x), from_none], self.navic)
        if self.qzss is not None:
            result["qzss"] = from_union([lambda x: from_dict(from_int, x), from_none], self.qzss)
        if self.sbas is not None:
            result["sbas"] = from_union([lambda x: from_dict(from_int, x), from_none], self.sbas)
        return result


@dataclass
class GNSSTime:
    """BeiDou Time (strictly monotonic)
    
    Native GNSS time in week and time-of-week in milliseconds. No leap seconds for
    GPS/Galileo/BeiDou; GLONASS is UTC-like.
    
    GPS Time (strictly monotonic)
    
    Galileo System Time (strictly monotonic)
    """
    tow_ms: int
    """Time of week in milliseconds."""

    week: int
    """Week number since GNSS system epoch. Maximum depends on GNSS system."""

    drift_ns_per_s: Optional[float] = None
    """Clock drift in ns/s. Positive means GNSS time is faster than receiver clock."""

    leap_seconds_utc: Optional[int] = None
    """Number of leap seconds (GNSS-UTC) applicable at this epoch."""

    offset_ns: Optional[float] = None
    """Clock offset in nanoseconds. Positive means GNSS time is ahead of receiver clock."""

    rollovers: Optional[int] = None
    """Number of week rollovers since GNSS system epoch (e.g., GPS epoch: January 6, 1980)."""

    @staticmethod
    def from_dict(obj: Any) -> 'GNSSTime':
        assert isinstance(obj, dict)
        tow_ms = from_int(obj.get("tow_ms"))
        week = from_int(obj.get("week"))
        drift_ns_per_s = from_union([from_float, from_none], obj.get("drift_ns_per_s"))
        leap_seconds_utc = from_union([from_int, from_none], obj.get("leap_seconds_utc"))
        offset_ns = from_union([from_float, from_none], obj.get("offset_ns"))
        rollovers = from_union([from_int, from_none], obj.get("rollovers"))
        return GNSSTime(tow_ms, week, drift_ns_per_s, leap_seconds_utc, offset_ns, rollovers)

    def to_dict(self) -> dict:
        result: dict = {}
        result["tow_ms"] = from_int(self.tow_ms)
        result["week"] = from_int(self.week)
        if self.drift_ns_per_s is not None:
            result["drift_ns_per_s"] = from_union([to_float, from_none], self.drift_ns_per_s)
        if self.leap_seconds_utc is not None:
            result["leap_seconds_utc"] = from_union([from_int, from_none], self.leap_seconds_utc)
        if self.offset_ns is not None:
            result["offset_ns"] = from_union([to_float, from_none], self.offset_ns)
        if self.rollovers is not None:
            result["rollovers"] = from_union([from_int, from_none], self.rollovers)
        return result


@dataclass
class CartesianVelocity:
    """Cartesian velocity in meters per second."""

    vx: float
    """X velocity in meters per second."""

    vy: float
    """Y velocity in meters per second."""

    vz: float
    """Z velocity in meters per second."""

    @staticmethod
    def from_dict(obj: Any) -> 'CartesianVelocity':
        assert isinstance(obj, dict)
        vx = from_float(obj.get("vx"))
        vy = from_float(obj.get("vy"))
        vz = from_float(obj.get("vz"))
        return CartesianVelocity(vx, vy, vz)

    def to_dict(self) -> dict:
        result: dict = {}
        result["vx"] = to_float(self.vx)
        result["vy"] = to_float(self.vy)
        result["vz"] = to_float(self.vz)
        return result


@dataclass
class EastNorthUpVelocity:
    """Velocity in east, north, and up directions (ENU)."""

    east: float
    """Meters per second"""

    north: float
    """Meters per second"""

    up: float
    """Meters per second"""

    @staticmethod
    def from_dict(obj: Any) -> 'EastNorthUpVelocity':
        assert isinstance(obj, dict)
        east = from_float(obj.get("east"))
        north = from_float(obj.get("north"))
        up = from_float(obj.get("up"))
        return EastNorthUpVelocity(east, north, up)

    def to_dict(self) -> dict:
        result: dict = {}
        result["east"] = to_float(self.east)
        result["north"] = to_float(self.north)
        result["up"] = to_float(self.up)
        return result


@dataclass
class GroundAndVerticalVelocity:
    course_over_ground: float
    """Heading relative to true north in degrees."""

    speed_over_ground: float
    """Speed over ground in meters per second."""

    climb_rate: Optional[float] = None
    """Climb rate in meters per second. Positive values indicate ascending."""

    heading_magnetic: Optional[float] = None
    """Heading relative to magnetic north in degrees."""

    @staticmethod
    def from_dict(obj: Any) -> 'GroundAndVerticalVelocity':
        assert isinstance(obj, dict)
        course_over_ground = from_float(obj.get("course_over_ground"))
        speed_over_ground = from_float(obj.get("speed_over_ground"))
        climb_rate = from_union([from_float, from_none], obj.get("climb_rate"))
        heading_magnetic = from_union([from_float, from_none], obj.get("heading_magnetic"))
        return GroundAndVerticalVelocity(course_over_ground, speed_over_ground, climb_rate, heading_magnetic)

    def to_dict(self) -> dict:
        result: dict = {}
        result["course_over_ground"] = to_float(self.course_over_ground)
        result["speed_over_ground"] = to_float(self.speed_over_ground)
        if self.climb_rate is not None:
            result["climb_rate"] = from_union([to_float, from_none], self.climb_rate)
        if self.heading_magnetic is not None:
            result["heading_magnetic"] = from_union([to_float, from_none], self.heading_magnetic)
        return result


@dataclass
class NorthEastDownVelocity:
    """Velocity in north, east, and down directions (NED)."""

    down: float
    """Meters per second"""

    east: float
    """Meters per second"""

    north: float
    """Meters per second"""

    @staticmethod
    def from_dict(obj: Any) -> 'NorthEastDownVelocity':
        assert isinstance(obj, dict)
        down = from_float(obj.get("down"))
        east = from_float(obj.get("east"))
        north = from_float(obj.get("north"))
        return NorthEastDownVelocity(down, east, north)

    def to_dict(self) -> dict:
        result: dict = {}
        result["down"] = to_float(self.down)
        result["east"] = to_float(self.east)
        result["north"] = to_float(self.north)
        return result


@dataclass
class Velocity:
    """Velocity in various coordinate systems."""

    cartesian_ecef: Optional[CartesianVelocity] = None
    enu: Optional[EastNorthUpVelocity] = None
    ground_vertical: Optional[GroundAndVerticalVelocity] = None
    ned: Optional[NorthEastDownVelocity] = None

    @staticmethod
    def from_dict(obj: Any) -> 'Velocity':
        assert isinstance(obj, dict)
        cartesian_ecef = from_union([CartesianVelocity.from_dict, from_none], obj.get("cartesian_ecef"))
        enu = from_union([EastNorthUpVelocity.from_dict, from_none], obj.get("enu"))
        ground_vertical = from_union([GroundAndVerticalVelocity.from_dict, from_none], obj.get("ground_vertical"))
        ned = from_union([NorthEastDownVelocity.from_dict, from_none], obj.get("ned"))
        return Velocity(cartesian_ecef, enu, ground_vertical, ned)

    def to_dict(self) -> dict:
        result: dict = {}
        if self.cartesian_ecef is not None:
            result["cartesian_ecef"] = from_union([lambda x: to_class(CartesianVelocity, x), from_none], self.cartesian_ecef)
        if self.enu is not None:
            result["enu"] = from_union([lambda x: to_class(EastNorthUpVelocity, x), from_none], self.enu)
        if self.ground_vertical is not None:
            result["ground_vertical"] = from_union([lambda x: to_class(GroundAndVerticalVelocity, x), from_none], self.ground_vertical)
        if self.ned is not None:
            result["ned"] = from_union([lambda x: to_class(NorthEastDownVelocity, x), from_none], self.ned)
        return result


@dataclass
class PositionNavigationTimingPNT:
    """Reliable position, navigation, and timing including sensors, algorithms,
    integrity/continuity/availability, and policies.
    """
    datum: GeodeticDatum
    fix: str
    position: Position
    time: Dict[str, Union[GNSSTime, datetime]]
    velocity: Velocity
    algorithm: Optional[str] = None
    covariance: Optional[Covariance] = None
    dop: Optional[DilutionOfPrecision] = None
    orientation: Optional[Orientation] = None
    signals: Optional[GNSSSignals] = None

    @staticmethod
    def from_dict(obj: Any) -> 'PositionNavigationTimingPNT':
        assert isinstance(obj, dict)
        datum = GeodeticDatum.from_dict(obj.get("datum"))
        fix = from_str(obj.get("fix"))
        position = Position.from_dict(obj.get("position"))
        time = from_dict(lambda x: from_union([GNSSTime.from_dict, from_datetime], x), obj.get("time"))
        velocity = Velocity.from_dict(obj.get("velocity"))
        algorithm = from_union([from_str, from_none], obj.get("algorithm"))
        covariance = from_union([Covariance.from_dict, from_none], obj.get("covariance"))
        dop = from_union([DilutionOfPrecision.from_dict, from_none], obj.get("dop"))
        orientation = from_union([Orientation.from_dict, from_none], obj.get("orientation"))
        signals = from_union([GNSSSignals.from_dict, from_none], obj.get("signals"))
        return PositionNavigationTimingPNT(datum, fix, position, time, velocity, algorithm, covariance, dop, orientation, signals)

    def to_dict(self) -> dict:
        result: dict = {}
        result["datum"] = to_class(GeodeticDatum, self.datum)
        result["fix"] = from_str(self.fix)
        result["position"] = to_class(Position, self.position)
        result["time"] = from_dict(lambda x: from_union([lambda x: to_class(GNSSTime, x), lambda x: x.isoformat()], x), self.time)
        result["velocity"] = to_class(Velocity, self.velocity)
        if self.algorithm is not None:
            result["algorithm"] = from_union([from_str, from_none], self.algorithm)
        if self.covariance is not None:
            result["covariance"] = from_union([lambda x: to_class(Covariance, x), from_none], self.covariance)
        if self.dop is not None:
            result["dop"] = from_union([lambda x: to_class(DilutionOfPrecision, x), from_none], self.dop)
        if self.orientation is not None:
            result["orientation"] = from_union([lambda x: to_class(Orientation, x), from_none], self.orientation)
        if self.signals is not None:
            result["signals"] = from_union([lambda x: to_class(GNSSSignals, x), from_none], self.signals)
        return result


@dataclass
class CovarianceMatrices:
    """Covariance matrices for position + time and velocity + time drift."""

    position: CovarianceMatrix
    velocity: Optional[VelocityCovarianceMatrix] = None

    @staticmethod
    def from_dict(obj: Any) -> 'CovarianceMatrices':
        assert isinstance(obj, dict)
        position = CovarianceMatrix.from_dict(obj.get("position"))
        velocity = from_union([VelocityCovarianceMatrix.from_dict, from_none], obj.get("velocity"))
        return CovarianceMatrices(position, velocity)

    def to_dict(self) -> dict:
        result: dict = {}
        result["position"] = to_class(CovarianceMatrix, self.position)
        if self.velocity is not None:
            result["velocity"] = from_union([lambda x: to_class(VelocityCovarianceMatrix, x), from_none], self.velocity)
        return result


@dataclass
class Time:
    """GNSS system time representations."""

    bdt: Optional[GNSSTime] = None
    """BeiDou Time (strictly monotonic)"""

    glonasst: Optional[datetime] = None
    """GLONASS Time (UTC-like)"""

    gpst: Optional[GNSSTime] = None
    """GPS Time (strictly monotonic)"""

    gst: Optional[GNSSTime] = None
    """Galileo System Time (strictly monotonic)"""

    tai: Optional[datetime] = None
    """International Atomic Time (strictly monotonic)"""

    @staticmethod
    def from_dict(obj: Any) -> 'Time':
        assert isinstance(obj, dict)
        bdt = from_union([GNSSTime.from_dict, from_none], obj.get("bdt"))
        glonasst = from_union([from_datetime, from_none], obj.get("glonasst"))
        gpst = from_union([GNSSTime.from_dict, from_none], obj.get("gpst"))
        gst = from_union([GNSSTime.from_dict, from_none], obj.get("gst"))
        tai = from_union([from_datetime, from_none], obj.get("tai"))
        return Time(bdt, glonasst, gpst, gst, tai)

    def to_dict(self) -> dict:
        result: dict = {}
        if self.bdt is not None:
            result["bdt"] = from_union([lambda x: to_class(GNSSTime, x), from_none], self.bdt)
        if self.glonasst is not None:
            result["glonasst"] = from_union([lambda x: x.isoformat(), from_none], self.glonasst)
        if self.gpst is not None:
            result["gpst"] = from_union([lambda x: to_class(GNSSTime, x), from_none], self.gpst)
        if self.gst is not None:
            result["gst"] = from_union([lambda x: to_class(GNSSTime, x), from_none], self.gst)
        if self.tai is not None:
            result["tai"] = from_union([lambda x: x.isoformat(), from_none], self.tai)
        return result


@dataclass
class PositionVelocityTimePVT:
    """Position and velocity refer to earth-centered, earth-fixed cartesian coordinate system
    defined by `datum`.
    """
    datum: GeodeticDatum
    fix: str
    position: CartesianPosition
    time: Time
    algorithm: Optional[str] = None
    covariance: Optional[CovarianceMatrices] = None
    velocity: Optional[CartesianVelocity] = None

    @staticmethod
    def from_dict(obj: Any) -> 'PositionVelocityTimePVT':
        assert isinstance(obj, dict)
        datum = GeodeticDatum.from_dict(obj.get("datum"))
        fix = from_str(obj.get("fix"))
        position = CartesianPosition.from_dict(obj.get("position"))
        time = Time.from_dict(obj.get("time"))
        algorithm = from_union([from_str, from_none], obj.get("algorithm"))
        covariance = from_union([CovarianceMatrices.from_dict, from_none], obj.get("covariance"))
        velocity = from_union([CartesianVelocity.from_dict, from_none], obj.get("velocity"))
        return PositionVelocityTimePVT(datum, fix, position, time, algorithm, covariance, velocity)

    def to_dict(self) -> dict:
        result: dict = {}
        result["datum"] = to_class(GeodeticDatum, self.datum)
        result["fix"] = from_str(self.fix)
        result["position"] = to_class(CartesianPosition, self.position)
        result["time"] = to_class(Time, self.time)
        if self.algorithm is not None:
            result["algorithm"] = from_union([from_str, from_none], self.algorithm)
        if self.covariance is not None:
            result["covariance"] = from_union([lambda x: to_class(CovarianceMatrices, x), from_none], self.covariance)
        if self.velocity is not None:
            result["velocity"] = from_union([lambda x: to_class(CartesianVelocity, x), from_none], self.velocity)
        return result


@dataclass
class Ogrp:
    """The OGRP message is the base schema for all OGRP messages."""

    epoch: UUID
    """Either UUIDv1 or UUIDv6 according to RFC9562. The Node ID should be the MAC address of
    the GNSS receiver.
    """
    schema: str
    """The schema of this OGRP message."""

    pnt: Optional[PositionNavigationTimingPNT] = None
    pvt: Optional[PositionVelocityTimePVT] = None

    @staticmethod
    def from_dict(obj: Any) -> 'Ogrp':
        assert isinstance(obj, dict)
        epoch = UUID(obj.get("$epoch"))
        schema = from_str(obj.get("$schema"))
        pnt = from_union([PositionNavigationTimingPNT.from_dict, from_none], obj.get("pnt"))
        pvt = from_union([PositionVelocityTimePVT.from_dict, from_none], obj.get("pvt"))
        return Ogrp(epoch, schema, pnt, pvt)

    def to_dict(self) -> dict:
        result: dict = {}
        result["$epoch"] = str(self.epoch)
        result["$schema"] = from_str(self.schema)
        if self.pnt is not None:
            result["pnt"] = from_union([lambda x: to_class(PositionNavigationTimingPNT, x), from_none], self.pnt)
        if self.pvt is not None:
            result["pvt"] = from_union([lambda x: to_class(PositionVelocityTimePVT, x), from_none], self.pvt)
        return result


def ogrp_from_dict(s: Any) -> Ogrp:
    return Ogrp.from_dict(s)


def ogrp_to_dict(x: Ogrp) -> Any:
    return to_class(Ogrp, x)
