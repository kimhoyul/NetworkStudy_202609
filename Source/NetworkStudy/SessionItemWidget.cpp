// Fill out your copyright notice in the Description page of Project Settings.


#include "SessionItemWidget.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"

void USessionItemWidget::SetInfo(FBlueprintSessionResult SesssionResult)
{
	Result = SesssionResult;
	RefreshUI();
}

void USessionItemWidget::RefreshUI()
{
	Txt_SessionName->SetText(FText());
	Txt_PlayerCount->SetText(FText());
	Txt_MapName->SetText(FText());
}