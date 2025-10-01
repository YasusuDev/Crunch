// Fill out your copyright notice in the Description page of Project Settings.

#include "Player/CPlayerController.h"
#include "Player/CPlayerCharacter.h"

void ACPlayerController::OnPossess(APawn* NewPawn)
{
	Super::OnPossess(NewPawn);

	if (!IsValid(NewPawn)) return;
	
	CPlayerCharacter = Cast<ACPlayerCharacter>(NewPawn);
	if (CPlayerCharacter)
	{
		CPlayerCharacter->ServerSideInit();
	}
}

void ACPlayerController::AcknowledgePossession(APawn* NewPawn)
{
	Super::AcknowledgePossession(NewPawn);

	if (!IsValid(NewPawn)) return;
	
	CPlayerCharacter = Cast<ACPlayerCharacter>(NewPawn);
	if (CPlayerCharacter)
	{
		CPlayerCharacter->ClientSideInit();
	}
}
