#include "Transform.h"

namespace Skyers
{
    bool Transform::Write(const rapidjson::Value& value) const
    {
        return true;
    }

    bool Transform::Read(const rapidjson::Value& value)
    {
        READ_DATA(value, rotation); 
        READ_DATA(value, position);
        READ_DATA(value, scale);


        return true;
    }

}

