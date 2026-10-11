struct string_ptr {
    long long field_0;
};

extern "C" long long hk_string_ptr_set_879350(string_ptr* target, const char* text);

extern "C" string_ptr* hk_string_ptr_assign_clear_flag_879290(string_ptr* target, string_ptr* source) {
    hk_string_ptr_set_879350(target, (const char*)(source->field_0 & -2));
    return target;
}
