cmake_minimum_required(VERSION 3.27)
project(2024_I2P2_TowerDefense_with_answer)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(Resource)

file(COPY ${CMAKE_CURRENT_BINARY_DIR}/Resource/scoreboard.txt DESTINATION ${CMAKE_SOURCE_DIR}/Resource)
file(COPY Resource/audios DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY Resource/fonts DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY Resource/images DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY Resource DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY allegro_monolith-5.2.dll DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

add_executable(2024_I2P2_TowerDefense_with_answer
        Engine/Allegro5Exception.cpp
        Engine/Allegro5Exception.hpp
        Engine/AudioHelper.cpp
        Engine/AudioHelper.hpp
        Bullet/Bullet.cpp
        Bullet/Bullet.hpp
        Engine/Collider.cpp
        Engine/Collider.hpp
        UI/Animation/DirtyEffect.cpp
        UI/Animation/DirtyEffect.hpp
        Enemy/Enemy.cpp
        Enemy/Enemy.hpp
        UI/Animation/ExplosionEffect.cpp
        UI/Animation/ExplosionEffect.hpp
        Bullet/FireBullet.cpp
        Bullet/FireBullet.hpp
        Engine/GameEngine.cpp
        Engine/GameEngine.hpp
        Engine/Group.cpp
        Engine/Group.hpp
        Engine/IControl.cpp
        Engine/IControl.hpp
        UI/Component/Image.cpp
        UI/Component/Image.hpp
        UI/Component/ImageButton.cpp
        UI/Component/ImageButton.hpp
        Engine/IObject.cpp
        Engine/IObject.hpp
        Engine/IScene.cpp
        Engine/IScene.hpp
        UI/Component/Label.cpp
        UI/Component/Label.hpp
        Bullet/LaserBullet.cpp
        Bullet/LaserBullet.hpp
        Turret/LaserTurret.cpp
        Turret/LaserTurret.hpp
        Engine/LOG.cpp
        Engine/LOG.hpp
        Turret/MachineGunTurret.cpp
        Turret/MachineGunTurret.hpp
        main.cpp
        Bullet/MissileBullet.cpp
        Bullet/MissileBullet.hpp
        Turret/MissileTurret.cpp
        Turret/MissileTurret.hpp
        UI/Animation/Plane.cpp
        UI/Animation/Plane.hpp
        Enemy/PlaneEnemy.cpp
        Enemy/PlaneEnemy.hpp
        Engine/Point.cpp
        Engine/Point.hpp
        Engine/Resources.cpp
        Engine/Resources.hpp
        UI/Component/Slider.cpp
        UI/Component/Slider.hpp
        Enemy/SoldierEnemy.cpp
        Enemy/SoldierEnemy.hpp
        Engine/Sprite.cpp
        Engine/Sprite.hpp
        Turret/Turret.cpp
        Turret/Turret.hpp
        Turret/TurretButton.cpp
        Turret/TurretButton.hpp
        Enemy/TankEnemy.cpp
        Enemy/TankEnemy.hpp
        Scene/StartScene.cpp
        Scene/StartScene.h
        Scene/SettingsScene.cpp
        Scene/SettingsScene.hpp
        Scene/StageSelectScene.cpp
        Scene/StageSelectScene.hpp
        Scene/PlayScene.cpp
        Scene/PlayScene.hpp
        Scene/WinScene.cpp
        Scene/WinScene.hpp
        Scene/LoseScene.cpp
        Scene/LoseScene.hpp
        Scene/ScoreboardScene.cpp
        Scene/ScoreboardScene.h
        Turret/FreezerTurret.cpp
        Turret/FreezerTurret.hpp
        Bullet/FreezerBullet.cpp
        Bullet/FreezerBullet.hpp
        Tool/Shovel.cpp
        Tool/Shovel.hpp
        Tool/ToolButton.cpp
        Tool/ToolButton.hpp
        Scene/ShopScene.cpp
        Scene/ShopScene.hpp
        Scene/SkinScene.cpp
        Scene/SkinScene.hpp
        Scene/CustomTurretScene.hpp
        Scene/CustomTurretScene.cpp
        Engine/Player.cpp
        Engine/Player.hpp
        Turret/CustomTurret.cpp
        Turret/CustomTurret.hpp
        Bullet/CustomBullet.cpp
        Bullet/CustomBullet.hpp
        Scene/GalleryScene.cpp
        Scene/GalleryScene.hpp
        Scene/GalleryTurretScene.cpp
        Scene/GalleryTurretScene.hpp
        Scene/GalleryEnemyScene.cpp
        Scene/GalleryEnemyScene.hpp

        # TODO: [HACKATHON-1-SCENE] (2/4) Add the new scene source files here


#        UI/Component/TextInput.cpp
#        UI/Component/TextInput.hpp
)

IF (WIN32)
    target_include_directories(2024_I2P2_TowerDefense_with_answer PUBLIC C:/allegro/include)
    target_link_directories(2024_I2P2_TowerDefense_with_answer PUBLIC C:/allegro/lib)
    target_compile_options(2024_I2P2_TowerDefense_with_answer PUBLIC ${ALLEGRO5_CFLAGS_OTHER})
    target_link_libraries(2024_I2P2_TowerDefense_with_answer liballegro_monolith)
ELSE()
    find_package(PkgConfig)
    pkg_check_modules(ALLEGRO5 REQUIRED allegro-5 allegro_main-5 allegro_font-5 allegro_dialog-5 allegro_primitives-5 allegro_image-5 allegro_ttf-5 allegro_audio-5 allegro_acodec-5)
    target_include_directories(2024_I2P2_TowerDefense_with_answer PUBLIC lib)
    target_include_directories(2024_I2P2_TowerDefense_with_answer PUBLIC ${ALLEGRO5_INCLUDE_DIRS})
    target_compile_options(2024_I2P2_TowerDefense_with_answer PUBLIC ${ALLEGRO5_CFLAGS_OTHER})
    target_link_libraries(2024_I2P2_TowerDefense_with_answer ${ALLEGRO5_LIBRARIES})
    target_link_directories(2024_I2P2_TowerDefense_with_answer PUBLIC ${ALLEGRO5_LIBRARY_DIRS})
ENDIF()