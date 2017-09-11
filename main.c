#include <stdio.h>
#include <intuition/intuition.h>
#include <exec/types.h>

extern LONG OpenLibrary();
extern struct Screen *OpenScreen();
extern struct Window *OpenWindow();

struct IntuitionBase *IntuitionBase;

#define INTUITION_REV 39

struct NewScreen NewScreen =
{
    0,0,
    640, /* Width */
    256, /* Heigth PAL */
    5, /* BITPLANES 256 Colors */
    3,5, /* Another color combination */
    HIRES,
    CUSTOMSCREEN,
    NULL,
    "To end the program, please click close-gadget",
    NULL,
    NULL
};

struct NewWindow NewWindow = 
{
    40,40, /* X and Y coords */
    280,120, /* Width and height */
    4, 6, /* Colors (0-256) */
    CLOSEWINDOW,
    WindoWCLOSE | SMART_REFRESH | ACTIVATE | WINDOWSIZING | SIZEBRIGHT | WINDOWDRAG| WINDOWDEPTH,
    NULL,
    NULL,
    "*** Hello ***",
    NULL,
    NULL,
    190,20,
    640,256, /* PAL = 256 */
    CUSTOMSCREEN
};

int main(int argc, int **argv)
{
    struct Screen *Screen;
    struct Window *Window;

    if((IntuitionBase = (struct IntuitionBase *)OpenLibrary("intuition.library", INTUITION_REV)) == NULL)
	exit(FALSE);
    if((Screen = OpenScreen(&NewScreen)) == NULL)
	exit(FALSE);

    NewWindow.Screen = Screen; 
    
    if((Window = OpenWindow(&NewWindow)) == NULL)
	exit(FALSE);

    /* Wait for Close-gadget */
    Wait(1 << Window->UserPort->mp_SigBit);

    printf("\nLast Window Values: %d/%d/%d/%d\n\n",
	    Window->LeftEdge,
	    Window->TopEdge,
	    Window->Width,
	    Window->Height );
    CloseWindow(Window); /* Close Everything in Sequence */
    CloseScreen(Screen);
    CloseLibrary(IntuitionBase);
    exit(true);
}
}


