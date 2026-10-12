struct activation_info {
    unsigned char reserved0[0x2C];
    unsigned short index;
};

struct body_info {
    unsigned char reserved0[0x130];
    activation_info* activation;
};

struct island_entry {
    unsigned char reserved0[8];
    body_info* first;
    body_info* second;
};

extern "C" char* function_8ba880(char* result, island_entry* left, island_entry* right) {
    if (left->first->activation->index < right->first->activation->index ||
        (left->first->activation->index == right->first->activation->index &&
         left->second->activation->index < right->second->activation->index)) {
        *result = 1;
        return result;
    }
    *result = 0;
    return result;
}
