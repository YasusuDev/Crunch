// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitysystemInterface.h"
#include "CCharacter.generated.h"

UCLASS()
class ACCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	ACCharacter();
	
	void ServerSideInit();
	void ClientSideInit();
	
protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	/******************************************************************************************************************/
	/*											   Gameplay Ability													  */
	/******************************************************************************************************************/
public:
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
private:
	UPROPERTY(VisibleDefaultsOnly, Category = "Gameplay Ability")
	class UCAbilitySystemComponent* CAbilitySystemComponent;
	UPROPERTY()
	class UCAttributeSet* CAttributeSet;
	
	/******************************************************************************************************************/
	/*											          UI         												  */
	/******************************************************************************************************************/
private:
	UPROPERTY(VisibleDefaultsOnly, Category = "Gameplay Ability")
	class UWidgetComponent* OverHeadWidgetComponent;
	void ConfigureOverHeadStatsWidget();
};
