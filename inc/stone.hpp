#pragma once

enum class StoneColor {
    Black,
    White
};

class Stone {
public:
    Stone(StoneColor color);
    StoneColor color() const;
private:
    const StoneColor m_color;
};
