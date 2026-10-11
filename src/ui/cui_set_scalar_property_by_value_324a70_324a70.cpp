struct property_value {
    unsigned char reserved0[8];
    void* pointer;
};

extern "C" void* c_player_model_widget__set_player_configuration_3244f8(void* widget, void* configuration);

extern "C" char cui_set_scalar_property_by_value_324a70_324a70(void* widget, void*, const property_value* value) {
    c_player_model_widget__set_player_configuration_3244f8(widget, value->pointer);
    return 1;
}
