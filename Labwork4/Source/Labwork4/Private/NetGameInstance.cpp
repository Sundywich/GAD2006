// Fill out your copyright notice in the Description page of Project Settings.


#include "NetGameInstance.h"
#include "NetBaseCharacter.h"

void UNetGameInstance::Host(FString MapName, FSPlayerInfo Info)
{
	GEngine -> AddOnScreenDebugMessage(0, 1.f, FColor::Red, "Hosting Game...");
	PlayerInfo = Info;
	GWorld -> ServerTravel(FString::Printf(TEXT("/Game/Maps/%s?listen"), *MapName));
}

void UNetGameInstance::Join(FString Address, FSPlayerInfo Info)
{
	GEngine -> AddOnScreenDebugMessage(0, 1.f, FColor::Green, FString::Printf(TEXT("Joining Game at %s...")), *Address);
	PlayerInfo = Info;
	GWorld -> GetFirstPlayerController() -> ClientTravel(Address, ETravelType::TRAVEL_Absolute);
}
