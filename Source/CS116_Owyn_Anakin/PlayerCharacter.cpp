// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"

/*
* Source file for PlayerCharacter class, which manages player behavior
* Owyn Lee, Anakin Schneider
*/

APlayerCharacter::APlayerCharacter()
{
 	// Request the Pawn to run its tick function every frame
	PrimaryActorTick.bCanEverTick = true;

	// Create a capsule collider at the Pawn's position
	CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("RootCapsule"));
	CapsuleComponent->InitCapsuleSize(42.f, 96.f);
	CapsuleComponent->SetCollisionProfileName(TEXT("Pawn"));
	RootComponent = CapsuleComponent;
}

void APlayerCharacter::BeginPlay()
{
	// Call the superclass (Pawn)'s beginplay function
	Super::BeginPlay();
	
}

void APlayerCharacter::Tick(float DeltaTime)
{
	// Call the superclass (Pawn)'s tick function
	Super::Tick(DeltaTime);
	// Output a log message to verify that this script is running ingame
	UE_LOG(LogTemp, Warning, TEXT("This Owyn Lee's debug warning message."));

	// If the player character is moving,
	if (!CurrentVelocity.IsZero()) {
		// Detect geometry collisions using a delta vector and a raycast to perform a sweep
		FVector DeltaLocation = CurrentVelocity * DeltaTime;
		FHitResult Hit;
		AddActorLocalOffset(DeltaLocation, true, &Hit);

		// If the player is colliding with geometry,
		if (Hit.IsValidBlockingHit())
		{
			// Calculate a delta to let them slide against the geometry instead of sticking
			FVector SlideDelta = FVector::VectorPlaneProject(DeltaLocation, Hit.Normal) * (1.f - Hit.Time);
			
			// Apply the slide delta to the player character's position
			AddActorLocalOffset(SlideDelta, true);
		}
	}

}

void APlayerCharacter::MoveXAxis(float AxisValue) {
	// Register horizontal player input (A,D)
	CurrentVelocity.X = FMath::Clamp(AxisValue, -1.0f, 1.0f) * MovementSpeed;
}

void APlayerCharacter::MoveYAxis(float AxisValue) {
	// Register vertical player input (W,S)
	CurrentVelocity.Y = FMath::Clamp(AxisValue, -1.0f, 1.0f) * MovementSpeed;
}

void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) {
	// To let the player character move, register MoveXAxis and MoveYAxis functions in PlayerInputComponent
	// MoveForward (W = 1.0, S = -1.0) and MoveRight (A = -1.0, D = 1.0) need to be registered in Project Settings -> Input -> Axis Mappings
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("MoveForward", this, &APlayerCharacter::MoveXAxis);
	PlayerInputComponent->BindAxis("MoveRight", this, &APlayerCharacter::MoveYAxis);
}