#pragma once
#include "cocos2d.h"
#include "json/document.h"
#include "json/writer.h"
#include "json/stringbuffer.h"

USING_NS_CC;
using namespace rapidjson;

/// <summary>
/// ���ڴ��Card���ݵ�������
/// </summary>
class CardModel {
public:
    /// <summary>
    /// ��ɫ����
    /// </summary>
    enum CardSuitType
    {
        CST_NONE = -1,
        CST_CLUBS,      // ÷��
        CST_DIAMONDS,   // ����
        CST_HEARTS,     // ����
        CST_SPADES,     // ����
        CST_NUM_CARD_SUIT_TYPES
    };

    /// <summary>
    /// ������ֵ����
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
	/// ��ȡ�������õ�λ��
	/// </summary>
	/// <returns>Ԥ��λ��</returns>
	Vec2 getPosition() const;
	
	/// <summary>
	/// ���л������������������л�Ϊrapidjson::Value����
	/// </summary>
	/// <param name="out">���Ŀ��Value����</param>
	/// <param name="allocator">��ż�ֵ�ķ�����</param>
	void toJson(rapidjson::Value& out, rapidjson::Document::AllocatorType& allocator) const;

	/// <summary>
	/// �����л���������json��Value�����ȡ��Card����
	/// </summary>
	/// <param name="value">����ȡ��json����</param>
	/// <returns>ʵ����Card����</returns>
	static CardModel* fromJson(rapidjson::Value& value);

    /// <summary>
    /// ��ȡ��res��Դ���ļ�������
    /// </summary>
    /// <returns>��Դ����</returns>
    std::string getResName() const;

    /// <summary>
    /// ��ȡ��ɫ����
    /// </summary>
    /// <returns>��ɫstring��club,heart,spade,diamond��</returns>
    std::string getSuitName() const;
    
};