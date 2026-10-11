struct vorbis_stream {
    unsigned char reserved_0[0x3c];
    unsigned char flag;
    unsigned char reserved_3d[0x12f];
    int end_position;
    unsigned char reserved_170[0x8];
    int start_position;
};

extern "C" int fmod_codec_oggvorbis_tell_callback_5fd980(vorbis_stream* stream) {
    int position = stream->end_position - stream->start_position;
    stream->flag = 0;
    return position;
}
