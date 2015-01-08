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
//    constexpr address_v4() noexcept;
//  ...
//  };
// 
// }}}} // namespace std::experimental::network_v1::ip

#include <experimental/internet>
#include <cassert>

namespace ip = std::experimental::network_v1::ip;

int main()
{
    {
    ip::address_v4 addr1;
    assert(addr1.to_ulong() == 0);
    ip::address_v4::bytes_type b = addr1.to_bytes ();
    assert(b[0] == 0);
    assert(b[1] == 0);
    assert(b[2] == 0);
    assert(b[3] == 0);
    }
    {
    constexpr ip::address_v4 addr1;
    static_assert((addr1.to_ulong() == 0), "");
    constexpr ip::address_v4::bytes_type b = addr1.to_bytes ();
    static_assert((b[0] == 0), "");
    static_assert((b[1] == 0), "");
    static_assert((b[2] == 0), "");
    static_assert((b[3] == 0), "");
    }
}
