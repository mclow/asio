// -*- C++ -*-
//===-------------------------- executor.cpp ------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is dual licensed under the MIT and the University of Illinois Open
// Source Licenses. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

#include <experimental/executor>

_LIBCPP_BEGIN_NAMESPACE_NETWORK

service_already_exists::~service_already_exists() noexcept {}

execution_context::execution_context()
{
}

execution_context::~execution_context()
{
	shutdown();
	destroy();
}

// Effects: For each service object svc in the set:
// — If e == fork_event::prepare, performs svc->notify_fork(e) 
//      in reverse order of addition to the set.
// — Otherwise, performs svc->notify_fork(e) in order of addition to the set.
void execution_context::notify_fork(fork_event e)
{
	if (e == fork_event::prepare)
		std::for_each(svcs_.rbegin(), svcs_.rend(), [=](const service_entry &val) {val.svc_->notify_fork(e); } );
	else
		std::for_each(svcs_. begin(), svcs_. end(), [=](const service_entry &val) {val.svc_->notify_fork(e); } );
}

// Effects: For each service object svc in the execution_context set, 
//      in reverse order of addition to the set, performs svc->shutdown(). 
// For each service in the set, svc->shutdown() is called only once 
//     irrespective of the number of calls to shutdown on the execution_context.
void execution_context::shutdown() noexcept
{
	std::for_each(svcs_.rbegin(), svcs_.rend(),
		[](service_entry &val) {
			if (!val.shutdown_)
			{
				val.svc_->shutdown();
				val.shutdown_ = true;
			}
		} );
}

// Effects: Destroys each service object in the execution_context set, 
//      and removes it from the set, in reverse order of addition to the set.
void execution_context::destroy() noexcept
{
	while (!svcs_.empty())
		svcs_.erase(--svcs_.end());
}

execution_context::service::~service()
{
}   
_LIBCPP_END_NAMESPACE_NETWORK