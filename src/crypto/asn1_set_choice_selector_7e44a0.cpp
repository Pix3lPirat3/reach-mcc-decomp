struct asn1_item {
    unsigned char reserved0[4];
    int offset;
};

extern "C" int asn1_set_choice_selector_7e44a0(char** value, int selector, const asn1_item* item) {
    int* slot = (int*)(*value + item->offset);
    int previous = *slot;
    *slot = selector;
    return previous;
}
