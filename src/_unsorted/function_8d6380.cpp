struct triple {
    long long field_0;
    long long field_8;
    int field_10;
};

extern "C" char* function_8d6380(triple* left, char* result, triple* right) {
    if (right->field_0 != left->field_0 || right->field_8 != left->field_8 || right->field_10 != left->field_10) {
        *result = 0;
        return result;
    }
    *result = 1;
    return result;
}
