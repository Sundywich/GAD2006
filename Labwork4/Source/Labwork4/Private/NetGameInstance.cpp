// Fill out your copyright notice in the Description page of Project Settings.


#include "NetGameInstance.h"
#include "NetBaseCharacter.h"

void UNetGameInstance::Host(FString MapName, FSPlayerInfo Info)
{
	GEngine -> AddOnScreenDebugMessage(0, 1.f, FColor::Red, "Hosting Game...");
	PlayerInfo = Info; // PlayerInfo will have its own copy in game instance
	GWorld -> ServerTravel(FString::Printf(TEXT("/Game/Maps/%s?listen"), *MapName));
}

void UNetGameInstance::Join(FSPlayerInfo Info)
{
	GEngine -> AddOnScreenDebugMessage(0, 1.f, FColor::Green, FString::Printf(TEXT("Joining Game at %s...")), *IPAdressToJoin);
	PlayerInfo = Info;
	GWorld -> GetFirstPlayerController() -> ClientTravel(IPAdressToJoin, ETravelType::TRAVEL_Absolute);
}

void UNetGameInstance::SetIPAdressToJoin(FString IP)
{
	IPAdressToJoin = IP;
}

