#pragma once
#include "models/CardModel.h"

/// <summary>
/// 服务层，处理替换的逻辑
/// </summary>
class ReplaceService
{
public:
	/// <summary>
	/// 尝试进行一次替换
	/// </summary>
	/// <param name="m">准备进行替换的卡牌（用户点击的卡牌）</param>
	/// <returns>是否进行了替换（替换成功）</returns>
	static bool replace(CardModel* m);
};
