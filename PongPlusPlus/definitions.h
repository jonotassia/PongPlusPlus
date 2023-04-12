#ifndef DEFINITIONS_H
#define DEFINITIONS_H

#include <random>
#include <time.h>

const int WINDOW_WIDTH = 1280;
const int WINDOW_HEIGHT = 720;

enum class PowerUps {
	kNone = 0,
	kFire = 1,
	kIce = 2,
	kSun = 3,
	kShadow = 4,
	kConfusion = 5
};

enum class Direction {
	kNone,
	kUp,
	kDown,
	kLeft,
	kRight
};

static std::mt19937 MTE(time(nullptr));

#endif // !DEFINITIONS_H