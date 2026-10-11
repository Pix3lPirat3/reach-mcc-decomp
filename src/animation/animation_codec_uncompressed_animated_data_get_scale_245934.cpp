extern "C" long long animation_codec_uncompressed_animated_data_get_scale_245934(long long data, int frame_index, int track_index, long long, long long, long long, long long result) {
    *(int*)(result + 0x1c) = *(int*)(*(unsigned int*)(data + 0x10) + data + (unsigned int)(frame_index * *(int*)(data + 0x1c)) + (long long)track_index * 4);
    return result;
}
