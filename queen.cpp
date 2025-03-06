#include "queen.hpp"
#include "board.hpp"

Queen::Queen(const sf::Texture& texture, float x, float y, Color color)
    : Piece(texture, x, y, Type::Queen, color) {}

bool Queen::canMove(int startRow, int startCol, int endRow, int endCol, std::array<std::array<std::unique_ptr<Piece>, 8>, 8>& board) 
{
    if (endRow < 0 || endRow >= 8 || endCol < 0 || endCol >= 8) 
    {
        return false;
    }

    if (board[endRow][endCol] && board[endRow][endCol]->getColor() == pieceColor) 
    {
        return false;
    }

    if (startCol == endCol) 
    {
        int rowDirection = (endRow > startRow) ? 1 : -1;
        int row = startRow + rowDirection;

        while (row != endRow)
        {
            if (board[row][startCol])  
            {
                return false;
            }
            row += rowDirection;
        }
        return true;
    }

    if (startRow == endRow) 
    {
        int colDirection = (endCol > startCol) ? 1 : -1;
        int col = startCol + colDirection;

        while (col != endCol)
        {
            if (board[startRow][col])  
            {
                return false;
            }
            col += colDirection;
        }
        return true;
    }

    if (abs(endRow - startRow) == abs(endCol - startCol))
    {
        int rowDirection = (endRow > startRow) ? 1 : -1;
        int colDirection = (endCol > startCol) ? 1 : -1;

        int row = startRow + rowDirection;
        int col = startCol + colDirection;
        while (row != endRow && col != endCol)
        {
            if (board[row][col])
            {
                return false;
            }
            row += rowDirection;
            col += colDirection;
        }

        return true;
    }

    return false;
}