
<h1 align="center">
  Wireparticles.cpp

  Simple ImGui particle creator
</h1>
## ⚡️Screenshots:
Heres an example picture of wireparticles (in a cs2 cheat project)

<img width="2550" height="1212" alt="image" src="https://github.com/user-attachments/assets/0d99b8c2-66c2-4111-91be-518394a830ce" />

## ⚡️Fully customizable!
Customize colors for particles or add more particles for your needs!

## ⚡️Example usage:
    ImVec2 screenSize = ImGui::GetIO().DisplaySize;
    static bool particlesInitialized = false;
    if (!particlesInitialized) {
        wireparticle::InitWireParticles(230, screenSize); // amount, example 230
        particlesInitialized = true;
    }
    ImDrawList* bgDrawList = ImGui::GetBackgroundDrawList();
    wireparticle::DrawWireParticles(bgDrawList, screenSize);
This example shows how to draw particles in the background of your menu
