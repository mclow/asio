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
//    constexpr address_v4(const address_v4& a) noexcept;
//  ...
//  };
// 
// }}}} // namespace std::experimental::network_v1::ip
//
//  Postconditions: *this == a


#include <experimental/internet>
#include <cassert>

namespace ip = std::experimental::network_v1::ip;

int main()
{
    {
    ip::address_v4 addr1;
    ip::address_v4 addr2 = addr1;
    ip::address_v4 addr3(123456);
    ip::address_v4 addr4 = addr3;
    assert(addr1 == addr2);
    assert(addr1 != addr3);
    assert(addr3 == addr4);
    }
    {
    constexpr ip::address_v4 addr1;
    constexpr ip::address_v4 addr2 = addr1;
    constexpr ip::address_v4 addr3(654321);
    constexpr ip::address_v4 addr4 = addr3;
    static_assert((addr1 == addr2), "");
    static_assert((addr1 != addr3), "");
    static_assert((addr3 == addr4), "");
    }
}
