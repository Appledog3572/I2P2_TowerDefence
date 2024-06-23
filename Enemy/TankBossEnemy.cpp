#include <string>

#include "TankBossEnemy.hpp"

TankBossEnemy::TankBossEnemy(int x, int y) : Enemy("play/enemy-6.png", x, y, 16, 100, 300, 10) {
    // Use bounding circle to detect collision is for simplicity, pixel-perfect collision can be implemented quite easily,
    // and efficiently if we use AABB collision detection first, and then pixel-perfect collision.
}