extern "C" void function_3af604();
extern "C" void function_3af788(void* page, void * quality);

extern "C" void function_41bb84(long long, void* page, void * quality) {
    function_3af788(page, quality);
    function_3af604();
}
