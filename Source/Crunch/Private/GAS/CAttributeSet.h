// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "CAttributeSet.generated.h"

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

UCLASS()
class UCAttributeSet : public UAttributeSet
{
	GENERATED_BODY()
public:
	ATTRIBUTE_ACCESSORS(UCAttributeSet, Health)
	ATTRIBUTE_ACCESSORS(UCAttributeSet, MaxHealth)

	ATTRIBUTE_ACCESSORS(UCAttributeSet, Mana)
	ATTRIBUTE_ACCESSORS(UCAttributeSet, MaxMana)
private:
	UPROPERTY(ReplicatedUsing= OnRep_Health)
	FGameplayAttributeData Health;
	UPROPERTY(ReplicatedUsing= OnRep_MaxHealth)
	FGameplayAttributeData MaxHealth;
	UPROPERTY(ReplicatedUsing= OnRep_Mana)
	FGameplayAttributeData Mana;
	UPROPERTY(ReplicatedUsing= OnRep_MaxMana)
	FGameplayAttributeData MaxMana;

	UFUNCTION()
	void OnRep_Health(FGameplayAttributeData& OldValue);
	UFUNCTION()
	void OnRep_MaxHealth(FGameplayAttributeData& OldValue);
	UFUNCTION()
	void OnRep_Mana(FGameplayAttributeData& OldValue);
	UFUNCTION()
	void OnRep_MaxMana(FGameplayAttributeData& OldValue);


	virtual void GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const override;
};
