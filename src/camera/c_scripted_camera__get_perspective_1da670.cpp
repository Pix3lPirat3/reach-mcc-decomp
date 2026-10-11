extern "C" int scripted_camera_get_first_person_camera_object_1d7dc8();

extern "C" int c_scripted_camera__get_perspective_1da670() {
    return scripted_camera_get_first_person_camera_object_1d7dc8() != -1 ? 0 : 2;
}
