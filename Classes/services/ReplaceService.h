#pragma once
#include "models/CardModel.h"

/// <summary>
/// ����㣬�����滻���߼�
/// </summary>
class ReplaceService
{
public:
	/// <summary>
	/// ���Խ���һ���滻
	/// </summary>
	/// <param name="m">׼�������滻�Ŀ��ƣ��û�����Ŀ��ƣ�</param>
	/// <returns>�Ƿ�������滻���滻�ɹ���</returns>
	static bool replace(CardModel* m);
};
