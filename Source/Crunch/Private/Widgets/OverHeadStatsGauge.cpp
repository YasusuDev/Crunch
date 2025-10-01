// Fill out your copyright notice in the Description page of Project Settings.

#include "OverHeadStatsGauge.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "AbilitySystemComponent.h"
#include "ValueGauge.h"
#include "GAS/CAttributeSet.h"

void UOverHeadStatsGauge::ConfigureWitASC(class UAbilitySystemComponent* AbilitySystemComponent)
{
	AbilitySystemComponent = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(GetOwningPlayerPawn());
	if (AbilitySystemComponent)
	{
		HealthBar->SetAndBoundToGameplayAttributes(AbilitySystemComponent, UCAttributeSet::GetHealthAttribute(), UCAttributeSet::GetMaxHealthAttribute());
		ManaBar->SetAndBoundToGameplayAttributes(AbilitySystemComponent, UCAttributeSet::GetManaAttribute(), UCAttributeSet::GetMaxManaAttribute());
	}
}
