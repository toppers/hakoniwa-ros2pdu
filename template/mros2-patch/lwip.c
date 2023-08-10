#include "cmsis_os.h"
#include "lwip.h"
#include "lwip/def.h"
#include "lwip/sys.h"

#include "lwip/udp.h"
#include "lwip/init.h"

#include "sys_utils.h"
#include <pthread.h>

static pthread_mutex_t tcpip_core_mutex = PTHREAD_MUTEX_INITIALIZER;
#ifdef __APPLE__
struct stats_ lwip_stats;
#endif
void MX_LWIP_Init(void)
{
  sys_init();
  mem_init();
  memp_init();
  pbuf_init();
  udp_init();
  return;
}

u32_t lwip_htonl(u32_t val)
{
  return sys_htonl(val);
}

void sys_lock_tcpip_core(void)
{
  pthread_mutex_lock(&tcpip_core_mutex);
  return;
}

void sys_unlock_tcpip_core(void)
{
  pthread_mutex_unlock(&tcpip_core_mutex);
  return;
}

uint32_t sys_now(void)
{
  return osKernelGetTickCount();
}
