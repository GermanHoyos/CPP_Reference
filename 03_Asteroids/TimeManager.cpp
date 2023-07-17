#include <raylib.h>
#include "TimeManager.h"
#pragma once

float TimeUtils::getDeltaTime(){
	return GetFrameTime();
};

int TimeUtils::getFPS() {
	return GetFPS();
};