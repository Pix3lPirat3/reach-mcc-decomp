struct point_to_path_constraint_data {
    unsigned char reserved0[0x30];
    void* path;
    unsigned char reserved38[4];
    unsigned char field_3C;
};

extern "C" char* function_8d6460(point_to_path_constraint_data* data, char* result) {
    if (data->path == 0 || data->field_3C == 0) {
        *result = 0;
        return result;
    }
    *result = 1;
    return result;
}
