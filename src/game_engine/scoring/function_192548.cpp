struct pair_arg {
    void* first;
    char second;
};

extern "C" long long function_192438(int first, int second, void* third, char fourth);

extern "C" char function_192548(int first, int second, pair_arg* pair) {
    return (int)function_192438(first, second, pair->first, pair->second) > 0;
}
