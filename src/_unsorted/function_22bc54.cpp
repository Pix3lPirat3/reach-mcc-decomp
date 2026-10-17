struct request {
    char reserved0[0xc];
    int value;
    char field_10;
};

extern "C" unsigned char function_28ec90(void* target, int first, int second, void * third);

extern "C" unsigned char function_22bc54(request* self) {
    return function_28ec90(&self->field_10, 1, self->value, 0);
}
