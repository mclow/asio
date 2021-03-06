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
// basic_ostream<CharT, Traits>& __os, const address_v6& __addr);
// 
// }}}} // namespace std::experimental::network_v1::ip
// 
// Effects: Outputs the string representation of the address to the stream, as if:
// 
//  string s = addr.to_string();
//      for (string::iterator i = s.begin(); i != s.end(); ++i)
//          os << os.widen(*i);

#include <experimental/internet>
#include <cassert>

namespace ip = std::experimental::network_v1::ip;
typedef std::experimental::string_view SV;

SV make_sv(const char *s) { return SV{s, strlen(s)}; }

void pass(SV sv, const ip::address_v6::bytes_type &b)
{
    ip::address_v6 addr = ip::make_address_v6(sv);
    assert(addr.to_bytes() == b);   
}

void fail(SV sv)
{
    try { ip::address_v6 addr = ip::make_address_v6(sv); }
    catch ( const std::error_code &ec )
    {
        assert(ec == std::make_error_code(std::errc::invalid_argument));
        return ;
    }
    assert(false);
}

int main()
{

    pass(make_sv("00:01:02:03:04:05:06:07:08:09:0A:0B:0C:0D:0E:0F"),
        ip::address_v6::bytes_type{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15});
    pass(make_sv("00:11:22:33:44:55:66:77:88:99:AA:BB:CC:DD:EE:FF"), 
        ip::address_v6::bytes_type{0,17,34,51,68,85,102,119,136,153,170,187,204,221,238,255});

    fail(make_sv(""));
    fail(make_sv("127.0.0.1"));
    fail(make_sv("7F:0.0.1"));
    fail(make_sv("abcdef"));
    fail(make_sv("zyxwvuts"));

}
