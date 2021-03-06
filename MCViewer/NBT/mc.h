#pragma once
#include <conio.h>
#include <stdio.h>
#include <memory>
#include <string>
#include <vector>
#include <array>
#include <map>
#include <unordered_map>
#include <sstream>
#include <fstream>
#include <iostream>
//#include <boost/iostreams/filter/gzip.hpp>
//#include <boost/iostreams/device/array.hpp>
//#include <boost/iostreams/filtering_streambuf.hpp>
//#include <boost/iostreams/filtering_stream.hpp>
//#include <boost/iostreams/stream.hpp>
//#include <boost/filesystem/fstream.hpp>
//#include <boost/filesystem.hpp>
//#include <boost/locale/utf8_codecvt.hpp>
//#include <boost/iostreams/copy.hpp>
//#include <boost/archive/binary_iarchive.hpp>
//using ByteDevice = boost::iostreams::basic_array_source<__int8>;
//using ByteBuffer = boost::iostreams::stream_buffer<ByteDevice>;
#include <io.h>		// _wopen,_write,_close,_lseek
#include <fcntl.h>	// _O_RDONLY

namespace MC {
	static wchar_t _Buffer[_MAX_PATH * 2];

	enum COMPRESSION_SCHEME : __int32 {
		COMPRESSION_SCHEME_GZIP = 1,
		COMPRESSION_SCHEME_ZLIB_DEFLATE = 2,
	};

	inline __int16 BigEndian16(const __int16* littleEndian) {
		char* v = (char*)littleEndian;
		return (__int16)((v[0] & 0xff) << 8) | (v[1] & 0xff);
	}

	inline __int32 BigEndian32(const __int32* littleEndian) {
		char* v = (char*)littleEndian;
		return (__int32)(((v[0] & 0xff) << 24) | ((v[1] & 0xff) << 16) |
			((v[2] & 0xff) << 8) | (v[3] & 0xff));
	}

	inline __int64 BigEndian64(const __int64* littleEndian) {
		char* v = (char*)littleEndian;
		return (__int64)(((__int64)(v[0] & 0xff) << 56) |
			((__int64)(v[1] & 0xff) << 48) |
			((__int64)(v[2] & 0xff) << 40) |
			((__int64)(v[3] & 0xff) << 32) |
			((long)(v[4] & 0xff) << 24) |
			((long)(v[5] & 0xff) << 16) |
			((long)(v[6] & 0xff) << 8) |
			((long)(v[7] & 0xff)));
	}

	inline float BigEndianF(const __int32* littleEndian) {
		__int32 v = BigEndian32(littleEndian);
		return *(float*)&v;
	}

	inline double BigEndianD(const __int64* littleEndian) {
		__int64 v = BigEndian64(littleEndian);
		return *(double*)&v;
	}

	using NbtTagPtr = std::shared_ptr<class NbtTag>;
	using TagArray = std::vector<NbtTagPtr>;
	//using TagList = std::vector<const NbtTag*>;

	//namespace FS = boost::filesystem;
	//namespace IO = boost::iostreams;
	//using IFilteringStream = boost::iostreams::filtering_istream;
	//using OFilteringStream = boost::iostreams::filtering_ostream;

	extern const int MCREGION_VERSION_ID;
	extern const int ANVIL_VERSION_ID;
	extern const wchar_t* NETHER_FOLDER;
	extern const wchar_t* ENDER_FOLDER;

	using BoolArray = std::vector<bool>;
	using ByteArray = std::vector<__int8>;
	using IntArray = std::vector<__int32>;
	using LongArray = std::vector<__int64>;
	using StringArray = std::vector<std::wstring>;
	using SharedPtrC = std::shared_ptr<const __int8>;
	using SharedPtr2 = std::shared_ptr<__int16>;
	using SharedPtr4 = std::shared_ptr<__int32>;
	using SharedPtr8 = std::shared_ptr<__int64>;
	using UniquePtr = std::unique_ptr<char[]>;
	using UniquePtrB = std::unique_ptr<bool[]>;

#ifdef _DEBUG
	inline void DebugMessageW(const wchar_t* _Format, ...) {
		int _Result = 0;
		va_list _ArgList;
		__crt_va_start(_ArgList, _Format);
		_Result = vswprintf_s(_Buffer, _Format, _ArgList);
		__crt_va_end(_ArgList);
		//std::_Debug_message(_Buffer, __FILEW__, __LINE__);
		OutputDebugStringW(_Buffer);
	}
#else
#define DebugMessageW(msg)
#endif

	//
	//	inline int DebugMessageW(const wchar_t* _Format, ...) {
	//		int _Result = 0;
	//#ifdef _DEBUG
	//		static wchar_t _Buffer[128];
	//		va_list _ArgList;
	//		__crt_va_start(_ArgList, _Format);
	//		_Result = __vswprintf_l(_Buffer, _Format, NULL, _ArgList);
	//		__crt_va_end(_ArgList);
	//		//std::_Debug_message(_Buffer, __FILEW__, __LINE__);
	//		std::wcerr << _Buffer;
	//#endif
	//		return _Result;
	//	}
#define _SWAP_SHORT(l)                \
            ( ( ((l) >> 8) & 0x000000FFL ) |       \
              ( (l << 8) & 0x0000FF00L ) )

#define _SWAP_LONG(l)                \
            ( ( ((l) >> 24) & 0x000000FFL ) |       \
              ( ((l) >>  8) & 0x0000FF00L ) |       \
              ( ((l) <<  8) & 0x00FF0000L ) |       \
              ( ((l) << 24) & 0xFF000000L ) )

#define _SWAP_LONGLONG(l)            \
            ( ( ((l) >> 56) & 0x00000000000000FFLL ) |       \
              ( ((l) >> 40) & 0x000000000000FF00LL ) |       \
              ( ((l) >> 24) & 0x0000000000FF0000LL ) |       \
              ( ((l) >>  8) & 0x00000000FF000000LL ) |       \
              ( ((l) <<  8) & 0x000000FF00000000LL ) |       \
              ( ((l) << 24) & 0x0000FF0000000000LL ) |       \
              ( ((l) << 40) & 0x00FF000000000000LL ) |       \
              ( ((l) << 56) & 0xFF00000000000000LL ) )
}