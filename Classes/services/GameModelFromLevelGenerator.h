#pragma once
#include "models/GameModel.h"
#include "configs/LevelConfig.h"

/// <summary>
/// 服务层，按照关卡编号将对应关卡的配置转化为GameModel实例
/// </summary>
class GameModelFromLevelGenerator
{
public:
	/// <summary>
	/// 根据关卡编号获取对应GameModel实例
	/// </summary>
	/// <param name="level">关卡编号</param>
	/// <returns>GameModel实例</returns>
	static GameModel* getGameModel(int level);
};
