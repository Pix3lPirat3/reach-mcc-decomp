extern "C" long _InterlockedExchangeAdd(long volatile* target, long value);

struct evp_pkey {
    unsigned char reserved0[8];
    long references;
};

extern "C" int EVP_PKEY_up_ref_7a7840(evp_pkey* key) {
    return _InterlockedExchangeAdd(&key->references, 1) + 1 > 1;
}
