#pragma once
#include "cocos2d.h"

USING_NS_CC;

/// <summary>
/// 用于静态加载所有图像资源，无需实例化
/// </summary>
class CardResConfig {
public:
	/// <summary>
	/// 加载所有资源
	/// </summary>
	static void loadAllResource();
};