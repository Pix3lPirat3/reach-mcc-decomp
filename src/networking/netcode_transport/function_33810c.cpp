struct value_slot {
    int kind;
    int reserved4;
    int number;
};

extern "C" int network_squad_session_get_session_privacy_mode_398a64();

extern "C" char function_33810c(char*, void*, value_slot* out) {
    out->number = (char)network_squad_session_get_session_privacy_mode_398a64();
    out->kind = 1;
    return 1;
}
