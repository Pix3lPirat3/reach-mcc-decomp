struct sigx_entry {
    unsigned char reserved0[4];
    unsigned int first_key;
    unsigned int second_key;
};

extern "C" int sigx_cmp_7f8b70(sigx_entry** left, sigx_entry** right) {
    sigx_entry* right_entry = *right;
    sigx_entry* left_entry = *left;
    unsigned int difference = left_entry->first_key - right_entry->first_key;
    if (difference != 0)
        return difference;
    return left_entry->second_key - right_entry->second_key;
}
