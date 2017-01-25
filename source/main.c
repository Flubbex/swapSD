/*
	Hello World example made by Aurelio Mannara for ctrulib
	This code was modified for the last time on: 12/12/2014 21:00 UTC+1
*/

#include <3ds.h>
#include <stdio.h>
#include <fatfs/ff.h>
int main(int argc, char **argv)
{
	gfxInitDefault();
	//Initialize console on top screen. Using NULL as the second argument tells the console library to use the internal console structure as current one
	consoleInit(GFX_TOP, NULL);
	f_mount(NULL, "0:", 1);

	printf("\x1b[1;24HswapSD 1.0");
	printf("\x1b[2;28Hby Flubbex ");
	printf("\x1b[5;1HYou can safely swap SD cards now.");
	printf("\x1b[6;1HPress Start to exit.");
	
	// Main loop
	while (aptMainLoop())
	{
		//Scan all the inputs. This should be done once for each frame
		hidScanInput();

		//hidKeysDown returns information about which buttons have been just pressed (and they weren't in the previous frame)
		u32 kDown = hidKeysDown();

		if (kDown & KEY_START) break; // break in order to return to hbmenu

		// Flush and swap framebuffers
		gfxFlushBuffers();
		gfxSwapBuffers();

		//Wait for VBlank
		gspWaitForVBlank();
	}

	gfxExit();
	return 0;
}
