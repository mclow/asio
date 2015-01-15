// -*- C++ -*-
//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is dual licensed under the MIT and the University of Illinois Open
// Source Licenses. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// namespace std {  namespace experimental { inline namespace network_v1 {  namespace ip {
//   constexpr address_v4 make_address_v4(const address_v4::bytes_type& bytes);
// }}}} // namespace std::experimental::network_v1::ip
// 
// Returns: address_v4(bytes)



#include <experimental/internet>
#include <cassert>

namespace ip = std::experimental::network_v1::ip;

int main()
{
//     static_assert ( noexcept(ip::address_v4::any()), "" );

	constexpr ip::address_v4::bytes_type b0{0,0,0,0};
	constexpr ip::address_v4::bytes_type b1{1,2,3,4};

    {
    ip::address_v4 addr0 = ip::make_address_v4(b0);
    ip::address_v4 addr1 = ip::make_address_v4(b1);
    assert( (addr0 == ip::address_v4{b0}));
    assert( (addr1 == ip::address_v4{b1}));
    }
    {
    constexpr ip::address_v4 addr0 = ip::make_address_v4(b0);
    constexpr ip::address_v4 addr1 = ip::make_address_v4(b1);
    static_assert( (addr0 == ip::address_v4{b0}), "");
    static_assert( (addr1 == ip::address_v4{b1}), "");
    }
}
