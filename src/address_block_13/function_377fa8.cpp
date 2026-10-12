struct Owner {
    char reserved_0[0x70];
    int mode;
    char reserved_74[0x5fc4];
    long long field_6038;
    char reserved_6040[0xaf8];
    char* field_6b38;
    int field_6b40;
};
extern "C" char function_22b44c(void* block, void* a, void* b);
extern "C" char* function_22b4ac(void* base, int kind, void* b, long long c, void* d);
extern "C" char function_377fa8(Owner* owner)
{
    int kind = -1;
    switch (owner->mode) {
    case 1:
        kind = 3;
        break;
    case 2:
        kind = 5;
        break;
    case 3:
        kind = 6;
        break;
    }
    char* block = function_22b4ac((void*)(((long long)owner + 0x604F) & -8), kind, (char*)owner + 0x84, 0x19, &owner->field_6038);
    owner->field_6b38 = block;
    char ok = function_22b44c(block, (char*)owner + 0x6040, &owner->field_6b40);
    if (ok == 0)
        owner->field_6b38 = nullptr;
    return ok;
}
