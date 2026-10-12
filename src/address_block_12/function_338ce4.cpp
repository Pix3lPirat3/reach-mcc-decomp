struct value_slot {
    int kind;
    int reserved4;
    char flag;
};

extern "C" int user_interface_squad_get_privacy_selection_index_2a4738();

extern "C" char function_338ce4(char*, void*, value_slot* out) {
    char mode = (char)user_interface_squad_get_privacy_selection_index_2a4738();
    out->kind = 0;
    out->flag = mode == 2;
    return 1;
}
