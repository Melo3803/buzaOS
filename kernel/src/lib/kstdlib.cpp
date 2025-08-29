#include <stddef.h>
#include "../paging/PageFrameAllocator.h"


void* alloc_page();
void free_page(void* address);


struct MallocHeader {
    uint64_t num_pages; // su anda her zaman 1 olacak
};

void* operator new(size_t size) {
    
    if (size > 4096 - sizeof(MallocHeader)) {
       
        return NULL;
    }

    
    void* allocated_page = alloc_page();
    if (allocated_page == NULL) {
        return NULL;
    }

    
    MallocHeader* header = (MallocHeader*)allocated_page;
    header->num_pages = 1;


    void* user_ptr = (void*)((uint64_t)allocated_page + sizeof(MallocHeader));
    return user_ptr;
}

void operator delete(void* ptr) {
    if (ptr == NULL) return;

    
    void* page_start = (void*)((uint64_t)ptr - sizeof(MallocHeader));
    
    
    free_page(page_start);
}

void operator delete(void* ptr, size_t size) {
    if (ptr == NULL) return;

    void* page_start = (void*)((uint64_t)ptr - sizeof(MallocHeader));
    free_page(page_start);
}


void* alloc_page() {
    return GlobalAllocator.RequestPage();
}

void free_page(void* address) {
    GlobalAllocator.FreePage(address);
}


extern "C" {
    void __cxa_pure_virtual() {
        while(1);
    }

    int __cxa_atexit(void (*f)(void *), void *p, void *d) {
        return 0;
    }
    
    void *__dso_handle;
    
    void __cxa_guard_acquire() {}
    void __cxa_guard_release() {}
    void __cxa_guard_abort() {}
    void _Unwind_Resume() { while(1); } 
    void __gxx_personality_v0() { while(1); }  
}
