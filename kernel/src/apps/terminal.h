#pragma once
#include "app.h"

class TerminalApp : public Application {
public:
    void OnStart() override;
    void OnUpdate() override;
};
