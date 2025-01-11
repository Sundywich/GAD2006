// Fill out your copyright notice in the Description page of Project Settings.


#include "FinalHealingCollectible.h"

AFinalHealingCollectible::AFinalHealingCollectible() : HealingAmount(20)
{
	PrimaryActorTick.bCanEverTick = true;
	bReplicates = true;
}

