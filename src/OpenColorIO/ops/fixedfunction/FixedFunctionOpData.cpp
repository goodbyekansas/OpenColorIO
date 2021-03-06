// SPDX-License-Identifier: BSD-3-Clause
// Copyright Contributors to the OpenColorIO Project.

#include <sstream>

#include <OpenColorIO/OpenColorIO.h>

#include "ops/fixedfunction/FixedFunctionOpData.h"
#include "Platform.h"

namespace OCIO_NAMESPACE
{

namespace DefaultValues
{
const int FLOAT_DECIMALS = 7;
}

constexpr const char * ACES_RED_MOD_03_FWD_STR = "RedMod03Fwd";
constexpr const char * ACES_RED_MOD_03_REV_STR = "RedMod03Rev";
constexpr const char * ACES_RED_MOD_10_FWD_STR = "RedMod10Fwd";
constexpr const char * ACES_RED_MOD_10_REV_STR = "RedMod10Rev";
constexpr const char * ACES_GLOW_03_FWD_STR    = "Glow03Fwd";
constexpr const char * ACES_GLOW_03_REV_STR    = "Glow03Rev";
constexpr const char * ACES_GLOW_10_FWD_STR    = "Glow10Fwd";
constexpr const char * ACES_GLOW_10_REV_STR    = "Glow10Rev";
constexpr const char * ACES_DARK_TO_DIM_10_STR = "DarkToDim10";
constexpr const char * ACES_DIM_TO_DARK_10_STR = "DimToDark10";
constexpr const char * SURROUND_STR            = "Surround"; // Is old name for Rec2100Surround
constexpr const char * REC_2100_SURROUND_STR   = "Rec2100Surround";
constexpr const char * RGB_TO_HSV_STR          = "RGB_TO_HSV";
constexpr const char * HSV_TO_RGB_STR          = "HSV_TO_RGB";
constexpr const char * XYZ_TO_xyY_STR          = "XYZ_TO_xyY";
constexpr const char * xyY_TO_XYZ_STR          = "xyY_TO_XYZ";
constexpr const char * XYZ_TO_uvY_STR          = "XYZ_TO_uvY";
constexpr const char * uvY_TO_XYZ_STR          = "uvY_TO_XYZ";
constexpr const char * XYZ_TO_LUV_STR          = "XYZ_TO_LUV";
constexpr const char * LUV_TO_XYZ_STR          = "LUV_TO_XYZ";


// NOTE: Converts the enumeration value to its string representation (i.e. CLF reader).
//       It could add details for error reporting.
//          
// Convert internal OpData style enum to CTF attribute string.  Set 'detailed' to true to get
// a more verbose human readable string
const char * FixedFunctionOpData::ConvertStyleToString(Style style, bool detailed)
{
    switch(style)
    {
        case ACES_RED_MOD_03_FWD:
            return detailed ? "ACES_RedMod03 (Forward)"    : ACES_RED_MOD_03_FWD_STR;
        case ACES_RED_MOD_03_INV:
            return detailed ? "ACES_RedMod03 (Inverse)"    : ACES_RED_MOD_03_REV_STR;
        case ACES_RED_MOD_10_FWD:
            return detailed ? "ACES_RedMod10 (Forward)"    : ACES_RED_MOD_10_FWD_STR;
        case ACES_RED_MOD_10_INV:
            return detailed ? "ACES_RedMod10 (Inverse)"    : ACES_RED_MOD_10_REV_STR;
        case ACES_GLOW_03_FWD:
            return detailed ? "ACES_Glow03 (Forward)"      : ACES_GLOW_03_FWD_STR;
        case ACES_GLOW_03_INV:
            return detailed ? "ACES_Glow03 (Inverse)"      : ACES_GLOW_03_REV_STR;
        case ACES_GLOW_10_FWD:
            return detailed ? "ACES_Glow10 (Forward)"      : ACES_GLOW_10_FWD_STR;
        case ACES_GLOW_10_INV:
            return detailed ? "ACES_Glow10 (Inverse)"      : ACES_GLOW_10_REV_STR;
        case ACES_DARK_TO_DIM_10_FWD:
            return detailed ? "ACES_DarkToDim10 (Forward)" : ACES_DARK_TO_DIM_10_STR;
        case ACES_DARK_TO_DIM_10_INV: 
            return detailed ? "ACES_DarkToDim10 (Inverse)" : ACES_DIM_TO_DARK_10_STR;
        case REC2100_SURROUND_FWD:
        case REC2100_SURROUND_INV:
            return detailed ? "REC2100_Surround"           : REC_2100_SURROUND_STR;
        case RGB_TO_HSV:
            return RGB_TO_HSV_STR;
        case HSV_TO_RGB: 
            return HSV_TO_RGB_STR;
        case XYZ_TO_xyY:
            return XYZ_TO_xyY_STR;
        case xyY_TO_XYZ:
            return xyY_TO_XYZ_STR;
        case XYZ_TO_uvY:
            return XYZ_TO_uvY_STR;
        case uvY_TO_XYZ:
            return uvY_TO_XYZ_STR;
        case XYZ_TO_LUV:
            return XYZ_TO_LUV_STR;
        case LUV_TO_XYZ:
            return LUV_TO_XYZ_STR;
    }

    std::stringstream ss("Unknown FixedFunction style: ");
    ss << style;

    throw Exception(ss.str().c_str());
}

// Convert CTF attribute string into OpData style enum.
FixedFunctionOpData::Style FixedFunctionOpData::GetStyle(const char * name)
{
    if (name && *name)
    {
        if (0 == Platform::Strcasecmp(name, ACES_RED_MOD_03_FWD_STR))
        {
            return ACES_RED_MOD_03_FWD;
        }
        else if (0 == Platform::Strcasecmp(name, ACES_RED_MOD_03_REV_STR))
        {
            return ACES_RED_MOD_03_INV;
        }
        else if (0 == Platform::Strcasecmp(name, ACES_RED_MOD_10_FWD_STR))
        {
            return ACES_RED_MOD_10_FWD;
        }
        else if (0 == Platform::Strcasecmp(name, ACES_RED_MOD_10_REV_STR))
        {
            return ACES_RED_MOD_10_INV;
        }
        else if (0 == Platform::Strcasecmp(name, ACES_GLOW_03_FWD_STR))
        {
            return ACES_GLOW_03_FWD;
        }
        else if (0 == Platform::Strcasecmp(name, ACES_GLOW_03_REV_STR))
        {
            return ACES_GLOW_03_INV;
        }
        else if (0 == Platform::Strcasecmp(name, ACES_GLOW_10_FWD_STR))
        {
            return ACES_GLOW_10_FWD;
        }
        else if (0 == Platform::Strcasecmp(name, ACES_GLOW_10_REV_STR))
        {
            return ACES_GLOW_10_INV;
        }
        else if (0 == Platform::Strcasecmp(name, ACES_DARK_TO_DIM_10_STR))
        {
            return ACES_DARK_TO_DIM_10_FWD;
        }
        else if (0 == Platform::Strcasecmp(name, ACES_DIM_TO_DARK_10_STR))
        {
            return ACES_DARK_TO_DIM_10_INV;
        }
        else if (0 == Platform::Strcasecmp(name, SURROUND_STR) ||
                 0 == Platform::Strcasecmp(name, REC_2100_SURROUND_STR) )
        {
            return REC2100_SURROUND_FWD;
        }
        else if (0 == Platform::Strcasecmp(name, RGB_TO_HSV_STR))
        {
            return RGB_TO_HSV;
        }
        else if (0 == Platform::Strcasecmp(name, HSV_TO_RGB_STR))
        {
            return HSV_TO_RGB;
        }
        else if (0 == Platform::Strcasecmp(name, XYZ_TO_xyY_STR))
        {
            return XYZ_TO_xyY;
        }
        else if (0 == Platform::Strcasecmp(name, xyY_TO_XYZ_STR))
        {
            return xyY_TO_XYZ;
        }
        else if (0 == Platform::Strcasecmp(name, XYZ_TO_uvY_STR))
        {
            return XYZ_TO_uvY;
        }
        else if (0 == Platform::Strcasecmp(name, uvY_TO_XYZ_STR))
        {
            return uvY_TO_XYZ;
        }
        else if (0 == Platform::Strcasecmp(name, XYZ_TO_LUV_STR))
        {
            return XYZ_TO_LUV;
        }
        else if (0 == Platform::Strcasecmp(name, LUV_TO_XYZ_STR))
        {
            return LUV_TO_XYZ;
        }
    }

    std::string st("Unknown FixedFunction style: ");
    st += name;

    throw Exception(st.c_str());
}

// Combine the Transform style and direction into the internal OpData style.
FixedFunctionOpData::Style FixedFunctionOpData::ConvertStyle(FixedFunctionStyle style,
                                                             TransformDirection dir)
{
    const bool isForward = dir == TRANSFORM_DIR_FORWARD;

    switch (style)
    {
        case FIXED_FUNCTION_ACES_RED_MOD_03:
        {
            return isForward ? FixedFunctionOpData::ACES_RED_MOD_03_FWD :
                               FixedFunctionOpData::ACES_RED_MOD_03_INV;
        }
        case FIXED_FUNCTION_ACES_RED_MOD_10:
        {
            return isForward ? FixedFunctionOpData::ACES_RED_MOD_10_FWD :
                               FixedFunctionOpData::ACES_RED_MOD_10_INV;
        }
        case FIXED_FUNCTION_ACES_GLOW_03:
        {
            return isForward ? FixedFunctionOpData::ACES_GLOW_03_FWD :
                               FixedFunctionOpData::ACES_GLOW_03_INV;
        }
        case FIXED_FUNCTION_ACES_GLOW_10:
        {
            return isForward ? FixedFunctionOpData::ACES_GLOW_10_FWD :
                               FixedFunctionOpData::ACES_GLOW_10_INV;
        }
        case FIXED_FUNCTION_ACES_DARK_TO_DIM_10:
        {
            return isForward ? FixedFunctionOpData::ACES_DARK_TO_DIM_10_FWD :
                               FixedFunctionOpData::ACES_DARK_TO_DIM_10_INV;
        }
        case FIXED_FUNCTION_REC2100_SURROUND:
        {
            return isForward ? FixedFunctionOpData::REC2100_SURROUND_FWD :
                               FixedFunctionOpData::REC2100_SURROUND_INV;
        }
        case FIXED_FUNCTION_RGB_TO_HSV:
        {
            return FixedFunctionOpData::RGB_TO_HSV;
        }
        case FIXED_FUNCTION_XYZ_TO_xyY:
        {
            return FixedFunctionOpData::XYZ_TO_xyY;
        }
        case FIXED_FUNCTION_XYZ_TO_uvY:
        {
            return FixedFunctionOpData::XYZ_TO_uvY;
        }
        case FIXED_FUNCTION_XYZ_TO_LUV:
        {
            return FixedFunctionOpData::XYZ_TO_LUV;
        }
    }

    std::stringstream ss("Unknown FixedFunction transform style: ");
    ss << style;

    throw Exception(ss.str().c_str());
}

// Convert internal OpData style to Transform style.
FixedFunctionStyle FixedFunctionOpData::ConvertStyle(FixedFunctionOpData::Style style)
{
    switch (style)
    {
    case FixedFunctionOpData::ACES_RED_MOD_03_FWD:
    case FixedFunctionOpData::ACES_RED_MOD_03_INV:
        return FIXED_FUNCTION_ACES_RED_MOD_03;

    case FixedFunctionOpData::ACES_RED_MOD_10_FWD:
    case FixedFunctionOpData::ACES_RED_MOD_10_INV:
        return FIXED_FUNCTION_ACES_RED_MOD_10;

    case FixedFunctionOpData::ACES_GLOW_03_FWD:
    case FixedFunctionOpData::ACES_GLOW_03_INV:
        return FIXED_FUNCTION_ACES_GLOW_03;

    case FixedFunctionOpData::ACES_GLOW_10_FWD:
    case FixedFunctionOpData::ACES_GLOW_10_INV:
        return FIXED_FUNCTION_ACES_GLOW_10;

    case FixedFunctionOpData::ACES_DARK_TO_DIM_10_FWD:
    case FixedFunctionOpData::ACES_DARK_TO_DIM_10_INV:
        return FIXED_FUNCTION_ACES_DARK_TO_DIM_10;

    case FixedFunctionOpData::REC2100_SURROUND_FWD:
    case FixedFunctionOpData::REC2100_SURROUND_INV:
        return FIXED_FUNCTION_REC2100_SURROUND;

    case FixedFunctionOpData::RGB_TO_HSV:
    case FixedFunctionOpData::HSV_TO_RGB:
        return FIXED_FUNCTION_RGB_TO_HSV;

    case FixedFunctionOpData::XYZ_TO_xyY:
    case FixedFunctionOpData::xyY_TO_XYZ:
        return FIXED_FUNCTION_XYZ_TO_xyY;

    case FixedFunctionOpData::XYZ_TO_uvY:
    case FixedFunctionOpData::uvY_TO_XYZ:
        return FIXED_FUNCTION_XYZ_TO_uvY;

    case FixedFunctionOpData::XYZ_TO_LUV:
    case FixedFunctionOpData::LUV_TO_XYZ:
        return FIXED_FUNCTION_XYZ_TO_LUV;
    }

    std::stringstream ss("Unknown FixedFunction style: ");
    ss << style;

    throw Exception(ss.str().c_str());
}

FixedFunctionOpData::FixedFunctionOpData()
    :   OpData()
    ,   m_style(ACES_RED_MOD_03_FWD)
{
}

FixedFunctionOpData::FixedFunctionOpData(Style style)
    :   OpData()
    ,   m_style(style)
{
    validate();
}

FixedFunctionOpData::FixedFunctionOpData(const Params & params, Style style)
    :   OpData()
    ,   m_style(style)
    ,   m_params(params)
{
    validate();
}

FixedFunctionOpData::~FixedFunctionOpData()
{
}

FixedFunctionOpDataRcPtr FixedFunctionOpData::clone() const
{
    return std::make_shared<FixedFunctionOpData>(getParams(), getStyle());
}

void FixedFunctionOpData::validate() const
{
    OpData::validate();

    if(m_style==REC2100_SURROUND_FWD || m_style == REC2100_SURROUND_INV)
    {
        if (m_params.size() != 1)
        {
            std::stringstream ss;
            ss  << "The style '" << ConvertStyleToString(m_style, true) 
                << "' must have one parameter but " 
                << m_params.size() << " found.";
            throw Exception(ss.str().c_str());
        }

        const double p = m_params[0];
        const double low_bound = 0.01;
        const double hi_bound  = 100.;

        if (p < low_bound)
        {
            std::stringstream ss;
            ss << "Parameter " << p << " is less than lower bound " << low_bound;
            throw Exception(ss.str().c_str());
        }
        else if (p > hi_bound)
        {
            std::stringstream ss;
            ss << "Parameter " << p << " is greater than upper bound " << hi_bound;
            throw Exception(ss.str().c_str());
        }
    }
    else
    {
        if(m_params.size()!=0)
        {
            std::stringstream ss;
            ss  << "The style '" << ConvertStyleToString(m_style, true) 
                << "' must have zero parameters but " 
                << m_params.size() << " found.";
            throw Exception(ss.str().c_str());
        }
    }
}

bool FixedFunctionOpData::isInverse(ConstFixedFunctionOpDataRcPtr & r) const
{
    const auto thisStyle = getStyle();
    if (REC2100_SURROUND_FWD == thisStyle || REC2100_SURROUND_INV == thisStyle)
    {
        // Check for the case where the styles are the same but the parameter is inverted.
        if (thisStyle == r->getStyle())
        {
            return m_params[0] == 1. / r->m_params[0];
        }
    }
    return *r == *inverse();
}

void FixedFunctionOpData::invert()
{
    // NB: The following assumes the op has already been validated.

    switch(getStyle())
    {
        case ACES_RED_MOD_03_FWD:
        {
            setStyle(ACES_RED_MOD_03_INV);
            break;
        }
        case ACES_RED_MOD_03_INV:
        {
            setStyle(ACES_RED_MOD_03_FWD);
            break;
        }
        case ACES_RED_MOD_10_FWD:
        {
            setStyle(ACES_RED_MOD_10_INV);
            break;
        }
        case ACES_RED_MOD_10_INV:
        {
            setStyle(ACES_RED_MOD_10_FWD);
            break;
        }
        case ACES_GLOW_03_FWD:
        {
            setStyle(ACES_GLOW_03_INV);
            break;
        }
        case ACES_GLOW_03_INV:
        {
            setStyle(ACES_GLOW_03_FWD);
            break;
        }
        case ACES_GLOW_10_FWD:
        {
            setStyle(ACES_GLOW_10_INV);
            break;
        }
        case ACES_GLOW_10_INV:
        {
            setStyle(ACES_GLOW_10_FWD);
            break;
        }
        case ACES_DARK_TO_DIM_10_FWD:
        {
            setStyle(ACES_DARK_TO_DIM_10_INV);
            break;
        }
        case ACES_DARK_TO_DIM_10_INV:
        {
            setStyle(ACES_DARK_TO_DIM_10_FWD);
            break;
        }
        case REC2100_SURROUND_FWD:
        {
            setStyle(REC2100_SURROUND_INV);
            break;
        }
        case REC2100_SURROUND_INV:
        {
            setStyle(REC2100_SURROUND_FWD);
            break;
        }

        case RGB_TO_HSV:
        {
            setStyle(HSV_TO_RGB);
            break;
        }
        case HSV_TO_RGB:
        {
            setStyle(RGB_TO_HSV);
            break;
        }

        case XYZ_TO_xyY:
        {
            setStyle(xyY_TO_XYZ);
            break;
        }
        case xyY_TO_XYZ:
        {
            setStyle(XYZ_TO_xyY);
            break;
        }

        case XYZ_TO_uvY:
        {
            setStyle(uvY_TO_XYZ);
            break;
        }
        case uvY_TO_XYZ:
        {
            setStyle(XYZ_TO_uvY);
            break;
        }

        case XYZ_TO_LUV:
        {
            setStyle(LUV_TO_XYZ);
            break;
        }
        case LUV_TO_XYZ:
        {
            setStyle(XYZ_TO_LUV);
            break;
        }
    }

    // Note that any existing metadata could become stale at this point but
    // trying to update it is also challenging since inverse() is sometimes
    // called even during the creation of new ops.
}

FixedFunctionOpDataRcPtr FixedFunctionOpData::inverse() const
{
    FixedFunctionOpDataRcPtr func = clone();
    func->invert();
    return func;
}

// Convert internal OpData style into Transform direction.
TransformDirection FixedFunctionOpData::getDirection() const
{
    switch (m_style)
    {
    case FixedFunctionOpData::ACES_RED_MOD_03_FWD:
    case FixedFunctionOpData::ACES_RED_MOD_10_FWD:
    case FixedFunctionOpData::ACES_GLOW_03_FWD:
    case FixedFunctionOpData::ACES_GLOW_10_FWD:
    case FixedFunctionOpData::ACES_DARK_TO_DIM_10_FWD:
    case FixedFunctionOpData::REC2100_SURROUND_FWD:
    case FixedFunctionOpData::RGB_TO_HSV:
    case FixedFunctionOpData::XYZ_TO_xyY:
    case FixedFunctionOpData::XYZ_TO_uvY:
    case FixedFunctionOpData::XYZ_TO_LUV:
        return TRANSFORM_DIR_FORWARD;

    case FixedFunctionOpData::ACES_RED_MOD_03_INV:
    case FixedFunctionOpData::ACES_RED_MOD_10_INV:
    case FixedFunctionOpData::ACES_GLOW_03_INV:
    case FixedFunctionOpData::ACES_GLOW_10_INV:
    case FixedFunctionOpData::ACES_DARK_TO_DIM_10_INV:
    case FixedFunctionOpData::REC2100_SURROUND_INV:
    case FixedFunctionOpData::HSV_TO_RGB:
    case FixedFunctionOpData::xyY_TO_XYZ:
    case FixedFunctionOpData::uvY_TO_XYZ:
    case FixedFunctionOpData::LUV_TO_XYZ:
        return TRANSFORM_DIR_INVERSE;
    }
    return TRANSFORM_DIR_FORWARD;
}

void FixedFunctionOpData::setDirection(TransformDirection dir)
{
    if (dir != TRANSFORM_DIR_UNKNOWN)
    {
        const auto curDir = getDirection();
        if (curDir != dir)
        {
            invert();
        }
    }
}

bool FixedFunctionOpData::operator==(const OpData & other) const
{
    if (!OpData::operator==(other)) return false;

    const FixedFunctionOpData* fop = static_cast<const FixedFunctionOpData*>(&other);

    return getStyle() == fop->getStyle() && getParams()==fop->getParams();
}

void FixedFunctionOpData::finalize()
{
    AutoMutex lock(m_mutex);

    validate();

    std::ostringstream cacheIDStream;
    cacheIDStream << getID();

    cacheIDStream.precision(DefaultValues::FLOAT_DECIMALS);

    cacheIDStream << ConvertStyleToString(m_style, true) << " ";

    for( auto param: m_params ) cacheIDStream << param << " ";

    m_cacheID = cacheIDStream.str();
}

} // namespace OCIO_NAMESPACE

