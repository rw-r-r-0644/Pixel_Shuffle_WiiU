#pragma once
#include <stdint.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

typedef enum
{
	KEY_A    = (1 << 0),  KEY_B     = (1 << 1),
	KEY_X    = (1 << 2),  KEY_Y     = (1 << 3),
	KEY_UP   = (1 << 4),  KEY_DOWN  = (1 << 5),
	KEY_LEFT = (1 << 6),  KEY_RIGHT = (1 << 7),
	KEY_PLUS = (1 << 8),  KEY_TOUCH = (1 << 9),
    KEY_L    = (1 << 10), KEY_R     = (1 << 11),
} sdlKeys;

typedef struct
{
	uint32_t px;
	uint32_t py;
} sdlTouch;

void sdlScanInput(void);
uint32_t sdlKeysUp(void);
uint32_t sdlKeysDown(void);
uint32_t sdlKeysHeld(void);
void sdlTouchRead(sdlTouch *touch);

