struct pointer_list {
    unsigned char reserved0[0x18];
    long long* items;
    int count;
};

extern "C" long long function_3209c(pointer_list* list, long long* value) {
    int index = list->count;
    long long item = *value;
    list->count = index + 1;
    list->items[index] = item;
    return item;
}
