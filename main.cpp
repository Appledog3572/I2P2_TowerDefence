// [main.cpp]
// This is the entry point of your game.
// You can register your scenes here, and start the game.
#include "Engine/GameEngine.hpp"
#include "Engine/LOG.hpp"
#include "Scene/LoseScene.hpp"
#include "Scene/PlayScene.hpp"
#include "Scene/StageSelectScene.hpp"
#include "Scene/WinScene.hpp"
#include "Scene/StartScene.h"
#include "Scene/SettingsScene.hpp"
#include "Scene/ScoreboardScene.h"
#include "Scene/ShopScene.hpp"
#include "Scene/CustomTurretScene.hpp"
#include "Scene/GalleryScene.hpp"
#include "Scene/GalleryTurretScene.hpp"
#include "Scene/GalleryEnemyScene.hpp"
#include "Scene/SkinScene.hpp"
#include "Scene/Freezerskin.hpp"
#include "Scene/Laserskin.hpp"
#include "Scene/Fireskin.hpp"
#include "Scene/Missileskin.hpp"
#include "Scene/MapEditScene.hpp"
#include "Scene/LogInScene.hpp"

int main(int argc, char **argv) {
	Engine::LOG::SetConfig(true);
	Engine::GameEngine& game = Engine::GameEngine::GetInstance();

    game.AddNewScene("start", new StartScene());
    game.AddNewScene("stage-select", new StageSelectScene());
	game.AddNewScene("settings", new SettingsScene());
	game.AddNewScene("play", new PlayScene());
	game.AddNewScene("lose", new LoseScene());
	game.AddNewScene("win", new WinScene());
    game.AddNewScene("scoreboard", new ScoreboardScene());
    game.AddNewScene("shop", new ShopScene());
    game.AddNewScene("skin", new SkinScene());
    game.AddNewScene("custom", new CustomTurretScene());
    game.AddNewScene("gallery", new GalleryScene());
    game.AddNewScene("gallery-turret", new GalleryTurretScene());
    game.AddNewScene("gallery-enemy", new GalleryEnemyScene());
    game.AddNewScene("Freezerskin", new Freezerskin());
    game.AddNewScene("Laserskin", new Laserskin());
    game.AddNewScene("Fireskin", new Fireskin());
    game.AddNewScene("Missileskin", new Missileskin());
    game.AddNewScene("mapeditor", new MapEditScene());
    game.AddNewScene("login", new LogInScene());

	game.Start("login", 60, 1600, 832);
	return 0;
}
