struct property_value {
    int kind;
    unsigned char reserved4[4];
    void* pointer;
};

extern "C" void* c_networking_squad_session_reader_component__get_saved_film_map_338400();

extern "C" char cui_get_scalar_property_by_return_value_33942c_33942c(void*, void*, property_value* value) {
    value->pointer = c_networking_squad_session_reader_component__get_saved_film_map_338400();
    value->kind = 3;
    return 1;
}
