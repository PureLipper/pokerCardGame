#include "GameController.h"

#include "configs/CardResConfig.h"
#include "configs/LevelConfigLoader.h"
#include "services/GameModelFromLevelGenerator.h"

GameController* GameController::instance = nullptr;

GameController::GameController()
{
}

GameController::~GameController()
{
	delete instance;
	instance = nullptr;
	delete _gameModel;
}


void GameController::initGame(Size s)
{
	CardResConfig::loadAllResource();
	LevelConfigLoader::loadAllLevelConfig();
	designedSize = s;
}

GameController* GameController::getInstance()
{
	if (instance == nullptr)
	{
		instance = new GameController();
	}
	return instance;
}

GameModel* GameController::getCurrentGameModel() const
{
	return _gameModel;
}

void GameController::addUndoHistory(UndoModel* undoModel)
{
	_undoManager->joinUndoModel(undoModel);
}

void GameController::startGame(int level)
{
	_gameModel = GameModelFromLevelGenerator::getGameModel(level);

	_playFieldController = new PlayFieldController(_gameModel->getPlayField());
	_stackController = new StackController(_gameModel->getStack());
	_undoManager = new UndoManager();

	_playFieldController->init();
	_stackController->init();
	_undoManager->init();

	_gameView = GameView::create(designedSize);
	
	auto playFieldView = _playFieldController->getPlayFieldView();
	playFieldView->setPosition(0, _gameView->getContentSize().height - playFieldView->getContentSize().height);
	
	_gameView->addChild(_stackController->getStackView());
	_gameView->addChild(playFieldView);
}

GameModel* GameController::getGameModel() const
{
	return _gameModel;
}

GameView* GameController::getGameView() const
{
	return _gameView;
}

void GameController::addViewToScene(Scene* Node) const
{
	Node->addChild(_gameView);
	auto s = Director::getInstance()->getVisibleSize();
	auto ds = designedSize;
	_gameView->setPosition((s.width - ds.width) / 2, (s.height - ds.height) / 2);
}

PlayFieldController* GameController::getPlayFieldController() const
{
	return _playFieldController;
}

StackController* GameController::getStackController() const
{
	return _stackController;
}

UndoManager* GameController::getUndoManager() const
{
	return _undoManager;
}

void GameController::setBackspaceAvailable(bool f) const
{
	_stackController->setBackspaceAvailable(f);
}
