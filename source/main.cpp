#include <3ds.h>
#include <stdio.h>
#include "fetch.hpp"

int main (int argc, char **argv) {
	gfxInitDefault();
	
	PrintConsole TOP_SCREEN, BOTTOM_SCREEN;
	
	consoleInit(GFX_TOP, &TOP_SCREEN);
	consoleInit(GFX_BOTTOM, &BOTTOM_SCREEN);
	
	consoleSelect(&BOTTOM_SCREEN);
	
	Fetch::download("https://github.com/FlagBrew/PKSM/releases/download/6.2.1/PKSM.cia", "PKSM.cia");
	printf("Finished, press START to quit");
	
	while (aptMainLoop()) {
		hidScanInput();
		u32 kDown = hidKeysDown();
		
		if (kDown & KEY_START) break;
		//if (kDown & KEY_A) { consoleSelect(&TOP_SCREEN); }
		
		gfxFlushBuffers();
		gfxSwapBuffers();
		gspWaitForVBlank();
	}
	
	gfxExit();
	return 0;
}
