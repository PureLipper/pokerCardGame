#pragma once

#include "cocos2d.h"
#include "json/document.h"
#include "json/stringbuffer.h"
#include "json/writer.h"

using namespace rapidjson;

/// <summary>
/// Json常用方法
/// </summary>
class JsonUtils
{
public:
	/*static std::string toString(Document* jsonObject)
	{
		StringBuffer buffer;
		Writer<StringBuffer> writer(buffer);
		jsonObject->Accept(writer);
		return std::string(buffer.GetString());
	}*/
	static std::string toString(rapidjson::Value* jsonObject)
	{
		StringBuffer buffer;
		Writer<StringBuffer> writer(buffer);
		jsonObject->Accept(writer);
		return std::string(buffer.GetString());
	}
};