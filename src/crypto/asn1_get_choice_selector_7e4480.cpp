struct asn1_item {
    unsigned char reserved0[4];
    int offset;
};

extern "C" int asn1_get_choice_selector_7e4480(char** value, const asn1_item* item) {
    return *(const int*)(*value + item->offset);
}
