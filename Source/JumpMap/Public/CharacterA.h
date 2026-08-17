#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CharacterA.generated.h"

UCLASS()
class JUMPMAP_API ACharacterA : public ACharacter
{
	GENERATED_BODY()

public:
	ACharacterA();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
