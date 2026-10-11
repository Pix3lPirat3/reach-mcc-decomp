struct probe_object_7 {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
};

struct probe_object_16 {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
};

extern "C" bool forge_probe_6b008(probe_object_7* object, void** out_member, unsigned int* out_status) {
    bool result = false;
    if (out_status) {
        *out_status = 0xb61;
        result = true;
    }
    if (out_member && out_status) {
        object->slot7();
        *out_member = reinterpret_cast<unsigned char*>(object) + 0xa38;
        result = true;
    }
    return result;
}

extern "C" bool forge_probe_6ae98(probe_object_16* object, void** out_member, unsigned int* out_status) {
    bool result = false;
    if (out_status) {
        *out_status = 0xcce1;
        result = true;
    }
    if (out_member && out_status) {
        object->slot16();
        *out_member = reinterpret_cast<unsigned char*>(object) + 0xcbb8;
        result = true;
    }
    return result;
}
