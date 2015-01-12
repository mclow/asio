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
//  static constexpr address_v4 broadcast() noexcept;
//  static constexpr address_v4 broadcast(const address_v4& addr, const address_v4& mask) noexcept;
//  ...
//  };
// 
// }}}} // namespace std::experimental::network_v1::ip
// 
// Returns: address_v4(0xFFFFFFFF)



#include <experimental/internet>
#include <cassert>

namespace ip = std::experimental::network_v1::ip;

int main()
{
    static_assert ( noexcept(ip::address_v4::broadcast()), "" );

    {
    ip::address_v4 addr0(0xFFFFFFFF);
    ip::address_v4 addr1 = ip::address_v4::broadcast();
    assert( addr0 == addr1 );
    }
    {
    constexpr ip::address_v4 addr0(0xFFFFFFFF);
    constexpr ip::address_v4 addr1 = ip::address_v4::broadcast();
    static_assert((addr0 == addr1), "");
    }
}
