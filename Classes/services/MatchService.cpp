#include "MatchService.h"

bool MatchService::ifMatch(CardModel* m1, CardModel* m2)
{
	if (abs(m1->getCardFace() - m2->getCardFace()) == 1)
	{
		return true;
	}else
	{
		return false;
	}
}
