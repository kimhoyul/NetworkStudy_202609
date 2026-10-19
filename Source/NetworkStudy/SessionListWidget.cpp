// Fill out your copyright notice in the Description page of Project Settings.


#include "SessionListWidget.h"
#include "SessionItemWidget.h"
#include "Components/Button.h"
#include "Components/WrapBox.h"

bool USessionListWidget::Initialize()
{
	if (Super::Initialize() == false)
		return false;

	SetInfo();

	return true;
}

void USessionListWidget::SetInfo()
{
	Sessions.Empty();

	for (int i = 0; i < 10; i++)
	{
		if (SessionItemClass == nullptr)
			continue;

		USessionItemWidget* ChildWidget = CreateWidget<USessionItemWidget>(GetWorld(), SessionItemClass);
	}
}

void USessionListWidget::RefreshUI()
{

}