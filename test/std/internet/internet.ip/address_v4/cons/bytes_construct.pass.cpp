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
//    constexpr address_v4(const bytes_type& bytes);
//  ...
//  };
// 
// }}}} // namespace std::experimental::network_v1::ip
// 
// Requires: Each element of bytes is in the range [0, 0xFF].
// 
// Throws: out_of_range if any element of bytes is not in the range [0, 0xFF]. 
//  [Note: For implementations where UCHAR_MAX == 0xFF, no out-of-range detection is needed]
// 
// Postconditions: to_bytes() == bytes and 
//  to_ulong() == (bytes[0] << 24) | (bytes[1] << 16) | (bytes[2] << 8) | bytes[3].


#include <experimental/internet>
#include <cassert>

namespace ip = std::experimental::network_v1::ip;

constexpr unsigned long from_bytes ( const ip::address_v4::bytes_type b )
{
    return (((unsigned long)b[0]) << 24)
         | (((unsigned long)b[1]) << 16)
         | (((unsigned long)b[2]) << 8)
         | b[3];
}

void test_throw()
{
#if UCHAR_MAX > 0xFF
    {
    ip::address_v4::bytes b1{2,4,6,512};
    try { ip::address_v4 addr1(b1); }
    catch ( const std::out_of_range & ) { return ; }
    assert ( false );
    }
#endif
}

int main()
{
    {
    ip::address_v4::bytes_type b1{2,4,6,8};
    ip::address_v4 addr1(b1);;
    ip::address_v4::bytes_type b = addr1.to_bytes ();
    assert(b[0] == 2);
    assert(b[1] == 4);
    assert(b[2] == 6);
    assert(b[3] == 8);
    assert(addr1.to_ulong() == from_bytes(b));
    }
    {
    constexpr ip::address_v4::bytes_type b1{2,4,6,8};
    constexpr ip::address_v4 addr1(b1);
    constexpr ip::address_v4::bytes_type b = addr1.to_bytes ();
    static_assert((b[0] == 2), "");
    static_assert((b[1] == 4), "");
    static_assert((b[2] == 6), "");
    static_assert((b[3] == 8), "");
    static_assert((addr1.to_ulong() == from_bytes(b)), "");
    }
    test_throw();
}
