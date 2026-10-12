struct bucket {
    unsigned char reserved0[0x20];
    void* field_20;
};

struct page {
    unsigned char reserved0[0x4c];
    unsigned int field_4c;
};

struct page_details {
    unsigned char bytes[64];
};

extern "C" page* Rockall_Page_Details_79a3c0(page* item, void* argument, page_details* details, void* extra, char flag);
extern "C" char Rockall_Page_Delete_79a240(page* item, page_details* details);

extern "C" char Rockall_Bucket_Delete_79ac60(bucket* self, void* argument, page* item, int expected) {
    page_details details;
    if (item->field_4c != (unsigned int)expected)
        return 0;
    if (Rockall_Page_Details_79a3c0(item, argument, &details, self->field_20, 0) == 0)
        return 0;
    if (Rockall_Page_Delete_79a240(item, &details) == 0)
        return 0;
    return 1;
}
