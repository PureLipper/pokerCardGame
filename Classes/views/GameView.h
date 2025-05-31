#pragma once
#include "cocos2d.h"

USING_NS_CC;

/// <summary>
/// 游戏视图，含有一场游戏中所有的视图
/// </summary>
class GameView : public Node
{
private:

	/// <summary>
	/// 对GameView进行初始化
	/// </summary>
	/// <returns>是否初始化成功</returns>
	bool _init();

public:
	/// <summary>
	/// 创建GameView对象
	/// </summary>
	/// <param name="gm">绑定的GameModel对象</param>
	/// <returns>实例化的GameView对象</returns>
	static GameView* create();
};