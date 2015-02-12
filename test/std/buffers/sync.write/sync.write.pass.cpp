// -*- C++ -*-
//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is dual licensed under the MIT and the University of Illinois Open
// Source Licenses. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

#include <experimental/buffer>
#include <vector>
#include <cassert>

namespace net = std::experimental::network_v1;

//	Is a synchronous write stream object
class VectorWriteStream {
private:
	std::vector<char> v_;
public:
	VectorWriteStream() {}
	~VectorWriteStream() {}
	
	size_t write_some(net::const_buffer buf, std::error_code& ec)
	{
		const char *p = net::buffer_cast<const char *>(buf);
		size_t ret = net::buffer_size(buf);
		for ( size_t i = 0; i < ret; ++i )
			v_.push_back(*p++);
		return ret;
	}
	
	size_t write_some(net::const_buffer buf)
	{
		std::error_code ec;
		size_t ret = write_some(buf, ec);
		if (ec) throw std::system_error(ec, "write_some");
		return ret;
	}
	
	size_t size() const { return v_.size(); }
	const char *data() const { return v_.data(); }
	};

int main()
{
	const char *src = "0123456789_123456789_123456789_123456789";
	net::const_buffer buf(src, strlen(src));
	VectorWriteStream stream;
	net::write(stream, buf);
	assert(stream.size() == buf.size());
	assert(memcmp(stream.data(), src, stream.size()) == 0);
}
