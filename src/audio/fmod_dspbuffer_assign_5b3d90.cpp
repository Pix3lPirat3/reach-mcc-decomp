struct buffer_block {
    unsigned char reserved_0[8];
    int ref_count;
};

struct dsp_buffer {
    buffer_block* block;
    long long field_8;
    int field_10;
    int field_14;
    int field_18;
    int field_1c;
};

extern "C" long long fmod_dspbuffer_release_5b3df0(dsp_buffer* buffer);

extern "C" long long fmod_dspbuffer_assign_5b3d90(dsp_buffer* source, dsp_buffer* target) {
    if (target->block != nullptr) {
        long long result = fmod_dspbuffer_release_5b3df0(target);
        if ((int)result != 0)
            return result;
    }
    target->block = source->block;
    target->field_10 = source->field_10;
    target->field_8 = source->field_8;
    target->field_14 = source->field_14;
    target->field_18 = source->field_18;
    target->field_1c = source->field_1c;
    source->block->ref_count = source->block->ref_count + 1;
    return 0;
}
