/****************************************************************************
 * apps/netutils/netlib/netlib_delarp.c
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.  The
 * ASF licenses this file to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance with the
 * License.  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  See the
 * License for the specific language governing permissions and limitations
 * under the License.
 *
 ****************************************************************************/

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>
#ifdef CONFIG_NET_ARP

#include <sys/socket.h>
#include <sys/ioctl.h>

#include <unistd.h>
#include <string.h>
#include <assert.h>
#include <errno.h>

#include <netinet/arp.h>
#include <netinet/in.h>
#include <net/if.h>

#include "netutils/netlib.h"

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: netlib_del_arpmapping
 *
 * Description:
 *   Delete the hardware address mapping for the provided protocol address.
 *
 * Parameters:
 *   inaddr   The IPv4 address to use in the query
 *   ifname   The Network device name
 *
 * Return:
 *   0 on success; a negated errno value on failure.
 *
 ****************************************************************************/

int netlib_del_arpmapping(FAR const struct sockaddr_in *inaddr,
                          FAR const char *ifname)
{
  int ret = -EINVAL;

  if (inaddr != NULL)
    {
      int sockfd = socket(NET_SOCK_FAMILY, NET_SOCK_TYPE, NET_SOCK_PROTOCOL);
      if (sockfd >= 0)
        {
          struct arpreq req;

          memcpy(&req.arp_pa, inaddr, sizeof(struct sockaddr_in));
          memset(&req.arp_ha, 0, sizeof(struct sockaddr_in));
          if (ifname != NULL)
            {
               strlcpy((FAR char *)&req.arp_dev, ifname,
                       sizeof(req.arp_dev));
            }
          else
            {
              req.arp_dev[0] = '\0';
            }

          ret = ioctl(sockfd, SIOCDARP, (unsigned long)((uintptr_t)&req));
          if (ret < 0)
            {
              ret = -errno;
              DEBUGASSERT(ret < 0);
            }

          close(sockfd);
        }
    }

  return ret;
}

#endif /* CONFIG_NET_ARP */
