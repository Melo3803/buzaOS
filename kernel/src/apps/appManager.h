#pragma once
#include "app.h"
#include "desktop.h"
#include "paint.h"
#include "buza.h"
#include "terminal.h"

class AppManager {
public:
    AppManager();
    ~AppManager();

    Application* CurrentApp;
    DesktopApp* Desktop;
    PaintApp* Paint;
    BuzaApp* Buza; // Yeni uygulama
    TerminalApp* Terminal;

    void RunCurrentApp();
    void SwitchTo(Application* app);

    void HandleClick();
};

extern AppManager* GlobalAppManager;
