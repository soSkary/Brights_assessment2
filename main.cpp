#include "deck.hpp"
#include "card.hpp"

void fill_deck_with_cards(deck<playing_card>& deck_of_cards)
{
    suits suit{ suits::clubs };
    uint16_t value{ 0 };

    for (auto& element : deck_of_cards)
    {
        ++value;
        element = { suit, value };
        if (value == static_cast<uint16_t>(deck_of_cards.size() / 4))
        {
            value = 0;
            ++suit;
        }
    }
}


int main()
{
    deck<int> test(52);
    for (int value{ 1 }; auto & card: test)
    {
        card = value;

        if (value == test.size() / 4)
            value = 0;
        ++value;
    }
    std::cout << test << '\n';

    test.shuffle();
    std::cout << test << '\n';

    std::cout << "test.top(): " << test.top() << " test.bottom(): " << test.bottom() << '\n';
    
    std::cout << std::boolalpha << "test.empty(): " << test.empty() << '\n';

    while (!test.empty())
    {
        std::cout << test.draw() << ' ';
    }
    std::cout << '\n';
    
    std::cout << std::boolalpha << "test.empty(): " << test.empty() << '\n';

    deck<playing_card> deck_of_cards(52);
    fill_deck_with_cards(deck_of_cards);
    std::cout << deck_of_cards << '\n';

    std::cout << "Last card is D13: " << (deck_of_cards.top().suit == suits::diamonds) <<
        ' ' << (deck_of_cards.top().value == 13) << ' ' << deck_of_cards.top() << '\n';

    uint8_t ui{ 13 };

    std::cout << ui << '\n';

    return 0;
}
