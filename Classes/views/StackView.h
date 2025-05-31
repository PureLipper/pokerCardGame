#pragma once

#include "cocos2d.h"
USING_NS_CC;

/// <summary>
/// 手牌区视图
/// </summary>
class StackView : public Node
{
private:
	/// <summary>
	/// 对StackView进行初始化
	/// </summary>
	/// <returns>是否初始化成功</returns>
	bool _init();

public:
	/// <summary>
	/// 创建StackView对象
	/// </summary>
	/// <returns>实例化的StackView对象</returns>
	static StackView* create();

};
