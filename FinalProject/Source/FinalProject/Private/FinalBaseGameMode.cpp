// Fill out your copyright notice in the Description page of Project Settings.


#include "FinalBaseGameMode.h"
#include "FinalBaseCharacter.h"

AFinalBaseGameMode::AFinalBaseGameMode()
{
	DefaultPawnClass = AFinalBaseCharacter::StaticClass();
}

