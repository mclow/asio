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
#include <string>
#include <cassert>

namespace net = std::experimental::network_v1;

int main()
{
	static_assert (!net::is_const_buffer_sequence<void>::value, "" );
	static_assert (!net::is_const_buffer_sequence<int>::value, "" );
	static_assert (!net::is_const_buffer_sequence<double>::value, "" );
	static_assert (!net::is_const_buffer_sequence<std::string>::value, "" );

	static_assert (!net::is_const_buffer_sequence<net::const_buffer>::value, "" );
	static_assert (!net::is_const_buffer_sequence<net::mutable_buffer>::value, "" );
	
	static_assert ( net::is_const_buffer_sequence<net::const_buffers_1>::value, "" );
	static_assert ( net::is_const_buffer_sequence<net::mutable_buffers_1>::value, "" );

	static_assert (!net::is_const_buffer_sequence<net::dynamic_vector_buffer<char, std::allocator<char>>>::value, "" );
	static_assert (!net::is_const_buffer_sequence<net::dynamic_string_buffer<char, std::char_traits<char>, std::allocator<char>>>::value, "" );
}
