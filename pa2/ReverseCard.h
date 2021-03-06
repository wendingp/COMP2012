/*
 * ReverseCard.h
 *
 *  Created on: Feb 2, 2018
 *      Author: kevinw, wpengae
 */

#ifndef REVERSECARD_H_
#define REVERSECARD_H_

#include "Card.h"

class ReverseCard : public Card {
public:
    ReverseCard(Color color);
    
    virtual bool operator^(const Card &following_card) const override;
    
    virtual void castEffect(Player *&currentPlayer, CardPile &drawPile, CardPile &discardPile) override;

protected:
    virtual void serialize(ostream &os) const override;
    
};

#endif /* REVERSECARD_H_ */
