#pragma once
#include "PlayFieldController.h"
#include "StackController.h"
#include "managers/UndoManager.h"
#include "models/GameModel.h"
#include "views/GameView.h"

/// <summary>
/// ��Ϸ��������������Ϸ���̣�ʹ�õ���ģʽ
/// </summary>
class GameController
{
private:
	static GameController* instance;//����ʵ��

	Size designedSize;//Ԥ��ߴ�
	GameModel* _gameModel;//��Ϸģ��
	GameView* _gameView;//��Ϸ��ͼ

	PlayFieldController* _playFieldController;//��������������
	StackController* _stackController;//������������
	UndoManager* _undoManager;//���˹�����

	GameController();
	~GameController();

public:
	static GameController* getInstance();

	void initGame(Size);

	/// <summary>
	/// ��UndoManager���һ����¼
	/// </summary>
	/// <param name="undoModel"></param>
	void addUndoHistory(UndoModel* undoModel);

	/// <summary>
	/// ��ʼ��Ϸ
	/// </summary>
	/// <param name="level">ѡ��Ĺؿ����</param>
	void startGame(int level);

	/// <summary>
	/// ���������е���ͼ��ӵ�������
	/// </summary>
	/// <param name="Node">Ŀ�곡��</param>
	void addViewToScene(Scene* Node) const;

	void setBackspaceAvailable(bool) const;

	GameModel* getCurrentGameModel() const;
	GameView* getGameView() const;
	GameModel* getGameModel() const;
	PlayFieldController* getPlayFieldController() const;
	StackController* getStackController() const;
	UndoManager* getUndoManager() const;
};
