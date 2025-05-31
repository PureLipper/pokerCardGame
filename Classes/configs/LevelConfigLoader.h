#pragma once
#include "cocos2d.h"
#include "json/document.h"
#include "LevelConfig.h"

USING_NS_CC;
using namespace rapidjson;

/// <summary>
/// 关卡配置加载器
/// </summary>
class LevelConfigLoader {
private:

	/// <summary>
	/// 静态配置关卡配置文件的路径
	/// </summary>
	static const std::string kConfigFolderPath;

public:
	/// <summary>
	/// 使用予定的路径加载关卡资源levelConfig.json
	/// </summary>
	static void loadAllLevelConfig();
};