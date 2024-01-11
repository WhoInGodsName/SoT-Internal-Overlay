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

// Class Athena.LoadableComponent
// Size: 0x1f0 (Inherited: 0xc8)
struct ULoadableComponent : UActorComponent {
	char UnknownData_C8[0x8]; // 0xc8(0x08)
	float LoadTime; // 0xd0(0x04)
	float UnloadTime; // 0xd4(0x04)
	struct TArray<struct FLoadableComponentTimerOverride> TimerOverrides; // 0xd8(0x10)
	struct UClass* DefaultObjectToLoad; // 0xe8(0x08)
	char UnknownData_F0[0x50]; // 0xf0(0x50)
	char UnloadingPoint[0x30]; // 0x140(0x30)
	char UnknownData_170[0x18]; // 0x170(0x18)
	char LoadableComponentState[0x10]; // 0x188(0x10)
	bool AlwaysLoaded; // 0x198(0x01)
	char UnknownData_199[0x57]; // 0x199(0x57)

	void OnRepLoadableComponentState(struct FLoadableComponentState PrevLoadableComponentState); // Function Athena.LoadableComponent.OnRepLoadableComponentState // Final|RequiredAPI|Native|Private // @ game+0x114f8a0
};

// Class Athena.ControllableObject
// Size: 0x510 (Inherited: 0x400)
struct AControllableObject : AInteractableBase {
	char UnknownData_400[0x30]; // 0x400(0x30)
	char ControlObjectActionRuleParams[0x10]; // 0x430(0x10)
	struct UPhrasesRadialDataAsset* Phrases; // 0x440(0x08)
	bool AllowDisconnectWhenIdle; // 0x448(0x01)
	char UnknownData_449[0x3]; // 0x449(0x03)
	uint32_t IdleDisconnectSecondsThreshold; // 0x44c(0x04)
	char UnknownData_450[0xa0]; // 0x450(0xa0)
	struct AActor* ControllingActor; // 0x4f0(0x08)
	char UnknownData_4F8[0x18]; // 0x4f8(0x18)

	void TakenControlImpl(struct AActor* Controller); // Function Athena.ControllableObject.TakenControlImpl // Native|Event|Public|BlueprintEvent // @ game+0x39f3ba0
	void RelinquishedControlImpl(struct AActor* Controller); // Function Athena.ControllableObject.RelinquishedControlImpl // Native|Event|Public|BlueprintEvent // @ game+0x39f3840
	struct AActor* GetControllingActor(); // Function Athena.ControllableObject.GetControllingActor // Native|Public|BlueprintCallable|BlueprintPure|Const // @ game+0x39f33b0
	bool CanInteractImpl(struct AActor* InCharacter); // Function Athena.ControllableObject.CanInteractImpl // Native|Event|Protected|BlueprintCallable|BlueprintEvent|BlueprintPure|Const // @ game+0x39f32f0
};

// Class Athena.Cannon
// Size: 0xdb0 (Inherited: 0x510)
struct ACannon : AControllableObject {
	char UnknownData_510[0x30]; // 0x510(0x30)
	struct USkeletalMeshMemoryConstraintComponent* BaseMeshComponent; // 0x540(0x08)
	struct UStaticMeshMemoryConstraintComponent* BarrelMeshComponent; // 0x548(0x08)
	struct UStaticMeshComponent* FuseMeshComponent; // 0x550(0x08)
	struct UReplicatedShipPartCustomizationComponent* CustomizationComponent; // 0x558(0x08)
	struct ULoadableComponent* LoadableComponent; // 0x560(0x08)
	struct ULoadingPointComponent* LoadingPointComponent; // 0x568(0x08)
	struct UChildActorComponent* CannonBarrelInteractionComponent; // 0x570(0x08)
	struct UFuseComponent* FuseComponent; // 0x578(0x08)
	struct FName CameraSocket; // 0x580(0x08)
	struct FName CameraInsideCannonSocket; // 0x588(0x08)
	struct FName LaunchSocket; // 0x590(0x08)
	struct FName TooltipSocket; // 0x598(0x08)
	struct FName AudioAimRTPCName; // 0x5a0(0x08)
	struct FName InsideCannonRTPCName; // 0x5a8(0x08)
	struct UClass* ProjectileClass; // 0x5b0(0x08)
	float TimePerFire; // 0x5b8(0x04)
	float ProjectileSpeed; // 0x5bc(0x04)
	float ProjectileGravityScale; // 0x5c0(0x04)
	char PitchRange[0x10]; // 0x5c4(0x10)
	char YawRange[0x10]; // 0x5d4(0x10)
	float PitchSpeed; // 0x5e4(0x04)
	float YawSpeed; // 0x5e8(0x04)
	char UnknownData_5EC[0x4]; // 0x5ec(0x04)
	struct UClass* CameraShake; // 0x5f0(0x08)
	float ShakeInnerRadius; // 0x5f8(0x04)
	float ShakeOuterRadius; // 0x5fc(0x04)
	float CannonFiredAINoiseRange; // 0x600(0x04)
	struct FName AINoiseTag; // 0x604(0x08)
	char UnknownData_60C[0x4]; // 0x60c(0x04)
	char CannonDisabledToolTipText[0x38]; // 0x610(0x38)
	char LoadingDisabledToolTipText[0x38]; // 0x648(0x38)
	struct UClass* UseCannonInputId; // 0x680(0x08)
	struct UClass* StartLoadingCannonInputId; // 0x688(0x08)
	struct UClass* StopLoadingCannonInputId; // 0x690(0x08)
	float DefaultFOV; // 0x698(0x04)
	float AimFOV; // 0x69c(0x04)
	float IntoAimBlendSpeed; // 0x6a0(0x04)
	float OutOfAimBlendSpeed; // 0x6a4(0x04)
	struct UWwiseEvent* FireSfx; // 0x6a8(0x08)
	struct UWwiseEvent* DryFireSfx; // 0x6b0(0x08)
	struct UWwiseEvent* LoadingSfx_Play; // 0x6b8(0x08)
	struct UWwiseEvent* LoadingSfx_Stop; // 0x6c0(0x08)
	struct UWwiseEvent* UnloadingSfx_Play; // 0x6c8(0x08)
	struct UWwiseEvent* UnloadingSfx_Stop; // 0x6d0(0x08)
	struct UWwiseEvent* LoadedPlayerSfx; // 0x6d8(0x08)
	struct UWwiseEvent* UnloadedPlayerSfx; // 0x6e0(0x08)
	struct UWwiseEvent* FiredPlayerSfx; // 0x6e8(0x08)
	struct UWwiseObjectPoolWrapper* SfxPool; // 0x6f0(0x08)
	struct UWwiseEvent* StartPitchMovement; // 0x6f8(0x08)
	struct UWwiseEvent* StopPitchMovement; // 0x700(0x08)
	struct UWwiseEvent* StartYawMovement; // 0x708(0x08)
	struct UWwiseEvent* StopYawMovement; // 0x710(0x08)
	struct UWwiseEvent* StopMovementAtEnd; // 0x718(0x08)
	struct UWwiseObjectPoolWrapper* SfxMovementPool; // 0x720(0x08)
	struct UObject* FuseVfxFirstPerson; // 0x728(0x08)
	struct UObject* FuseVfxThirdPerson; // 0x730(0x08)
	struct UObject* MuzzleFlashVfxFirstPerson; // 0x738(0x08)
	struct UObject* MuzzleFlashVfxThirdPerson; // 0x740(0x08)
	struct FName FuseSocketName; // 0x748(0x08)
	struct FName BarrelSocketName; // 0x750(0x08)
	struct UClass* RadialCategoryFilter; // 0x758(0x08)
	struct UClass* DefaultLoadedItemDesc; // 0x760(0x08)
	float ClientRotationBlendTime; // 0x768(0x04)
	char UnknownData_76C[0x4]; // 0x76c(0x04)
	struct AItemInfo* LoadedItemInfo; // 0x770(0x08)
	bool FiringDisabled; // 0x778(0x01)
	char UnknownData_779[0x1f]; // 0x779(0x1f)
	struct UMemoryConstrainedMeshInitializer* BaseMMCMeshInitializer; // 0x798(0x08)
	struct UMemoryConstrainedMeshInitializer* BarrelMMCMeshInitializer; // 0x7a0(0x08)
	struct UCannonDescAsset* DescToSetWhenSafe; // 0x7a8(0x08)
	struct UCannonDescAsset* CurrentCannonDesc; // 0x7b0(0x08)
	float ServerPitch; // 0x7b8(0x04)
	float ServerYaw; // 0x7bc(0x04)
	struct UParticleSystemComponent* LoadedItemVFXComp; // 0x7c0(0x08)
	struct UStaticMesh* DefaultFuseMesh; // 0x7c8(0x08)
	char UnknownData_7D0[0x5d0]; // 0x7d0(0x5d0)
	char InteractionState; // 0xda0(0x01)
	char UnknownData_DA1[0xf]; // 0xda1(0x0f)
};

// ScriptStruct Athena.LoadableComponentTimerOverride
// Size: 0x18 (Inherited: 0x00)
struct FLoadableComponentTimerOverride {
	struct FName FeatureFlag; // 0x00(0x08)
	struct UClass* Item; // 0x08(0x08)
	float LoadTime; // 0x10(0x04)
	char UnknownData_14[0x4]; // 0x14(0x04)
};

// Class Athena.HarpoonLauncher
// Size: 0xcc0 (Inherited: 0x510)
struct AHarpoonLauncher : AControllableObject {
	char UnknownData_510[0x1d0]; // 0x510(0x1d0)
	char InteractionDisplayUseVerb[0x38]; // 0x6e0(0x38)
	char InteractionDisplayName[0x38]; // 0x718(0x38)
	struct FName CameraDockSocket; // 0x750(0x08)
	struct FName CharacterDockSocket; // 0x758(0x08)
	struct FName TooltipSocket; // 0x760(0x08)
	struct FName ProjectileLaunchSocket; // 0x768(0x08)
	struct FName TetherAttachSocket; // 0x770(0x08)
	struct FName RetractedCharacterTargetPositionSocket; // 0x778(0x08)
	char RetractedCharacterTargetPositionSourceMesh[0x10]; // 0x780(0x10)
	char PitchRange[0x10]; // 0x790(0x10)
	char YawRange[0x10]; // 0x7a0(0x10)
	struct FName FireAINoiseTag; // 0x7b0(0x08)
	float FireAINoiseRange; // 0x7b8(0x04)
	char UnknownData_7BC[0x4]; // 0x7bc(0x04)
	struct UChildActorComponent* TetherChildActorComponent; // 0x7c0(0x08)
	struct UStaticMeshComponent* BaseMeshComponent; // 0x7c8(0x08)
	struct UStaticMeshComponent* MountMeshComponent; // 0x7d0(0x08)
	struct UStaticMeshComponent* BarrelMeshComponent; // 0x7d8(0x08)
	struct UStaticMeshComponent* LeftSpinnerMeshComponent; // 0x7e0(0x08)
	struct UStaticMeshComponent* RightSpinnerMeshComponent; // 0x7e8(0x08)
	struct UStaticMeshComponent* RopeSpoolMeshComponent; // 0x7f0(0x08)
	struct UInteractableComponent* InteractableComponent; // 0x7f8(0x08)
	struct URetractorComponent* RetractorComponent; // 0x800(0x08)
	struct UChildActorComponent* ProjectileChildActorComponent; // 0x808(0x08)
	struct UDamageableComponent* LauncherDamageComponent; // 0x810(0x08)
	struct UTetherCustomisationComponent* TetherCustomisationComponent; // 0x818(0x08)
	struct UBalanceableWalkwayComponent* BalanceableWalkwayComponent; // 0x820(0x08)
	char TetherInterface[0x10]; // 0x828(0x10)
	char UnknownData_838[0xc0]; // 0x838(0xc0)
	struct TArray<struct UClass*> ItemTypesToExclude; // 0x8f8(0x10)
	struct TArray<struct FStringClassReference> ItemInfosToIgnore; // 0x908(0x10)
	struct TArray<struct FVector> ItemLocationsForHarpoon; // 0x918(0x10)
	struct UHarpoonLauncherAudioParamsDataAsset* AudioParams; // 0x928(0x08)
	struct UHarpoonLauncherVFXDataAsset* VFXParams; // 0x930(0x08)
	struct UForceFeedbackEffect* HarpoonImpactRumble; // 0x938(0x08)
	struct UForceFeedbackEffect* HarpoonDockedRumble; // 0x940(0x08)
	struct UClass* HarpoonDockedCameraShake; // 0x948(0x08)
	struct UCurveFloat* EstimatedRetractionTimeScalarCurve; // 0x950(0x08)
	struct UClass* StartControllingNotificationInputId; // 0x958(0x08)
	float ProjectileSpeed; // 0x960(0x04)
	float RetractionSpeed; // 0x964(0x04)
	float SpinnerPitchScalar; // 0x968(0x04)
	float RopeSpoolPitchScalar; // 0x96c(0x04)
	float SpinnerMaxSlideDistance; // 0x970(0x04)
	float MaximumTetherLengthCm; // 0x974(0x04)
	struct FRotator AimRelativeAngularLimitsDegrees; // 0x978(0x0c)
	float PositionRelativeOutOfWaterPitchLimitDegrees; // 0x984(0x04)
	float ShipSubmersionProportionRetractThreshold; // 0x988(0x04)
	char UnknownData_98C[0x2ac]; // 0x98c(0x2ac)
	float ShipOutOfWaterRetractTimeSecs; // 0xc38(0x04)
	char UnknownData_C3C[0x4]; // 0xc3c(0x04)
	float PitchSpeed; // 0xc40(0x04)
	float YawSpeed; // 0xc44(0x04)
	float ClientToServerAimBlendSpeed; // 0xc48(0x04)
	float OrientateBarrelTowardsTetherSpeedDistanceMultiplier; // 0xc4c(0x04)
	float MaxReelInSpeedCmPerSec; // 0xc50(0x04)
	float MaxWeightReelableAtMaxSpeedKg; // 0xc54(0x04)
	float ReplicatedPitch; // 0xc58(0x04)
	float ReplicatedYaw; // 0xc5c(0x04)
	bool IsMigrating; // 0xc60(0x01)
	char UnknownData_C61[0x1c]; // 0xc61(0x1c)
	bool AlwaysRetractAtMaxLength; // 0xc7d(0x01)
	char UnknownData_C7E[0x2]; // 0xc7e(0x02)
	struct TArray<struct UClass*> ForwardedDamagerTypes; // 0xc80(0x10)
	char UnknownData_C90[0x30]; // 0xc90(0x30)
};

// Class Athena.MapTable
// Size: 0x7b0 (Inherited: 0x3c8)
struct AMapTable : AActor {
	char UnknownData_3C8[0x10]; // 0x3c8(0x10)
	struct UStaticMeshComponent* TableMeshComponent; // 0x3d8(0x08)
	float MousePanSpeed; // 0x3e0(0x04)
	float MouseZoomSpeed; // 0x3e4(0x04)
	float PanSpeedMinZoom; // 0x3e8(0x04)
	float PanSpeedMaxZoom; // 0x3ec(0x04)
	float ZoomSpeed; // 0x3f0(0x04)
	float MinZoom; // 0x3f4(0x04)
	float MaxZoom; // 0x3f8(0x04)
	float InitialZoom; // 0x3fc(0x04)
	float RemoteBlendTime; // 0x400(0x04)
	float RemotePanSettleRange; // 0x404(0x04)
	float RemoteZoomSettleRange; // 0x408(0x04)
	float DrunknessStaggerScalarWhileUsing; // 0x40c(0x04)
	int32_t MaxPins; // 0x410(0x04)
	float PinToggleDist; // 0x414(0x04)
	int32_t MaxTrail; // 0x418(0x04)
	float MinDistPerTrailDrop; // 0x41c(0x04)
	float TimePerTrailUpdate; // 0x420(0x04)
	char UnknownData_424[0x4]; // 0x424(0x04)
	struct UWwiseObjectPoolWrapper* MapTablePool; // 0x428(0x08)
	struct UWwiseEvent* JoinTableSfx; // 0x430(0x08)
	struct UWwiseEvent* LeaveTableSfx; // 0x438(0x08)
	struct UWwiseEvent* PlayMoveMapSfx; // 0x440(0x08)
	struct UWwiseEvent* StopMoveMapSfx; // 0x448(0x08)
	struct UWwiseEvent* PlacePinSfx; // 0x450(0x08)
	struct UWwiseEvent* RemovePinSfx; // 0x458(0x08)
	struct UWwiseEvent* ClearAllPinsSfx; // 0x460(0x08)
	struct UWwiseEvent* ShowTaleSfx; // 0x468(0x08)
	struct UWwiseEvent* HideTaleSfx; // 0x470(0x08)
	struct UWwiseEvent* HighlightTaleMarkerSfx; // 0x478(0x08)
	float TrackedBootyItemsUpdateInterval; // 0x480(0x04)
	float TrackedShipsUpdateInterval; // 0x484(0x04)
	float TrackedShipDistanceThreshold; // 0x488(0x04)
	char UnknownData_48C[0x4]; // 0x48c(0x04)
	struct UClass* ReapersMarkFlag; // 0x490(0x08)
	bool DisplayFactionShips; // 0x498(0x01)
	bool DisplayTallTaleIcons; // 0x499(0x01)
	char UnknownData_49A[0x6]; // 0x49a(0x06)
	struct UMaterialInstanceDynamic* DynamicMaterial; // 0x4a0(0x08)
	struct UMaterialInterface* ExpandedMapMaterial; // 0x4a8(0x08)
	struct UMaterialInterface* BaseMapMaterial; // 0x4b0(0x08)
	float TopMargin; // 0x4b8(0x04)
	float RightMargin; // 0x4bc(0x04)
	float BottomMargin; // 0x4c0(0x04)
	float LeftMargin; // 0x4c4(0x04)
	char ServerCentreLocation[0x8]; // 0x4c8(0x08)
	float ServerZoomLevel; // 0x4d0(0x04)
	char UnknownData_4D4[0x4]; // 0x4d4(0x04)
	struct TArray<struct AActor*> ControllerQueue; // 0x4d8(0x10)
	struct TArray<struct FVector2D> MapPins; // 0x4e8(0x10)
	struct TArray<struct FWorldMapShipLocation> TrackedShips; // 0x4f8(0x10)
	struct TArray<struct FReapersMarkTrackedBootyItemInfo> TrackedBootyItemInfos; // 0x508(0x10)
	char BoundaryData[0x10]; // 0x518(0x10)
	struct UTexture* AllianceOverlayIcon; // 0x528(0x08)
	char UnknownData_530[0x258]; // 0x530(0x258)
	char CachedPlaymode; // 0x788(0x01)
	char UnknownData_789[0x17]; // 0x789(0x17)
	char MapTableTutorialHandler[0x10]; // 0x7a0(0x10)
};

// Class Athena.Ship
// Size: 0x1880 (Inherited: 0x3c8)
struct AShip : AActor {
	char UnknownData_3C8[0xf8]; // 0x3c8(0xf8)
	char PartConnections[0x98]; // 0x4c0(0x98)
	struct UStaticMeshComponent* BoatCollision; // 0x558(0x08)
	struct UBasisComponent* BoatBasis; // 0x560(0x08)
	struct UStaticMeshComponent* OverlapHit; // 0x568(0x08)
	struct UStaticMeshComponent* BelowDeckVolume; // 0x570(0x08)
	struct UStaticMeshComponent* CabinVolume; // 0x578(0x08)
	char ObjectMessageDispatcher[0xa0]; // 0x580(0xa0)
	struct UTeleportLocationRetrievalComponent* TeleportLocationRetrievalComponent; // 0x620(0x08)
	struct UChildActorComponent* ShipInternalWaterComponent; // 0x628(0x08)
	struct USinkingComponent* SinkingComponent; // 0x630(0x08)
	struct UShipHullCollisionComponent* HullCollisionComponent; // 0x638(0x08)
	struct UTetherCustomisationComponent* TetherCustomisationComponent; // 0x640(0x08)
	struct UShipStuckDetectionComponent* StuckDetectionComponent; // 0x648(0x08)
	struct UStatusEffectManagerComponent* StatusEffectManagerComponent; // 0x650(0x08)
	struct UStatusEffectPersistenceComponent* StatusEffectPersistenceComponent; // 0x658(0x08)
	struct UShipCurseComponent* ShipCurseComponent; // 0x660(0x08)
	struct UAIOnShipManagerComponent* AIOnShipManagerComponent; // 0x668(0x08)
	struct UInstancedNavMeshComponent* InstancedNavMeshComponent; // 0x670(0x08)
	struct UDockableComponent* DockableComponent; // 0x678(0x08)
	struct UInvasionBattleBoundsComponent* InvasionBattleBoundsComponent; // 0x680(0x08)
	char UnknownData_688[0x8]; // 0x688(0x08)
	char Buoyancy[0x130]; // 0x690(0x130)
	struct UCrewOwnershipComponent* CrewOwnershipComponent; // 0x7c0(0x08)
	struct UOnboardCharacterTrackerComponent* OnboardCharacterTrackerComponent; // 0x7c8(0x08)
	struct URewindComponent* RewindComponent; // 0x7d0(0x08)
	struct UShipLiveryComponent* LiveryComponent; // 0x7d8(0x08)
	struct UShipAnnouncementComponent* ShipAnnouncementComponent; // 0x7e0(0x08)
	struct UReplicatedShipPartCustomizationComponent* HullLiveryCustomizationComponent; // 0x7e8(0x08)
	struct UReplicatedShipPartCustomizationComponent* SailsLiveryCustomizationComponent; // 0x7f0(0x08)
	struct UReplicatedShipPartCustomizationComponent* CannonEnchantmentCustomizationComponent; // 0x7f8(0x08)
	struct UReplicatedShipPartCustomizationComponent* ShipAnnouncementPartCustomizationComponent; // 0x800(0x08)
	struct UShipActivityComponent* ShipActivityComponent; // 0x808(0x08)
	struct UClass* RammerType; // 0x810(0x08)
	struct UGroupedInteractableAreaComponent* GroupedInteractableAreaComponent; // 0x818(0x08)
	char ShipConfigurationSettings[0x18]; // 0x820(0x18)
	float RainFillRate; // 0x838(0x04)
	float RainTimePerDrop; // 0x83c(0x04)
	float RainDropScale; // 0x840(0x04)
	float RainDropRadius; // 0x844(0x04)
	float RainStrengthMinimumToFillShip; // 0x848(0x04)
	char UnknownData_84C[0x4]; // 0x84c(0x04)
	struct TArray<struct FVector> AITargetVisibilityPoints; // 0x850(0x10)
	char AchievementSailThroughStormAtNightWithLightsOff[0x90]; // 0x860(0x90)
	char AchievementSailCloseToShipWithoutFiring[0x18]; // 0x8f0(0x18)
	char AchievementSailFullyIntoTheWind[0x8]; // 0x908(0x08)
	char AchievementSailWithFlameOfFateColoursAboard[0x118]; // 0x910(0x118)
	struct UShipSunkTrackingComponent* ShipSunkTracker; // 0xa28(0x08)
	struct UImpulseThrottlerComponent* ImpulseThrottlerComponent; // 0xa30(0x08)
	struct USphereComponent* ReturnToShipVolume; // 0xa38(0x08)
	float ReturnToShipVolumeRadius; // 0xa40(0x04)
	char BowSplashReturnType; // 0xa44(0x01)
	char UnknownData_A45[0x3]; // 0xa45(0x03)
	char ShipDynamics[0xa0]; // 0xa48(0xa0)
	char PhysicsErrorCorrection[0x1c]; // 0xae8(0x1c)
	char UnknownData_B04[0x4]; // 0xb04(0x04)
	struct UShipSinkingParametersDataAsset* AdventureSinkingData; // 0xb08(0x08)
	struct UShipSinkingParametersDataAsset* ArenaSinkingData; // 0xb10(0x08)
	char BuoyancySampleMovement[0x68]; // 0xb18(0x68)
	char SurfacingBuoyancySampleMovement[0x68]; // 0xb80(0x68)
	bool AttachPlayersToShipWhenSurfacing; // 0xbe8(0x01)
	char UnknownData_BE9[0x3]; // 0xbe9(0x03)
	float SurfacingAttachDuration; // 0xbec(0x04)
	char DivingBuoyancySampleMovement[0x68]; // 0xbf0(0x68)
	bool AttachPlayersToShipWhenDiving; // 0xc58(0x01)
	char UnknownData_C59[0x3]; // 0xc59(0x03)
	float DivingAttachDuration; // 0xc5c(0x04)
	struct UShipNosediveBrake* NosediveBrake; // 0xc60(0x08)
	struct UShipRolloverCorrector* RolloverCorrector; // 0xc68(0x08)
	struct UBowSplashContainer* BowSplashContainer; // 0xc70(0x08)
	struct UBowSplashContainer* SurfacingBowSplashContainer; // 0xc78(0x08)
	struct UBowSplashContainer* DivingBowSplashContainer; // 0xc80(0x08)
	struct UShipResurfaceWetnessContainer* ShipResurfaceWetnessContainer; // 0xc88(0x08)
	bool DisableSailingBowSplashesWhenDiving; // 0xc90(0x01)
	char UnknownData_C91[0x7]; // 0xc91(0x07)
	struct ULocatorContainer* ShipLocators; // 0xc98(0x08)
	struct FVector LocalSailForceApplicationOffset; // 0xca0(0x0c)
	char UnknownData_CAC[0x4]; // 0xcac(0x04)
	struct UCurveFloat* ShipSpeedToChoppinessScalarCurve; // 0xcb0(0x08)
	struct UCurveFloat* HullSubmergedValueRemapping; // 0xcb8(0x08)
	float FakeBuoyancyZOffsetScalarSpringAccel; // 0xcc0(0x04)
	float ResurfacingFinishedSubmergedHullPercentageThreshold; // 0xcc4(0x04)
	float PositionSamplerTimeWindow; // 0xcc8(0x04)
	struct FName ClientConvexHullCollisionProfile; // 0xccc(0x08)
	float EmpiricalMaxSpeedInMPS; // 0xcd4(0x04)
	char UnknownData_CD8[0x8]; // 0xcd8(0x08)
	char BrigSpawnLocation[0x30]; // 0xce0(0x30)
	float WaterStrengthThresholdForStormDamage; // 0xd10(0x04)
	char UnknownData_D14[0x4]; // 0xd14(0x04)
	struct UClass* FirePropagationBlueprint; // 0xd18(0x08)
	struct UShipFirePropagationComponent* FirePropagationComponent; // 0xd20(0x08)
	char UnknownData_D28[0xd8]; // 0xd28(0xd8)
	struct AGuildPlaque* GuildPlaque; // 0xe00(0x08)
	char SightingEncounterParams[0x0c]; // 0xe08(0x0c)
	char CloseProximityEncounterParams[0x0c]; // 0xe14(0x0c)
	char UnknownData_E20[0x10]; // 0xe20(0x10)
	struct UClass* ShipCategoryObject; // 0xe30(0x08)
	struct UClass* ShipSizeObject; // 0xe38(0x08)
	struct UClass* ShipTypeObject; // 0xe40(0x08)
	struct TArray<struct AActor*> DamageableChildActors; // 0xe48(0x10)
	struct UShipPartsDamageTrackerComponent* ShipPartsDamageTrackerComponent; // 0xe58(0x08)
	struct ACrewShipManifest* CrewShipManifest; // 0xe60(0x08)
	char ShipIdentity[0x28]; // 0xe68(0x28)
	bool IsInCaptainedCrew; // 0xe90(0x01)
	char UnknownData_E91[0x6f]; // 0xe91(0x6f)
	struct UObject* HullDamage; // 0xf00(0x08)
	struct AVoyageProposalContainer* QuestTable; // 0xf08(0x08)
	struct USurfaceWaterComponent* DeckWater; // 0xf10(0x08)
	struct UWaterExposureComponent* WaterExposureComponent; // 0xf18(0x08)
	struct UShroudBreakerTrackerComponent* ShroudBreakerTrackerComponent; // 0xf20(0x08)
	struct UFlotsamItemSpawnComponent* FlotsamComponent; // 0xf28(0x08)
	char MovementTimeStamp[0x70]; // 0xf30(0x70)
	char UnknownData_FA0[0xc8]; // 0xfa0(0xc8)
	float StormStrainWeight; // 0x1068(0x04)
	float WorldEdgeWeight; // 0x106c(0x04)
	float TetherMassInertiaScaleWhenAnchored; // 0x1070(0x04)
	char UnknownData_1074[0x4]; // 0x1074(0x04)
	char StormStrainDamage[0x28]; // 0x1078(0x28)
	char WorldEdgeDamage[0x28]; // 0x10a0(0x28)
	char ScuttleDamage[0x28]; // 0x10c8(0x28)
	struct FVector2D WorldEdgeDamageRange; // 0x10f0(0x08)
	float ScuttleForceSinkTime; // 0x10f8(0x04)
	char UnknownData_10FC[0x4]; // 0x10fc(0x04)
	struct UClass* ProxyClass; // 0x1100(0x08)
	struct UShipEntitlementProcessingPolicyDataAsset* ShipEntitlementProcessingPolicyDataAsset; // 0x1108(0x08)
	char UnknownData_1110[0x1]; // 0x1110(0x01)
	bool HasEverStartedSailing; // 0x1111(0x01)
	bool EmissaryFlagActive; // 0x1112(0x01)
	bool InTunnelOfTheDamned; // 0x1113(0x01)
	char SurfacingState; // 0x1114(0x01)
	char UnknownData_1115[0x3]; // 0x1115(0x03)
	double FinishedResurfacingTimeStamp; // 0x1118(0x08)
	bool Scuttled; // 0x1120(0x01)
	char UnknownData_1121[0x7]; // 0x1121(0x07)
	struct TArray<struct UMobileInstancedStaticMeshComponent*> InstancedMeshes; // 0x1128(0x10)
	struct UClass* ConstraintBudget; // 0x1138(0x08)
	char UnknownData_1140[0x6b0]; // 0x1140(0x6b0)
	float ScuttleTime; // 0x17f0(0x04)
	char UnknownData_17F4[0x8c]; // 0x17f4(0x8c)
};

// Class Athena.HullDamage
// Size: 0x5d0 (Inherited: 0x3c8)
struct AHullDamage : AActor {
	char UnknownData_3C8[0x20]; // 0x3c8(0x20)
	struct USceneComponent* Root; // 0x3e8(0x08)
	struct UMobileInstancedStaticMeshComponent* RepairPlanksMesh; // 0x3f0(0x08)
	struct UShipDamageableComponent* ShipDamageComponent; // 0x3f8(0x08)
	int32_t DamageZoneTickInterval; // 0x400(0x04)
	char UnknownData_404[0x4]; // 0x404(0x04)
	struct AShipInternalWater* InternalWater; // 0x408(0x08)
	struct TArray<struct ADamageZone*> DamageZones; // 0x410(0x10)
	struct TArray<struct ADamageZone*> ActiveHullDamageZones; // 0x420(0x10)
	struct TArray<struct ADamageZone*> BottomDeckDamageZones; // 0x430(0x10)
	struct TArray<struct ADamageZone*> MiddleDeckDamageZones; // 0x440(0x10)
	char DamageZoneDeckDistribution[0x20]; // 0x450(0x20)
	struct UPersistenceIdentifierSettingsAsset* PersistenceIdentifierSettingsAsset; // 0x470(0x08)
	char UnknownData_478[0x120]; // 0x478(0x120)
	struct TArray<struct URepairableComponent*> RepairablePoints; // 0x598(0x10)
	char UnknownData_5A8[0x28]; // 0x5a8(0x28)
};

// Class Athena.ShipInternalWater
// Size: 0x620 (Inherited: 0x3c8)
struct AShipInternalWater : AActor {
	char UnknownData_3C8[0x18]; // 0x3c8(0x18)
	char InternalWaterParams[0x38]; // 0x3e0(0x38)
	float CurrentVisualWaterLevel; // 0x418(0x04)
	float WaterAmount; // 0x41c(0x04)
	float SuperheatedWaterScaleSpeed; // 0x420(0x04)
	struct FVector OcclusionCylinderPosition; // 0x424(0x0c)
	float OcclusionCylinderHeight; // 0x430(0x04)
	char UnknownData_434[0xa4]; // 0x434(0xa4)
	float ServerWaterAmount; // 0x4d8(0x04)
	bool IsInSuperheatedWater; // 0x4dc(0x01)
	bool IsInSuperheatedWaterViaHeating; // 0x4dd(0x01)
	char UnknownData_4DE[0x2]; // 0x4de(0x02)
	struct USceneComponent* SceneRootComponent; // 0x4e0(0x08)
	struct UStaticMeshComponent* WaterPlaneActivationVolume; // 0x4e8(0x08)
	struct UStaticMeshComponent* WaterOcclusionVolume; // 0x4f0(0x08)
	struct UFlatWaterMeshComponent* WaterMeshComponent; // 0x4f8(0x08)
	struct UFlatWaterPlaneComponent* WaterPlaneComponent; // 0x500(0x08)
	int32_t WaterOcclusionVolumeShrinkMaterialId; // 0x508(0x04)
	struct FName WaterOcclusionVolumeShrinkPropertyName; // 0x50c(0x08)
	char UnknownData_514[0x4]; // 0x514(0x04)
	struct UCurveFloat* WaterOcclusionZoneReductionCurve; // 0x518(0x08)
	float RippleSizeMin; // 0x520(0x04)
	float RippleSizeMax; // 0x524(0x04)
	float RippleHeight; // 0x528(0x04)
	float SuperheatedWaterCoolingRatePerSecond; // 0x52c(0x04)
	float TimeToIgnoreCoolingDueToSuperheating; // 0x530(0x04)
	char UnknownData_534[0x4]; // 0x534(0x04)
	char SuperheatedWaterStatusToApply[0x18]; // 0x538(0x18)
	char UnknownData_550[0x28]; // 0x550(0x28)
	struct TArray<struct AActor*> OverlappingActors; // 0x578(0x10)
	char UnknownData_588[0x98]; // 0x588(0x98)
};

/*
// Class Engine.CharacterMovementComponent
// Size: 0x590 (Inherited: 0x160)
struct UCharacterMovementComponent : UPawnMovementComponent {
	char UnknownData_160[0x18]; // 0x160(0x18)
	struct ACharacter* CharacterOwner; // 0x178(0x08)
	float GravityScale; // 0x180(0x04)
	float MaxStepHeight; // 0x184(0x04)
	float JumpZVelocity; // 0x188(0x04)
	float JumpOffJumpZFactor; // 0x18c(0x04)
	float WalkableFloorAngle; // 0x190(0x04)
	float WalkableFloorZ; // 0x194(0x04)
	char MovementMode; // 0x198(0x01)
	char CustomMovementMode; // 0x199(0x01)
	char UnknownData_19A[0x26]; // 0x19a(0x26)
	float GroundFriction; // 0x1c0(0x04)
	float MaxWalkSpeed; // 0x1c4(0x04)
	float MaxWalkSpeedBackwards; // 0x1c8(0x04)
	float WalkBackwardsMinAngle; // 0x1cc(0x04)
	float WalkBackwardsMaxAngle; // 0x1d0(0x04)
	float MaxWalkSpeedCrouched; // 0x1d4(0x04)
	float MaxSwimSpeed; // 0x1d8(0x04)
	float MaxFlySpeed; // 0x1dc(0x04)
	float MaxCustomMovementSpeed; // 0x1e0(0x04)
	float MaxAcceleration; // 0x1e4(0x04)
	float MaxChargeAcceleration; // 0x1e8(0x04)
	float BrakingFrictionFactor; // 0x1ec(0x04)
	float BrakingFriction; // 0x1f0(0x04)
	char bUseSeparateBrakingFriction : 1; // 0x1f4(0x01)
	char UnknownData_1F4_1 : 7; // 0x1f4(0x01)
	char UnknownData_1F5[0x3]; // 0x1f5(0x03)
	float BrakingDecelerationWalking; // 0x1f8(0x04)
	float BrakingDecelerationFalling; // 0x1fc(0x04)
	float BrakingDecelerationSwimming; // 0x200(0x04)
	float BrakingDecelerationFlying; // 0x204(0x04)
	float AirControl; // 0x208(0x04)
	float AirControlBoostMultiplier; // 0x20c(0x04)
	float AirControlBoostVelocityThreshold; // 0x210(0x04)
	float FallingLateralFriction; // 0x214(0x04)
	float CrouchedHalfHeight; // 0x218(0x04)
	float Buoyancy; // 0x21c(0x04)
	float PerchRadiusThreshold; // 0x220(0x04)
	float PerchAdditionalHeight; // 0x224(0x04)
	struct FRotator RotationRate; // 0x228(0x0c)
	char bUseControllerDesiredRotation : 1; // 0x234(0x01)
	char bOrientRotationToMovement : 1; // 0x234(0x01)
	char bMovementInProgress : 1; // 0x234(0x01)
	char bEnableScopedMovementUpdates : 1; // 0x234(0x01)
	char bForceMaxAccel : 1; // 0x234(0x01)
	char bRunPhysicsWithNoController : 1; // 0x234(0x01)
	char bForceNextFloorCheck : 1; // 0x234(0x01)
	char bShrinkProxyCapsule : 1; // 0x234(0x01)
	char bCanWalkOffLedges : 1; // 0x235(0x01)
	char bCanWalkOffLedgesWhenCrouching : 1; // 0x235(0x01)
	char bDeferUpdateMoveComponent : 1; // 0x235(0x01)
	char UnknownData_235_3 : 5; // 0x235(0x01)
	char UnknownData_236[0x2]; // 0x236(0x02)
	struct USceneComponent* DeferredUpdatedMoveComponent; // 0x238(0x08)
	float MaxOutOfWaterStepHeight; // 0x240(0x04)
	float OutofWaterZ; // 0x244(0x04)
	float Mass; // 0x248(0x04)
	bool bEnablePhysicsInteraction; // 0x24c(0x01)
	bool bTouchForceScaledToMass; // 0x24d(0x01)
	bool bPushForceScaledToMass; // 0x24e(0x01)
	bool bScalePushForceToVelocity; // 0x24f(0x01)
	float StandingDownwardForceScale; // 0x250(0x04)
	float InitialPushForceFactor; // 0x254(0x04)
	float PushForceFactor; // 0x258(0x04)
	float PushForcePointZOffsetFactor; // 0x25c(0x04)
	float TouchForceFactor; // 0x260(0x04)
	float MinTouchForce; // 0x264(0x04)
	float MaxTouchForce; // 0x268(0x04)
	float RepulsionForce; // 0x26c(0x04)
	float NetMoveDelta; // 0x270(0x04)
	char bForceBraking : 1; // 0x274(0x01)
	char UnknownData_274_1 : 7; // 0x274(0x01)
	char UnknownData_275[0x3]; // 0x275(0x03)
	float CrouchedSpeedMultiplier; // 0x278(0x04)
	float UpperImpactNormalScale; // 0x27c(0x04)
	struct FVector Acceleration; // 0x280(0x0c)
	struct FVector LastUpdateLocation; // 0x28c(0x0c)
	struct FVector PendingImpulseToApply; // 0x298(0x0c)
	struct FVector PendingForceToApply; // 0x2a4(0x0c)
	float AnalogInputModifier; // 0x2b0(0x04)
	char UnknownData_2B4[0x34]; // 0x2b4(0x34)
	float MaxSimulationTimeStep; // 0x2e8(0x04)
	int32_t MaxSimulationIterations; // 0x2ec(0x04)
	float MaxSmoothNetUpdateDist; // 0x2f0(0x04)
	float NoSmoothNetUpdateDist; // 0x2f4(0x04)
	float NetworkSimulatedSmoothLocationTime; // 0x2f8(0x04)
	float NetworkSimulatedSmoothRotationTime; // 0x2fc(0x04)
	float LedgeCheckThreshold; // 0x300(0x04)
	float JumpOutOfWaterPitch; // 0x304(0x04)
	struct FFindFloorResult CurrentFloor; // 0x308(0x8c)
	char DefaultLandMovementMode; // 0x394(0x01)
	char DefaultWaterMovementMode; // 0x395(0x01)
	char GroundMovementMode; // 0x396(0x01)
	char UnknownData_397[0x1]; // 0x397(0x01)
	char bMaintainHorizontalGroundVelocity : 1; // 0x398(0x01)
	char bImpartBaseVelocityX : 1; // 0x398(0x01)
	char bImpartBaseVelocityY : 1; // 0x398(0x01)
	char bImpartBaseVelocityZ : 1; // 0x398(0x01)
	char bImpartBaseAngularVelocity : 1; // 0x398(0x01)
	char bJustTeleported : 1; // 0x398(0x01)
	char bNetworkUpdateReceived : 1; // 0x398(0x01)
	char bBasedMovementUpdateReceived : 1; // 0x398(0x01)
	char bMovementUpdateReceived : 1; // 0x399(0x01)
	char bNetworkMovementModeChanged : 1; // 0x399(0x01)
	char bNotifyApex : 1; // 0x399(0x01)
	char bCheatFlying : 1; // 0x399(0x01)
	char bWantsToCrouch : 1; // 0x399(0x01)
	char bCrouchMaintainsBaseLocation : 1; // 0x399(0x01)
	char bIgnoreBaseRotation : 1; // 0x399(0x01)
	char bFastAttachedMove : 1; // 0x399(0x01)
	char bAlwaysCheckFloor : 1; // 0x39a(0x01)
	char bUseFlatBaseForFloorChecks : 1; // 0x39a(0x01)
	char bPerformingJumpOff : 1; // 0x39a(0x01)
	char bWantsToLeaveNavWalking : 1; // 0x39a(0x01)
	char bUseRVOAvoidance : 1; // 0x39a(0x01)
	char bRequestedMoveUseAcceleration : 1; // 0x39a(0x01)
	char bPreventSimulatedFloorChecks : 1; // 0x39a(0x01)
	char bPreventNavMeshFalling : 1; // 0x39a(0x01)
	char bHasRequestedVelocity : 1; // 0x39b(0x01)
	char bRequestedMoveWithMaxSpeed : 1; // 0x39b(0x01)
	char bWasAvoidanceUpdated : 1; // 0x39b(0x01)
	char UnknownData_39B_3 : 2; // 0x39b(0x01)
	char bProjectNavMeshWalking : 1; // 0x39b(0x01)
	char UnknownData_39B_6 : 2; // 0x39b(0x01)
	char UnknownData_39C[0x14]; // 0x39c(0x14)
	float SmoothingClientPositionTolerance; // 0x3b0(0x04)
	float AvoidanceConsiderationRadius; // 0x3b4(0x04)
	struct FVector RequestedVelocity; // 0x3b8(0x0c)
	int32_t AvoidanceUID; // 0x3c4(0x04)
	struct FNavAvoidanceMask AvoidanceGroup; // 0x3c8(0x04)
	struct FNavAvoidanceMask GroupsToAvoid; // 0x3cc(0x04)
	struct FNavAvoidanceMask GroupsToIgnore; // 0x3d0(0x04)
	float AvoidanceWeight; // 0x3d4(0x04)
	struct FVector PendingLaunchVelocity; // 0x3d8(0x0c)
	char UnknownData_3E4[0x9c]; // 0x3e4(0x9c)
	float NavMeshProjectionInterval; // 0x480(0x04)
	float NavMeshProjectionTimer; // 0x484(0x04)
	bool bUseNavMeshProjectionTimeModifier; // 0x488(0x01)
	char UnknownData_489[0x3]; // 0x489(0x03)
	float MaxNavMeshProjectionInterval; // 0x48c(0x04)
	char UnknownData_490[0x4]; // 0x490(0x04)
	float NavMeshProjectionInterpSpeed; // 0x494(0x04)
	bool bUsePlaneBasedNavMeshProjectionInterpSystem; // 0x498(0x01)
	char UnknownData_499[0x3]; // 0x499(0x03)
	float MaxAllowedZOffsetFromCurrentPlane; // 0x49c(0x04)
	float MaxZDiffFromPrevPlane; // 0x4a0(0x04)
	char UnknownData_4A4[0x1c]; // 0x4a4(0x1c)
	float NavMeshProjectionHeightScaleUp; // 0x4c0(0x04)
	float NavMeshProjectionHeightScaleDown; // 0x4c4(0x04)
	bool UseControllerRotationInNavWalkingMoveComponent; // 0x4c8(0x01)
	char UnknownData_4C9[0x7]; // 0x4c9(0x07)
	struct FCharacterMovementComponentPreClothTickFunction PreClothComponentTick; // 0x4d0(0x50)
	char UnknownData_520[0x14]; // 0x520(0x14)
	float MinTimeBetweenTimeStampResets; // 0x534(0x04)
	char UnknownData_538[0x8]; // 0x538(0x08)
	struct FRootMotionMovementParams RootMotionParams; // 0x540(0x40)
	bool bWasSimulatingRootMotion; // 0x580(0x01)
	char UnknownData_581[0xf]; // 0x581(0x0f)
};*/
