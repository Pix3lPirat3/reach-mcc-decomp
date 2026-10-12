struct matrix {
    float values[12];
};

extern "C" void function_86fce0(void * result, void * left, void * right);

extern "C" void function_8b36c0(char* self, matrix* right) {
    return function_86fce0((matrix*)(self + 0xC0), (matrix*)(self + 0x70), right);
}
