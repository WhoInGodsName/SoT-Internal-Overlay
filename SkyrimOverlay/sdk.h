#pragma once
#include "engine.h"
#include <cstdint>




struct FMinimalViewInfo {
	struct FVector Location; // 0x00(0x0c)
	struct FRotator Rotation; // 0x0c(0x0c)
	char UnknownData_18[0x10]; // 0x18(0x10)
	float FOV; // 0x28(0x04)
	float OrthoWidth; // 0x2c(0x04)
	float OrthoNearClipPlane; // 0x30(0x04)
	float OrthoFarClipPlane; // 0x34(0x04)
	float AspectRatio; // 0x38(0x04)
	char bConstrainAspectRatio : 1; // 0x3c(0x01)
	char bUseFieldOfViewForLOD : 1; // 0x3c(0x01)
	char UnknownData_3C_2 : 6; // 0x3c(0x01)
	char UnknownData_3D[0x3]; // 0x3d(0x03)
	char ProjectionMode; // 0x40(0x01)
	char UnknownData_41[0x3]; // 0x41(0x03)
	float PostProcessBlendWeight; // 0x44(0x04)
	char UnknownData_48[0x8]; // 0x48(0x08)
	char PostProcessSettings[1344]; // 0x50(0x540)
	char UnknownData_590[0x10]; // 0x590(0x10)
};

struct FCameraCacheEntry {
	char pad[16];
	struct FMinimalViewInfo POV;
	float TimeStamp;
};



// Class Engine.GameInstance
// Size: 0x88 (Inherited: 0x28)
struct UGameInstance : UObject {
	char UnknownData_28[0x10]; // 0x28(0x10)
	struct TArray<struct ULocalPlayer*> LocalPlayers; // 0x38(0x10)
	char UnknownData_48[0x8]; // 0x48(0x08)
	struct UOnlineSession* OnlineSession; // 0x50(0x08)
	char UnknownData_58[0x30]; // 0x58(0x30)

	void ReceiveShutdown(); // Function Engine.GameInstance.ReceiveShutdown // Event|Public|BlueprintEvent // @ game+0x18e5fa0
	void ReceiveInit(); // Function Engine.GameInstance.ReceiveInit // Event|Public|BlueprintEvent // @ game+0x18e5fa0
	void DebugRemovePlayer(int32_t ControllerId); // Function Engine.GameInstance.DebugRemovePlayer // Exec|Native|Public // @ game+0x2d313b0
	void DebugCreatePlayer(int32_t ControllerId); // Function Engine.GameInstance.DebugCreatePlayer // Exec|Native|Public // @ game+0x2d31320
};

struct UActorComponent : UObject {
	char UnknownData_28[0x8]; // 0x28(0x08)
	char PrimaryComponentTick[80]; // 0x30(0x50)
	struct TArray<struct FName> ComponentTags; // 0x80(0x10)
	struct TArray<struct FSimpleMemberReference> UCSModifiedProperties; // 0x90(0x10)
	char UnknownData_A0[0x10]; // 0xa0(0x10)
	struct TArray<struct UAssetUserData*> AssetUserData; // 0xb0(0x10)
	char UnknownData_C0_0 : 3; // 0xc0(0x01)
	char bReplicates : 1; // 0xc0(0x01)
	char bNetAddressable : 1; // 0xc0(0x01)
	char UnknownData_C0_5 : 3; // 0xc0(0x01)
	char UnknownData_C1_0 : 6; // 0xc1(0x01)
	char bCreatedByConstructionScript : 1; // 0xc1(0x01)
	char bInstanceComponent : 1; // 0xc1(0x01)
	char bAutoActivate : 1; // 0xc2(0x01)
	char bIsActive : 1; // 0xc2(0x01)
	char bEditableWhenInherited : 1; // 0xc2(0x01)
	char UnknownData_C2_3 : 5; // 0xc2(0x01)
	char UnknownData_C3_0 : 3; // 0xc3(0x01)
	char bNeedsLoadForClient : 1; // 0xc3(0x01)
	char bNeedsLoadForServer : 1; // 0xc3(0x01)
	char UnknownData_C3_5 : 3; // 0xc3(0x01)
	char TargetNetDormancy; // 0xc4(0x01)
	char CreationMethod; // 0xc5(0x01)
	char UnknownData_C6[0x2]; // 0xc6(0x02)
};

// Class Athena.IntentComponent
// Size: 0x188 (Inherited: 0xc8)
struct UIntentComponent : UActorComponent {
	char UnknownData_C8[0x10]; // 0xc8(0x10)
	char AckToken; // 0xd8(0x01)
	bool RequiresHandshake; // 0xd9(0x01)
	char UnknownData_DA[0x2]; // 0xda(0x02)
	float ServerIntent; // 0xdc(0x04)
	float LocalIntent; // 0xe0(0x04)
	char UnknownData_E4[0xa4]; // 0xe4(0xa4)
};

struct UClimbingComponent : UIntentComponent {
	struct FVector UseLadderOffset; // 0x188(0x0c)
	float ServerHeight; // 0x194(0x04)
	char ServerClimbId; // 0x198(0x01)
	char UnknownData_199[0x7]; // 0x199(0x07)

	void SetClimbId(char InClimbId); // Function Athena.ClimbingComponent.SetClimbId // Final|Native|Public|BlueprintCallable // @ game+0x39dca90
	bool IsClimbIdInSyncWithServer(); // Function Athena.ClimbingComponent.IsClimbIdInSyncWithServer // Final|Native|Public|BlueprintCallable|BlueprintPure|Const // @ game+0x39dc870
	float GetServerHeight(); // Function Athena.ClimbingComponent.GetServerHeight // Final|Native|Public|BlueprintCallable|BlueprintPure|Const // @ game+0x39dc840
	bool GetIsCurrentlyClimbing(); // Function Athena.ClimbingComponent.GetIsCurrentlyClimbing // Final|Native|Public|BlueprintCallable|BlueprintPure|Const // @ game+0x39dc810
};

// Class Engine.SceneComponent
// Size: 0x2e0 (Inherited: 0xc8)
struct USceneComponent {
	char pad[300];
	struct FVector ActorCoordinates; // 0x12c(0x104)
	char Mobility; // 0x230(0x01)
	char DetailMode; // 0x231(0x01)
	char UnknownData_232[0xa]; // 0x232(0x0a)
	struct FVector ComponentVelocity; // 0x23c(0x0c)
	char PhysicsVolumeChangedDelegate[16]; // 0x248(0x10)
	char UnknownData_258[0x10]; // 0x258(0x10)
	struct TArray<struct FName> SocketVelocitiesToCache; // 0x268(0x10)
	struct TArray<struct AActor*> MovedActors; // 0x278(0x10)
	char UnknownData_288[0x58]; // 0x288(0x58)

};


// Class Engine.Actor
// Size: 0x3c8 (Inherited: 0x28)
struct AActor : UObject {
	char pad[296];
	struct APawn* Instigator; // 0x150(0x08)
	char pad2[16];
	struct USceneComponent* RootComponent; // 0x168(0x08)
	struct TArray<struct AMatineeActor*> ControllingMatineeActors; // 0x170(0x10)
	float InitialLifeSpan; // 0x180(0x04)
	char UnknownData_184[0x4]; // 0x184(0x04)
	char bAllowReceiveTickEventOnDedicatedServer : 1; // 0x188(0x01)
	char UnknownData_188_1 : 7; // 0x188(0x01)
	char UnknownData_189[0x7]; // 0x189(0x07)
	struct TArray<struct FName> Layers; // 0x190(0x10)
	char ParentComponentActor[0x8]; // 0x1a0(0x08)
	struct TArray<struct AActor*> ChildComponentActors; // 0x1a8(0x10)
	char UnknownData_1B8[0x8]; // 0x1b8(0x08)
	char bActorSeamlessTraveled : 1; // 0x1c0(0x01)
	char bIgnoresOriginShifting : 1; // 0x1c0(0x01)
	char bEnableAutoLODGeneration : 1; // 0x1c0(0x01)
	char InvertFeatureCheck : 1; // 0x1c0(0x01)
	char UnknownData_1C0_4 : 4; // 0x1c0(0x01)
	char UnknownData_1C1[0x3]; // 0x1c1(0x03)
	struct FName Feature; // 0x1c4(0x08)
	char UnknownData_1CC[0x4]; // 0x1cc(0x04)
	struct TArray<struct FName> Tags; // 0x1d0(0x10)
	uint64_t HiddenEditorViews; // 0x1e0(0x08)
	char OnActorBeginOverlap; // 0x1e8(0x01)
	char OnActorEndOverlap; // 0x1e9(0x01)
	char OnActorHit; // 0x1ea(0x01)
	char OnDestroyed; // 0x1eb(0x01)
	char UnknownData_1EC[0x3c]; // 0x1ec(0x3c)
	char OnEndPlay; // 0x228(0x01)
	bool bDoOverlapNotifiesOnLoad; // 0x229(0x01)
	char UnknownData_22A[0xf6]; // 0x22a(0xf6)
	struct TArray<struct UActorComponent*> BlueprintCreatedComponents; // 0x320(0x10)
	struct TArray<struct UActorComponent*> InstanceComponents; // 0x330(0x10)
	char UnknownData_340[0x8]; // 0x340(0x08)
	struct TArray<struct AActor*> ChildActorInterfaceProviders; // 0x348(0x10)
	char UnknownData_358[0x68]; // 0x358(0x68)
	double DormancyLingeringInSeconds; // 0x3c0(0x08)

};

struct APlayerCameraManager : AActor {
	struct APlayerController* PCOwner; // 0x3c8(0x08)
	struct USceneComponent* TransformComponent; // 0x3d0(0x08)
	char UnknownData_3D8[0x8]; // 0x3d8(0x08)
	float DefaultFOV; // 0x3e0(0x04)
	char UnknownData_3E4[0x4]; // 0x3e4(0x04)
	float DefaultOrthoWidth; // 0x3e8(0x04)
	char UnknownData_3EC[0x4]; // 0x3ec(0x04)
	float DefaultAspectRatio; // 0x3f0(0x04)
	char UnknownData_3F4[0x4c]; // 0x3f4(0x4c)
	struct FCameraCacheEntry CameraCache; // 0x440(0x5b0)
	struct FCameraCacheEntry LastFrameCameraCache; // 0x9f0(0x5b0)
	char ViewTarget[0x5c0]; // 0xfa0(0x5c0)
	char PendingViewTarget[0x5c0]; // 0x1560(0x5c0)
	char UnknownData_1B20[0x30]; // 0x1b20(0x30)
	struct TArray<struct UCameraModifier*> ModifierList; // 0x1b50(0x10)
	struct TArray<struct UClass*> DefaultModifiers; // 0x1b60(0x10)
	float FreeCamDistance; // 0x1b70(0x04)
	struct FVector FreeCamOffset; // 0x1b74(0x0c)
	struct FVector ViewTargetOffset; // 0x1b80(0x0c)
	char UnknownData_1B8C[0x14]; // 0x1b8c(0x14)
	struct TArray<struct AEmitterCameraLensEffectBase*> CameraLensEffects; // 0x1ba0(0x10)
	struct UCameraModifier_CameraShake* CachedCameraShakeMod; // 0x1bb0(0x08)
	struct UCameraAnimInst* AnimInstPool[0x08]; // 0x1bb8(0x40)
	struct TArray<struct FPostProcessSettings> PostProcessBlendCache; // 0x1bf8(0x10)
	char UnknownData_1C08[0x10]; // 0x1c08(0x10)
	struct TArray<struct UCameraAnimInst*> ActiveAnims; // 0x1c18(0x10)
	struct TArray<struct UCameraAnimInst*> FreeAnims; // 0x1c28(0x10)
	struct ACameraActor* AnimCameraActor; // 0x1c38(0x08)
	char bIsOrthographic : 1; // 0x1c40(0x01)
	char UnknownData_1C40_1 : 5; // 0x1c40(0x01)
	char bUseClientSideCameraUpdates : 1; // 0x1c40(0x01)
	char UnknownData_1C41_0 : 5; // 0x1c41(0x01)
	char bFollowHmdOrientation : 1; // 0x1c41(0x01)
	char UnknownData_1C41_6 : 2; // 0x1c41(0x01)
	char UnknownData_1C42[0x2]; // 0x1c42(0x02)
	float ViewPitchMin; // 0x1c44(0x04)
	float ViewPitchMax; // 0x1c48(0x04)
	float ViewYawMin; // 0x1c4c(0x04)
	float ViewYawMax; // 0x1c50(0x04)
	float ViewRollMin; // 0x1c54(0x04)
	float ViewRollMax; // 0x1c58(0x04)
	char UnknownData_1C5C[0x4]; // 0x1c5c(0x04)
};

// Class Engine.Pawn
// Size: 0x440 (Inherited: 0x3c8)
struct APawn : AActor {
	char UnknownData_3C8[0x8]; // 0x3c8(0x08)
	char bUseControllerRotationPitch : 1; // 0x3d0(0x01)
	char bUseControllerRotationYaw : 1; // 0x3d0(0x01)
	char bUseControllerRotationRoll : 1; // 0x3d0(0x01)
	char bCanAffectNavigationGeneration : 1; // 0x3d0(0x01)
	char UnknownData_3D0_4 : 4; // 0x3d0(0x01)
	char UnknownData_3D1[0x3]; // 0x3d1(0x03)
	float BaseEyeHeight; // 0x3d4(0x04)
	char AutoPossessPlayer; // 0x3d8(0x01)
	char AutoPossessAI; // 0x3d9(0x01)
	char UnknownData_3DA[0x6]; // 0x3da(0x06)
	struct UClass* AIControllerClass; // 0x3e0(0x08)
	struct APlayerState* PlayerState; // 0x3e8(0x08)
	char RemoteViewPitch; // 0x3f0(0x01)
	char UnknownData_3F1[0x7]; // 0x3f1(0x07)
	struct AController* LastHitBy; // 0x3f8(0x08)
	struct AController* Controller; // 0x400(0x08)
	char UnknownData_408[0x18]; // 0x408(0x18)
	struct FVector ControlInputVector; // 0x420(0x0c)
	struct FVector LastControlInputVector; // 0x42c(0x0c)
	char UnknownData_438[0x8]; // 0x438(0x08)

	void SpawnDefaultController(); // Function Engine.Pawn.SpawnDefaultController // Native|Public|BlueprintCallable // @ game+0x2e43e50
	void SetCanAffectNavigationGeneration(bool bNewValue); // Function Engine.Pawn.SetCanAffectNavigationGeneration // Final|Native|Public|BlueprintCallable // @ game+0x2e3eab0
	void ReceiveUnpossessed(struct AController* OldController); // Function Engine.Pawn.ReceiveUnpossessed // Event|Public|BlueprintEvent // @ game+0x18e5fa0
	void ReceivePossessed(struct AController* NewController); // Function Engine.Pawn.ReceivePossessed // Event|Public|BlueprintEvent // @ game+0x18e5fa0
	void PawnMakeNoise(float Loudness, struct FVector NoiseLocation, bool bUseNoiseMakerLocation, struct AActor* NoiseMaker); // Function Engine.Pawn.PawnMakeNoise // Final|BlueprintAuthorityOnly|Native|Public|HasDefaults|BlueprintCallable // @ game+0x2e3bdd0
	void OnRep_PlayerState(); // Function Engine.Pawn.OnRep_PlayerState // Native|Public // @ game+0x2e3ba10
	void OnRep_Controller(); // Function Engine.Pawn.OnRep_Controller // Native|Public // @ game+0x2e3b970
	void LaunchPawn(struct FVector LaunchVelocity, bool bXYOverride, bool bZOverride); // Function Engine.Pawn.LaunchPawn // Final|Native|Public|HasDefaults|BlueprintCallable // @ game+0x2e3b0d0
	struct FVector K2_GetMovementInputVector(); // Function Engine.Pawn.K2_GetMovementInputVector // Final|Native|Public|HasDefaults|BlueprintCallable|BlueprintPure|Const // @ game+0x2e3ab40
	bool IsMoveInputIgnored(); // Function Engine.Pawn.IsMoveInputIgnored // Native|Public|BlueprintCallable|BlueprintPure|Const // @ game+0x2e3a5f0
	bool IsLocallyControlled(); // Function Engine.Pawn.IsLocallyControlled // Native|Public|BlueprintCallable|BlueprintPure|Const // @ game+0x2e3a590
	bool IsControlled(); // Function Engine.Pawn.IsControlled // Final|Native|Public|BlueprintCallable|BlueprintPure|Const // @ game+0x2e3a3e0
	struct FVector GetPendingMovementInputVector(); // Function Engine.Pawn.GetPendingMovementInputVector // Final|Native|Public|HasDefaults|BlueprintCallable|BlueprintPure|Const // @ game+0x2e37480
	struct FVector GetNavAgentLocation(); // Function Engine.Pawn.GetNavAgentLocation // Native|Public|HasDefaults|BlueprintCallable|BlueprintPure|Const // @ game+0x2e368f0
	struct UPawnMovementComponent* GetMovementComponent(); // Function Engine.Pawn.GetMovementComponent // Native|Public|BlueprintCallable|BlueprintPure|Const // @ game+0x2e36820
	struct AActor* GetMovementBaseActor(struct APawn* Pawn); // Function Engine.Pawn.GetMovementBaseActor // Final|Native|Static|Public|BlueprintCallable|BlueprintPure // @ game+0x2e367a0
	struct FVector GetLastMovementInputVector(); // Function Engine.Pawn.GetLastMovementInputVector // Final|Native|Public|HasDefaults|BlueprintCallable|BlueprintPure|Const // @ game+0x2e35df0
	struct FRotator GetControlRotation(); // Function Engine.Pawn.GetControlRotation // Final|Native|Public|HasDefaults|BlueprintCallable|BlueprintPure|Const // @ game+0x2e355c0
	struct AController* GetController(); // Function Engine.Pawn.GetController // Final|Native|Public|BlueprintCallable|BlueprintPure|Const // @ game+0x2e35600
	struct FRotator GetBaseAimRotation(); // Function Engine.Pawn.GetBaseAimRotation // Native|Public|HasDefaults|BlueprintCallable|BlueprintPure|Const // @ game+0x2e34fe0
	void DetachFromControllerPendingDestroy(); // Function Engine.Pawn.DetachFromControllerPendingDestroy // Native|Public|BlueprintCallable // @ game+0x2e33060
	struct FVector ConsumeMovementInputVector(); // Function Engine.Pawn.ConsumeMovementInputVector // Native|Public|HasDefaults|BlueprintCallable // @ game+0x2e32950
	void AddMovementInput(struct FVector WorldDirection, float ScaleValue, bool bForce); // Function Engine.Pawn.AddMovementInput // Native|Public|HasDefaults|BlueprintCallable // @ game+0x2e31810
	void AddControllerYawInput(float Val); // Function Engine.Pawn.AddControllerYawInput // Native|Public|BlueprintCallable // @ game+0x2e30a80
	void AddControllerRollInput(float Val); // Function Engine.Pawn.AddControllerRollInput // Native|Public|BlueprintCallable // @ game+0x2e30a00
	void AddControllerPitchInput(float Val); // Function Engine.Pawn.AddControllerPitchInput // Native|Public|BlueprintCallable // @ game+0x2e30980
};

// Class Engine.Character
// Size: 0x5e0 (Inherited: 0x440)
struct ACharacter : APawn {
	struct USkeletalMeshComponent* Mesh; // 0x440(0x08)
	struct UCharacterMovementComponent* CharacterMovement; // 0x448(0x08)
	struct UCapsuleComponent* CapsuleComponent; // 0x450(0x08)
	char BasedMovement[56]; // 0x458(0x38)
	char ReplicatedBasedMovement[56]; // 0x490(0x38)
	struct FVector BaseTranslationOffset; // 0x4c8(0x0c)
	char UnknownData_4D4[0xc]; // 0x4d4(0x0c)
	char BaseRotationOffset[16]; // 0x4e0(0x10)
	char ReplicatedMovementMode; // 0x4f0(0x01)
	bool bInBaseReplication; // 0x4f1(0x01)
	char UnknownData_4F2[0x2]; // 0x4f2(0x02)
	float CrouchedEyeHeight; // 0x4f4(0x04)
	char bIsCrouched : 1; // 0x4f8(0x01)
	char bPressedJump : 1; // 0x4f8(0x01)
	char bClientUpdating : 1; // 0x4f8(0x01)
	char bClientWasFalling : 1; // 0x4f8(0x01)
	char bClientResimulateRootMotion : 1; // 0x4f8(0x01)
	char bSimGravityDisabled : 1; // 0x4f8(0x01)
	char bServerMoveIgnoreRootMotion : 1; // 0x4f8(0x01)
	char UnknownData_4F9[0x3]; // 0x4f9(0x03)
	float JumpKeyHoldTime; // 0x4fc(0x04)
	float JumpMaxHoldTime; // 0x500(0x04)
	char UnknownData_504[0x4]; // 0x504(0x04)
	char OnReachedJumpApex[16]; // 0x508(0x10)
	char UnknownData_518[0x10]; // 0x518(0x10)
	char OnCharacterMovementUpdated[16]; // 0x528(0x10)
	char UnknownData_538[0x8]; // 0x538(0x08)
	char ClientRootMotionParams[64]; // 0x540(0x40)
	struct TArray<struct FSimulatedRootMotionReplicatedMove> RootMotionRepMoves; // 0x580(0x10)
	char RepRootMotion[64]; // 0x590(0x40)
	char UnknownData_5D0[0x10]; // 0x5d0(0x10)

	void UnCrouch(bool bClientSimulation); // Function Engine.Character.UnCrouch // Native|Public|BlueprintCallable // @ game+0x2e44690
	void StopJumping(); // Function Engine.Character.StopJumping // Native|Public|BlueprintCallable // @ game+0x2e44070
	void StopAnimMontage(struct UAnimMontage* AnimMontage); // Function Engine.Character.StopAnimMontage // Native|Public|BlueprintCallable // @ game+0x2e43fe0
	void SetReplicateMovement(bool bInReplicateMovement); // Function Engine.Character.SetReplicateMovement // Native|Public|BlueprintCallable // @ game+0x2e42b10
	float PlayAnimMontage(struct UAnimMontage* AnimMontage, float InPlayRate, struct FName StartSectionName); // Function Engine.Character.PlayAnimMontage // Native|Public|BlueprintCallable // @ game+0x2e3c150
	void OnWalkingOffLedge(struct FVector PreviousFloorImpactNormal, struct FVector PreviousFloorContactNormal, struct FVector PreviousLocation, float TimeDelta); // Function Engine.Character.OnWalkingOffLedge // Native|Event|Public|HasOutParms|HasDefaults|BlueprintEvent // @ game+0x2e3bc10
	void OnRep_RootMotion(); // Function Engine.Character.OnRep_RootMotion // Final|Native|Public // @ game+0x2e3bab0
	void OnRep_ReplicatedBasedMovement(); // Function Engine.Character.OnRep_ReplicatedBasedMovement // Native|Public // @ game+0x2e3ba30
	void OnRep_IsCrouched(); // Function Engine.Character.OnRep_IsCrouched // Native|Public // @ game+0x2e3b9d0
	void OnLaunched(struct FVector LaunchVelocity, bool bXYOverride, bool bZOverride); // Function Engine.Character.OnLaunched // Event|Public|HasDefaults|BlueprintEvent // @ game+0x18e5fa0
	void OnLanded(struct FHitResult Hit); // Function Engine.Character.OnLanded // Event|Public|HasOutParms|BlueprintEvent // @ game+0x18e5fa0
	void OnJumped(); // Function Engine.Character.OnJumped // Native|Event|Public|BlueprintEvent // @ game+0x2e3b840
	void LaunchCharacter(struct FVector LaunchVelocity, bool bXYOverride, bool bZOverride); // Function Engine.Character.LaunchCharacter // Native|Public|HasDefaults|BlueprintCallable // @ game+0x2e3afb0
	void K2_UpdateCustomMovement(float DeltaTime); // Function Engine.Character.K2_UpdateCustomMovement // Event|Public|BlueprintEvent // @ game+0x18e5fa0
	void K2_OnStartCrouch(float HalfHeightAdjust, float ScaledHalfHeightAdjust); // Function Engine.Character.K2_OnStartCrouch // Event|Public|BlueprintEvent // @ game+0x18e5fa0
	void K2_OnMovementModeChanged(char PrevMovementMode, char NewMovementMode, char PrevCustomMode, char NewCustomMode); // Function Engine.Character.K2_OnMovementModeChanged // Event|Public|BlueprintEvent // @ game+0x18e5fa0
	void K2_OnEndCrouch(float HalfHeightAdjust, float ScaledHalfHeightAdjust); // Function Engine.Character.K2_OnEndCrouch // Event|Public|BlueprintEvent // @ game+0x18e5fa0
	void Jump(); // Function Engine.Character.Jump // Native|Public|BlueprintCallable // @ game+0x2e3a9d0
	bool IsPlayingRootMotion(); // Function Engine.Character.IsPlayingRootMotion // Final|Native|Public|BlueprintCallable|BlueprintPure|Const // @ game+0x2e3a880
	bool IsPlayingNetworkedRootMotionMontage(); // Function Engine.Character.IsPlayingNetworkedRootMotionMontage // Final|Native|Public|BlueprintCallable|BlueprintPure|Const // @ game+0x2e3a850
	bool IsJumpProvidingForce(); // Function Engine.Character.IsJumpProvidingForce // Native|Public|BlueprintCallable|BlueprintPure|Const // @ game+0x2e3a560
	struct UAnimMontage* GetCurrentMontage(); // Function Engine.Character.GetCurrentMontage // Final|Native|Public|BlueprintCallable // @ game+0x2e35630
	void Crouch(bool bClientSimulation); // Function Engine.Character.Crouch // Native|Public|BlueprintCallable // @ game+0x2e32e00
	void ClientCheatWalk(); // Function Engine.Character.ClientCheatWalk // Net|NetReliableNative|Event|Public|NetClient // @ game+0x2e326e0
	void ClientCheatGhost(); // Function Engine.Character.ClientCheatGhost // Net|NetReliableNative|Event|Public|NetClient // @ game+0x2e326c0
	void ClientCheatFly(); // Function Engine.Character.ClientCheatFly // Net|NetReliableNative|Event|Public|NetClient // @ game+0x2e326a0
	bool CanJumpInternal(); // Function Engine.Character.CanJumpInternal // Native|Event|Protected|BlueprintEvent|Const // @ game+0x2e322f0
	bool CanJump(); // Function Engine.Character.CanJump // Final|Native|Public|BlueprintCallable|BlueprintPure|Const // @ game+0x2e322c0
};

struct UHealthComponent : UActorComponent {
	char UnknownData_C8[0x10]; // 0xc8(0x10)
	float MinTimeSinceLastPredictedHealthChangeToFireChangedEventAgain; // 0xd8(0x04)
	bool PreventDamageFromAllSourcesExceptWhitelistedSources; // 0xdc(0x01)
	bool ShowKillNotifications; // 0xdd(0x01)
	char UnknownData_DE[0x2]; // 0xde(0x02)
	float MaxHealth; // 0xe0(0x04)
	struct FCurrentHealthInfo CurrentHealthInfo; // 0xe4(0x18)
	char UnknownData_FC[0x4]; // 0xfc(0x04)
	struct TArray<struct FContinuousHealthChange> ContinuousHealthChangeSources; // 0x100(0x10)
	bool IsHealthAdjustLocked; // 0x110(0x01)
	char UnknownData_111[0x137]; // 0x111(0x137)
};


// Class Athena.AthenaCharacter
// Size: 0xc30 (Inherited: 0x5e0)
struct AAthenaCharacter : ACharacter {
	char UnknownData_5E0[0x130]; // 0x5e0(0x130)
	struct ULookAtOffsetComponent* LookAtOffsetComponent; // 0x710(0x08)
	struct UAnimationDataStoreAsset* AnimationDataStoreAsset; // 0x718(0x08)
	struct UAthenaAnimationSittingDataAsset* SittingAnimationDataAssets; // 0x720(0x08)
	struct UAthenaCharacterMovementComponent* AthenaCharacterMovementComponent; // 0x728(0x08)
	char Docker[144]; // 0x730(0x90)
	struct UActionStateMachineComponent* ActionStateMachineComponent; // 0x7c0(0x08)
	struct UActionStatePriorityTableData* ActionStatePriorityTableData; // 0x7c8(0x08)
	struct UClass* ActionStateCreatorDefinition; // 0x7d0(0x08)
	char ObjectMessageDispatcher[160]; // 0x7d8(0xa0)
	struct UWieldableItemSetComponent* WieldableItemSetComponent; // 0x878(0x08)
	struct UWieldedItemComponent* WieldedItemComponent; // 0x880(0x08)
	struct USceneComponent* MeshAdjustmentComponent; // 0x888(0x08)
	struct UInventoryManipulatorComponent* InventoryManipulatorComponent; // 0x890(0x08)
	struct ULoadoutComponent* LoadoutComponent; // 0x898(0x08)
	struct UItemLoadoutComponent* ItemLoadoutComponent; // 0x8a0(0x08)
	struct UHealthComponent* HealthComponent; // 0x8a8(0x08)
	struct UAthenaCharacterStateManagerComponent* StateManagerComponent; // 0x8b0(0x08)
	struct URewindComponent* RewindComponent; // 0x8b8(0x08)
	struct UActorDamageableComponent* ActorDamageableComponent; // 0x8c0(0x08)
	struct UCharacterHitReactionComponent* CharacterHitReactionComponent; // 0x8c8(0x08)
	struct UAnimNotifyWwiseEmitterComponent* AnimNotifyWwiseEmitterComponent; // 0x8d0(0x08)
	struct UMeleeAttackProcessorComponent* MeleeAttackProcessor; // 0x8d8(0x08)
	struct UHitDetectionComponent* HitDetectionComponent; // 0x8e0(0x08)
	struct UAthenaCharacterKnockbackComponent* KnockBackComponent; // 0x8e8(0x08)
	struct UAthenaCharacterDodgeComponent* DodgeComponent; // 0x8f0(0x08)
	struct UCharacterAINoiseEventComponent* CharacterAINoiseEventComponent; // 0x8f8(0x08)
	struct UActionRulesComponent* PrivateActionRulesComponent; // 0x900(0x08)
	struct UShipTrackerComponent* ShipTrackerComponent; // 0x908(0x08)
	struct UWatercraftTrackerComponent* WatercraftTrackerComponent; // 0x910(0x08)
	struct UItemLoaderComponent* ItemLoaderComponent; // 0x918(0x08)
	struct URetractableCharacterComponent* RetractableCharacterComponent; // 0x920(0x08)
	struct UResourceProviderComponent* ResourceProviderComponent; // 0x928(0x08)
	struct UCharacterFlammableComponent* CharacterFlammableComponent; // 0x930(0x08)
	struct USoakableComponent* SoakableComponent; // 0x938(0x08)
	struct UWaterExposureComponent* WaterExposureComponent; // 0x940(0x08)
	struct UShelteredComponent* ShelteredComponent; // 0x948(0x08)
	struct UBoxedRpcDispatcherComponent* BoxedRpcDispatcherComponent; // 0x950(0x08)
	struct UCosmeticItemAnimationComponent* CosmeticItemAnimationComponent; // 0x958(0x08)
	struct UInteractionPreventionComponent* InteractionPreventionComponent; // 0x960(0x08)
	struct UDeathCustomisationComponent* DeathCustomisation; // 0x968(0x08)
	char OnJumpedDelegate[16]; // 0x970(0x10)
	char UnknownData_980[0x10]; // 0x980(0x10)
	struct UMovementInterferenceComponent* InterferenceComponent; // 0x990(0x08)
	struct UWaterInteractionComponent* WaterInteractionComponent; // 0x998(0x08)
	struct UClass* ThirdPersonAnimSetDataId; // 0x9a0(0x08)
	bool OverrideEncroachesBlockingGeometry; // 0x9a8(0x01)
	char OverrideEncroachesBlockingGeometryChannel; // 0x9a9(0x01)
	char UnknownData_9AA[0x2]; // 0x9aa(0x02)
	struct FName OverrideFloorSweepCollisionProfileName; // 0x9ac(0x08)
	char UnknownData_9B4[0x20]; // 0x9b4(0x20)
	float MovementThresholdToRecordRewindTransform; // 0x9d4(0x04)
	char UnknownData_9D8[0xc]; // 0x9d8(0x0c)
	int32_t SpawnAnimIndex; // 0x9e4(0x04)
	char UnknownData_9E8[0x70]; // 0x9e8(0x70)
	struct UAnimationDataStore* AnimationDataStore; // 0xa58(0x08)
	char UnknownData_A60[0x58]; // 0xa60(0x58)
	struct APlayerState* OldPlayerState; // 0xab8(0x08)
	char UnknownData_AC0[0x3c]; // 0xac0(0x3c)
	float RelativeTargetYawOnMovingBase; // 0xafc(0x04)
	char UnknownData_B00[0x30]; // 0xb00(0x30)
	float SmoothYawOnMovingBaseTime; // 0xb30(0x04)
	int32_t RandomAnimationSeed; // 0xb34(0x04)
	char UnknownData_B38[0x8]; // 0xb38(0x08)
	bool RandomBool; // 0xb40(0x01)
	char UnknownData_B41[0x27]; // 0xb41(0x27)
	struct USkeletalMeshSocket* CameraSocket; // 0xb68(0x08)
	char UnknownData_B70[0x48]; // 0xb70(0x48)
	struct TArray<struct UInputComponent*> RegisteredInputComponents; // 0xbb8(0x10)
	char UnknownData_BC8[0x68]; // 0xbc8(0x68)

	//char WieldItem(TScriptInterface<struct UWieldableInterface> Item, bool Fast); // Function Athena.AthenaCharacter.WieldItem // RequiredAPI|Native|Public|BlueprintCallable // @ game+0xd80fd0
	bool UseItem(struct UClass* NotificationInputId); // Function Athena.AthenaCharacter.UseItem // RequiredAPI|Native|Public|BlueprintCallable // @ game+0xd80540
	void UpdateWaterServiceInterface(); // Function Athena.AthenaCharacter.UpdateWaterServiceInterface // Final|Native|Public|BlueprintCallable // @ game+0xd80460
	void UnforceWaterHeight(); // Function Athena.AthenaCharacter.UnforceWaterHeight // Final|Native|Public|BlueprintCallable // @ game+0xd7fcd0
	void SetIgnoreReplicationRotationOnly(bool InIgnoreReplicationRotationOnly); // Function Athena.AthenaCharacter.SetIgnoreReplicationRotationOnly // Final|RequiredAPI|Native|Public|BlueprintCallable // @ game+0xd7e3e0
	void ReceiveRestart(); // Function Athena.AthenaCharacter.ReceiveRestart // Event|Protected|BlueprintEvent // @ game+0x18e5fa0
	void PickUpItem(struct AItemInfo* ItemInfo, bool AndWield); // Function Athena.AthenaCharacter.PickUpItem // RequiredAPI|Native|Public|BlueprintCallable // @ game+0xd7cfd0
	void OnRep_RandomAnimationSeed(); // Function Athena.AthenaCharacter.OnRep_RandomAnimationSeed // Final|Native|Private // @ game+0xd7c9c0
	void Multicast_DebugSetInertFromServer(bool IsInert); // Function Athena.AthenaCharacter.Multicast_DebugSetInertFromServer // RequiredAPI|Net|NetReliableNative|Event|NetMulticast|Public // @ game+0xd7bd70
	void Kill(char DeathType); // Function Athena.AthenaCharacter.Kill // RequiredAPI|Native|Public|BlueprintCallable // @ game+0xd7b6d0
	bool IsInWater(); // Function Athena.AthenaCharacter.IsInWater // Final|Native|Public|BlueprintCallable|BlueprintPure|Const // @ game+0xd7b210
	bool IsInteractionValid(struct UObject* InInteractable); // Function Athena.AthenaCharacter.IsInteractionValid // RequiredAPI|Native|Public|BlueprintCallable // @ game+0xd7b240
	bool IsDead(); // Function Athena.AthenaCharacter.IsDead // RequiredAPI|Native|Public|BlueprintCallable|BlueprintPure|Const // @ game+0xd7b1d0
	void InteractWith(struct UObject* InInteractable, struct UClass* NotificationInputId); // Function Athena.AthenaCharacter.InteractWith // RequiredAPI|Native|Public|BlueprintCallable // @ game+0xd7aee0
	void Interact(struct UObject* InInteractable); // Function Athena.AthenaCharacter.Interact // Final|Native|Public|BlueprintCallable // @ game+0xd7ae60
	bool HasValidWaterHeight(); // Function Athena.AthenaCharacter.HasValidWaterHeight // RequiredAPI|Native|Public|BlueprintCallable|BlueprintPure|Const // @ game+0xd7acf0
	bool HasMovementBase(); // Function Athena.AthenaCharacter.HasMovementBase // Final|Native|Public|BlueprintCallable|BlueprintPure|Const // @ game+0xd7ac90
	void HandleCharacterMovementUpdated(float DeltaSeconds, struct FVector OldLocation, struct FVector OldVelocity); // Function Athena.AthenaCharacter.HandleCharacterMovementUpdated // Final|Native|Private|HasDefaults // @ game+0xd7aa80
	float GetYawOnMovingBase(); // Function Athena.AthenaCharacter.GetYawOnMovingBase // Final|Native|Public|BlueprintCallable|BlueprintPure|Const // @ game+0xd7aa50
	float GetWaterLevelRelativeToCharacterBasePosition(); // Function Athena.AthenaCharacter.GetWaterLevelRelativeToCharacterBasePosition // Final|RequiredAPI|Native|Public|BlueprintCallable|BlueprintPure|Const // @ game+0xd7a9f0
	float GetWaterHeight(); // Function Athena.AthenaCharacter.GetWaterHeight // RequiredAPI|Native|Public|BlueprintCallable|BlueprintPure|Const // @ game+0xd7a9b0
	float GetViewPitch(); // Function Athena.AthenaCharacter.GetViewPitch // Final|RequiredAPI|Native|Public|BlueprintCallable|BlueprintPure|Const // @ game+0xd7a8b0
	bool GetValidWaterHeightAtomic(float OutWaterHeight); // Function Athena.AthenaCharacter.GetValidWaterHeightAtomic // RequiredAPI|Native|Public|HasOutParms|BlueprintCallable|BlueprintPure|Const // @ game+0xd7a750
	struct USkeletalMeshComponent* GetThirdPersonMeshComponent(); // Function Athena.AthenaCharacter.GetThirdPersonMeshComponent // RequiredAPI|Native|Public|BlueprintCallable|BlueprintPure|Const // @ game+0xd7a440
	bool GetIgnoreReplicationRotationOnly(); // Function Athena.AthenaCharacter.GetIgnoreReplicationRotationOnly // Final|Native|Public|BlueprintCallable|BlueprintPure|Const // @ game+0xd78010
	struct UObject* GetFocusedInteractable(); // Function Athena.AthenaCharacter.GetFocusedInteractable // RequiredAPI|Native|Public|BlueprintCallable|BlueprintPure|Const // @ game+0xd77ec0
	struct FCollisionResponseContainer GetFloorSweepCollisionResponseContainer(); // Function Athena.AthenaCharacter.GetFloorSweepCollisionResponseContainer // Final|Native|Public|BlueprintCallable|BlueprintPure|Const // @ game+0xd77e80
	struct USkeletalMeshComponent* GetFirstPersonMeshComponent(); // Function Athena.AthenaCharacter.GetFirstPersonMeshComponent // RequiredAPI|Native|Public|BlueprintCallable|BlueprintPure|Const // @ game+0xd77e00
	struct AActor* GetCurrentShip(); // Function Athena.AthenaCharacter.GetCurrentShip // RequiredAPI|Native|Public|BlueprintCallable|BlueprintPure|Const // @ game+0xd77c50
	struct FTransform GetCharacterTransform(); // Function Athena.AthenaCharacter.GetCharacterTransform // RequiredAPI|Native|Public|HasDefaults|BlueprintCallable|BlueprintPure|Const // @ game+0xd77820
	struct FRotator GetCharacterRotation(); // Function Athena.AthenaCharacter.GetCharacterRotation // RequiredAPI|Native|Public|HasDefaults|BlueprintCallable|BlueprintPure|Const // @ game+0xd777d0
	void GenerateNewRandomBool(); // Function Athena.AthenaCharacter.GenerateNewRandomBool // Final|Native|Public|BlueprintCallable // @ game+0xd770e0
	void GenerateNewRandomAnimationSeed(); // Function Athena.AthenaCharacter.GenerateNewRandomAnimationSeed // RequiredAPI|Native|Public|BlueprintCallable // @ game+0xd770c0
	void ForceWaterHeight(float WaterHeight, struct UClass* WaterId); // Function Athena.AthenaCharacter.ForceWaterHeight // Final|RequiredAPI|Native|Public|BlueprintCallable // @ game+0xd76ff0
	void CureAllAilings(); // Function Athena.AthenaCharacter.CureAllAilings // Final|RequiredAPI|Native|Public|BlueprintCallable // @ game+0xd76970
	void CreateProjectileTraceHitVolume(); // Function Athena.AthenaCharacter.CreateProjectileTraceHitVolume // RequiredAPI|Native|Public|BlueprintCallable // @ game+0xd76950
	bool CanInteractWith(struct UObject* InInteractable, struct UClass* NotificationInputId); // Function Athena.AthenaCharacter.CanInteractWith // RequiredAPI|Native|Public|BlueprintCallable // @ game+0xd76400
	void CalculateWaterHeight(); // Function Athena.AthenaCharacter.CalculateWaterHeight // RequiredAPI|Native|Public|BlueprintCallable // @ game+0xd763d0
	bool AllAnimationsLoaded(); // Function Athena.AthenaCharacter.AllAnimationsLoaded // RequiredAPI|Native|Public|BlueprintCallable|BlueprintPure|Const // @ game+0xd75d70
};

struct AAthenaPlayerCharacter : AAthenaCharacter {
	char UnknownData_C40[0x150]; // 0xc40(0x150)
	struct USceneComponent* FirstPersonMeshOffsetComponent; // 0xd90(0x08)
	struct USkeletalMeshComponent* FirstPersonMesh; // 0xd98(0x08)
	struct UAthenaCameraComponent* FirstPersonCamera; // 0xda0(0x08)
	struct TArray<struct UParticleSystemComponent*> FirstPersonParticleComponents; // 0xda8(0x10)
	struct UAthenaCameraComponent* ThirdPersonCamera; // 0xdb8(0x08)
	struct TArray<struct UParticleSystemComponent*> ThirdPersonParticleComponents; // 0xdc0(0x10)
	struct UAthenaCameraComponent* SpringArmCamera; // 0xdd0(0x08)
	struct ULookAtEmoteCameraComponent* LookAtEmoteCameraComponent; // 0xdd8(0x08)
	struct UAthenaSpringArmComponent* SpringArm; // 0xde0(0x08)
	struct UChildActorComponent* LocalCloudDome; // 0xde8(0x08)
	struct UCharacterInteractionComponent* InteractionComponent; // 0xdf0(0x08)
	struct UClimbingComponent* ClimbingComponent; // 0xdf8(0x08)
	struct UDrunkennessComponent* DrunkennessComponent; // 0xe00(0x08)
	struct UStaggerComponent* StaggerComponent; // 0xe08(0x08)
	struct UDrowningComponent* DrowningComponent; // 0xe10(0x08)
	struct URumbleHandlerComponent* RumbleHandlerComponent; // 0xe18(0x08)
	struct UScreenSpaceVfxComponent* ScreenSpaceVfxComponent; // 0xe20(0x08)
	struct UTreasureMapCollectionComponent* TreasureMapCollectionComponent; // 0xe28(0x08)
	struct UPhrasesRadialComponent* PhrasesRadialComponent; // 0xe30(0x08)
	struct UQuickInventoryComponent* QuickInventoryComponent; // 0xe38(0x08)
	struct UPointOfInterestTrackerComponent* PointOfInterestTrackerComponent; // 0xe40(0x08)
	struct UProjectileWeaponQSDebugComponent* ProjectileWeaponQSDebugComponent; // 0xe48(0x08)
	struct ULimpingComponent* LimpingComponent; // 0xe50(0x08)
	struct UPacingComponent* PacingComponent; // 0xe58(0x08)
	struct UBurpComponent* BurpComponent; // 0xe60(0x08)
	struct UMeleeAttackLockOnComponent* MeleeLockOnComponent; // 0xe68(0x08)
	struct UDeathSelfInteractionComponent* DeathSelfInteractionComponent; // 0xe70(0x08)
	struct URidePlayerComponent* RidePlayerComponent; // 0xe78(0x08)
	struct UReviveDebugComponent* ReviveDebugComponent; // 0xe80(0x08)
	struct UFlashbangEffectComponent* FlashbangEffectComponent; // 0xe88(0x08)
	struct UBalancingComponent* BalancingComponent; // 0xe90(0x08)
	struct UWorldLocationVisitorComponent* WorldLocationVisitorComponent; // 0xe98(0x08)
	struct UMeleeAttackLockOnComponentSettings* MeleeAttackLockOnSettings; // 0xea0(0x08)
	struct UStatusEffectManagerComponent* StatusEffectManagerComponent; // 0xea8(0x08)
	struct UStatusEffectPersistenceComponent* StatusEffectPersistenceComponent; // 0xeb0(0x08)
	struct UPlayerCurseComponent* PlayerCurseComponent; // 0xeb8(0x08)
	struct UMaterialStatusSusceptibilityComponent* MaterialStatusSusceptibilityComponent; // 0xec0(0x08)
	struct UHealthRegenerationPoolComponent* HealthRegenerationPoolComponent; // 0xec8(0x08)
	struct USicknessComponent* SicknessComponent; // 0xed0(0x08)
	struct URewindComponent* PlayerViewRewindComponent; // 0xed8(0x08)
	struct UCapsuleComponent* ProjectileTraceHitVolume; // 0xee0(0x08)
	struct UPlayerMerchantContractsComponent* PlayerMerchantContractsComponent; // 0xee8(0x08)
	struct UPlayerShroudBreakerTrackerComponent* PlayerShroudBreakerTrackerComponent; // 0xef0(0x08)
	struct UPetOwnerComponent* PetOwnerComponent; // 0xef8(0x08)
	struct UAISpawnContextContainerComponent* SpawnContextContainerComponent; // 0xf00(0x08)
	struct URadialManagerComponent* RadialManager; // 0xf08(0x08)
	struct UStreamingLocationComponent* StreamingLocationComponent; // 0xf10(0x08)
	struct UEquipClothingComponent* EquipClothingComponent; // 0xf18(0x08)
	struct UGenericStatusVFXComponent* GenericStatusVFXComponent; // 0xf20(0x08)
	float CameraFOVWhenSprinting; // 0xf28(0x04)
	char UnknownData_F2C[0x4]; // 0xf2c(0x04)
	struct UCurveVector* ApproximateCamPitchToLocalCamOffsetCurve; // 0xf30(0x08)
	char WalkConditionParams[0x8]; // 0xf38(0x08)
	char ServerSprintConditionParams[0x0c]; // 0xf40(0x0c)
	char ClientSprintConditionParams[0x0c]; // 0xf4c(0x0c)
	float SprintingServerTimeTolerance; // 0xf58(0x04)
	float PostSprintResetTime; // 0xf5c(0x04)
	struct UAthenaSpringArmComponentParams* EmoteSpringArmParameters; // 0xf60(0x08)
	struct UAthenaSpringArmComponentParams* DeathSpringArmParameters; // 0xf68(0x08)
	struct UEmotesRadialDataAsset* EmotesRadialDataAsset; // 0xf70(0x08)
	bool AllowAnimationTickAggregation; // 0xf78(0x01)
	char UnknownData_F79[0x3]; // 0xf79(0x03)
	char AchievementKillOpponentFromBehindWithBlunderbuss[0x4]; // 0xf7c(0x04)
	char AchievementHeavyAttackRivalOffTheirShip[0x10]; // 0xf80(0x10)
	char AchievementBlockThenHitAndGetBlockedThenTakeHit[0x10]; // 0xf90(0x10)
	char AchievementHaveADrinkWithAnotherCrewAtAnOutpost[0x10]; // 0xfa0(0x20)
	char AchievementKillOpponentInContest[0x08]; // 0xfc0(0x08)
	struct UClass* ConditionalStatsTriggerForKillingAnotherPlayer; // 0xfc8(0x08)
	struct UAICreatureMovementModifierParamsDataAsset* PirateLegendHideoutPetMovementData; // 0xfd0(0x08)
	struct UAICreatureMovementModifierParamsDataAsset* OnShipPetMovementData; // 0xfd8(0x08)
	struct UAsyncLoadoutRepairComponent* RepairComponent; // 0xfe0(0x08)
	struct USeasonProgressionUIComponent* SeasonUIComponent; // 0xfe8(0x08)
	struct UAimAssistComponent* AimAssistComponent; // 0xff0(0x08)
	struct UAimAssistTargetComponent* AimAssistTargetComponent; // 0xff8(0x08)
	struct USequencerCameraDockingComponent* SequencerCameraDockingComponent; // 0x1000(0x08)
	struct UEmotePropData* EmotePropData; // 0x1008(0x08)
	char UnknownData_1010[0xb0]; // 0x1010(0xb0)
	struct UClass* FirstPersonAnimSetDataId; // 0x10c0(0x08)
	struct UAnimationDataStoreWeakReferenceAsset* FirstPersonAnimationDataStoreWeakReferencesAsset; // 0x10c8(0x08)
	char CharacterType; // 0x10d0(0x01)
	char UnknownData_10D1[0x20]; // 0x10d1(0x20)
	bool IsWearingSkeletonCurseCached; // 0x10f1(0x01)
	bool IsWearingGhostCurseCached; // 0x10f2(0x01)
	char UnknownData_10F3[0xc85]; // 0x10f3(0xc85)
	struct UClothingLoadoutComponent* ClothingLoadoutComponent; // 0x1d78(0x08)
	struct UPetLoadoutComponent* PetLoadoutComponent; // 0x1d80(0x08)
	struct UVoyageParticipantComponent* PrimaryVoyageParticipantComponent; // 0x1d88(0x08)
	struct UVoyageParticipantComponent* TaleVoyageParticipantComponent; // 0x1d90(0x08)
	struct UVoyageParticipantComponent* EmergentVoyageParticipantComponent; // 0x1d98(0x08)
	struct UPlayerWorldLocationComponent* PlayerWorldLocationComponent; // 0x1da0(0x08)
	struct UChainLightningReceiverComponent* ChainLightningReceiverComponent; // 0x1da8(0x08)
	struct UPlayerGuildComponent* PlayerGuildComponent; // 0x1db0(0x08)
	struct UGuildInviterComponent* GuildInviterComponent; // 0x1db8(0x08)
	struct UInteractableComponentWithTooltipDetailedEventProvider* EmoteInteractableComponent; // 0x1dc0(0x08)
	char PendingModelSwap[0x68]; // 0x1dc8(0x68)
	char UnknownData_1E30[0x20]; // 0x1e30(0x20)
	struct FName ReplicatedOverrideAnimationEntry; // 0x1e50(0x08)
	char UnknownData_1E58[0x9]; // 0x1e58(0x09)
	bool ReplicatedEmoteExitAllowed; // 0x1e61(0x01)
	char UnknownData_1E62[0x7e]; // 0x1e62(0x7e)
	bool FinishedWaitingForSpawn; // 0x1ee0(0x01)
	char UnknownData_1EE1[0x31]; // 0x1ee1(0x31)
	bool AutoFloatInWater; // 0x1f12(0x01)
	char UnknownData_1F13[0x1]; // 0x1f13(0x01)
	bool ReplicatedIsSprinting; // 0x1f14(0x01)
	char UnknownData_1F15[0x1b]; // 0x1f15(0x1b)
	float AutoMoveCancelThreshold; // 0x1f30(0x04)
	int32_t ReplicatedOverridePirateDescSeed; // 0x1f34(0x04)
	bool PreventJumping; // 0x1f38(0x01)
	bool StopMovementAndPreventSwimming; // 0x1f39(0x01)
	bool PlayerIsInTunnelOfTheDamned; // 0x1f3a(0x01)
	char UnknownData_1F3B[0x95]; // 0x1f3b(0x95)
};

// Class Athena.AthenaAICharacter
// Size: 0x13b0 (Inherited: 0xc30)
struct AAthenaAICharacter : AAthenaCharacter {
	char UnknownData_C30[0xa8]; // 0xc30(0xa8)
	struct UClass* DefaultAmmoItemDescType; // 0xcd8(0x08)
	struct UClass* DefaultInteractableAmmoItemDescType; // 0xce0(0x08)
	struct UCurveFloat* DistanceInMToCannonShotHitChanceCurve; // 0xce8(0x08)
	bool AimNoiseEnabled; // 0xcf0(0x01)
	char UnknownData_CF1[0x3]; // 0xcf1(0x03)
	float AmplitudeChangeSpeed; // 0xcf4(0x04)
	float AmplitudeOffset; // 0xcf8(0x04)
	float Frequency; // 0xcfc(0x04)
	float InteractableMissFallShortMinProportion; // 0xd00(0x04)
	float InteractableMissFallShortMaxProportion; // 0xd04(0x04)
	char TrackedActorType; // 0xd08(0x01)
	char UnknownData_D09[0x7]; // 0xd09(0x07)
	struct UFaceTargetComponent* FaceTargetComponent; // 0xd10(0x08)
	struct UAIPartsRetrievalComponent* AIPartsRetrievalComponent; // 0xd18(0x08)
	struct UAthenaAIFormComponent* FormComponent; // 0xd20(0x08)
	struct UAICharacterAudioComponent* AICharacterAudioComponent; // 0xd28(0x08)
	struct UStatusEffectManagerComponent* StatusEffectManagerComponent; // 0xd30(0x08)
	struct UStatusEffectPersistenceComponent* StatusEffectPersistenceComponent; // 0xd38(0x08)
	struct UPlayerCurseComponent* PlayerCurseComponent; // 0xd40(0x08)
	struct UVulnerabilityDuringAIStrategyComponent* VulnerabilityDuringAIStrategyComponent; // 0xd48(0x08)
	struct UCapsuleComponent* ProjectileTraceHitVolume; // 0xd50(0x08)
	struct UAnimationDataOverriderComponent* AnimationDataOverriderComponent; // 0xd58(0x08)
	struct UCustomAnimationHandlerComponent* CustomAnimationHandlerComponent; // 0xd60(0x08)
	struct UAIProjectileWeaponFiringIntentionComponent* FiringIntentionComponent; // 0xd68(0x08)
	struct UObject* KilledVfxTemplate; // 0xd70(0x08)
	struct UObject* PartSpecificKilledVfxTemplate; // 0xd78(0x08)
	char AISpawnLoadout[32]; // 0xd80(0x20)
	bool KillOnFallingIntoWater; // 0xda0(0x01)
	char UnknownData_DA1[0x7]; // 0xda1(0x07)
	struct UClass* MeleeAttackStrategyId; // 0xda8(0x08)
	struct UClass* GunpowderKegAnimationStoreId; // 0xdb0(0x08)
	char OnFireStat[4]; // 0xdb8(0x04)
	char UnknownData_DBC[0x4c]; // 0xdbc(0x4c)
	struct USkeletalMesh* AssignedMesh; // 0xe08(0x08)
	struct UColorTexture* TeamColorTexture; // 0xe10(0x08)
	char TeamID; // 0xe18(0x01)
	char UnknownData_E19[0x7]; // 0xe19(0x07)
	struct AActor* CurrentShip; // 0xe20(0x08)
	float MeshScale; // 0xe28(0x04)
	bool DamageResponsesDisabled; // 0xe2c(0x01)
	bool TurnActive; // 0xe2d(0x01)
	char UnknownData_E2E[0x2]; // 0xe2e(0x02)
	struct UClass* CurrentAIStrategy; // 0xe30(0x08)
	struct UClass* CurrentAnimationState; // 0xe38(0x08)
	struct UClass* AlternateLocomotionItemType; // 0xe40(0x08)
	char UnknownData_E48[0x3b0]; // 0xe48(0x3b0)
	struct UAthenaAIAmmoDataAsset* Ammo; // 0x11f8(0x08)
	char PawnEncounterSpec[208]; // 0x1200(0xd0)
	char UnknownData_12D0[0xe0]; // 0x12d0(0xe0)

	void SetTargetActorToFace(struct AActor* InActor); // Function Athena.AthenaAICharacter.SetTargetActorToFace // Final|RequiredAPI|Native|Public|BlueprintCallable // @ game+0xd7ecc0
	void SetRegion(struct FName InRegion); // Function Athena.AthenaAICharacter.SetRegion // Final|RequiredAPI|Native|Public|HasOutParms|BlueprintCallable // @ game+0xd7eb20
	void SetOverrideCannonShotHitChance(bool Enabled, float HitChance); // Function Athena.AthenaAICharacter.SetOverrideCannonShotHitChance // Final|RequiredAPI|Native|Public|BlueprintCallable // @ game+0xd7e9d0
	void SetLoadout(struct ULoadoutAsset* InLoadout); // Function Athena.AthenaAICharacter.SetLoadout // Final|Native|Public|BlueprintCallable // @ game+0xd7e650
	void SetAIStrategy(struct UClass* InStrategy); // Function Athena.AthenaAICharacter.SetAIStrategy // RequiredAPI|Native|Public|BlueprintCallable // @ game+0xd7dc50
	void SetAIAnimationState(struct UClass* InAnimationState); // Function Athena.AthenaAICharacter.SetAIAnimationState // RequiredAPI|Native|Public|BlueprintCallable // @ game+0xd7dbc0
	void ResetMaxHealthTo(float InMaxHealth); // Function Athena.AthenaAICharacter.ResetMaxHealthTo // RequiredAPI|Native|Public|BlueprintCallable // @ game+0xd7d4f0
	void OnRep_MeshScale(float OldMeshScale); // Function Athena.AthenaAICharacter.OnRep_MeshScale // Final|RequiredAPI|Native|Public // @ game+0xd7c8a0
	void OnRep_DamageResponsesDisabled(bool OldDamageResponsesDisabled); // Function Athena.AthenaAICharacter.OnRep_DamageResponsesDisabled // Final|Native|Public // @ game+0xd7c790
	void OnRep_CurrentAnimationState(struct UClass* OldAnimationState); // Function Athena.AthenaAICharacter.OnRep_CurrentAnimationState // Final|RequiredAPI|Native|Public // @ game+0xd7c600
	void OnRep_CurrentAIStrategy(struct UClass* OldAIStrategy); // Function Athena.AthenaAICharacter.OnRep_CurrentAIStrategy // Final|RequiredAPI|Native|Public // @ game+0xd7c580
	struct FName GetRegion(); // Function Athena.AthenaAICharacter.GetRegion // Final|RequiredAPI|Native|Public|BlueprintCallable|BlueprintPure|Const // @ game+0xd7a1f0
	struct UClass* GetAIStrategy(); // Function Athena.AthenaAICharacter.GetAIStrategy // RequiredAPI|Native|Public|BlueprintCallable|BlueprintPure|Const // @ game+0xd77200
	struct FAIEncounterSpecification GetAIEncounterSpec(); // Function Athena.AthenaAICharacter.GetAIEncounterSpec // Final|Native|Public|BlueprintCallable|BlueprintPure|Const // @ game+0xd77140
	struct UClass* GetAIAnimationState(); // Function Athena.AthenaAICharacter.GetAIAnimationState // RequiredAPI|Native|Public|BlueprintCallable|BlueprintPure|Const // @ game+0xd77100
};
// Class Engine.Level
// Size: 0x300 (Inherited: 0x28)
struct ULevel {
	char padding[0xA0];
	TArray<AActor*> actors;
};

// Class Engine.LevelActorContainer
// Size: 0x38 (Inherited: 0x28)
/*struct ULevelActorContainer : UObject {
	struct TArray<struct AActor*> Actors; // 0x28(0x10)
};*/

// Class Engine.Player
// Size: 0x48 (Inherited: 0x28)
struct UPlayer {
	char UnknownData_28[48]; // 0x28(0x08)
	struct APlayerController* PlayerController; // 0x30(0x08)
	int32_t CurrentNetSpeed; // 0x38(0x04)
	int32_t ConfiguredInternetSpeed; // 0x3c(0x04)
	int32_t ConfiguredLanSpeed; // 0x40(0x04)
	char UnknownData_44[0x4]; // 0x44(0x04)
};

// Class Engine.LocalPlayer
// Size: 0x210 (Inherited: 0x48)
struct ULocalPlayer : UPlayer {
	char UnknownData_48[0x18]; // 0x48(0x18)
	struct UGameViewportClient* ViewportClient; // 0x60(0x08)
	char UnknownData_68[0x40]; // 0x68(0x40)
	char AspectRatioAxisConstraint; // 0xa8(0x01)
	char UnknownData_A9[0x7]; // 0xa9(0x07)
	struct UClass* PendingLevelPlayerControllerClass; // 0xb0(0x08)
	char bSentSplitJoin : 1; // 0xb8(0x01)
	char UnknownData_B8_1 : 7; // 0xb8(0x01)
	char UnknownData_B9[0x3]; // 0xb9(0x03)
	float MinimumAspectRatio; // 0xbc(0x04)
	char UnknownData_C0[0x150]; // 0xc0(0x150)
};

// Class Engine.World
// Size: 0x7e0 (Inherited: 0x28)
struct UWorld : UObject {
	char UnknownData_28[0x8]; // 0x28(0x08)
	struct ULevel* PersistentLevel; // 0x30(0x08)
	struct UNetDriver* NetDriver; // 0x38(0x08)
	struct ULineBatchComponent* LineBatcher; // 0x40(0x08)
	struct ULineBatchComponent* PersistentLineBatcher; // 0x48(0x08)
	struct ULineBatchComponent* ForegroundLineBatcher; // 0x50(0x08)
	struct AGameState* GameState; // 0x58(0x08)
	struct AGameNetworkManager* NetworkManager; // 0x60(0x08)
	struct UPhysicsCollisionHandler* PhysicsCollisionHandler; // 0x68(0x08)
	struct TArray<struct UObject*> ExtraReferencedObjects; // 0x70(0x10)
	struct TArray<struct UObject*> PerModuleDataObjects; // 0x80(0x10)
	struct TArray<struct ULevelStreaming*> StreamingLevels; // 0x90(0x10)
	char StreamingLevelsPrefix[16]; // 0xa0(0x10)
	struct ULevel* CurrentLevelPendingVisibility; // 0xb0(0x08)
	struct AParticleEventManager* MyParticleEventManager; // 0xb8(0x08)
	struct APhysicsVolume* DefaultPhysicsVolume; // 0xc0(0x08)
	struct TArray<struct ULevelStreaming*> DirtyStreamingLevels; // 0xc8(0x10)
	char UnknownData_D8[0x1c]; // 0xd8(0x1c)
	char Feature[8]; // 0xf4(0x08)
	char UnknownData_FC[0x4]; // 0xfc(0x04)
	struct TArray<struct FName> FeatureReferences; // 0x100(0x10)
	bool ParticleLOD_bUseGameThread; // 0x110(0x01)
	bool ParticleLOD_bUseMultipleViewportCase; // 0x111(0x01)
	char UnknownData_112[0x2]; // 0x112(0x02)
	char ParticleLOD_PlayerViewpointLocation[12]; // 0x114(0x0c)
	char TestMetadata[16]; // 0x120(0x10)
	struct UNavigationSystem* NavigationSystem; // 0x130(0x08)
	struct AGameMode* AuthorityGameMode; // 0x138(0x08)
	struct UAISystemBase* AISystem; // 0x140(0x08)
	struct UAvoidanceManager* AvoidanceManager; // 0x148(0x08)
	struct TArray<struct ULevel*> Levels; // 0x150(0x10)
	char UnknownData_160[0x50]; // 0x160(0x50)
	struct ULevel* CurrentLevel; // 0x1b0(0x08)
	char UnknownData_1B8[0x8]; // 0x1b8(0x08)
	struct UGameInstance* OwningGameInstance; // 0x1c0(0x08)
	struct TArray<struct UMaterialParameterCollectionInstance*> ParameterCollectionInstances; // 0x1c8(0x10)
	char UnknownData_1D8[0x538]; // 0x1d8(0x538)
	struct UWorldComposition* WorldComposition; // 0x710(0x08)
	char UnknownData_718[0x3d]; // 0x718(0x3d)
	char UnknownData_755_0 : 7; // 0x755(0x01)
	char bAreConstraintsDirty : 1; // 0x755(0x01)
	char UnknownData_756[0x8a]; // 0x756(0x8a)
};







struct AController : AActor {
	char UnknownData_3C8[0x8]; // 0x3c8(0x08)
	struct APawn* Pawn; // 0x3d0(0x08)
	char UnknownData_3D8[0x8]; // 0x3d8(0x08)
	struct ACharacter* Character; // 0x3e0(0x08)
	struct APlayerState* PlayerState; // 0x3e8(0x08)
	struct USceneComponent* TransformComponent; // 0x3f0(0x08)
	struct FRotator ControlRotation; // 0x3f8(0x0c)
	char bAttachToPawn : 1; // 0x404(0x01)
	char UnknownData_404_1 : 7; // 0x404(0x01)
	char UnknownData_405[0xb]; // 0x405(0x0b)
	struct FName StateName; // 0x410(0x08)
	char OnInstigatedAnyDamage[16]; // 0x418(0x10)

	void UnPossess(); // Function Engine.Controller.UnPossess // Native|Public|BlueprintCallable // @ game+0x2d3ead0
	void StopMovement(); // Function Engine.Controller.StopMovement // Native|Public|BlueprintCallable // @ game+0x2d3e8a0
	void SetInitialLocationAndRotation(struct FVector NewLocation, struct FRotator NewRotation); // Function Engine.Controller.SetInitialLocationAndRotation // Native|Public|HasOutParms|HasDefaults|BlueprintCallable // @ game+0x2d3d170
	void SetControlRotation(struct FRotator NewRotation); // Function Engine.Controller.SetControlRotation // Native|Public|HasOutParms|HasDefaults|BlueprintCallable // @ game+0x2d3cb50
	void ReceiveInstigatedAnyDamage(float Damage, struct UDamageType* DamageType, struct AActor* DamagedActor, struct AActor* DamageCauser); // Function Engine.Controller.ReceiveInstigatedAnyDamage // BlueprintAuthorityOnly|Event|Protected|BlueprintEvent // @ game+0x18e5fa0
	void Possess(struct APawn* InPawn); // Function Engine.Controller.Possess // BlueprintAuthorityOnly|Native|Public|BlueprintCallable // @ game+0x2d3a830
	void OnRep_PlayerState(); // Function Engine.Controller.OnRep_PlayerState // Native|Public // @ game+0x2d39d10
	void OnRep_Pawn(); // Function Engine.Controller.OnRep_Pawn // Native|Public // @ game+0x2d39cf0
	bool LineOfSightTo(struct AActor* Other, struct FVector ViewPoint, bool bAlternateChecks); // Function Engine.Controller.LineOfSightTo // Native|Public|HasDefaults|BlueprintCallable|BlueprintPure|Const // @ game+0x2d398a0
	struct APawn* K2_GetPawn(); // Function Engine.Controller.K2_GetPawn // Final|Native|Public|BlueprintCallable|BlueprintPure|Const // @ game+0x2d37d60
	bool IsLocalPlayerController(); // Function Engine.Controller.IsLocalPlayerController // Native|Public|BlueprintCallable|BlueprintPure|Const // @ game+0x2d35b90
	bool IsLocalController(); // Function Engine.Controller.IsLocalController // Native|Public|BlueprintCallable|BlueprintPure|Const // @ game+0x2d35b60
	struct AActor* GetViewTarget(); // Function Engine.Controller.GetViewTarget // Native|Public|BlueprintCallable|BlueprintPure|Const // @ game+0x2d35640
	struct FRotator GetDesiredRotation(); // Function Engine.Controller.GetDesiredRotation // Native|Public|HasDefaults|BlueprintCallable|BlueprintPure|Const // @ game+0x2d32f20
	struct FRotator GetControlRotation(); // Function Engine.Controller.GetControlRotation // Native|Public|HasDefaults|BlueprintCallable|BlueprintPure|Const // @ game+0x2d329c0
	void ClientSetRotation(struct FRotator NewRotation, bool bResetCamera); // Function Engine.Controller.ClientSetRotation // Net|NetReliableNative|Event|Public|HasDefaults|NetClient // @ game+0x2d30310
	void ClientSetLocation(struct FVector NewLocation, struct FRotator NewRotation); // Function Engine.Controller.ClientSetLocation // Net|NetReliableNative|Event|Public|HasDefaults|NetClient // @ game+0x2d30230
	struct APlayerController* CastToPlayerController(); // Function Engine.Controller.CastToPlayerController // Final|Native|Public|BlueprintCallable // @ game+0x2d2e670
};

// Class Engine.Info
// Size: 0x3c8 (Inherited: 0x3c8)
struct AInfo : AActor { };

// Class Engine.PlayerState
// Size: 0x450 (Inherited: 0x3c8)
struct APlayerState : AInfo {
	float Score; // 0x3c8(0x04)
	char Ping; // 0x3cc(0x01)
	char UnknownData_3CD[0x3]; // 0x3cd(0x03)
	struct FString PlayerName; // 0x3d0(0x10)
	char UnknownData_3E0[0x10]; // 0x3e0(0x10)
	int32_t PlayerId; // 0x3f0(0x04)
	char bIsSpectator : 1; // 0x3f4(0x01)
	char bOnlySpectator : 1; // 0x3f4(0x01)
	char bIsABot : 1; // 0x3f4(0x01)
	char UnknownData_3F4_3 : 1; // 0x3f4(0x01)
	char bIsInactive : 1; // 0x3f4(0x01)
	char bFromPreviousLevel : 1; // 0x3f4(0x01)
	char UnknownData_3F4_6 : 2; // 0x3f4(0x01)
	char UnknownData_3F5[0x3]; // 0x3f5(0x03)
	int32_t StartTime; // 0x3f8(0x04)
	char UnknownData_3FC[0x4]; // 0x3fc(0x04)
	struct UClass* EngineMessageClass; // 0x400(0x08)
	char UnknownData_408[0x18]; // 0x408(0x18)
	char UniqueId[24]; // 0x420(0x18)
	char UnknownData_438[0x18]; // 0x438(0x18)

	void OnRep_UniqueId(); // Function Engine.PlayerState.OnRep_UniqueId // Native|Public // @ game+0x2e3bb70
};




// Class Engine.PlayerController
// Size: 0x770 (Inherited: 0x428)
struct APlayerController : AController {
	struct UPlayer* Player; // 0x428(0x08)
	char UnknownData_430[0x8]; // 0x430(0x08)
	struct APawn* AcknowledgedPawn; // 0x438(0x08)
	struct UInterpTrackInstDirector* ControllingDirTrackInst; // 0x440(0x08)
	char UnknownData_448[0x8]; // 0x448(0x08)
	struct AHUD* MyHUD; // 0x450(0x08)
	struct APlayerCameraManager* PlayerCameraManager; // 0x458(0x08)
	struct UClass* PlayerCameraManagerClass; // 0x460(0x08)
	bool bAutoManageActiveCameraTarget; // 0x468(0x01)
	char UnknownData_469[0x3]; // 0x469(0x03)
	struct FRotator TargetViewRotation; // 0x46c(0x0c)
	char UnknownData_478[0x10]; // 0x478(0x10)
	struct TArray<struct AActor*> HiddenActors; // 0x488(0x10)
	float LastSpectatorStateSynchTime; // 0x498(0x04)
	struct FVector LastSpectatorSyncLocation; // 0x49c(0x0c)
	struct FRotator LastSpectatorSyncRotation; // 0x4a8(0x0c)
	int32_t ClientCap; // 0x4b4(0x04)
	struct UCheatManager* CheatManager; // 0x4b8(0x08)
	struct UClass* CheatClass; // 0x4c0(0x08)
	struct UPlayerInput* PlayerInput; // 0x4c8(0x08)
	struct TArray<struct FActiveForceFeedbackEffect> ActiveForceFeedbackEffects; // 0x4d0(0x10)
	char UnknownData_4E0[0x90]; // 0x4e0(0x90)
	char UnknownData_570_0 : 2; // 0x570(0x01)
	char bPlayerIsWaiting : 1; // 0x570(0x01)
	char UnknownData_570_3 : 5; // 0x570(0x01)
	char UnknownData_571[0x3]; // 0x571(0x03)
	char NetPlayerIndex; // 0x574(0x01)
	bool bHasVoiceHandshakeCompleted; // 0x575(0x01)
	char UnknownData_576[0x2]; // 0x576(0x02)
	struct UNetConnection* PendingSwapConnection; // 0x578(0x08)
	struct UNetConnection* NetConnection; // 0x580(0x08)
	char UnknownData_588[0xc]; // 0x588(0x0c)
	float InputYawScale; // 0x594(0x04)
	float InputPitchScale; // 0x598(0x04)
	float InputRollScale; // 0x59c(0x04)
	char bShowMouseCursor : 1; // 0x5a0(0x01)
	char bEnableClickEvents : 1; // 0x5a0(0x01)
	char bEnableTouchEvents : 1; // 0x5a0(0x01)
	char bEnableMouseOverEvents : 1; // 0x5a0(0x01)
	char bEnableTouchOverEvents : 1; // 0x5a0(0x01)
	char bForceFeedbackEnabled : 1; // 0x5a0(0x01)
	char UnknownData_5A0_6 : 2; // 0x5a0(0x01)
	char UnknownData_5A1[0x3]; // 0x5a1(0x03)
	char DefaultMouseCursor; // 0x5a4(0x01)
	char CurrentMouseCursor; // 0x5a5(0x01)
	char DefaultClickTraceChannel; // 0x5a6(0x01)
	char CurrentClickTraceChannel; // 0x5a7(0x01)
	float HitResultTraceDistance; // 0x5a8(0x04)
	float ForceFeedbackIntensity; // 0x5ac(0x04)
	char UnknownData_5B0[0x88]; // 0x5b0(0x88)
	struct UInputComponent* InactiveStateInputComponent; // 0x638(0x08)
	char UnknownData_640[0x20]; // 0x640(0x20)
	struct UTouchInterface* CurrentTouchInterface; // 0x660(0x08)
	char UnknownData_668[0x30]; // 0x668(0x30)
	struct ASpectatorPawn* SpectatorPawn; // 0x698(0x08)
	struct FVector SpawnLocation; // 0x6a0(0x0c)
	char UnknownData_6AC[0x4]; // 0x6ac(0x04)
	char LevelInputComponents[80]; // 0x6b0(0x50)
	char UnknownData_700[0x14]; // 0x700(0x14)
	bool bIsLocalPlayerController; // 0x714(0x01)
	char UnknownData_715[0x1]; // 0x715(0x01)
	uint16_t SeamlessTravelCount; // 0x716(0x02)
	uint16_t LastCompletedSeamlessTravelCount; // 0x718(0x02)
	bool bInCinematicMode; // 0x71a(0x01)
	char UnknownData_71B[0x55]; // 0x71b(0x55)

};

struct FCrewSessionTemplate
{
	char pad[0x18];
	struct FString MatchmakingHopper;                                        // 0x0018(0x0010) (ZeroConstructor)
	class UClass* ShipSize;                                                 // 0x0028(0x0008) (ZeroConstructor, IsPlainOldData)
	int MaxMatchmakingPlayers;                                    // 0x0030(0x0004) (ZeroConstructor, IsPlainOldData)
	unsigned char UnknownData00[0x4];                                       // 0x0034(0x0004) MISSED OFFSET
};

// ScriptStruct Athena.Crew
// Size: 0x98 (Inherited: 0x00)
struct FCrew {
	struct FGuid CrewId; // 0x00(0x10)
	char SessionId[0x10]; // 0x10(0x10)
	struct TArray<struct APlayerState*> Players; // 0x20(0x10)
	struct FCrewSessionTemplate CrewSessionTemplate; // 0x30(0x38)
	char LiveryID[0x10]; // 0x68(0x10)
	char UnknownData_78[0x8]; // 0x78(0x08)
	struct TArray<struct AActor*> AssociatedActors; // 0x80(0x10)
	bool HasEverSetSail; // 0x90(0x01)
	bool RequiresDiveOnceShipHasSpawned; // 0x91(0x01)
	bool CrewDivingToWorldEvent; // 0x92(0x01)
	char UnknownData_93[0x1]; // 0x93(0x01)
	int32_t ScrambleNameIndex; // 0x94(0x04)
};

// Class Athena.CrewService
// Size: 0x6e0 (Inherited: 0x3c8)
struct ACrewService : AActor {
	char UnknownData_3C8[0xd8]; // 0x3c8(0xd8)
	struct TArray<struct FCrew> Crews; // 0x4a0(0x10)
	char UnknownData_4B0[0x230]; // 0x4b0(0x230)
};

// Class Athena.InteractableBase
// Size: 0x400 (Inherited: 0x3c8)
struct AInteractableBase : AActor {
	char UnknownData_3C8[0x10]; // 0x3c8(0x10)
	bool RequiresFacingFront; // 0x3d8(0x01)
	bool RequiresNotBeingAirborne; // 0x3d9(0x01)
	bool RequiresNotSwimming; // 0x3da(0x01)
	bool InteractionsCanBeDisabled; // 0x3db(0x01)
	bool CanSetInteractionState; // 0x3dc(0x01)
	char UnknownData_3DD[0x3]; // 0x3dd(0x03)
	struct TArray<struct UInteractionPrerequisiteBase*> InteractionPrerequisites; // 0x3e0(0x10)
	struct UActionRulesComponent* ActionRulesComponent; // 0x3f0(0x08)
	char InteractableIdentifier; // 0x3f8(0x01)
	char UnknownData_3F9[0x1]; // 0x3f9(0x01)
	char CurrentInteractionState; // 0x3fa(0x01)
	char UnknownData_3FB[0x5]; // 0x3fb(0x05)
};

// Class Athena.Ladder
// Size: 0x5e0 (Inherited: 0x400)
struct ALadder : AInteractableBase {
	char UnknownData_400[0x38]; // 0x400(0x38)
	struct UStaticMeshComponent* MeshComponent; // 0x438(0x08)
	struct USplineComponent* OnTopSplineComponent; // 0x440(0x08)
	struct USplineComponent* OffTopSplineComponent; // 0x448(0x08)
	float MaxDistFromLadderTopToClassifyAsTopDocking; // 0x450(0x04)
	struct FVector InteractOffset; // 0x454(0x0c)
	char LadderDefinition[0x1C]; // 0x460(0x1c)
	char UnknownData_47C[0x4]; // 0x47c(0x04)
	struct UPhysicalMaterial* LadderPhysicsMaterial; // 0x480(0x08)
	struct UPhrasesRadialDataAsset* Phrases; // 0x488(0x08)
	float RepeatExecutionThreshold; // 0x490(0x04)
	char UnknownData_494[0x14c]; // 0x494(0x14c)

	struct FTransform GetTopLadderRungTransform(); // Function Athena.Ladder.GetTopLadderRungTransform // RequiredAPI|Native|Event|Public|HasDefaults|BlueprintCallable|BlueprintEvent // @ game+0x105d850
	struct FTransform GetBottomLadderRungTransform(); // Function Athena.Ladder.GetBottomLadderRungTransform // Native|Event|Public|HasDefaults|BlueprintCallable|BlueprintEvent // @ game+0x105c280
};
