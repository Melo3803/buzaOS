#pragma once
#include "../Framebuffer.h"
#include "../userinput/mouse.h"

class Application {
public:
    virtual ~Application() = default;
    virtual void OnStart() {}; // Başlangıçta bir kez çalışır
    virtual void OnUpdate() {}; // Sürekli çalışır
};
