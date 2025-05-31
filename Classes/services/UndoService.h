#pragma once
#include "models/CardModel.h"

/// <summary>
/// 服务器，提供判断是否接受替换的逻辑
/// </summary>
class UndoService
{
public:
	/// <summary>
	/// 判断m1是否可以替换m2
	/// </summary>
	/// <param name="m1">替换牌</param>
	/// <param name="m2">被替换牌</param>
	/// <returns>是否接受替换</returns>
	static bool ifMatch(CardModel* m1, CardModel* m2);
};
