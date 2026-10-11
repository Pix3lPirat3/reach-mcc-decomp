typedef char* argument_list;
extern "C" void __cdecl __va_start(argument_list*, ...);
extern "C" void format_into_35d84(char* buffer, unsigned int capacity, const char* format, argument_list arguments);
extern "C" void format_into_11978(char* buffer, unsigned int capacity, const char* format, argument_list arguments);

extern "C" char* forge_format_128_6b210(char* buffer, const char* format, ...) {
    argument_list arguments;
    __va_start(&arguments, format);
    format_into_35d84(buffer, 0x80, format, arguments);
    arguments = nullptr;
    return buffer;
}

extern "C" char* forge_format_80_6b244(char* buffer, const char* format, ...) {
    argument_list arguments;
    __va_start(&arguments, format);
    format_into_11978(buffer, 0x50, format, arguments);
    arguments = nullptr;
    return buffer;
}
