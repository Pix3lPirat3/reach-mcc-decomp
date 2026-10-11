struct bit_reader;

extern "C" char single_bit_window_reader_core_54214(bit_reader* reader, long long read_arg);

extern "C" char biped_laser_designation_event_decode_payload_3b8394(long long, long long read_arg, char* out_flag, bit_reader* reader) {
    *out_flag = single_bit_window_reader_core_54214(reader, read_arg);
    return 1;
}
