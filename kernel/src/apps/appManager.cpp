#include "appManager.h"
#include "../BasicRenderer.h"

extern bool LeftMouseDown; // Fare durumunu dışarıdan alacağız
extern bool RightMouseDown;

AppManager* GlobalAppManager;

AppManager::AppManager(){
    Desktop = new DesktopApp();
    Paint = new PaintApp();
    CurrentApp = Desktop; // Başlangıçta Masaüstü uygulamasını çalıştır
    CurrentApp->Run(); // İlk ekranı çiz
}

AppManager::~AppManager(){
    delete Desktop;
    delete Paint;
}

void AppManager::RunCurrentApp(){
    CurrentApp->Run();
}

void AppManager::SwitchTo(Application* app){
    CurrentApp = app;
    CurrentApp->Run(); // Yeni uygulamanın ilk ekranını çiz
}

void AppManager::HandleClick(){
    // Eğer masaüstündeysek ve butona tıklandıysa uygulamalara geç
    if (CurrentApp == Desktop){
        // Paint
        if (MousePosition.X >= 50 && MousePosition.X <= 150 &&
            MousePosition.Y >= 50 && MousePosition.Y <= 100)
        {
            
            SwitchTo(Paint);
            GlobalRenderer->Clear();
        }
        // Buza
        else if (MousePosition.X >= 50 && MousePosition.X <= 150 &&
                 MousePosition.Y >= 120 && MousePosition.Y <= 170)
        {
            if (Buza == nullptr) Buza = new BuzaApp();
            SwitchTo(Buza);
            GlobalRenderer->Clear();
        }
    }
    // Eğer Paint'te isek ve sağ tıklandıysa Masaüstüne dön
    else { //masaustune donus
        if (RightMouseDown){
        
        GlobalAppManager->SwitchTo(GlobalAppManager->Desktop);
        GlobalRenderer->Clear();
        }
    }
}

