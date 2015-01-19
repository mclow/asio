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
//   address make_address(const char* str);
// 
// }}}} // namespace std::experimental::network_v1::ip
// 
// Returns: address_v6(bytes, scope_id)



#include <experimental/internet>
#include <cassert>

namespace ip = std::experimental::network_v1::ip;

void pass(const char *s)
{
    ip::address addr0 = ip::make_address(s);
    std::string str = addr0.to_string();
    ip::address addr1 = ip::make_address(str);
    assert(addr0 == addr1); 
}

void fail(const char *s)
{
    try { ip::address addr0 = ip::make_address(s); }
    catch ( const std::error_code &ec )
    {
        assert(ec == std::make_error_code(std::errc::invalid_argument));
        return ;
    }
    assert(false);
}

int main()
{

//  IPv4 strings
    pass("1.2.3.4");
    pass("127.0.0.1");
    pass("127.0.34.1");
    fail("127");
    fail("127.");
    
//  IPv6 strings
    pass("00:01:02:03:04:05:06:07:08:09:0A:0B:0C:0D:0E:0F");
    pass("00:11:22:33:44:55:66:77:88:99:AA:BB:CC:DD:EE:FF");

    fail("");
    fail("7F:0.0.1");
    fail("abcdef");
    fail("zyxwvuts");
}
