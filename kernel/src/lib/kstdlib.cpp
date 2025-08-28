#include <stddef.h>

// C++'ın ihtiyaç duyduğu temel fonksiyonlar

// 'operator new' ve 'delete' için çok basit bir bellek yöneticisi (heap)
char simple_heap[1024 * 1024 * 4]; // 4 MB heap
size_t heap_ptr = 0;

void* operator new(size_t size) {
    if (heap_ptr + size > sizeof(simple_heap)) {
        // kernel panic yasiyok
        return 0; // HATALI
    }
    void* ptr = &simple_heap[heap_ptr];
    heap_ptr += size;
    return ptr;
}

void operator delete(void* ptr) {
    
}

void operator delete(void* ptr, size_t size) {
    
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
