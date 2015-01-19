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
//  constexpr constexpr bytes_type to_bytes() const noexcept;
//  ...
//  };
// 
// }}}} // namespace std::experimental::network_v1::ip
// 



#include <experimental/internet>
#include <cassert>

namespace ip = std::experimental::network_v1::ip;
int main()
{
    static_assert ( noexcept(ip::address_v4().to_bytes()), "" );

    constexpr ip::address_v4::bytes_type b1{1,2,3,4};
    constexpr ip::address_v4::bytes_type b2{0x80,1,2,3};

    {
    ip::address_v4 addr0;
    ip::address_v4 addr1{b1};
    ip::address_v4 addr2{b2};
    assert( (addr0.to_bytes() == ip::address_v4::bytes_type{0,0,0,0}));
    assert( (addr1.to_bytes() == b1));
    assert( (addr2.to_bytes() == b2));
    }
    {
    constexpr ip::address_v4 addr0;
    constexpr ip::address_v4 addr1{b1};
    constexpr ip::address_v4 addr2{b2};
    static_assert((addr0.to_bytes() == ip::address_v4::bytes_type{0,0,0,0}), "");
    static_assert((addr1.to_bytes() == b1), "" );
    static_assert((addr2.to_bytes() == b2), "" );
    }
}
