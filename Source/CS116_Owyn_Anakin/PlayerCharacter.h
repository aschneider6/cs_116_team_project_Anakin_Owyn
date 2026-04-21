// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Components/CapsuleComponent.h"
#include "PlayerCharacter.generated.h"

/*
* Header file for PlayerCharacter class, which manages player behavior
* Owyn Lee, Anakin Schneider
*/

UCLASS()
class CS116_OWYN_ANAKIN_API APlayerCharacter : public APawn
{
	GENERATED_BODY()

public:
	/**
	* Default constructor for PlayerCharacter
	*/
	APlayerCharacter();

	// UProperty makes the datamember below accessible via the outliner
	UPROPERTY(EditAnywhere)
	float MovementSpeed = 600.0f; // Affects the speed of the player's movement
	FVector CurrentVelocity; // Internal storage variable for the player's current velocity (stored as a 3d vector)

	UCapsuleComponent* CapsuleComponent; // Player's capsule collider

	/**
	* Function called every tick. Used to run behavior that must be constantly active (IE, collision handling)
	* @param DeltaTime Measurement variable for the device's tickrate. Allows Tick to run at the same speed on any device
	* */
	virtual void Tick(float DeltaTime) override;

	/**
	* Function that handles horizontal player movement
	* @param AxisValue Player's horizontal movement input (clamped between 1.0 and -1.0)
	*/
	void MoveXAxis(float AxisValue);


	/**
	* Function that handles vertical player movement
	* @param AxisValue Player's vertical movement input (clamped between 1.0 and -1.0)
	*/
	void MoveYAxis(float AxisValue);

	/* *
	* Function used to run this class's movement functions (MoveXAxis, MoveYAxis) with player inputs
	* @param PlayerInputComponent Referral to player input handler class
	*/
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	

protected:
	/**
	* Function called when the game starts
	*/
	virtual void BeginPlay() override;
};
