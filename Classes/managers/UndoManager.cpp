#include "UndoManager.h"

void UndoManager::joinUndoModel(UndoModel* model)
{
	undoStack->push(model);
}

void UndoManager::popTopModel()
{
	undoStack->pop();
}

UndoModel* UndoManager::getTopModel()
{
	return undoStack->top();
}

void UndoManager::init()
{
	undoStack = new std::stack<UndoModel*>;
}

