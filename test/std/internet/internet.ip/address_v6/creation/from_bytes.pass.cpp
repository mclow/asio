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
//   constexpr address_v6 make_address_v6(const address_v6::bytes_type& bytes,
//                                        unsigned long scope_id);
// }}}} // namespace std::experimental::network_v1::ip
// 
// Returns: address_v6(bytes, scope_id)



#include <experimental/internet>
#include <cassert>

namespace ip = std::experimental::network_v1::ip;

int main()
{
//     static_assert ( noexcept(ip::address_v6::any()), "" );

    constexpr ip::address_v6::bytes_type b0{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    constexpr ip::address_v6::bytes_type b1{1,2,3,4,5,6,7,8,7,6,5,4,3,2,1,0};

    {
    ip::address_v6 addr0 = ip::make_address_v6(b0, 0);
    ip::address_v6 addr1 = ip::make_address_v6(b1, 1);
    ip::address_v6 addr2 = ip::make_address_v6(b1, 2);
    assert( (addr0 == ip::address_v6{b0, 0}));
    assert( (addr1 == ip::address_v6{b1, 1}));
    assert( (addr2 == ip::address_v6{b1, 2}));
    }
    {
    constexpr ip::address_v6 addr0 = ip::make_address_v6(b0, 0);
    constexpr ip::address_v6 addr1 = ip::make_address_v6(b1, 1);
    constexpr ip::address_v6 addr2 = ip::make_address_v6(b1, 2);
    static_assert( (addr0 == ip::address_v6{b0, 0}), "");
    static_assert( (addr1 == ip::address_v6{b1, 1}), "");
    static_assert( (addr2 == ip::address_v6{b1, 2}), "");
    }
}
