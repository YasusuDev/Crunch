// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/CCharacter.h"
#include "InputActionValue.h"
#include "CPlayerCharacter.generated.h"

class UInputAction;

UCLASS()
class ACPlayerCharacter : public ACCharacter
{
	GENERATED_BODY()

public:
	ACPlayerCharacter();

	virtual void PawnClientRestart() override;
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;
private:
	UPROPERTY(VisibleDefaultsOnly, Category = "View")
	class USpringArmComponent* CameraBoom;
	UPROPERTY(VisibleDefaultsOnly, Category = "View")
	class UCameraComponent* ViewCam;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	UInputAction* JumpInputAction;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	UInputAction* LookInputAction;
	
	UPROPERTY(EditDefaultsOnly, Category = "Input")
	class UInputMappingContext* GameplayInputMappingContext;

	void  HandleLookInput(const FInputActionValue& InputActionValue);
};
