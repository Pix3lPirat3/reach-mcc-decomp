struct block {
    char reserved0[0x28];
    int field_28;
    int field_2c;
};

extern "C" long long function_d2818(block* self, long long first, long long second, long long third);

extern "C" long long function_2a66b0(block* self, long long first, long long second, long long third) {
    long long result = function_d2818(self, first, second, third);
    self->field_28 = 0;
    self->field_2c = 0;
    return result;
}
