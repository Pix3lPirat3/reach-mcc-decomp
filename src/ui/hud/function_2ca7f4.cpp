extern "C" long long c_window_manager__transition_out_screens_with_id_2ca778(long long manager, int index, int value);

extern "C" long long function_2ca7f4(long long manager, int value) {
    int index = 0;
    long long result;
    do {
        result = c_window_manager__transition_out_screens_with_id_2ca778(manager, index, value);
        ++index;
    } while (index < 6);
    return result;
}
