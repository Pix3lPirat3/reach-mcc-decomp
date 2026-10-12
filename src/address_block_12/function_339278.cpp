struct value_slot {
    int kind;
    int reserved4;
    char flag;
};

extern "C" int network_squad_session_get_session_privacy_mode_398a64();

extern "C" char function_339278(char*, void*, value_slot* out) {
    char mode = (char)network_squad_session_get_session_privacy_mode_398a64();
    out->kind = 0;
    out->flag = mode == 2;
    return 1;
}
