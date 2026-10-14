typedef unsigned __int64 size_t;
void* __cdecl memset(
      void*  _Dst,
                               int    _Val,
                               size_t _Size
    );
typedef unsigned char JSAMPLE;
typedef unsigned int JDIMENSION;
typedef JSAMPLE  *JSAMPROW;
typedef JSAMPROW *JSAMPARRAY;
typedef int DCTELEM;
extern void jpeg_fdct_1x1
    (DCTELEM * data, JSAMPARRAY sample_data, JDIMENSION start_col);
void
jpeg_fdct_1x1 (DCTELEM * data, JSAMPARRAY sample_data, JDIMENSION start_col)
{
  memset((void *)(data), 0, (size_t)(((size_t) sizeof(DCTELEM)) * 64));
  data[0] = (DCTELEM)
    ((((int) (sample_data[0][start_col])) - 128) << 6);
}
