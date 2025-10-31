#pragma once
#include "../../pch.h"
#include "FortInventory.h"
#include "../../Engine/Public/AbilitySystemComponent.h"

struct FFortAbilitySetHandle final
{
public:
    USCRIPTSTRUCT_COMMON_MEMBERS(FFortAbilitySetHandle);

    TWeakObjectPtr<UAbilitySystemComponent> TargetAbilitySystemComponent;
    TArray<FGameplayAbilitySpecHandle> GrantedAbilityHandles;
    TArray<FActiveGameplayEffectHandle> AppliedEffectHandles;
    TArray<FGuid> ItemGuidsForAdditionalItems;
    uint8_t Padding[0x30]; // incase
};

class AFortWeapon : public AActor
{
public:
    UCLASS_COMMON_MEMBERS(AFortWeapon);

    DEFINE_PROP(ItemEntryGuid, FGuid);
    DEFINE_PROP(WeaponData, UFortWeaponItemDefinition*);
    DEFINE_PROP(ContextTrapItemDefinition, UFortItemDefinition*);
    DEFINE_PROP(PrimaryAbilitySpecHandle, FGameplayAbilitySpecHandle);
    DEFINE_PROP(SecondaryAbilitySpecHandle, FGameplayAbilitySpecHandle);
    DEFINE_PROP(ReloadAbilitySpecHandle, FGameplayAbilitySpecHandle);
    DEFINE_PROP(ImpactAbilitySpecHandle, FGameplayAbilitySpecHandle);
    DEFINE_PROP(ReticleTraceOverrideSpecHandle, FGameplayAbilitySpecHandle);
    DEFINE_PROP(EquippedAbilityHandles, TArray<FGameplayAbilitySpecHandle>);
    DEFINE_PROP(EquippedAbilitySetHandles, TArray<FFortAbilitySetHandle>);

    DEFINE_FUNC(ServerReleaseWeaponAbility, void);
};