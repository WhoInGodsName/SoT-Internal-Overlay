#pragma once
#include <map>
#include <iostream>
#include <string>

std::map<std::string, std::string> ships{
    // ------------ SHIPS / AI SHIPS ------------
    {"BP_SmallShipTemplate_C", "Sloop (Near)"},
    { "BP_SmallShipNetProxy_C", "Sloop" },
    { "BP_MediumShipTemplate_C", "Brig (Near)" },
    { "BP_MediumShipNetProxy_C", "Brig" },
    { "BP_LargeShipTemplate_C", "Galleon (Near)" },
    { "BP_LargeShipNetProxy_C", "Galleon" },
    { "BP_AISmallShipTemplate_C", "Skeleton Sloop (Near)" },
    { "BP_AISmallShipNetProxy_C", "Skeleton Sloop" },
    { "BP_AILargeShipTemplate_C", "Skeleton Galleon (Near)" },
    { "BP_AILargeShipNetProxy_C", "Skeleton Galleon" },
};