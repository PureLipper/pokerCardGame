#pragma once
#include "CardModel.h"

/// <summary>
/// ��¼һ�β�����UndoManager���Ը��ݴ˲������лص�
/// </summary>
class UndoModel
{
private:

	/// <summary>
	/// �����ж��������ƶ����ƣ�����Ŀ��ƣ�
	/// </summary>
	CardModel* _moveCard;

	/// <summary>
	/// �����ж����Ƴ����ƣ����ƶ����ƣ�
	/// </summary>
	CardModel* _removeCard;

public:
	UndoModel(CardModel*, CardModel*);

	CardModel* getMoveCard() const;

	CardModel* getRemoveCard() const;

	//Document* toJsonDocument();

	//UndoModel* fromJson(const std::string& json);

};