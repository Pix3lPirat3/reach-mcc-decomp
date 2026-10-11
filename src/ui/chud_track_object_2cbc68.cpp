extern "C" float chud_scripting_track_object_internal_2cba94(int slot, int object, void* target, char flag, int first, int second);

extern "C" float chud_track_object_2cbc68(int object, void* target, char flag, int first, int second) {
    float result;
    int slot = 0;
    do {
        result = chud_scripting_track_object_internal_2cba94(slot, object, target, flag, first, second);
        slot++;
    } while (slot < 0x10);
    return result;
}
