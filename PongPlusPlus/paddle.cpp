#include "paddle.h"

void Paddle::movePaddle() {
	switch (direction_) {
	case kUp:
		position_y += speed;
	case kDown:
		position_y -= speed;
	}
}