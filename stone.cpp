#include "stone.hpp"

Stone::Stone(StoneColor color)
    : m_color{color} {
}

StoneColor Stone::color() const {
    return m_color;
}

