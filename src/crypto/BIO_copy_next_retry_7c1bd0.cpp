struct bio {
    unsigned char reserved0[0x28];
    unsigned int flags;
    unsigned int retry_reason;
    unsigned char reserved30[0x10];
    bio* next_bio;
};

extern "C" int BIO_copy_next_retry_7c1bd0(bio* current) {
    bio* next = current->next_bio;
    current->flags = current->flags | (next->flags & 0xF);
    int retry_reason = next->retry_reason;
    current->retry_reason = retry_reason;
    return retry_reason;
}
