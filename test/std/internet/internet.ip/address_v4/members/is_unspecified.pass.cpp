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
//  class address_v4 {
//  public:
//  ...
// 	constexpr bool is_unspecified() const noexcept;
//  ...
//  };
// 
// }}}} // namespace std::experimental::network_v1::ip
// 
// Returns: to_ulong() == 0.



#include <experimental/internet>
#include <cassert>

namespace ip = std::experimental::network_v1::ip;

constexpr bool test(const ip::address_v4 &addr)
{ return addr.is_unspecified() == (addr.to_ulong() == 0); }

int main()
{
    static_assert ( noexcept(ip::address_v4().is_unspecified()), "" );

    {
    ip::address_v4 addr0;
    ip::address_v4 addr1(ip::address_v4::bytes_type{1,2,3,4});
    ip::address_v4 addr2(ip::address_v4::bytes_type{0,0,0,0});
    assert(test(addr0));
    assert(test(addr1));
    assert(test(addr2));
    }
    {
    constexpr ip::address_v4 addr0;
    constexpr ip::address_v4 addr1(ip::address_v4::bytes_type{1,2,3,4});
    constexpr ip::address_v4 addr2(ip::address_v4::bytes_type{0,0,0,0});
    static_assert((test(addr0)), "");
    static_assert((test(addr1)), "" );
    static_assert((test(addr2)), "" );
    }
}
