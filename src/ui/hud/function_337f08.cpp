struct value_slot {
    int kind;
    int reserved4;
    int number;
};

extern "C" int user_interface_squad_get_privacy_selection_index_2a4738();

extern "C" char function_337f08(char*, void*, value_slot* out) {
    out->number = (char)user_interface_squad_get_privacy_selection_index_2a4738();
    out->kind = 1;
    return 1;
}
