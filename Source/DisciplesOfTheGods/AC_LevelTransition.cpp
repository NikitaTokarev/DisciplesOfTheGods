// Fill out your copyright notice in the Description page of Project Settings.


#include "AC_LevelTransition.h"
#include "UObject/UObjectGlobals.h"
#include "Kismet/GameplayStatics.h"

// Sets default values for this component's properties
UAC_LevelTransition::UAC_LevelTransition()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}



// Called when the game starts
void UAC_LevelTransition::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}



void UAC_LevelTransition::AsyncLevelLoad(const FString& LevelDir, const FString& LevelName)
{
	LoadPackageAsync(LevelDir + LevelName,
		FLoadPackageAsyncDelegate::CreateLambda([=](const FName& PackageName, UPackage* LoadedPackage, EAsyncLoadingResult::Type Result)
			{
				OnLevelLoaded.Broadcast(Result == EAsyncLoadingResult::Succeeded, FName(*LevelName));
			}
		),
		0,
		PKG_ContainsMap);
}