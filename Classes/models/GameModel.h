#pragma once
#include "cocos2d.h"
#include "CardStack.h"

/// <summary>
/// 作为一场游戏的模型，记录了手牌区和桌面牌区的所有卡片信息
/// </summary>
class GameModel
{
private:
	CardStack* _playField;
	CardStack* _stack;

public:
	GameModel(CardStack* playField, CardStack* stack) : _playField(playField), _stack(stack){}

	/// <summary>
	/// 序列化方法
	/// </summary>
	/// <returns>json字符串</returns>
	std::string toJson() const;

	/// <summary>
	/// 反序列化方法
	/// </summary>
	/// <param name="json">json字符串</param>
	/// <returns>实例化GameModel对象</returns>
	static GameModel* fromJson(const std::string& json);

	CardStack* getPlayField();

	CardStack* getStack();
};