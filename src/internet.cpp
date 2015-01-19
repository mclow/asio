// -*- C++ -*-
//===-------------------------- internet.cpp ------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is dual licensed under the MIT and the University of Illinois Open
// Source Licenses. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

#include <experimental/internet>

#include <regex>

_LIBCPP_BEGIN_NAMESPACE_NETWORK_IP

char __to_hex(int __v) { return char(__v > 9 ? 'A' - 10 + __v : '0' + __v); }

// -- string conversions --
_VSTD::string address_v4::to_string() const // TODO: temporary implementation
{
    _VSTD::string ret(16, '0');
    auto it = ret.begin();
    for ( const auto c : __bytes ) {
        if ( c >= 100 )
            *it++ += ( c / 100 ) % 10;
        if ( c >= 10 )
            *it++  += ( c / 10 ) % 10;
        *it++  += c % 10;
        *it++  = '.';
        }
    ret.erase ( --it, ret.end());
    return ret;
}

_VSTD::string address_v6::to_string() const // TODO: temporary implementation
{
    _VSTD::string ret(48, '0');
    auto it = ret.begin();
    for ( const auto c : __bytes ) {
        *it++ = __to_hex((c >> 4) & 0x0F);
        *it++ = __to_hex((c     ) & 0x0F);
        *it++  = ':';
        }
    ret.erase ( --it, ret.end());
    return ret;
}

template <typename _Iter>
unsigned __dec_to_num(_Iter __f, _Iter __l)
{
    unsigned __ret = 0;
    while (__f != __l)
        __ret = 10 * __ret + (*__f++ - '0');
    return __ret;
}

template <typename _Iter>
unsigned __hex_to_num(_Iter __f, _Iter __l)
{
	unsigned __ret = 0;
	char __c;
	while (__f != __l)
	{
		__c = *__f++;
		__ret *= 16;
		if ( __c >= '0' && __c <= '9' ) __ret += __c - '0';
		if ( __c >= 'A' && __c <= 'F' ) __ret += __c + 10 - 'A';
		if ( __c >= 'a' && __c <= 'f' ) __ret += __c + 10 - 'a';
	}

	return __ret;
}

address_v4 make_address_v4(_VSTD_LFTS::string_view __sv, _VSTD::error_code& __ec) noexcept
{
    const std::regex re(R"((\d{1,3})\.(\d{1,3})\.(\d{1,3})\.(\d{1,3}))");
    std::match_results<std::experimental::string_view::const_iterator> m;
    if (!std::regex_match(__sv.begin(), __sv.end(), m, re))
    {
        __ec = _VSTD::make_error_code(_VSTD::errc::invalid_argument);
        return address_v4{};
    }

    address_v4::bytes_type b;
    __ec = _VSTD::error_code{};
    for ( int i = 0; i < b.size(); ++i )
        b[i] = __dec_to_num(m[i+1].first, m[i+1].second);
    return address_v4{b};
}

address_v6 make_address_v6(_VSTD_LFTS::string_view __sv, _VSTD::error_code& __ec) noexcept
{
    const std::regex re(R"(([0-9A-Fa-f]{1,2}):([0-9A-Fa-f]{1,2}):([0-9A-Fa-f]{1,2}):([0-9A-Fa-f]{1,2}):([0-9A-Fa-f]{1,2}):([0-9A-Fa-f]{1,2}):([0-9A-Fa-f]{1,2}):([0-9A-Fa-f]{1,2}):([0-9A-Fa-f]{1,2}):([0-9A-Fa-f]{1,2}):([0-9A-Fa-f]{1,2}):([0-9A-Fa-f]{1,2}):([0-9A-Fa-f]{1,2}):([0-9A-Fa-f]{1,2}):([0-9A-Fa-f]{1,2}):([0-9A-Fa-f]{1,2}))");
    std::match_results<std::experimental::string_view::const_iterator> m;
    if (!std::regex_match(__sv.begin(), __sv.end(), m, re))
    {
        __ec = _VSTD::make_error_code(_VSTD::errc::invalid_argument);
        return address_v6{};
    }

    address_v6::bytes_type b;
    __ec = _VSTD::error_code{};
    for ( int i = 0; i < b.size(); ++i )
        b[i] = __hex_to_num(m[i+1].first, m[i+1].second);
    return address_v6{b};
}

_LIBCPP_END_NAMESPACE_NETWORK_IP
