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

		if (ChildWidget == nullptr)
			continue;

		Sessions.Add(ChildWidget);
	}

	RefreshUI();
}

void USessionListWidget::RefreshUI()
{
	// 아직 누가 채워주는지는 모르지만 이게 채워지면 이게 곧 방의 개수
	const int32 SessionLength = SessionInfos.Num(); 

	for (int32 i = 0; i < Sessions.Num(); i++)
	{
		const int32 index = i;

		if (index < SessionLength)
		{
			// 차일드 위젯을 켜주기
			Sessions[index]->SetVisibility(ESlateVisibility::Visible);
			FBlueprintSessionResult Result = SessionInfos[index];
			Sessions[index]->SetInfo(Result);
		}
		else
		{
			// 차이드 위젯을 꺼주기
			Sessions[index]->SetVisibility(ESlateVisibility::Collapsed);
		}
	}

}