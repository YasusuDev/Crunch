// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "CPlayerController.generated.h"

UCLASS()
class ACPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	//Only called on the server.
	virtual void OnPossess(APawn* InPawn) override;
	//Only called on the client, also on the listening server.
	virtual void AcknowledgePossession(class APawn* P) override;

private:
	UPROPERTY()
	class ACPlayerCharacter* CPlayerCharacter;
};
