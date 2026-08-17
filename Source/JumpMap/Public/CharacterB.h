#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "CharacterB.generated.h"


class UInputAction;
class UInputMappingContext;
struct FInputActionValue;

UCLASS()
class JUMPMAP_API ACharacterB : public APawn
{
	GENERATED_BODY()

public:
	ACharacterB();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//박스 충돌체 컴포넌트
	UPROPERTY (EditAnywhere)
	class UBoxComponent* BoxComp;

	//스태틱 메시 컴포넌트 생성
	UPROPERTY(EditAnywhere)
	class UStaticMeshComponent* MeshComp;

	//스프링암 컴포넌트
	UPROPERTY(EditAnywhere)
	class USpringArmComponent* SpringArm;

	//카메라 컴포넌트
	UPROPERTY(EditAnywhere)
	class UCameraComponent* CameraComp;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	UInputAction* MoveAction;
	
	UPROPERTY(EditDefaultsOnly, Category = "Input")
	UInputAction* LookAction;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	float MoveSpeed = 500.0f;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	float RotationSpeed = 1.0f;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	UInputMappingContext* PlayerInputMappingContext;

	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);

};
