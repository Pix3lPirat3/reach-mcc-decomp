#pragma pack(push, 1)
struct quota_record_6bb64 {
    unsigned short word;
    unsigned char byte;
};
#pragma pack(pop)
static_assert(sizeof(unsigned short) == 2);
static_assert(sizeof(unsigned char) == 1);
static_assert(sizeof(quota_record_6bb64) == 3);
extern "C" quota_record_6bb64* target_6bb64(quota_record_6bb64* record) {
    record->word = 0;
    record->byte = 0;
    return record;
}
