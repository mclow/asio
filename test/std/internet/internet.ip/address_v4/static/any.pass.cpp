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
// 	static constexpr address_v4 any() noexcept;
//  ...
//  };
// 
// }}}} // namespace std::experimental::network_v1::ip
// 
// Returns: address_v4().



#include <experimental/internet>
#include <cassert>

namespace ip = std::experimental::network_v1::ip;

int main()
{
    static_assert ( noexcept(ip::address_v4::any()), "" );

    {
    ip::address_v4 addr0;
    ip::address_v4 addr1 = ip::address_v4::any();
    assert( addr0 == addr1 );
    }
    {
    constexpr ip::address_v4 addr0;
    constexpr ip::address_v4 addr1 = ip::address_v4::any();
    static_assert((addr0 == addr1), "");
    }
}
