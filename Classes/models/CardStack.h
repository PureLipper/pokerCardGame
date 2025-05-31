#pragma once

#include "CardModel.h"

USING_NS_CC;
using namespace rapidjson;

/// <summary>
/// ���ƶѣ����ڴ��һ�鿨������
/// </summary>
class CardStack {
private:
	std::vector<CardModel*> _cardList;

public:
	CardStack(){}

	~CardStack();

	/// <summary>
	/// ��ӿ���
	/// </summary>
	/// <param name="card">���ƶ���ָ��</param>
	void appendCard(CardModel* card);

	/// <summary>
	/// ��տ���
	/// </summary>
	void clearCard();

	std::vector<CardModel*>* getCardList();

	/// <summary>
	/// ���л�����
	/// </summary>
	/// <returns>json�ַ���</returns>
	std::string toJson() const;

	/// <summary>
	/// �����л�����
	/// </summary>
	/// <param name="json">json�ַ���</param>
	/// <returns>ʵ������CardStack����</returns>
	static CardStack* fromJson(const std::string& json);
};