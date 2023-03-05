/*
Copyright_License {

  XCSoar Glide Computer - http://www.xcsoar.org/
  Copyright (C) 2000-2022 The XCSoar Project
  A detailed list of copyright holders can be found in the file "AUTHORS".

  This program is free software; you can redistribute it and/or
  modify it under the terms of the GNU General Public License
  as published by the Free Software Foundation; either version 2
  of the License, or (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
}
*/

#pragma once

#include <tchar.h>

struct PCMetSettings;
class CurlGlobal;
class ProgressListener;
class AllocatedPath;
namespace Co { template<typename T> class Task; }

namespace PCMet {

struct ImageArea {
  const char *name;
  const TCHAR *display_name;
};

struct ImageType {
  const char *uri;
  const TCHAR *display_name;

  const ImageArea *areas;
};

extern const ImageType image_types[];

/**
 * Throws on error.
 */
Co::Task<::AllocatedPath>
DownloadLatestImage(const char *type, const char *area,
                    const PCMetSettings &settings,
                    CurlGlobal &curl, ProgressListener &progress);

} // namespace PCMet
