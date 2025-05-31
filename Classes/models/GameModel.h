#pragma once
#include "cocos2d.h"
#include "CardStack.h"

/// <summary>
/// ��Ϊһ����Ϸ��ģ�ͣ���¼�����������������������п�Ƭ��Ϣ
/// </summary>
class GameModel
{
private:
	CardStack* _playField;
	CardStack* _stack;

public:
	GameModel(CardStack* playField, CardStack* stack) : _playField(playField), _stack(stack){}

	/// <summary>
	/// ���л�����
	/// </summary>
	/// <returns>json�ַ���</returns>
	std::string toJson() const;

	/// <summary>
	/// �����л�����
	/// </summary>
	/// <param name="json">json�ַ���</param>
	/// <returns>ʵ����GameModel����</returns>
	static GameModel* fromJson(const std::string& json);

	CardStack* getPlayField();

	CardStack* getStack();
};