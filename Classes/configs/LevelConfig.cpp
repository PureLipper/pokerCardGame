#include "LevelConfig.h"

std::map<int, Document*>* LevelConfig::_levels = new std::map<int, Document*>();

void LevelConfig::registerLevel(int level, Document* config)
{
	_levels->emplace(level, config);
}

Document* LevelConfig::getLevelConfig(int level)
{
	return (*_levels)[level];
}