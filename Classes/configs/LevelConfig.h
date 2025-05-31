#pragma once
#include "cocos2d.h"
#include "json/document.h"

USING_NS_CC;
using namespace rapidjson;

/// <summary>
/// 用于管理所有levelConfig资源（用<int,Document>键值对进行存储
/// </summary>
class LevelConfig {
private:
	static std::map<int, Document*>* levels;
public:
	/// <summary>
	/// 注册levelConfig
	/// </summary>
	/// <param name="level">关卡编号</param>
	/// <param name="config">关卡具体配置</param>
	static void registerLevel(int level, Document* config);

	/// <summary>
	/// 根据关卡编号获取具体配置
	/// </summary>
	/// <param name="level">关卡编号</param>
	/// <returns></returns>
	static Document* getLevelConfig(int level);
};