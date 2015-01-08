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
//    explicit constexpr address_v4(unsigned long val);
//  ...
//  };
// 
// }}}} // namespace std::experimental::network_v1::ip
// 
// Throws: out_of_range if val is not in the range [0, 0xFFFFFFFF]. 
// [Note: For implementations where ULONG_MAX == 0xFFFFFFFF, no out-of-range detection is needed. —end note]
// 
// Postconditions: to_ulong() == val and to_bytes() is 
//  { (val >> 24) & 0xFF, (val >> 16) & 0xFF, (val >> 8) & 0xFF, val & 0xFF }.


#include <experimental/internet>
#include <cassert>

namespace ip = std::experimental::network_v1::ip;

constexpr bool bytes_match_long ( const ip::address_v4::bytes_type b, unsigned long l )
{
    return (b[0] == ((l >> 24) & 0xFF))
        && (b[1] == ((l >> 16) & 0xFF))
        && (b[2] == ((l >>  8) & 0xFF))
        && (b[3] == ((l      ) & 0xFF));
}

void test_throw()
{
#if ULONG_MAX > 0xFFFFFFFF
    {
    try { ip::address_v4 addr1(0x100000000); }
    catch ( const std::out_of_range & ) { return ; }
    assert ( false );
    }
#endif
}
    
int main()
{
    {
    ip::address_v4 addr1(123456);
    assert(addr1.to_ulong() == 123456);
    assert(bytes_match_long(addr1.to_bytes(), addr1.to_ulong()));
    }
    {
    constexpr ip::address_v4 addr1(123456);
    static_assert((addr1.to_ulong() == 123456), "");
    static_assert((bytes_match_long(addr1.to_bytes(), addr1.to_ulong())), "");
    }
    test_throw();
}
