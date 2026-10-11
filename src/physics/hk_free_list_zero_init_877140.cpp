struct free_list {
    unsigned long long field_0;
    unsigned long long field_8;
    unsigned char reserved10[8];
    unsigned long long field_18;
    unsigned long long field_20;
    unsigned long long field_28;
    unsigned long long field_30;
    unsigned long long field_38;
    unsigned long long field_40;
    unsigned long long field_48;
    unsigned long long field_50;
    unsigned long long field_58;
    unsigned long long field_60;
};

extern "C" free_list* hk_free_list_zero_init_877140(free_list* list) {
    list->field_0 = 0;
    list->field_18 = 0;
    list->field_20 = 0;
    list->field_28 = 0;
    list->field_30 = 0;
    list->field_40 = 0;
    list->field_48 = 0;
    list->field_50 = 0;
    list->field_58 = 0;
    list->field_60 = 0;
    list->field_8 = 0;
    list->field_38 = 0;
    return list;
}
