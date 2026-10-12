struct owner {
    char reserved0[0x98d8];
    char* object;
};

extern "C" long long BInflate__destroy_7784c4(void* inflate);

extern "C" long long function_237b88(owner* self) {
    long long result = BInflate__destroy_7784c4(self->object + 0x28);
    self->object = 0;
    return result;
}
