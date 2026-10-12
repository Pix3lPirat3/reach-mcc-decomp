extern "C" char function_333064(char* object, int index, int mode, int arg, long long extra);

extern "C" char function_333424(char* object, int arg, long long extra) {
    return function_333064(object, *reinterpret_cast<int*>(object + 0x70), 0, arg, extra);
}
