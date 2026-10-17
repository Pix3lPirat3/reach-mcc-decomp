extern "C" int function_4c850c(unsigned int animation);
extern "C" unsigned char function_4c8584(unsigned int unit, int mode, int first_state, int second_state, int count);

extern "C" unsigned char function_4c8554(unsigned int unit) {
    return function_4c8584(unit, function_4c850c(unit), 0x11A, 0x11A, 0xC);
}
