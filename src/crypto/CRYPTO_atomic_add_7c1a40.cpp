extern "C" long _InterlockedExchangeAdd(long volatile*, long);

extern "C" int CRYPTO_atomic_add_7c1a40(volatile long* value, int amount, int* result) {
    *result = _InterlockedExchangeAdd(value, amount) + amount;
    return 1;
}
