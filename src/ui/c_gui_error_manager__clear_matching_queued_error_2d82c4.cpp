struct queued_error {
    unsigned char active;
    unsigned char reserved1[0x423];
};

struct error_manager {
    queued_error errors[0x20];
};

extern "C" char c_gui_queued_error__match_2d7b80(queued_error* error, int first, int second, void* context);

extern "C" char c_gui_error_manager__clear_matching_queued_error_2d82c4(error_manager* manager, int first, int second, void* context) {
    for (int i = 0; (unsigned int)i < 0x20; i++) {
        queued_error* error = &manager->errors[i];
        char matched = c_gui_queued_error__match_2d7b80(error, second, first, context);
        if (matched != 0) {
            error->active = 0;
            return matched;
        }
    }
    return 0;
}
