#include "LevelConfig.h"

std::map<int, Document*>* LevelConfig::levels = new std::map<int, Document*>();

void LevelConfig::registerLevel(int level, Document* config)
{
	levels->emplace(level, config);
}

Document* LevelConfig::getLevelConfig(int level)
{
	return (*levels)[level];
}