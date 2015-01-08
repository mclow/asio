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
//  class address_v6 {
//  public:
//  ...
//    constexpr address_v6(const bytes_type& bytes, unsigned long scope = 0);
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
// Postconditions: to_bytes() == bytes and scope_id() == scope


#include <experimental/internet>
#include <cassert>

namespace ip = std::experimental::network_v1::ip;

void test_throw()
{
#if UCHAR_MAX > 0xFF
    {
    ip::address_v6::bytes_type b1{2,4,6,512,0,0,0,0,0,0,0,0,0,0,0,0};
    try { ip::address_v6 addr1(b1); }
    catch ( const std::out_of_range & ) { return ; }
    assert ( false );
    }
#endif
}

int main()
{
    {
    ip::address_v6::bytes_type b1{0,2,4,6,8,1,3,5,7,9,11,13,17,19,23,29};
    ip::address_v6 addr1(b1);
    ip::address_v6::bytes_type b = addr1.to_bytes ();
    assert(b[ 0] ==  0);
    assert(b[ 1] ==  2);
    assert(b[ 2] ==  4);
    assert(b[ 3] ==  6);
    assert(b[ 4] ==  8);
    assert(b[ 5] ==  1);
    assert(b[ 6] ==  3);
    assert(b[ 7] ==  5);
    assert(b[ 8] ==  7);
    assert(b[ 9] ==  9);
    assert(b[10] == 11);
    assert(b[11] == 13);
    assert(b[12] == 17);
    assert(b[13] == 19);
    assert(b[14] == 23);
    assert(b[15] == 29);
    }
    {
    constexpr ip::address_v6::bytes_type b1{0,2,4,6,8,1,3,5,7,9,11,13,17,19,23,29};
    constexpr ip::address_v6 addr1(b1);
    constexpr ip::address_v6::bytes_type b = addr1.to_bytes ();
    static_assert((b[ 0] ==  0), "");
    static_assert((b[ 1] ==  2), "");
    static_assert((b[ 2] ==  4), "");
    static_assert((b[ 3] ==  6), "");
    static_assert((b[ 4] ==  8), "");
    static_assert((b[ 5] ==  1), "");
    static_assert((b[ 6] ==  3), "");
    static_assert((b[ 7] ==  5), "");
    static_assert((b[ 8] ==  7), "");
    static_assert((b[ 9] ==  9), "");
    static_assert((b[10] == 11), "");
    static_assert((b[11] == 13), "");
    static_assert((b[12] == 17), "");
    static_assert((b[13] == 19), "");
    static_assert((b[14] == 23), "");
    static_assert((b[15] == 29), "");
    }
    test_throw();
}
