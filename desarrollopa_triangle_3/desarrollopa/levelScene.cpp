#include "levelScene.h"


void levelScene::Init() {

    healthText = Text();
    batteryText = Text();
    player = nullptr; 
}

void levelScene::SetPlayer(Player* p) {
    player = p;
}

void levelScene::RenderHUD() {
    if (player != nullptr) {

        healthText.SetText("Vidas: " + to_string(player->GetHealth()) + "/5");
        healthText.SetPosition(Vector3D(1.0f, 12.0f, 0.0f));
        healthText.SetColor(Color(1.0f, 0.0f, 0.0f, 1.0f));
        healthText.Render();

        batteryText.SetText("Baterias: " + to_string(player->GetBattery()) + "/10");
        batteryText.SetPosition(Vector3D(5.0f, 12.0f, 0.0f));
        batteryText.SetColor(Color(1.0f, 1.0f, 0.1f, 1.0f));
        batteryText.Render();
    }
}
void levelScene::Render() {
    RenderHUD();
}



