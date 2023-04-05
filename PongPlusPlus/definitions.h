#ifndef DEFINITIONS_H
#define DEFINITIONS_H

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

#endif // !DEFINITIONS_H