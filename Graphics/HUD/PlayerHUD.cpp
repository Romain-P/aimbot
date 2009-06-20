#include "PlayerHUD.h"
#include "../../Game/Updater.h"

void PlayerHUD::drawFPS()
{
	if(updater->getFrames() % 5 == 0)
	{
		ss << updater->getFps();
		//drawText(ss.str(), 40, 40);
		ss.clear();
	}
}
