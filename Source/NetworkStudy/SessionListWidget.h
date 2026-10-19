// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FindSessionsCallbackProxy.h"
#include "Blueprint/UserWidget.h"
#include "SessionListWidget.generated.h"

class UWrapBox;
class UButton;
class USessionItemWidget;

/**
 * 
 */
UCLASS()
class NETWORKSTUDY_API USessionListWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	virtual bool Initialize() override;

	UFUNCTION(BlueprintCallable)
	void SetInfo();

	UFUNCTION(BlueprintCallable)
	void RefreshUI();

protected:
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	TObjectPtr<UWrapBox> SessionList;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	TObjectPtr<UButton> Btn_Refresh;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	TObjectPtr<UButton> Btn_CreateSession;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	TObjectPtr<UButton> Btn_Close;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<USessionItemWidget> SessionItemClass; // WBP_SessionItem 을 CPP 에서 만들기위해서 블루프린트에서 클래스 받아오려고 만든 변수

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<TObjectPtr<USessionItemWidget>> Sessions; // 만들어진 WBP_SessionItem 을 담아두는 배열

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FBlueprintSessionResult> SessionInfos;
};
