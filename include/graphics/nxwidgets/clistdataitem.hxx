/****************************************************************************
 * apps/include/graphics/nxwidgets/clistdataitem.hxx
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
 *
 * Portions of this package derive from Woopsi (http://woopsi.org/) and
 * portions are original efforts.  It is difficult to determine at this
 * point what parts are original efforts and which parts derive from Woopsi.
 * However, in any event, the work of  Antony Dzeryn will be acknowledged
 * in most NxWidget files.  Thanks Antony!
 *
 *   Copyright (c) 2007-2011, Antony Dzeryn
 *   All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * * Redistributions of source code must retain the above copyright
 *   notice, this list of conditions and the following disclaimer.
 * * Redistributions in binary form must reproduce the above copyright
 *   notice, this list of conditions and the following disclaimer in the
 *   documentation and/or other materials provided with the distribution.
 * * Neither the names "Woopsi", "Simian Zombie" nor the
 *   names of its contributors may be used to endorse or promote products
 *   derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY Antony Dzeryn ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL Antony Dzeryn BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 ****************************************************************************/

#ifndef __APPS_INCLUDE_GRAPHICS_NXWIDGETS_CLISTDATAITEM_HXX
#define __APPS_INCLUDE_GRAPHICS_NXWIDGETS_CLISTDATAITEM_HXX

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>

#include <stdint.h>
#include <stdbool.h>

#include <nuttx/nx/nxglib.h>

#include "graphics/nxwidgets/cnxstring.hxx"

/****************************************************************************
 * Pre-Processor Definitions
 ****************************************************************************/

/****************************************************************************
 * Implementation Classes
 ****************************************************************************/

#if defined(__cplusplus)

namespace NXWidgets
{
  /**
   * Class representing a data item within a list.  Intended for use within
   * the CListData class.
   */

  class CListDataItem
  {
  protected:
    CNxString m_text;        /**< Text to display for option. */
    uint32_t  m_value;       /**< Option value. */
    bool      m_isSelected;  /**< True if the option is selected. */

  public:

    /**
     * Constructor.
     *
     * @param text The text to display in the item.
     * @param value The value of the item.
     */

    CListDataItem(const CNxString &text, const uint32_t value);

    /**
     * Destructor.
     */

    virtual ~CListDataItem(void);

    /**
     * Get the item's text.
     *
     * @return The item's text.
     */

    inline const CNxString &getText(void) const
    {
      return m_text;
    }

    /**
     * Get the item's value.
     *
     * @return The item's value.
     */

    inline const uint32_t getValue(void) const
    {
      return m_value;
    }

    /**
     * Get the item's selection state.
     *
     * @return True if the item is selected; false if not.
     */

    inline const bool isSelected(void) const
    {
      return m_isSelected;
    }

    /**
     * Set the item's selection state.
     *
     * @param selected True to select the item; false to deselect it.
     */

    inline void setSelected(bool selected)
    {
      m_isSelected = selected;
    }

    /**
     * Compare the item with another.  Comparison is based on the text of
     * the item.  Returns 0 if the text in the two items is the same,
     * a value less than 0 if this item is less than the argument, and
     * a value greater than 0 if this item is greater than the argument.
     *
     * @param item An item to compare this object with.
     * @return 0 if the text in the two items is the same,
     *   a value less than 0 if this item is less than the argument, and
     *   a value greater than 0 if this item is greater than the argument.
     */

    virtual int compareTo(const CListDataItem *item) const;
  };
}

#endif // __cplusplus

#endif // __APPS_INCLUDE_GRAPHICS_NXWIDGETS_CLISTDATAITEM_HXX
