#include "int2hex.h"

int main()
{
	{
		char dst[10] = { 0 };
		uint32tohex_tail(dst, 0xEF430A12);
		uint32tohex_tail(dst, 0x0);
		uint32tohex_tail(dst, 0x84);
		uint32tohex_tail(dst, 0x4451);
		uint32tohex_tail(dst, 0x62654);
		uint32tohex_tail(dst, 0x3412654);
		uint32tohex_tail(dst, UINT32_MAX);

		dst[0] = 0;
	}
	{
		char dst[10] = { 0 };
		int32tohex_tail(dst, -0x3F430A12);
		int32tohex_tail(dst, -1);
		int32tohex_tail(dst, INT32_MAX);
		int32tohex_tail(dst, INT32_MIN);

		dst[0] = 0;
	}

	{
		char dst[18] = { 0 };
		uint64tohex_tail(dst, 0x3F30A12);
		uint64tohex_tail(dst, 0x3F43F430A1230A12);
		uint64tohex_tail(dst, 0);
		uint64tohex_tail(dst, UINT64_MAX);

		dst[0] = 0;
	}

	{
		char dst[18] = { 0 };
		int64tohex_tail(dst, -0x3120A12);
		int64tohex_tail(dst, -0x3F43F430A1230A12);
		int64tohex_tail(dst, -1);
		int64tohex_tail(dst, INT64_MAX);
		int64tohex_tail(dst, INT64_MIN);

		dst[0] = 0;
	}
}
