// Fill out your copyright notice in the Description page of Project Settings.


#include "Lobby/UI/LobbyWidget.h"
#include "Lobby/Contents/LobbyPlayerState.h"
#include "GameFramework/GameStateBase.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"

TArray<ALobbyPlayerState*> ULobbyWidget::GetLobbyPlayerStates()
{
    TArray<ALobbyPlayerState*> LobbyPlayerStates; // 함수 종료시 내보낼 지역 변수

    if (AGameStateBase* GameState = UGameplayStatics::GetGameState(this))
    {
        for (APlayerState* PlayerState : GameState->PlayerArray)
        {
            ALobbyPlayerState* LobbyPlayerState = Cast<ALobbyPlayerState>(PlayerState);
            if (LobbyPlayerState == nullptr)
                continue;

            LobbyPlayerStates.Add(LobbyPlayerState);
        }
    }

    return LobbyPlayerStates;
}

ALobbyPlayerState* ULobbyWidget::GetLobbyPlayerStateAtIndex(int32 index)
{
    TArray<ALobbyPlayerState*> LobbyPlayerStates = GetLobbyPlayerStates();

    if (index < LobbyPlayerStates.Num())
        return LobbyPlayerStates[index];

    return nullptr;
}
