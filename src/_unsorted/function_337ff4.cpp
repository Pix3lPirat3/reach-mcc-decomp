struct value_slot {
    int kind;
    int reserved4;
    int number;
};

extern "C" int network_squad_session_get_maximum_player_count_38e854();

extern "C" char function_337ff4(char*, void*, value_slot* out) {
    out->number = network_squad_session_get_maximum_player_count_38e854();
    out->kind = 1;
    return 1;
}
