#include "appManager.h"
#include "../BasicRenderer.h"

extern bool LeftMouseDown; // Fare durumunu dışarıdan alacağız
extern bool RightMouseDown;

AppManager* GlobalAppManager;

AppManager::AppManager(){
    Desktop = new DesktopApp();
    Paint = new PaintApp();
    
    CurrentApp = Desktop; // Başlangıçta Masaüstü uygulamasını çalıştır
    CurrentApp->OnStart(); // İlk ekranı çiz
}

AppManager::~AppManager(){
    delete Desktop;
    delete Paint;
}

void AppManager::RunCurrentApp(){
    if (CurrentApp != nullptr){
        CurrentApp->OnUpdate(); // Mevcut uygulamanın güncelleme fonksiyonunu SÜREKLİ çağır
    }
}

void AppManager::SwitchTo(Application* app){
    if (app == nullptr) return; // Güvenlik için null kontrolü
    CurrentApp = app;
    CurrentApp->OnStart(); // Yeni uygulamanın ilk ekranını çiz
}

void AppManager::HandleClick(){
    // Eğer mevcut uygulama masaüstü değilse, sağ tıklama ile masaüstüne dön
    if (CurrentApp != Desktop) {
        if (RightMouseDown){
            SwitchTo(Desktop);
        }
    }
}

