/*
  +----------------------------------------------------------------------+
  | Zan                                                                  |
  +----------------------------------------------------------------------+
  | Copyright (c) 2016-2017 Zan Group <https://github.com/youzan/zan>    |
  +----------------------------------------------------------------------+
  | This source file is subject to version 2.0 of the Apache license,    |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.apache.org/licenses/LICENSE-2.0.html                      |
  | If you did not receive a copy of the Apache2.0 license and are unable|
  | to obtain it through the world-wide-web, please send a note to       |
  | zan@zanphp.io so we can mail you a copy immediately.                 |
  +----------------------------------------------------------------------+
  |         Zan Group   <zan@zanphp.io>                                  |
  +----------------------------------------------------------------------+
*/
#ifndef ZAN_ATOMIC_H_
#define ZAN_ATOMIC_H_

#include <stdint.h>

typedef long                    atomic_int_t;
typedef unsigned long           atomic_uint_t;
typedef volatile atomic_uint_t  zan_atomic_t;

#define zan_atomic_fetch_add(value, add)   __sync_fetch_and_add(value, add)
#define zan_atomic_fetch_sub(value, sub)   __sync_fetch_and_sub(value, sub)
#define zan_atomic_add_fetch(value, add)   __sync_add_and_fetch(value, add)
#define zan_atomic_sub_fetch(value, sub)   __sync_sub_and_fetch(value, sub)

#define zan_atomic_memory_barrier()        __sync_synchronize()
#define zan_atomic_set(ptr, value)         __sync_lock_test_and_set(ptr, value)
#define zan_atomic_release(ptr)            __sync_lock_release(ptr)

#define zan_atomic_cmp_set(lock, old, set) __sync_bool_compare_and_swap(lock, old, set)

#ifdef __arm__
#define zan_atomic_cpu_pause()             __asm__ __volatile__ ("NOP");
#elif defined(__x86_64__)
#define zan_atomic_cpu_pause()             __asm__ __volatile__ ("pause")
#else
#define zan_atomic_cpu_pause()
#endif

#define zan_spinlock_release(lock)         __sync_lock_release(lock)


#endif
