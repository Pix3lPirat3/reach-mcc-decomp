struct property_value {
    int kind;
    unsigned char reserved4[4];
    void* pointer;
};

extern "C" void* c_networking_squad_session_reader_component__get_leader_player_name_338634();

extern "C" char cui_get_scalar_property_by_return_value_3390f4_3390f4(void*, void*, property_value* value) {
    value->pointer = c_networking_squad_session_reader_component__get_leader_player_name_338634();
    value->kind = 3;
    return 1;
}
