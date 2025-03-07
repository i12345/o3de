/*
 * Copyright (c) Contributors to the Open 3D Engine Project.
 * For complete copyright and license terms please see the LICENSE at the root of this distribution.
 *
 * SPDX-License-Identifier: Apache-2.0 OR MIT
 *
 */

#include <AzCore/Memory/SystemAllocator.h>

#include "VirtualGamepadButtonComponent.h"
#include "VirtualGamepadSystemComponent.h"
#include "VirtualGamepadThumbStickComponent.h"

#include <IGem.h>

namespace VirtualGamepad
{
    class VirtualGamepadModule
        : public CryHooksModule
    {
    public:
        AZ_RTTI(VirtualGamepadModule, "{0454CF83-A35E-443B-A9BE-858EBE9C908F}", CryHooksModule);
        AZ_CLASS_ALLOCATOR(VirtualGamepadModule, AZ::SystemAllocator);

        VirtualGamepadModule()
            : CryHooksModule()
        {
            // Push results of [MyComponent]::CreateDescriptor() into m_descriptors here.
            m_descriptors.insert(m_descriptors.end(), {
                VirtualGamepadSystemComponent::CreateDescriptor(),
                VirtualGamepadButtonComponent::CreateDescriptor(),
                VirtualGamepadThumbStickComponent::CreateDescriptor(),
            });
        }

        /**
         * Add required SystemComponents to the SystemEntity.
         */
        AZ::ComponentTypeList GetRequiredSystemComponents() const override
        {
            return AZ::ComponentTypeList{
                azrtti_typeid<VirtualGamepadSystemComponent>(),
            };
        }
    };
}

// DO NOT MODIFY THIS LINE UNLESS YOU RENAME THE GEM
// The first parameter should be GemName_GemIdLower
// The second should be the fully qualified name of the class above
AZ_DECLARE_MODULE_CLASS(Gem_VirtualGamepad, VirtualGamepad::VirtualGamepadModule)
