#pragma once
#include "cocos2d.h"
#include "json/document.h"

USING_NS_CC;
using namespace rapidjson;

/// <summary>
/// ���ڹ�������levelConfig��Դ����<int,Document>��ֵ�Խ��д洢
/// </summary>
class LevelConfig {
private:
	static std::map<int, Document*>* levels;
public:
	/// <summary>
	/// ע��levelConfig
	/// </summary>
	/// <param name="level">�ؿ����</param>
	/// <param name="config">�ؿ���������</param>
	static void registerLevel(int level, Document* config);

	/// <summary>
	/// ���ݹؿ���Ż�ȡ��������
	/// </summary>
	/// <param name="level">�ؿ����</param>
	/// <returns></returns>
	static Document* getLevelConfig(int level);
};