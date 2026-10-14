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
extern void jpeg_fdct_10x5
    (DCTELEM * data, JSAMPARRAY sample_data, JDIMENSION start_col);
void
jpeg_fdct_10x5 (DCTELEM * data, JSAMPARRAY sample_data, JDIMENSION start_col)
{
  INT32 tmp0, tmp1, tmp2, tmp3, tmp4;
  INT32 tmp10, tmp11, tmp12, tmp13, tmp14;
  DCTELEM *dataptr;
  JSAMPROW elemptr;
  int ctr;
  memset((void *)(&data[8*5]), 0, (size_t)(((size_t) sizeof(DCTELEM)) * 8 * 3));
  dataptr = data;
  for (ctr = 0; ctr < 5; ctr++) {
    elemptr = sample_data[ctr] + start_col;
    tmp0 = ((int) (elemptr[0])) + ((int) (elemptr[9]));
    tmp1 = ((int) (elemptr[1])) + ((int) (elemptr[8]));
    tmp12 = ((int) (elemptr[2])) + ((int) (elemptr[7]));
    tmp3 = ((int) (elemptr[3])) + ((int) (elemptr[6]));
    tmp4 = ((int) (elemptr[4])) + ((int) (elemptr[5]));
    tmp10 = tmp0 + tmp4;
    tmp13 = tmp0 - tmp4;
    tmp11 = tmp1 + tmp3;
    tmp14 = tmp1 - tmp3;
    tmp0 = ((int) (elemptr[0])) - ((int) (elemptr[9]));
    tmp1 = ((int) (elemptr[1])) - ((int) (elemptr[8]));
    tmp2 = ((int) (elemptr[2])) - ((int) (elemptr[7]));
    tmp3 = ((int) (elemptr[3])) - ((int) (elemptr[6]));
    tmp4 = ((int) (elemptr[4])) - ((int) (elemptr[5]));
    dataptr[0] = (DCTELEM)
      ((tmp10 + tmp11 + tmp12 - 10 * 128) << 2);
    tmp12 += tmp12;
    dataptr[4] = (DCTELEM)
      (((((tmp10 - tmp12) * (((INT32) ((1.144122806) * (((INT32) 1) << 13) + 0.5)))) - ((tmp11 - tmp12) * (((INT32) ((0.437016024) * (((INT32) 1) << 13) + 0.5))))) + (((INT32) 1) << ((13-2)-1))) >> (13-2));
    tmp10 = ((tmp13 + tmp14) * (((INT32) ((0.831253876) * (((INT32) 1) << 13) + 0.5))));
    dataptr[2] = (DCTELEM)
      (((tmp10 + ((tmp13) * (((INT32) ((0.513743148) * (((INT32) 1) << 13) + 0.5))))) + (((INT32) 1) << ((13-2)-1))) >> (13-2));
    dataptr[6] = (DCTELEM)
      (((tmp10 - ((tmp14) * (((INT32) ((2.176250899) * (((INT32) 1) << 13) + 0.5))))) + (((INT32) 1) << ((13-2)-1))) >> (13-2));
    tmp10 = tmp0 + tmp4;
    tmp11 = tmp1 - tmp3;
    dataptr[5] = (DCTELEM) ((tmp10 - tmp11 - tmp2) << 2);
    tmp2 <<= 13;
    dataptr[1] = (DCTELEM)
      (((((tmp0) * (((INT32) ((1.396802247) * (((INT32) 1) << 13) + 0.5)))) + ((tmp1) * (((INT32) ((1.260073511) * (((INT32) 1) << 13) + 0.5)))) + tmp2 + ((tmp3) * (((INT32) ((0.642039522) * (((INT32) 1) << 13) + 0.5)))) + ((tmp4) * (((INT32) ((0.221231742) * (((INT32) 1) << 13) + 0.5))))) + (((INT32) 1) << ((13-2)-1))) >> (13-2));
    tmp12 = ((tmp0 - tmp4) * (((INT32) ((0.951056516) * (((INT32) 1) << 13) + 0.5)))) -
	    ((tmp1 + tmp3) * (((INT32) ((0.587785252) * (((INT32) 1) << 13) + 0.5))));
    tmp13 = ((tmp10 + tmp11) * (((INT32) ((0.309016994) * (((INT32) 1) << 13) + 0.5)))) +
	    (tmp11 << (13 - 1)) - tmp2;
    dataptr[3] = (DCTELEM) (((tmp12 + tmp13) + (((INT32) 1) << ((13-2)-1))) >> (13-2));
    dataptr[7] = (DCTELEM) (((tmp12 - tmp13) + (((INT32) 1) << ((13-2)-1))) >> (13-2));
    dataptr += 8;
  }
  dataptr = data;
  for (ctr = 8-1; ctr >= 0; ctr--) {
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
