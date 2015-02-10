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
#include <type_traits>
#include <cassert>

namespace net = std::experimental::network_v1;

void test(const net::transfer_all &trans, size_t sz) // pass as const ref tests that op() is const
{
	std::error_code err   = std::make_error_code(std::errc::bad_address);
	assert ( trans(err, 1234) == 0 );
	static_assert((std::is_same<decltype(trans(err, 1234)), size_t>::value), "");

	std::error_code noErr;
	assert ( trans(noErr, 0)        >  0 );
	assert ( trans(noErr, sz - 100) >  0 );
	assert ( trans(noErr, sz -   1) >  0 );
	assert ( trans(noErr, sz)       >  0 );
	assert ( trans(noErr, sz +   1) >  0 );
	assert ( trans(noErr, sz + 100) >  0 );
}

int main()
{
// 	static_assert(std::is_same<net::transfer_all()::result_type, size_t>::value, "" );
// 	static_assert(std::is_same<net::transfer_all()::first_argument_type, const std::error_code &>::value, "" );
// 	static_assert(std::is_same<net::transfer_all()::second_argument_type, size_t>::value, "" );
	
	test(net::transfer_all(), 1000);
}
