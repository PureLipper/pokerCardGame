#pragma once
#include "cocos2d.h"
#include "json/document.h"
#include "json/writer.h"
#include "json/stringbuffer.h"

USING_NS_CC;
using namespace rapidjson;

/// <summary>
/// 用于存放Card数据的数据类
/// </summary>
class CardModel {
public:
    /// <summary>
    /// 花色类型
    /// </summary>
    enum CardSuitType
    {
        CST_NONE = -1,
        CST_CLUBS,      // 梅花
        CST_DIAMONDS,   // 方块
        CST_HEARTS,     // 红桃
        CST_SPADES,     // 黑桃
        CST_NUM_CARD_SUIT_TYPES
    };

    /// <summary>
    /// 卡牌面值类型
    /// </summary>
    enum CardFaceType
    {
        CFT_NONE = -1,
        CFT_ACE,
        CFT_TWO,
        CFT_THREE,
        CFT_FOUR,
        CFT_FIVE,
        CFT_SIX,
        CFT_SEVEN,
        CFT_EIGHT,
        CFT_NINE,
        CFT_TEN,
        CFT_JACK,
        CFT_QUEEN,
        CFT_KING,
        CFT_NUM_CARD_FACE_TYPES
    };

private:
    CardFaceType _cardFace;
    CardSuitType _cardSuit;
	Vec2 _position;

public:
	CardModel(CardFaceType cardFace, CardSuitType cardSuit, const Vec2& pos);

	~CardModel();

	int getCardFace() const;

	int getCardSuit() const;

	/// <summary>
	/// 获取卡牌配置的位置
	/// </summary>
	/// <returns>预定位置</returns>
	Vec2 getPosition() const;
	
	/// <summary>
	/// 序列化方法，将调用者序列化为rapidjson::Value对象
	/// </summary>
	/// <param name="out">输出目标Value对象</param>
	/// <param name="allocator">存放键值的分配器</param>
	void toJson(rapidjson::Value& out, rapidjson::Document::AllocatorType& allocator) const;

	/// <summary>
	/// 反序列化方法，将json的Value对象读取成Card对象
	/// </summary>
	/// <param name="value">待读取的json对象</param>
	/// <returns>实例化Card对象</returns>
	static CardModel* fromJson(rapidjson::Value& value);

    /// <summary>
    /// 获取在res资源中文件的名字
    /// </summary>
    /// <returns>资源名称</returns>
    std::string getResName() const;

    /// <summary>
    /// 获取花色名字
    /// </summary>
    /// <returns>花色string（club,heart,spade,diamond）</returns>
    std::string getSuitName() const;
    
};