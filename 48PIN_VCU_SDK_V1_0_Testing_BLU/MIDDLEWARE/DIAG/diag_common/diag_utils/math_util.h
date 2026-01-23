#include <stdint.h>
#include "diag_typedefs.h"

#define SETBIT(x,bitpos)        ((x) |= (1 << (bitpos)))
#define CLRBIT(x,bitpos)        ((x) &= ~(1 << (bitpos)))
#define GETBIT(x,bitpos)        (((x) & (1 << (bitpos))) != 0)
#define PUTBIT(x,bitpos,val)    ((val) ? SETBIT(x,bitpos) : CLRBIT(x,bitpos))

/* Macros to set and clear registers with bitmasks*/
#define SETBITMASK(reg,bitmask)((reg) |= bitmask)
#define CLRBITMASK(reg,bitmask)((reg) &= (~bitmask))

#define ABS(a)          ((a)<0)?((a) * -1):(a)
#define MIN(a,b)        (((a)<(b))?(a):(b))
#define MAX(a,b)        (((a)<(b))?(b):(a))
#define LIMIT(lo,x,hi)  (((x)<(lo))?(lo):((x)>(hi))?(hi):(x))

#define SWAP_BYTES_IN_WORD(x)  (((x>>8) & 0x00FF) | ((x<<8) & 0xFF00))

#define CHANGE_ENDIAN_U32(x)        ((((x) >> 24) & 0x000000FF ) | \
                                     (((x) >> 8 ) & 0x0000FF00 ) | \
									 (((x) << 8 ) & 0x00FF0000 ) | \
									 (((x) << 24) & 0xFF000000 ))


uint32_t CalcAdditiveChecksum (const uint32_t len_u32, const uint8_t* data_pu8);
