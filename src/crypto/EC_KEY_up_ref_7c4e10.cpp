extern "C" long _InterlockedExchangeAdd(long volatile*, long);

extern "C" int EC_KEY_up_ref_7c4e10(unsigned char* key) {
    return (int)(_InterlockedExchangeAdd((volatile long*)(key + 0x38), 1) + 1) > 1;
}
