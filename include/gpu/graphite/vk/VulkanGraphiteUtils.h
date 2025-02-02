/*
 * Copyright 2022 Google LLC
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef skgpu_graphite_VulkanGraphiteUtils_DEFINED
#define skgpu_graphite_VulkanGraphiteUtils_DEFINED

#include "include/core/SkTypes.h"
#include <memory>

namespace skgpu { struct VulkanBackendContext; }

namespace skgpu::graphite {

class Context;
struct ContextOptions;

std::unique_ptr<Context> MakeVulkanContext(const VulkanBackendContext&, const ContextOptions&);

} // namespace skgpu::graphite

#endif // skgpu_graphite_VulkanGraphiteUtils_DEFINED
