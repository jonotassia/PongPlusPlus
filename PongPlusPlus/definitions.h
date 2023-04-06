#ifndef DEFINITIONS_H
#define DEFINITIONS_H

#include <random>
#include <time.h>

const int WINDOW_WIDTH = 1280;
const int WINDOW_HEIGHT = 720;

enum class PowerUps {
	kNone,
	kFire,
	kIce,
	kSun,
	kShadow,
	kSniper
};

enum class Direction {
	kNone,
	kUp,
	kDown,
	kLeft,
	kRight
};

static std::mt19937 MTE{};

#endif // !DEFINITIONS_H