#pragma once
#include "PlayFieldController.h"
#include "StackController.h"
#include "managers/UndoManager.h"
#include "models/GameModel.h"
#include "views/GameView.h"

/// <summary>
/// 游戏控制器，控制游戏流程，使用单例模式
/// </summary>
class GameController
{
private:
	static GameController* instance;//单例实例

	GameModel* _gameModel;//游戏模型
	GameView* _gameView;//游戏视图

	PlayFieldController* _playFieldController;//桌面牌区控制器
	StackController* _stackController;//手牌区控制器
	UndoManager* _undoManager;//回退管理器

	GameController();
	~GameController();

public:
	static GameController* getInstance();

	void initGame();

	/// <summary>
	/// 给UndoManager添加一条记录
	/// </summary>
	/// <param name="undoModel"></param>
	void addUndoHistory(UndoModel* undoModel);

	/// <summary>
	/// 开始游戏
	/// </summary>
	/// <param name="level">选择的关卡编号</param>
	void startGame(int level);

	/// <summary>
	/// 将控制器中的视图添加到场景中
	/// </summary>
	/// <param name="Node">目标场景</param>
	void addViewToScene(Scene* Node) const;

	void setBackspaceAvailable(bool) const;

	GameModel* getCurrentGameModel() const;
	GameView* getGameView() const;
	GameModel* getGameModel() const;
	PlayFieldController* getPlayFieldController() const;
	StackController* getStackController() const;
	UndoManager* getUndoManager() const;
};
