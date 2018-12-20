#include "MainWindow.h"

#include <Application.h>
#include <Menu.h>
#include <MenuItem.h>
#include <View.h>
#include <FilePanel.h> //add libtracker.so to linker settings in Paladin
#include <Alert.h>
#include <Button.h>
#include <Bitmap.h>

#define M_OPEN_REQUESTED 'open'
#define M_ABOUT_REQUESTED 'abrq'
#define BTN_PLAY_MSG 'btnply'
#define BTN_STOP_MSG 'btnstp'
#define BTN_RESET_MSG 'btnrst'
#define BTN_SHOT_MSG 'btnsht'
#define BTN_VIDEO_MSG 'btnvid'
#define BTN_REGISTERS_MSG 'btnregs'
#define BTN_DEBUG_MSG 'btndbg'

MainWindow::MainWindow(void)
	:	BWindow(BRect(100,100,716,512),"Intuition DemoBox",B_TITLED_WINDOW, B_ASYNCHRONOUS_CONTROLS) {

    // Draw menu bar
	BRect r(Bounds());
	r.bottom = 20;
	fMenuBar = new BMenuBar(r,"menubar");
	AddChild(fMenuBar);
    // Add menu to bar
	BMenu *menu;
	menu = new BMenu("File");
	fMenuBar->AddItem(menu);
    // Add items to menu
	menu->AddItem(new BMenuItem("Open", new BMessage(M_OPEN_REQUESTED)));
    menu->AddItem(new BMenuItem("About", new BMessage(M_ABOUT_REQUESTED)));

    BRect buttonOpenRect(0,22,75,50);
    const char* buttonOpenName = "Open File Button";
    const char* buttonOpenLabel = "Open";
    BButton *buttonOpen;
    buttonOpen = new BButton(buttonOpenRect, buttonOpenName, buttonOpenLabel, new BMessage(M_OPEN_REQUESTED));
    AddChild(buttonOpen);

    BRect buttonPlayRect(0,46,75,50); //left,top,right,bottom
    const char* buttonPlayName = "Play/Pause Button";
    const char* buttonPlayLabel = "Play/Pause";
    BButton *buttonPlay;
    buttonPlay = new BButton(buttonPlayRect, buttonPlayName, buttonPlayLabel, new BMessage(BTN_PLAY_MSG));
    AddChild(buttonPlay);

    BRect buttonStopRect(0,70,75,50);
    const char* buttonStopName = "Stop Button";
    const char* buttonStopLabel = "Stop";
    BButton *buttonStop;
    buttonStop = new BButton(buttonStopRect, buttonStopName, buttonStopLabel, new BMessage(BTN_STOP_MSG));
    AddChild(buttonStop);

    BRect buttonResetRect(0,96,75,50);
    const char* buttonResetName = "Reset Button";
    const char* buttonResetLabel = "Reset";
    BButton *buttonReset;
    buttonReset = new BButton(buttonResetRect, buttonResetName, buttonResetLabel, new BMessage(BTN_RESET_MSG));
    AddChild(buttonReset);

    BRect buttonScreenshotRect(0,120,75,50);
    const char* buttonScreenshotName = "Screenshot Button";
    const char* buttonScreenshotLabel = "Screenshot";
    BButton *buttonScreenshot;
    buttonScreenshot = new BButton(buttonScreenshotRect, buttonScreenshotName, buttonScreenshotLabel, new BMessage(BTN_SHOT_MSG));
    AddChild(buttonScreenshot);

    BRect buttonVideoRect(0,144,75,50);
    const char* buttonVideoName = "Video Button";
    const char* buttonVideoLabel = "Video";
    BButton *buttonVideo;
    buttonVideo = new BButton(buttonVideoRect, buttonVideoName, buttonVideoLabel, new BMessage(BTN_VIDEO_MSG));
    AddChild(buttonVideo);


    BRect buttonRegistersRect(0,168,75,50);
    const char* buttonRegistersName = "Registers Button";
    const char* buttonRegistersLabel = "Registers";
    BButton *buttonRegisters;
    buttonRegisters = new BButton(buttonRegistersRect, buttonRegistersName, buttonRegistersLabel, new BMessage(BTN_REGISTERS_MSG));
    AddChild(buttonRegisters);


    BRect buttonDebugRect(0,192,75,50);
    const char* buttonDebugName = "Debug Button";
    const char* buttonDebugLabel = "Debug";
    BButton *buttonDebug;
    buttonDebug = new BButton(buttonDebugRect, buttonDebugName, buttonDebugLabel, new BMessage(BTN_DEBUG_MSG));
    AddChild(buttonDebug);

    BRect vduRect(76,0,640,512);
    BBitmap *image = new BBitmap(vduRect, B_RGBA32);
}

void MainWindow::MessageReceived(BMessage *msg) {

    BFilePanel* fOpenPanel = new BFilePanel(B_OPEN_PANEL);

	switch (msg->what) {
        case M_OPEN_REQUESTED:
                fOpenPanel->Show();
            break;

        case M_ABOUT_REQUESTED: {
                BAlert *alert = new BAlert("Demobox", "Runtime engine for demoscene productions running on various virtual machine plugins.\n\n (c) 2018 Zayn Otley.\n\n", "OK");
                alert->Go();
            break;
        }

		default: {
			BWindow::MessageReceived(msg);
			break;
		}
	}
}

bool
MainWindow::QuitRequested(void) {
	be_app->PostMessage(B_QUIT_REQUESTED);
	return true;
}

