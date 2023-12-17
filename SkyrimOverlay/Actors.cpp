#include "engine.h"
#include "sdk.h"
#include "Actors.h"
#include <Windows.h>
#include <string>
#include <iostream>
#include "Functions.h"
#include "Data.h"
#include <format>
UWorld* world = 0;
uintptr_t aimedAt = 0;
bool ladderToggle = false;
bool aimToggle = false;

long long worldAddress = 0;

void FastLadder(AActor* actor, float value) {
    auto ladder = reinterpret_cast<ALadder*>(actor);
    if (!ladder) {
        return;
    }
    auto maxDist = ladder->MaxDistFromLadderTopToClassifyAsTopDocking;
    if (maxDist != value) {
        ladder->MaxDistFromLadderTopToClassifyAsTopDocking = value;
    }
}

float GetPlayerHealth(AActor* actor) {
    auto athena = (AAthenaCharacter*)(reinterpret_cast<uintptr_t>(actor));
    if (!athena) {        
        return 0;
    }
    auto health = athena->HealthComponent->CurrentHealthInfo.Health;
    return health;
}

void CrewService(AActor* actor) {
    auto crewService = reinterpret_cast<ACrewService*>(actor);
    auto crews = crewService->Crews;
    auto crewCount = crews.Count;

    int x = SOT_WINDOW_W - 200;
    int y = SOT_WINDOW_H - 1400;

    for (int i = 0; i < crewCount; i++) {
        RECT pos = { x, y + (i * 30), x + 140, y + 160 };
        auto crewPlayers = crews.Objects[i].Players;
        auto crewID = crews.Objects[i].CrewId.D;
        auto crewSession = crews.Objects[i].CrewSessionTemplate;
        auto crewMatchMaking = crewSession.MaxMatchmakingPlayers;

        std::string typeOfShip = "";

        switch (crewMatchMaking)
        {
        case 2:
            typeOfShip = "Sloop";
            break;
        case 3:
            typeOfShip = "Brig";
            break;
        case 4:
            typeOfShip = "Galleon";
            break;
        default:
            break;
        }


        wchar_t* text = convertCharArrayToLPCWSTR(convertStringToCharArray(std::format("Crew #{} - {}", i + 1, typeOfShip)));
        DirectX.Font->DrawTextW(NULL, text, -1, &pos, 0, D3DCOLOR_ARGB(255, 0, 100, 100));
        for (int j = 0; j < crewPlayers.Count; j++) {
            auto player = crewPlayers.Objects[j]->PlayerName;
            //DirectX.Font->DrawTextW(NULL, player.c_str(), -1, &pos, 0, D3DCOLOR_ARGB(255, 0, 100, 100));
        }
    }
}

void Player() {

}

void DrawActorOnScreen(const std::string& name, FVector& actorRelativeVector, APlayerState* playerState, ULocalPlayer* localPlayer, AActor* actor) {
    if (localPlayer->PlayerController == nullptr) {
        return;
    }
    auto playerCoordinates = playerState->RootComponent->ActorCoordinates;
    auto playerRotation = localPlayer->PlayerController->PlayerCameraManager->CameraCache.POV.Rotation;
    auto playerFov = localPlayer->PlayerController->PlayerCameraManager->CameraCache.POV.FOV;
    /*
    if (strstr(name.c_str(), "Barrel")) {
        auto screenPos = ToScreen(playerCoordinates, playerRotation, actorRelativeVector, playerFov);
        //Drawing::Rect(screenPos.x, screenPos.y, 10, 10, D3DCOLOR_ARGB(255, 255, 5, 5));
        // Add Direct3D Font rendering here if needed
        RECT pos = { screenPos.x - 5, screenPos.y + 15, screenPos.x + 60, screenPos.y + 30 };
        auto text = convertCharArrayToLPCWSTR(convertStringToCharArray("BARREL"));
        DirectX.Font->DrawTextW(NULL, text, -1, &pos, 0, D3DCOLOR_ARGB(255, 255, 5, 5));
    }
    */
    
    if (strstr(name.c_str(), "CrewService")) {
       
        CrewService(actor);
    }
    if (strstr(name.c_str(), "Ladder")) {
        
        if (ladderToggle) {
            FastLadder(actor, 5000);
        }
        else {
            FastLadder(actor, 1);
        }
        
        auto screenPos = ToScreen(playerCoordinates, playerRotation, actorRelativeVector, playerFov);
        Drawing::Rect(screenPos.x, screenPos.y, 5, 5, D3DCOLOR_ARGB(255, 50, 5, 100));
    }

    /*if (strstr(name.c_str(), "BP_PlayerPirate_C")
        && (playerCoordinates.x != actorRelativeVector.x
        || playerCoordinates.y != actorRelativeVector.y
        || playerCoordinates.z != actorRelativeVector.z)) {*/

    if(strstr(name.c_str(), "BP_PlayerPirate_C") && actor != localPlayer->PlayerController->AcknowledgedPawn){

        //Aimbot
        actorRelativeVector.z += 20;
        auto screenPos = ToScreen(playerCoordinates, playerRotation, actorRelativeVector, playerFov);
        actorRelativeVector.z -= 60;
        auto screenAim = ToScreen(playerCoordinates, playerRotation, actorRelativeVector, playerFov);

        

        if ((GetAsyncKeyState(VK_RBUTTON) & 0x8000) && GetDistance(playerCoordinates, actorRelativeVector) < 5 && aimToggle) {
            if (aimedAt == 0) {
                aimedAt = reinterpret_cast<uintptr_t>(actor);
            }
            auto actorAddress = reinterpret_cast<uintptr_t>(actor);
            Aim(screenAim.x, screenAim.y, aimedAt, actorAddress);
        }
        else {
            aimedAt = 0;
        }

        //actorRelativeVector.z += 60;
        actorRelativeVector.z -= 100;

        auto screenPosFeet = ToScreen(playerCoordinates, playerRotation, actorRelativeVector, playerFov);
        Drawing::Rect(screenPos.x - (screenPosFeet.y - screenPos.y) / 3, screenPos.y, (screenPosFeet.y - screenPos.y)/1.5, screenPosFeet.y - screenPos.y, D3DCOLOR_ARGB(255, 255, 5, 5));
      
        RECT pos = { screenPos.x - 15, screenPos.y - 40, screenPos.x + 180, screenPos.y + 30 };     
        RECT pos2 = { screenPos.x - 15, screenPos.y - 20, screenPos.x + 180, screenPos.y + 30 };     

        
        
        //playername
        wchar_t* text = convertCharArrayToLPCWSTR(convertStringToCharArray(std::format("Player - {}m ", GetDistance(playerCoordinates, actorRelativeVector))));
        if (actor) {
            auto playerInstigator = actor->Instigator;
            if (playerInstigator) {
                auto playerstateAddress = playerInstigator->PlayerState;
                if (playerstateAddress) {

                    auto colour = D3DCOLOR_ARGB(255, 5, 255, 5);
                    auto nameAddress = playerstateAddress->PlayerName;
                    auto playerHealth = GetPlayerHealth(actor);
                    Drawing::Rect(screenPos.x - 15, screenPos.y - 20, 60, 7, D3DCOLOR_ARGB(255, 255, 5, 5));
                    if (playerHealth < 33) {
                        colour = D3DCOLOR_ARGB(255, 255, 5, 5);
                    }
                    else if (playerHealth < 66) {
                        colour = D3DCOLOR_ARGB(255, 255, 170, 51);
                    }
                    Drawing::FilledRect(screenPos.x - 15, screenPos.y - 20, (int)((playerHealth / 100) * 60), 7, colour);

                    text = nameAddress.c_str();
                }
            }
        }
        else {
            //text = convertCharArrayToLPCWSTR(convertStringToCharArray(std::format("Player - {}m ", GetDistance(playerCoordinates, actorRelativeVector))));
            text = convertCharArrayToLPCWSTR(convertStringToCharArray("Player"));
        }

        
        DirectX.Font->DrawTextW(NULL, text, -1, &pos, 0, D3DCOLOR_ARGB(255, 255, 5, 5));
        
    }


    //typedef bool(__thiscall* AreCharactersInSameCrew_t)(AAthenaCharacter* Player1, AAthenaCharacter* Player2);
     if (ships.contains(name)) {
        auto screenPos = ToScreen(playerCoordinates, playerRotation, actorRelativeVector, playerFov);

        wchar_t* text2 = convertCharArrayToLPCWSTR(convertStringToCharArray(""));
        
        RECT pos = { screenPos.x - 5, screenPos.y + 10, screenPos.x + 180, screenPos.y + 30 };
        
        if (GetDistance(playerCoordinates, actorRelativeVector) < 995 && strstr(name.c_str(), "ShipTemplate_C")) {
            text2 = convertCharArrayToLPCWSTR(convertStringToCharArray(std::format(" {} - {}m", ships[name], GetDistance(playerCoordinates, actorRelativeVector))));
            Drawing::Rect(screenPos.x, screenPos.y, 10, 10, D3DCOLOR_ARGB(255, 5, 5, 255));
        }
        else if(!strstr(name.c_str(), "ShipTemplate_C")) {
            text2 = convertCharArrayToLPCWSTR(convertStringToCharArray(std::format(" {} - {}m", ships[name], GetDistance(playerCoordinates, actorRelativeVector))));
            Drawing::Rect(screenPos.x, screenPos.y, 10, 10, D3DCOLOR_ARGB(255, 5, 5, 255));
        }
        //std::cout << &nameAddress << "\n";

        DirectX.Font->DrawTextW(NULL, text2, -1, &pos, 0, D3DCOLOR_ARGB(255, 5, 5, 255));
    }   
}

void ProcessActor(AActor* actor, APlayerState* playerState, ULocalPlayer* localPlayer) {

    if (actor == nullptr)
        return;

    auto actorId = reinterpret_cast<uintptr_t>(actor) + 24;

    if ((uintptr_t*)actorId == nullptr) {
        return;
    }
    if (*(long*)actorId > 500000 || *(long*)actorId < 0) {
        return;
    }


    USceneComponent* actorRootComponent;

    actorRootComponent = actor->RootComponent;

    FVector actorRelativeVector;

    if (actorRootComponent != nullptr && &(actorRootComponent->ActorCoordinates) != nullptr) {

        actorRelativeVector = actorRootComponent->ActorCoordinates;


    }



    std::string name;

    if (*(long*)actorId != 0)
        name = ReadGname(actorId);

    DrawActorOnScreen(name, actorRelativeVector, playerState, localPlayer, actor);
    

    
    
}

void ProcessLevel(ULevel* level, APlayerState* playerState, ULocalPlayer* localPlayer) {
    if (!level || level == nullptr)
        return;

    auto actors = level->actors;
    if (IsBadReadPtr(reinterpret_cast<PVOID>(&actors), sizeof(LPVOID))) {
        return;
    }

    for (int j = 0; j < actors.Count; j++) {
        auto actor = actors.Objects[j];
        if (actor == nullptr || IsBadReadPtr(reinterpret_cast<PVOID>(actor), sizeof(LPVOID))) {
            continue;
        }
        __try {
            ProcessActor(actor, playerState, localPlayer);
        }
        __except (EXCEPTION_EXECUTE_HANDLER) {
            continue;
        }
       
    }
}
void GetActors() {

    if (GetAsyncKeyState(VK_END) & 1) {
        ladderToggle = !ladderToggle;

    }
    if (GetAsyncKeyState(VK_DELETE) & 1) {
        aimToggle = !aimToggle;
    }

    if (worldAddress == 0) {
        worldAddress = GetWorldAddress();
    }
    
    world = *(UWorld**)(worldAddress);

    //auto actorInfo = ActorInfo();
    if(!world){
        return;
    }
    auto gameInstance = world->OwningGameInstance;

    auto localPlayer = gameInstance->LocalPlayers.Objects[0];
    
    //auto persistentLevel = world->PersistentLevel;
    //auto actors = persistentLevel->actors;
    
    auto playerController = localPlayer->PlayerController;  
    
    auto pawn = playerController->AcknowledgedPawn;
    //FastLadder(pawn);
    auto playerState = pawn->PlayerState;
    
    auto levels = world->Levels;

    for (int i = 0; i < levels.Count; i++) {
        auto level = levels.Objects[i];
        if (level != nullptr && (uintptr_t)level < 0xF00000000000) {
            __try {
                ProcessLevel(level, playerState, localPlayer);
            }      
            __except (EXCEPTION_EXECUTE_HANDLER) {
                continue;
            }
        }
    }  
}