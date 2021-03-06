/*
 * SkipCard.cpp
 *
 *  Created on: Feb 2, 2018
 *      Author: kevinw, wpengae
 */

#include "SkipCard.h"
#include "Player.h"
#include <typeinfo>

SkipCard::SkipCard(Color color) : Card(color, POINT_SKIPCARD) {}

bool SkipCard::operator^(const Card &following_card) const {
    return Card::operator^(following_card) || typeid(following_card).name() == typeid(*this).name();
}

void SkipCard::castEffect(Player *&currentPlayer, CardPile &drawPile, CardPile &discardPile) {
    if (!currentPlayer) { return; }
    /* Current player plays skip card which skips the next player by moving one player forward. */
    currentPlayer = currentPlayer->getNextPlayer();
}

void SkipCard::serialize(ostream &os) const {
    os << (color == Color::red ? "R" :
           color == Color::blue ? "B" :
           color == Color::green ? "G" :
           color == Color::yellow ? "Y" : "ERROR") << "s";
}

