// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterA.h"

// Sets default values
ACharacterA::ACharacterA()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACharacterA::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACharacterA::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACharacterA::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

