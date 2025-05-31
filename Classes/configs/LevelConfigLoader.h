#pragma once
#include "cocos2d.h"
#include "json/document.h"
#include "LevelConfig.h"

USING_NS_CC;
using namespace rapidjson;

/// <summary>
/// �ؿ����ü�����
/// </summary>
class LevelConfigLoader {
private:

	/// <summary>
	/// ��̬���ùؿ������ļ���·��
	/// </summary>
	static const std::string kConfigFolderPath;

public:
	/// <summary>
	/// ʹ���趨��·�����عؿ���ԴlevelConfig.json
	/// </summary>
	static void loadAllLevelConfig();
};