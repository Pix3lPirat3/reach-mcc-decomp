extern "C" void* function_4cb41c(int unit_index, int animation_state, int mode, void* animation, short count, char flag);

extern "C" bool unit_animation_request_play_simple_4cb4c4(int unit_index, void* animation, char flag) {
    return function_4cb41c(unit_index, 0, -1, animation, 1, flag) != 0;
}
