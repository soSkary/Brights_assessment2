#ifndef PLAYING_CARD_HPP
#define PLAYING_CARD_HPP

#include <cstdint>
#include <iostream>

enum class suits
{
    clubs,
    spades,
    hearts,
    diamonds
};

struct playing_card
{
    suits suit;
    uint16_t value;
};

std::ostream& operator<<(std::ostream& out, const playing_card& card)
{
    switch (card.suit)
    {
    case suits::clubs:
        out << 'C' << card.value;
        break;
    case suits::spades:
        out << 'S' << card.value;
        break;
    case suits::hearts:
        out << 'H' << card.value;
        break;
    case suits::diamonds:
        out << 'D' << card.value;
        break;
    }
    return out;
}

suits& operator++(suits& suit)
{
    switch (suit)
    {
    case suits::clubs:
        suit = suits::spades;
        break;
    case suits::spades:
        suit = suits::hearts;
        break;
    case suits::hearts:
        suit = suits::diamonds;
        break;
    case suits::diamonds:
        suit = suits::clubs;
        break;
    }
    return suit;  
}


#endif
