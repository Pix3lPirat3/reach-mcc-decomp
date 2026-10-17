struct block {
    long long field_0;
    long long field_8;
    short field_10;
    char reserved12[6];
    long long field_18;
    long long field_20;
    long long field_28;
};

extern "C" block* function_270d40(block* self) {
    self->field_0 = 0;
    self->field_8 = 0;
    self->field_10 = 0;
    self->field_18 = 0;
    self->field_20 = 0;
    self->field_28 = 0;
    return self;
}
