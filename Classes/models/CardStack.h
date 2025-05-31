#pragma once

#include "CardModel.h"

USING_NS_CC;
using namespace rapidjson;

/// <summary>
/// 卡牌堆，用于存放一组卡牌数据
/// </summary>
class CardStack {
private:
	std::vector<CardModel*> _cardList;

public:
	CardStack(){}

	~CardStack();

	/// <summary>
	/// 添加卡牌
	/// </summary>
	/// <param name="card">卡牌对象指针</param>
	void appendCard(CardModel* card);

	/// <summary>
	/// 清空卡牌
	/// </summary>
	void clearCard();

	std::vector<CardModel*>* getCardList();

	/// <summary>
	/// 序列化方法
	/// </summary>
	/// <returns>json字符串</returns>
	std::string toJson() const;

	/// <summary>
	/// 反序列化方法
	/// </summary>
	/// <param name="json">json字符串</param>
	/// <returns>实例化的CardStack对象</returns>
	static CardStack* fromJson(const std::string& json);
};