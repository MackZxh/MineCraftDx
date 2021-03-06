// blockViewer.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <conio.h>
//#include <boost/lambda/lambda.hpp>
//#include <iostream>
//#include <iterator>
//#include <algorithm>
#include <boost/regex.hpp>
//#include <fstream>
#include <boost/iostreams/device/file.hpp>

#include <boost/iostreams/filtering_stream.hpp>
#include <boost/iostreams/filter/gzip.hpp>
//#include <vector>
#include <boost/array.hpp>
#include<array>
#include <boost/iostreams/device/array.hpp>
#include <boost/iostreams/stream.hpp>

const wchar_t AssetsPath[] = L"E:/Games/MineCraft/assets/";
const std::string levelFile = "E:/Games/MineCraft/.minecraft/versions/1.12.2/saves/新的世界/level.dat";

int main()
{
	boost::iostreams::file_source file(levelFile, std::ios_base::binary);
	boost::iostreams::stream_offset offset = 0;
	std::streampos fileSize = file.seek(offset, BOOST_IOS::_Seekend);
	file.seek(0, BOOST_IOS::_Seekbeg);

	//file.exceptions(std::ios::failbit | std::ios::badbit);
	//file.open(levelFile, std::ios_base::in | std::ios_base::binary);

	boost::iostreams::filtering_istream decompressor;
	decompressor.push(boost::iostreams::gzip_decompressor());
	//decompressor.push(file);

	std::unique_ptr<char[]> dp = std::make_unique<char[]>(fileSize);
	file.read(dp.get(), fileSize);
	file.close();

	boost::iostreams::array_source da(dp.get(), fileSize);
	decompressor.push(da);

	size_t size = decompressor.size();
	std::streamsize ssize = decompressor.width();

	std::vector<char> dataBuf = std::vector<char>(
		std::istreambuf_iterator<char>(decompressor)
		, std::istreambuf_iterator<char>()
		);

	size = dataBuf.size();

	const char*           h = "Hello World!";
	boost::iostreams::stream<boost::iostreams::array_source>  in(h, std::strlen(h));
	//in = decompressor;

	_getch();
	return 0;
}