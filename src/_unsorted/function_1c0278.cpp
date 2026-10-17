struct context {
    char reserved0[8];
    void* target;
    int value;
};

extern "C" long long function_1c006c(void* target, int value, int first, int second, int flag);

extern "C" char function_1c0278(context* self, int first, int second) {
    function_1c006c(self->target, self->value, first, second, 1);
    return 1;
}
