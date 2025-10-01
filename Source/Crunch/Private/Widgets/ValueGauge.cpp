// Fill out your copyright notice in the Description page of Project Settings.

#include "ValueGauge.h"

#include "Components/ProgressBar.h"
#include "Components/TextBlock.h"
#include "ProfilingDebugging/CookStats.h"

void UValueGauge::NativePreConstruct()
{
	Super::NativePreConstruct();
	ProgressBar->SetFillColorAndOpacity(BarColor);
}

void UValueGauge::SetValue(float NewValue, float NewMaxValue)
{
	if (NewMaxValue == 0)
	{
		UE_LOG(LogTemp, Display, TEXT("Value Gauge: %s, NewMaxValue can't be 0"), *GetName());
		return;
	}

	const float NewPercent = NewValue / NewMaxValue;
	ProgressBar->SetPercent(NewPercent);

	FNumberFormattingOptions FormattingOptions = FNumberFormattingOptions().SetMaximumFractionalDigits(0);

	ValueText->SetText(
		FText::Format(
			FTextFormat::FromString("{0}/{1}"),
			FText::AsNumber(NewValue, &FormattingOptions),
			FText::AsNumber(NewMaxValue, &FormattingOptions)
		)
	);
}