// Fill out your copyright notice in the Description page of Project Settings.


#include "FinalGameInstance.h"

void UFinalGameInstance::Host(FString MapName, FSPlayerInfo Info)
{
	PlayerInfo = Info;
	
	GWorld -> ServerTravel(FString::Printf(TEXT("/Game/Maps/%s?listen"), *MapName));
}

void UFinalGameInstance::Join(FString Address, FSPlayerInfo Info)
{
	PlayerInfo = Info;
	
	GWorld -> GetFirstPlayerController() -> ClientTravel(Address, ETravelType::TRAVEL_Absolute);
}

