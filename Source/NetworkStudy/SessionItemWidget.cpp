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
	FString SessionName;
	Result.OnlineResult.Session.SessionSettings.Get("SESSION_NAME", OUT SessionName);
	Txt_SessionName->SetText(FText::FromString(SessionName));

	const int32 currentPlayers = 
		// NumPublicConnections : 방을 만들때 들어올 수 있는 최대 인원수
		Result.OnlineResult.Session.SessionSettings.NumPublicConnections - 
		// NumOpenPublicConnections : 최대 인원수 에서 현재 남은 참가 자리 수
		Result.OnlineResult.Session.NumOpenPublicConnections;
	const int32 maxPlayers = Result.OnlineResult.Session.SessionSettings.NumPublicConnections;
	FString PlayerCountString = FString::Printf(TEXT("%d / %d"), currentPlayers, maxPlayers);
	Txt_PlayerCount->SetText(FText::FromString(PlayerCountString));

	FString MapName;
	Result.OnlineResult.Session.SessionSettings.Get("SESSION_MAP", OUT MapName);
	Txt_MapName->SetText(FText::FromString(MapName));
}