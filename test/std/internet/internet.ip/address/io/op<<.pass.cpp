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
//
// basic_ostream<CharT, Traits>& operator<<(
// basic_ostream<CharT, Traits>& __os, const address_64& __addr);
// 
// }}}} // namespace std::experimental::network_v1::ip
// 
// Effects: Outputs the string representation of the address to the stream, as if:
// 
//  string s = addr.to_string();
//      for (string::iterator i = s.begin(); i != s.end(); ++i)
//          os << os.widen(*i);

#include <experimental/internet>
#include <sstream>
#include <cassert>

namespace ip = std::experimental::network_v1::ip;

void test_empty(const ip::address& addr)
{
    std::stringstream ss;
    try { ss << addr; }
    catch ( const ip::bad_address_cast &) { return ; }
    assert(false);
}

void test(const ip::address& addr)
{
    std::stringstream ss;
    ss << addr;
    assert(ss.str() == addr.to_string());
}

int main()
{

    test_empty(ip::address{});
    
    test(ip::address{ip::address_v4()});
    test(ip::address{ip::address_v4(123456)});
    test(ip::address{ip::address_v4::any()});
    test(ip::address{ip::address_v4::loopback()});
    test(ip::address{ip::address_v4{ip::address_v4::bytes_type{0,17,34,51}}});
    
    test(ip::address{ip::address_v6()});
    test(ip::address{ip::address_v6::any()});
    test(ip::address{ip::address_v6::loopback()});
    test(ip::address{ip::address_v6{
         ip::address_v6::bytes_type{0,17,34,51,68,85,102,119,136,153,170,187,204,221,238,255}}});
    
}
