extern "C" void* c_subscreen_widget__get_active_subscreen_386680(void* widget);

extern "C" char c_subscreen_widget__do_is_focusable_3865a8(void* widget) {
    return c_subscreen_widget__get_active_subscreen_386680(widget) != 0;
}
