#pragma once
#include "models/GameModel.h"
#include "configs/LevelConfig.h"

/// <summary>
/// ����㣬���չؿ���Ž���Ӧ�ؿ�������ת��ΪGameModelʵ��
/// </summary>
class GameModelFromLevelGenerator
{
public:
	/// <summary>
	/// ���ݹؿ���Ż�ȡ��ӦGameModelʵ��
	/// </summary>
	/// <param name="level">�ؿ����</param>
	/// <returns>GameModelʵ��</returns>
	static GameModel* getGameModel(int level);
};
