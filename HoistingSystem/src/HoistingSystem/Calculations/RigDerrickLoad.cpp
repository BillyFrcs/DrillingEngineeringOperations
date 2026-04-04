#include "RigDerrickLoad.h"

long double HoistingSystem::RigDerrickLoad::HookLoad()
{
    long double buoyedWeight = 260000;
    long double blockAndHookWeight = 40000;

    long double totalHookLoad_W = buoyedWeight + blockAndHookWeight;

    return std::ceill(totalHookLoad_W);
}

long double HoistingSystem::RigDerrickLoad::FastLineTension()
{
    long double totalHookLoad = HoistingSystem::RigDerrickLoad::HookLoad();
    long double noLines = 10;
    long double efficiency = 0.811;

    long double fastLineTension_Tt = totalHookLoad / (noLines * efficiency);

    return std::ceill(fastLineTension_Tt);
}

long double HoistingSystem::RigDerrickLoad::DeadLineTension()
{
    long double totalHookLoad_W = HoistingSystem::RigDerrickLoad::HookLoad();
    long double linesEfficiency = 10;

    long double deadLineTension_Td = totalHookLoad_W / linesEfficiency;

    return std::ceill(deadLineTension_Td);
}

long double HoistingSystem::RigDerrickLoad::DerrickLoadUnderDynamicConditions()
{
    long double totalFastLineTension_Tf = FastLineTension();
    long double totalHookLoad_W = HoistingSystem::RigDerrickLoad::HookLoad();
    long double totalDeadLineTension_Td = DeadLineTension();

    long double derrickLoadDynamicCondition_FD = totalFastLineTension_Tf + totalHookLoad_W + totalDeadLineTension_Td;

    return std::ceill(derrickLoadDynamicCondition_FD);
}