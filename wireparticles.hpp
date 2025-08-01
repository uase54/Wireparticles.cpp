#pragma once
#include <cmath>
#include <vector>

#include "ImGui/imgui.h" // Edit to work for your directory.

namespace wireparticle
{
    void InitWireParticles(int count, ImVec2 screenSize);

    void DrawWireParticles(ImDrawList* drawList, ImVec2 screenSize);
}
