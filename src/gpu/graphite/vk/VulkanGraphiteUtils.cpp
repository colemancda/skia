/*
 * Copyright 2022 Google LLC
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "include/gpu/graphite/vk/VulkanGraphiteUtils.h"

#include "include/gpu/graphite/Context.h"
#include "include/gpu/vk/VulkanBackendContext.h"
#include "src/gpu/graphite/vk/VulkanQueueManager.h"
#include "src/gpu/graphite/vk/VulkanSharedContext.h"

namespace skgpu::graphite {

std::unique_ptr<Context> MakeVulkanContext(const VulkanBackendContext& backendContext,
                                           const ContextOptions& options) {
    sk_sp<SharedContext> sharedContext = VulkanSharedContext::Make(backendContext, options);
    if (!sharedContext) {
        return nullptr;
    }

    std::unique_ptr<QueueManager> queueManager(new VulkanQueueManager(backendContext.fQueue,
                                                                      sharedContext.get()));
    if (!queueManager) {
        return nullptr;
    }

    auto context = std::unique_ptr<Context>(new Context(std::move(sharedContext),
                                                        std::move(queueManager),
                                                        options));
    return context;
}

} // namespace skgpu::graphite
