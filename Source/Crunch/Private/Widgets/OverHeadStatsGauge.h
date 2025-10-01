// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "OverHeadStatsGauge.generated.h"

UCLASS()
class UOverHeadStatsGauge : public UUserWidget
{
	GENERATED_BODY()

public:
	void ConfigureWitASC(class UAbilitySystemComponent* AbilitySystemComponent);

private:
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UValueGauge* HealthBar;
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UValueGauge* ManaBar;
};
