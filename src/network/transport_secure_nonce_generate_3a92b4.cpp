extern "C" long long function_3a92d8(int size, long long* output);

extern "C" long long transport_secure_nonce_generate_3a92b4(void) {
    long long nonce;
    do {
        function_3a92d8(8, &nonce);
    } while (nonce == 0);
    return nonce;
}
