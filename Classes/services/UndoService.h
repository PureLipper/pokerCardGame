#pragma once
#include "models/CardModel.h"

/// <summary>
/// ���������ṩ�ж��Ƿ�����滻���߼�
/// </summary>
class UndoService
{
public:
	/// <summary>
	/// �ж�m1�Ƿ�����滻m2
	/// </summary>
	/// <param name="m1">�滻��</param>
	/// <param name="m2">���滻��</param>
	/// <returns>�Ƿ�����滻</returns>
	static bool ifMatch(CardModel* m1, CardModel* m2);
};
