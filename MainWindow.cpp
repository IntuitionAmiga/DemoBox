// (c) 2018 Zayn Otley
// intuitionamiga@gmail.com

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
#define BTN_PLAY_MSG 'bply'
#define BTN_STOP_MSG 'bstp'
#define BTN_RESET_MSG 'brst'
#define BTN_SHOT_MSG 'bsht'
#define BTN_VIDEO_MSG 'bvid'
#define BTN_REGISTERS_MSG 'breg'
#define BTN_DEBUG_MSG 'bdbg'

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

    // "Open" button
    BRect buttonOpenRect(0,22,75,50);
    const char* buttonOpenName = "Open File Button";
    const char* buttonOpenLabel = "Open";
    BButton *buttonOpen;
    buttonOpen = new BButton(buttonOpenRect, buttonOpenName, buttonOpenLabel, new BMessage(M_OPEN_REQUESTED));
    AddChild(buttonOpen);

    // "Play/Pause" button
    BRect buttonPlayRect(0,46,75,50); //left,top,right,bottom
    const char* buttonPlayName = "Play/Pause Button";
    const char* buttonPlayLabel = "Play/Pause";
    BButton *buttonPlay;
    buttonPlay = new BButton(buttonPlayRect, buttonPlayName, buttonPlayLabel, new BMessage(BTN_PLAY_MSG));
    AddChild(buttonPlay);

    // "Stop" button
    BRect buttonStopRect(0,70,75,50);
    const char* buttonStopName = "Stop Button";
    const char* buttonStopLabel = "Stop";
    BButton *buttonStop;
    buttonStop = new BButton(buttonStopRect, buttonStopName, buttonStopLabel, new BMessage(BTN_STOP_MSG));
    AddChild(buttonStop);

    // "Reset" button
    BRect buttonResetRect(0,96,75,50);
    const char* buttonResetName = "Reset Button";
    const char* buttonResetLabel = "Reset";
    BButton *buttonReset;
    buttonReset = new BButton(buttonResetRect, buttonResetName, buttonResetLabel, new BMessage(BTN_RESET_MSG));
    AddChild(buttonReset);

    // "Screenshot" button
    BRect buttonScreenshotRect(0,120,75,50);
    const char* buttonScreenshotName = "Screenshot Button";
    const char* buttonScreenshotLabel = "Screenshot";
    BButton *buttonScreenshot;
    buttonScreenshot = new BButton(buttonScreenshotRect, buttonScreenshotName, buttonScreenshotLabel, new BMessage(BTN_SHOT_MSG));
    AddChild(buttonScreenshot);

    // "Record video" button
    BRect buttonVideoRect(0,144,75,50);
    const char* buttonVideoName = "Video Button";
    const char* buttonVideoLabel = "Video";
    BButton *buttonVideo;
    buttonVideo = new BButton(buttonVideoRect, buttonVideoName, buttonVideoLabel, new BMessage(BTN_VIDEO_MSG));
    AddChild(buttonVideo);

    // "View CPU registers" button
    BRect buttonRegistersRect(0,168,75,50);
    const char* buttonRegistersName = "Registers Button";
    const char* buttonRegistersLabel = "Registers";
    BButton *buttonRegisters;
    buttonRegisters = new BButton(buttonRegistersRect, buttonRegistersName, buttonRegistersLabel, new BMessage(BTN_REGISTERS_MSG));
    AddChild(buttonRegisters);

    // "Show debugger" button
    BRect buttonDebugRect(0,192,75,50);
    const char* buttonDebugName = "Debug Button";
    const char* buttonDebugLabel = "Debug";
    BButton *buttonDebug;
    buttonDebug = new BButton(buttonDebugRect, buttonDebugName, buttonDebugLabel, new BMessage(BTN_DEBUG_MSG));
    AddChild(buttonDebug);

    // Create surface to blit to
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

        case BTN_REGISTERS_MSG: {
                BAlert *alert = new BAlert("Demobox","Register window goes here.", "OK");
                alert->Go();
            break;
        }

        case BTN_DEBUG_MSG: {
                BAlert *alert = new BAlert("Demobox","Debugger window goes here.", "OK");
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

