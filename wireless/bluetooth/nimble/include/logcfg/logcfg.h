/****************************************************************************
 * apps/wireless/bluetooth/nimble/include/logcfg/logcfg.h
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

#ifndef __APPS_WIRELESS_BLUETOOTH_NIMBLE_INCLUDE_LOGCFG_LOGCFG_H
#define __APPS_WIRELESS_BLUETOOTH_NIMBLE_INCLUDE_LOGCFG_LOGCFG_H

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <debug.h>

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

#ifdef CONFIG_NIMBLE_DEBUG_ERROR
#  define nimble_err  _err
#else
#  define nimble_err  _none
#endif

#ifdef CONFIG_NIMBLE_DEBUG_WARN
#  define nimble_warn _warn
#else
#  define nimble_warn _none
#endif

#ifdef CONFIG_NIMBLE_DEBUG_INFO
#  define nimble_info _info
#else
#  define nimble_info _none
#endif

#define BLE_HS_LOG_DEBUG(msg, ...)    nimble_info(msg, ##__VA_ARGS__)
#define BLE_HS_LOG_INFO(msg, ...)     nimble_info(msg, ##__VA_ARGS__)
#define BLE_HS_LOG_WARN(msg, ...)     nimble_warn(msg, ##__VA_ARGS__)
#define BLE_HS_LOG_ERROR(msg, ...)    nimble_err(msg, ##__VA_ARGS__)
#define BLE_HS_LOG_CRITICAL(msg, ...) nimble_err(msg, ##__VA_ARGS__)
#define BLE_HS_LOG_DISABLED(msg, ...) nimble_err(msg, ##__VA_ARGS__)

#define DFLT_LOG_DEBUG(msg, ...)      nimble_info(msg, ##__VA_ARGS__)
#define DFLT_LOG_INFO(msg, ...)       nimble_info(msg, ##__VA_ARGS__)
#define DFLT_LOG_WARN(msg, ...)       nimble_warn(msg, ##__VA_ARGS__)
#define DFLT_LOG_ERROR(msg, ...)      nimble_err(msg, ##__VA_ARGS__)
#define DFLT_LOG_CRITICAL(msg, ...)   nimble_err(msg, ##__VA_ARGS__)
#define DFLT_LOG_DISABLED(msg, ...)   nimble_err(msg, ##__VA_ARGS__)

#endif  /* __APPS_WIRELESS_BLUETOOTH_NIMBLE_INCLUDE_LOGCFG_LOGCFG_H */
