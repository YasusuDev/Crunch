 // Fill out your copyright notice in the Description page of Project Settings.

#include "Character/CCharacter.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/WidgetComponent.h"
#include "GAS/CAbilitySystemComponent.h"
#include "GAS/CAttributeSet.h"
#include "Widgets/OverHeadStatsGauge.h"

 ACCharacter::ACCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
	GetMesh()->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	CAbilitySystemComponent = CreateDefaultSubobject<UCAbilitySystemComponent>("CAbility System Component");
 	CAttributeSet = CreateDefaultSubobject<UCAttributeSet>("CAttribute Set") ;

 	OverHeadWidgetComponent = CreateDefaultSubobject<UWidgetComponent>("OverHead Widget");
 	OverHeadWidgetComponent->SetupAttachment(GetRootComponent());
}

 void ACCharacter::ServerSideInit()
 {
 	CAbilitySystemComponent->InitAbilityActorInfo(this, this);
 	CAbilitySystemComponent->ApplyInitialEffects();
 }

 void ACCharacter::ClientSideInit()
 {
 	CAbilitySystemComponent->InitAbilityActorInfo(this, this);
 }

 void ACCharacter::BeginPlay()
{
	Super::BeginPlay();
	ConfigureOverHeadStatsWidget();
}

void ACCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

 UAbilitySystemComponent* ACCharacter::GetAbilitySystemComponent() const
 {
	return CAbilitySystemComponent;
 }

 void ACCharacter::ConfigureOverHeadStatsWidget()
 {
	if (!IsValid(OverHeadWidgetComponent)) return;
 	
	 if (UOverHeadStatsGauge* OverHeadStatsGauge = Cast<UOverHeadStatsGauge>(OverHeadWidgetComponent->GetUserWidgetObject()))
 	{
 		OverHeadStatsGauge->ConfigureWitASC(GetAbilitySystemComponent());
 	}
 }

