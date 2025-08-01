#include "wireparticles.hpp"

struct WireParticle {
    ImVec2 pos;
    ImVec2 vel;
};

std::vector<WireParticle> wireParticles;

void wireparticle::InitWireParticles(int count, ImVec2 screenSize) {
    wireParticles.clear();
    for (int i = 0; i < count; ++i) {
        wireParticles.push_back({
            ImVec2(rand() % (int)screenSize.x, rand() % (int)screenSize.y),
            ImVec2(((rand() % 100) / 1000.0f) - 0.05f, ((rand() % 100) / 1000.0f) - 0.05f)
            });
    }
}

void wireparticle::DrawWireParticles(ImDrawList* drawList, ImVec2 screenSize) {
    float connectDistance = 100.0f;

    for (auto& p : wireParticles) {
        p.pos.x += p.vel.x;
        p.pos.y += p.vel.y;

        if (p.pos.x < 0 || p.pos.x > screenSize.x) p.vel.x *= -1;
        if (p.pos.y < 0 || p.pos.y > screenSize.y) p.vel.y *= -1;
    }


    for (size_t i = 0; i < wireParticles.size(); ++i) {
        drawList->AddCircleFilled(wireParticles[i].pos, 1.5f, ImColor(0.5f, 0.5f, 0.5f, 1.000f));

        for (size_t j = i + 1; j < wireParticles.size(); ++j) {
            float dx = wireParticles[i].pos.x - wireParticles[j].pos.x;
            float dy = wireParticles[i].pos.y - wireParticles[j].pos.y;
            float distSq = dx * dx + dy * dy;

            if (distSq < connectDistance * connectDistance) {
                float alpha = 255.0f * (1.0f - (sqrtf(distSq) / connectDistance));
                drawList->AddLine(wireParticles[i].pos, wireParticles[j].pos, ImColor(0.5f, 0.5f, 0.5f, 1.000f));
            }
        }
    }
}
