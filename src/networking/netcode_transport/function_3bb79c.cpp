struct download_state {
    unsigned char reserved0[0x1EB0];
    int position;
};

extern "C" char network_storage_file_furp_copy_downloaded_chunk_3bb7e0(download_state* state, char flag);

extern "C" char function_3bb79c(download_state* state, char flag) {
    char result = network_storage_file_furp_copy_downloaded_chunk_3bb7e0(state, flag);
    if (result != 0 && flag != 0) {
        int position = state->position;
        if (position < 0 || (unsigned int)position > 0x180)
            state->position = 0;
    }
    return result;
}
