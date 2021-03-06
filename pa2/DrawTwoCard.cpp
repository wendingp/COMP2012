/*
 * DrawTwoCard.cpp
 *
 *  Created on: Feb 5, 2018
 *      Author: kevinw, wpengae
 */

#include "DrawTwoCard.h"
#include "Player.h"

DrawTwoCard::DrawTwoCard(Color color) : SkipCard(color) {}

void DrawTwoCard::castEffect(Player *&currentPlayer, CardPile &drawPile, CardPile &discardPile) {
    if (!currentPlayer || !currentPlayer->getNextPlayer()) {
        return;
    }
    currentPlayer->getNextPlayer()->drawCard(drawPile, discardPile, 2);
    /* Skips the next player by moving one player forward. */
    currentPlayer = currentPlayer->getNextPlayer();
}

void DrawTwoCard::serialize(ostream &os) const {
    os << (color == Color::red ? "R" :
           color == Color::blue ? "B" :
           color == Color::green ? "G" :
           color == Color::yellow ? "Y" : "ERROR") << "+";
}
