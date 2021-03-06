/****************************************************************************
 *
 * Copyright 2016 Samsung Electronics All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND,
 * either express or implied. See the License for the specific
 * language governing permissions and limitations under the License.
 *
 ****************************************************************************/

/// @file tc_net_socket.c
/// @brief Test Case Example for close() API
#include <tinyara/config.h>
#include <stdio.h>
#include <errno.h>

#include <sys/stat.h>
#include <net/if.h>
#include <arpa/inet.h>
#include <netinet/in.h>
//#include <arch/board/board.h>
#include <apps/netutils/netlib.h>

#include <sys/socket.h>

#include "tc_internal.h"
/**
   * @fn                   :tc_net_close_p
   * @brief                :
   * @scenario             :
   * API's covered         :close()
   * Preconditions         :
   * Postconditions        :
   * @return               :void
   */
static void tc_net_close_p(void)
{

	int fd = -1;
	fd = socket(AF_INET, SOCK_STREAM, 0);
	int ret = close(fd);

	if (ret == -1) {
		printf("tc_net_close_p: fail\n");

		nw_total_fail++;
		RETURN_ERR;
	}

	printf("tc_net_close_p: PASS\n");
	nw_total_pass++;
}

/**
   * @fn                   :tc_net_close_n
   * @brief                :
   * @scenario             :
   * API's covered         :close()
   * Preconditions         :
   * Postconditions        :
   * @return               :void
   */
static void tc_net_close_n(void)
{

	int fd = -1;
	int ret = close(fd);

	if (ret == 0) {
		printf("tc_net_close_n: FAIL\n");

		nw_total_fail++;
		RETURN_ERR;
	}

	printf("tc_net_close_n: PASS\n");
	nw_total_pass++;
}

/****************************************************************************
 * Name: close()
 ****************************************************************************/

int net_close_main(void)
{

	tc_net_close_p();
	tc_net_close_n();
	return 0;
}
