typedef unsigned __int64 size_t;
void* __cdecl memset(
      void*  _Dst,
                               int    _Val,
                               size_t _Size
    );
typedef unsigned char JSAMPLE;
typedef long INT32;
typedef unsigned int JDIMENSION;
typedef JSAMPLE  *JSAMPROW;
typedef JSAMPROW *JSAMPARRAY;
typedef int DCTELEM;
extern void jpeg_fdct_5x5
    (DCTELEM * data, JSAMPARRAY sample_data, JDIMENSION start_col);
void
jpeg_fdct_5x5 (DCTELEM * data, JSAMPARRAY sample_data, JDIMENSION start_col)
{
  INT32 tmp0, tmp1, tmp2;
  INT32 tmp10, tmp11;
  DCTELEM *dataptr;
  JSAMPROW elemptr;
  int ctr;
  memset((void *)(data), 0, (size_t)(((size_t) sizeof(DCTELEM)) * 64));
  dataptr = data;
  for (ctr = 0; ctr < 5; ctr++) {
    elemptr = sample_data[ctr] + start_col;
    tmp0 = ((int) (elemptr[0])) + ((int) (elemptr[4]));
    tmp1 = ((int) (elemptr[1])) + ((int) (elemptr[3]));
    tmp2 = ((int) (elemptr[2]));
    tmp10 = tmp0 + tmp1;
    tmp11 = tmp0 - tmp1;
    tmp0 = ((int) (elemptr[0])) - ((int) (elemptr[4]));
    tmp1 = ((int) (elemptr[1])) - ((int) (elemptr[3]));
    dataptr[0] = (DCTELEM)
      ((tmp10 + tmp2 - 5 * 128) << (2+1));
    tmp11 = ((tmp11) * (((INT32) ((0.790569415) * (((INT32) 1) << 13) + 0.5))));
    tmp10 -= tmp2 << 2;
    tmp10 = ((tmp10) * (((INT32) ((0.353553391) * (((INT32) 1) << 13) + 0.5))));
    dataptr[2] = (DCTELEM) (((tmp11 + tmp10) + (((INT32) 1) << ((13-2-1)-1))) >> (13-2-1));
    dataptr[4] = (DCTELEM) (((tmp11 - tmp10) + (((INT32) 1) << ((13-2-1)-1))) >> (13-2-1));
    tmp10 = ((tmp0 + tmp1) * (((INT32) ((0.831253876) * (((INT32) 1) << 13) + 0.5))));
    dataptr[1] = (DCTELEM)
      (((tmp10 + ((tmp0) * (((INT32) ((0.513743148) * (((INT32) 1) << 13) + 0.5))))) + (((INT32) 1) << ((13-2-1)-1))) >> (13-2-1));
    dataptr[3] = (DCTELEM)
      (((tmp10 - ((tmp1) * (((INT32) ((2.176250899) * (((INT32) 1) << 13) + 0.5))))) + (((INT32) 1) << ((13-2-1)-1))) >> (13-2-1));
    dataptr += 8;
  }
  dataptr = data;
  for (ctr = 0; ctr < 5; ctr++) {
    tmp0 = dataptr[8*0] + dataptr[8*4];
    tmp1 = dataptr[8*1] + dataptr[8*3];
    tmp2 = dataptr[8*2];
    tmp10 = tmp0 + tmp1;
    tmp11 = tmp0 - tmp1;
    tmp0 = dataptr[8*0] - dataptr[8*4];
    tmp1 = dataptr[8*1] - dataptr[8*3];
    dataptr[8*0] = (DCTELEM)
      (((((tmp10 + tmp2) * (((INT32) ((1.28) * (((INT32) 1) << 13) + 0.5))))) + (((INT32) 1) << ((13+2)-1))) >> (13+2));
    tmp11 = ((tmp11) * (((INT32) ((1.011928851) * (((INT32) 1) << 13) + 0.5))));
    tmp10 -= tmp2 << 2;
    tmp10 = ((tmp10) * (((INT32) ((0.452548340) * (((INT32) 1) << 13) + 0.5))));
    dataptr[8*2] = (DCTELEM) (((tmp11 + tmp10) + (((INT32) 1) << ((13+2)-1))) >> (13+2));
    dataptr[8*4] = (DCTELEM) (((tmp11 - tmp10) + (((INT32) 1) << ((13+2)-1))) >> (13+2));
    tmp10 = ((tmp0 + tmp1) * (((INT32) ((1.064004961) * (((INT32) 1) << 13) + 0.5))));
    dataptr[8*1] = (DCTELEM)
      (((tmp10 + ((tmp0) * (((INT32) ((0.657591230) * (((INT32) 1) << 13) + 0.5))))) + (((INT32) 1) << ((13+2)-1))) >> (13+2));
    dataptr[8*3] = (DCTELEM)
      (((tmp10 - ((tmp1) * (((INT32) ((2.785601151) * (((INT32) 1) << 13) + 0.5))))) + (((INT32) 1) << ((13+2)-1))) >> (13+2));
    dataptr++;
  }
}
