
#ifndef _INT_TO_HEX_H_
#define _INT_TO_HEX_H_

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif


inline static void uint32tohex(char dst[8], uint32_t val)
{
	// clang-format off
	const uint16_t* const mm = (const uint16_t* const)
		"000102030405060708090A0B0C0D0E0F101112131415161718191A1B1C1D1E1F"
		"202122232425262728292A2B2C2D2E2F303132333435363738393A3B3C3D3E3F"
		"404142434445464748494A4B4C4D4E4F505152535455565758595A5B5C5D5E5F"
		"606162636465666768696A6B6C6D6E6F707172737475767778797A7B7C7D7E7F"
		"808182838485868788898A8B8C8D8E8F909192939495969798999A9B9C9D9E9F"
		"A0A1A2A3A4A5A6A7A8A9AAABACADAEAFB0B1B2B3B4B5B6B7B8B9BABBBCBDBEBF"
		"C0C1C2C3C4C5C6C7C8C9CACBCCCDCECFD0D1D2D3D4D5D6D7D8D9DADBDCDDDEDF"
		"E0E1E2E3E4E5E6E7E8E9EAEBECEDEEEFF0F1F2F3F4F5F6F7F8F9FAFBFCFDFEFF";
	// clang-format on
	uint16_t* const p = (uint16_t* const)dst;
	p[0] = mm[(val & 0xFF000000) >> 24];
	p[1] = mm[(val & 0x00FF0000) >> 16];
	p[2] = mm[(val & 0x0000FF00) >> 8];
	p[3] = mm[val & 0xFF];
}
inline static void uint32tohex_tail(char dst[9], uint32_t val)
{
	uint32tohex(dst, val);
	dst[8] = '\0';
}


inline static void int32tohex(char dst[9], int32_t val)
{
	if (val < 0)
	{
		*dst = '-';
		uint32tohex(dst + 1, 0 - val);
	} else
	{
		uint32tohex(dst, val);
	}
}
inline static void int32tohex_tail(char dst[10], int32_t val)
{
	if (val < 0)
	{
		*dst = '-';
		uint32tohex(dst + 1, 0 - val);
		dst[9] = '\0';
	} else
	{
		uint32tohex(dst, val);
		dst[8] = '\0';
	}
}


inline static void uint64tohex(char dst[16], uint64_t val)
{
	uint32tohex(dst, (uint32_t)(val >> 32ULL));
	uint32tohex(dst + 8, (uint32_t)val);
}
inline static void uint64tohex_tail(char dst[17], uint64_t val)
{
	uint64tohex(dst, val);
	dst[16] = '\0';
}


inline static void int64tohex(char dst[17], int64_t val)
{
	if (val < 0)
	{
		*dst = '-';
		uint64tohex(dst + 1, 0 - val);
	} else
	{
		uint64tohex(dst, val);
	}
}
inline static void int64tohex_tail(char dst[18], int64_t val)
{
	if (val < 0)
	{
		*dst = '-';
		uint64tohex(dst + 1, 0 - val);
		dst[17] = '\0';
	} else
	{
		uint64tohex(dst, val);
		dst[16] = '\0';
	}
}


#ifdef __cplusplus
}
#endif

#endif
