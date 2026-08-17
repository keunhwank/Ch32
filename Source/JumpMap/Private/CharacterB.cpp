#include "CharacterB.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"
#include "Camera/CameraComponent.h"

ACharacterB::ACharacterB()
{
	PrimaryActorTick.bCanEverTick = false;


	//박스 콜라이더 컴포넌트 생성
	BoxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
	SetRootComponent(BoxComp);
	BoxComp->SetSimulatePhysics(false);

	//스태틱 메시 컴포넌트 생성
	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	MeshComp->SetupAttachment(BoxComp);
	MeshComp->SetSimulatePhysics(false);

	//스프링암 컴포넌트 생성
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(BoxComp);
	SpringArm->TargetArmLength = 300.f;

	//카메라 컴포넌트 생성 
	CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	CameraComp->SetupAttachment(SpringArm);
}

void ACharacterB::BeginPlay()
{
	Super::BeginPlay();
	
	if (APlayerController* PlayerController = Cast<APlayerController>(GetController()))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem =
			ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(
				PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(PlayerInputMappingContext, 0);
		}
	}
}

void ACharacterB::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACharacterB::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* EnhancedInput =
		Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		EnhancedInput->BindAction(
			MoveAction,
			ETriggerEvent::Triggered,
			this,
			&ACharacterB::Move
		);

		EnhancedInput->BindAction(
			LookAction,
			ETriggerEvent::Triggered,
			this,
			&ACharacterB::Look
		);
	}
}

void ACharacterB::Move(const FInputActionValue& Value)
{
	FVector2D MoveInput = Value.Get<FVector2D>();

	FVector Forward = GetActorForwardVector();
	FVector Right = GetActorRightVector();

	FVector MoveDirection = Forward * MoveInput.Y + Right * MoveInput.X;

	float DeltaTime = GetWorld()->GetDeltaSeconds();

	AddActorWorldOffset(
		MoveDirection * MoveSpeed * DeltaTime
	);
}

void ACharacterB::Look(const FInputActionValue& Value)
{
	FVector2D LookInput = Value.Get<FVector2D>();

	float Yaw = LookInput.X * RotationSpeed;
	float Pitch = LookInput.Y * RotationSpeed;

	FRotator RotationDelta(
		Pitch,
		Yaw,
		0.0f
	);

	AddActorLocalRotation(RotationDelta);
}