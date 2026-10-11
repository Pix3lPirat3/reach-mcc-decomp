extern "C" char function_714b8(int value, long long zero);

extern "C" char forge_engine_object_value_override_zero_74da4(void*, int value, int* out_value) {
    char result = function_714b8(value, 0);
    if (result == 0)
        return result;
    *out_value = 0;
    return result;
}
