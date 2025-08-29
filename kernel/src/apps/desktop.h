#pragma once
#include "app.h"

class DesktopApp : public Application {
public:
    void OnStart() override;
    void OnUpdate() override;
};
