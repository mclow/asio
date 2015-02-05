// -*- C++ -*-
//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is dual licensed under the MIT and the University of Illinois Open
// Source Licenses. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

//  const error_category& resolver_category() noexcept;
// 
//  error_code make_error_code(resolver_errc e) noexcept;
//  error_condition make_error_condition(resolver_errc e) noexcept;

#include <experimental/internet>
#include <type_traits>
#include <cassert>

namespace ip = std::experimental::network_v1::ip;

void test_make_error_code(ip::resolver_errc value)
{
	std::error_code err = ip::make_error_code(value);
	assert(err.category() == ip::resolver_category());
	assert(err.value()    == static_cast<int>(value));
}

void test_make_error_condition(ip::resolver_errc value)
{
	std::error_condition cond = ip::make_error_condition(value);
	assert(cond.category() == ip::resolver_category());
	assert(cond.value()    == static_cast<int>(value));
}

int main()
{
    const std::error_category &res = ip::resolver_category();
    assert(res.name() == "resolver");

    test_make_error_code(ip::resolver_errc::host_not_found);
    test_make_error_code(ip::resolver_errc::host_not_found_try_again);
    test_make_error_code(ip::resolver_errc::service_not_found);

    test_make_error_condition(ip::resolver_errc::host_not_found);
    test_make_error_condition(ip::resolver_errc::host_not_found_try_again);
    test_make_error_condition(ip::resolver_errc::service_not_found);
}
