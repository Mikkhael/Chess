#ifndef PIECE_HPP
#define PIECE_HPP

#include <SFML/Graphics.hpp>

class Piece 
{
public:
    enum class Type { King, Queen, Rook, Bishop, Knight, Pawn };
    enum class Color { White, Black };

    Piece(const sf::Texture& texture, float x, float y, Type type, Color color);
    virtual ~Piece() = default;

    virtual bool canMove(int startRow, int startCol, int endRow, int endCol, 
        std::array<std::array<std::unique_ptr<Piece>, 8>, 8>& board) = 0;

    virtual bool canMove(int startRow, int startCol, int endRow, int endCol, 
        std::array<std::array<std::unique_ptr<Piece>, 8>, 8>& board, 
    unsigned int& rounds, unsigned int& roundEnPassant) 
    {
        return false; 
    }

    virtual void draw(sf::RenderWindow& window);

    virtual void setPosition(float x, float y);
    sf::Vector2f getPosition() const;
    bool contains(const sf::Vector2i& mousePosition);

    void setScaleFactor(float scaleFactor);

    Type getType() const 
    {
        return pieceType; 
    }

    Color getColor() const;
    sf::Sprite& getSprite();

protected:
    sf::Sprite sprite;
    Type pieceType;
    Color pieceColor;
    float scaleFactor;
};

#endif
