#include "input.h"
#include <stdint.h>

static uint32_t sdlkDown = 0, sdlkHeld = 0, sdlkUp = 0, sdlpx = 0, sdlpy = 0;

void sdlScanInput(void)
{
	sdlkDown = 0;
	sdlkUp = 0;

	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_JOYBUTTONDOWN)
		{
			sdlkDown |= ((event.jbutton.button == 0) ? KEY_A : 0);
			sdlkDown |= ((event.jbutton.button == 1) ? KEY_B : 0);
			sdlkDown |= ((event.jbutton.button == 2) ? KEY_X : 0);
			sdlkDown |= ((event.jbutton.button == 3) ? KEY_Y : 0);
			sdlkDown |= ((event.jbutton.button == 6) ? KEY_L : 0);
			sdlkDown |= ((event.jbutton.button == 7) ? KEY_R : 0);
			sdlkDown |= ((event.jbutton.button == 13) ? KEY_UP : 0);
			sdlkDown |= ((event.jbutton.button == 15) ? KEY_DOWN : 0);
			sdlkDown |= ((event.jbutton.button == 12) ? KEY_LEFT : 0);
			sdlkDown |= ((event.jbutton.button == 14) ? KEY_RIGHT : 0);
			sdlkDown |= ((event.jbutton.button == 10) ? KEY_PLUS : 0);
		}
		if (event.type == SDL_JOYBUTTONUP)
		{
			sdlkUp |= ((event.jbutton.button == 0) ? KEY_A : 0);
			sdlkUp |= ((event.jbutton.button == 1) ? KEY_B : 0);
			sdlkUp |= ((event.jbutton.button == 2) ? KEY_X : 0);
			sdlkUp |= ((event.jbutton.button == 3) ? KEY_Y : 0);
			sdlkUp |= ((event.jbutton.button == 6) ? KEY_L : 0);
			sdlkUp |= ((event.jbutton.button == 7) ? KEY_R : 0);
			sdlkUp |= ((event.jbutton.button == 13) ? KEY_UP : 0);
			sdlkUp |= ((event.jbutton.button == 15) ? KEY_DOWN : 0);
			sdlkUp |= ((event.jbutton.button == 12) ? KEY_LEFT : 0);
			sdlkUp |= ((event.jbutton.button == 14) ? KEY_RIGHT : 0);
			sdlkUp |= ((event.jbutton.button == 10) ? KEY_PLUS : 0);
		}
		if (event.type == SDL_FINGERDOWN || event.type == SDL_FINGERMOTION)
		{
			sdlkDown |= KEY_TOUCH;
			sdlpx = event.tfinger.y * 1080;
			sdlpy = event.tfinger.x * 1920;
		}
		if (event.type == SDL_FINGERUP)
		{
			sdlkUp |= KEY_TOUCH;
		}
	}

	sdlkHeld |= sdlkDown;
	sdlkHeld &= ~sdlkUp;
}

uint32_t sdlKeysUp(void)
{
	return sdlkUp;
}

uint32_t sdlKeysDown(void)
{
	return sdlkDown;
}

uint32_t sdlKeysHeld(void)
{
	return sdlkHeld;
}

void sdlTouchRead(sdlTouch *touch)
{
	touch->px = sdlpx;
	touch->py = sdlpy;
}

