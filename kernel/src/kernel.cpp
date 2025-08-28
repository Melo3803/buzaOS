#include "kernelUtil.h"
#include "apps/appManager.h" // AppManager'ı dahil et

extern "C" void _start(BootInfo* bootInfo){

    KernelInfo kernelInfo = InitializeKernel(bootInfo);
    PageTableManager* pageTableManager = kernelInfo.pageTableManager;

    // AppManager'ı başlat
    GlobalAppManager = new AppManager();

    // Ana döngü - sadece fare girdilerini işle, gerisini AppManager halleder
    while(true){
        ProcessMousePacket();
    }

    while(true);
}
