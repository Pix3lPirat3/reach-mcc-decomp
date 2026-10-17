extern "C" long long function_794270(long long first, long long second, long long count);

extern "C" char function_380344(long long first, long long second) {
    return (int)function_794270(first, second, 8) > 0;
}
