#include "Core/Logger.h"
#include "Json.h"
#include "rapidjson/istreamwrapper.h"
#include "Math/Vector2.h"
#include "Math/Color.h"
#include <fstream>

namespace Skyers
{

	bool json::Load(const std::string& filename, rapidjson::Document& document)
	{
		// !! create a std::ifstream object called stream 
		// !! check if it is open, if not use LOG to print error and return false 
	// !! https://riptutorial.com/cplusplus/example/1625/opening-a-file 

		std::ifstream stream(filename);
		if (stream.is_open() == false)
		{
			LOG("Opening file name %s", filename.c_str());
			return false;
		}

		rapidjson::IStreamWrapper istream(stream);
		document.ParseStream(istream);
		if (document.IsObject() == false)
		{
			LOG("json file cannot be read %s.", filename.c_str());
			return false;
		}

		return true;
	}

	bool json::Get(const rapidjson::Value& value, const std::string& name, int& data)
	{
		if (value.HasMember(name.c_str()) == false || value[name.c_str()].IsInt() == false)
		{
			LOG("Error reading Json data %s", name.c_str());
			return false;
		}
		
		data = value[name.c_str()].GetInt();

		return true;
	}

	bool json::Get(const rapidjson::Value& value, const std::string& name, float& data)
	{
		return false;
	}


	bool json::Get(const rapidjson::Value& value, const std::string& name, bool& data)
	{
		return false;
	}

	bool json::Get(const rapidjson::Value& value, const std::string& name, std::string& data)
	{
		return false;
	}

	bool json::Get(const rapidjson::Value& value, const std::string& name, Vector2& data)
	{
		return false;
	}

	bool json::Get(const rapidjson::Value& value, const std::string& name, Color& data)
	{
		return false;
	}


}