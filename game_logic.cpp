#include "deck.hpp"
#include "card.hpp"

#include <string>
#include <vector>

inline const static std::size_t cards_in_deck{ 52 };

void fill_deck_with_cards(deck<playing_card>& deck_of_cards)
{
    suits suit{ suits::clubs };
    uint16_t value{ 0 };

    for (auto& element : deck_of_cards)
    {
        ++value;
        element = { suit, value };
        if (value == static_cast<uint16_t>(cards_in_deck / 4))
        {
            value = 0;
            ++suit;
        }
    }
}

struct player
{
    player()
    {
        static int id{ 1 };
        name += std::to_string(id);
        ++id;
    }

    player(const std::string& new_name) : name{ new_name } {}
    
    deck<playing_card> hand{};
    std::string name{ "player " };

};

uint16_t sum_of_cards(const deck<playing_card> deck_of_cards)
{
    uint16_t ace_counter{ 0 };
    uint16_t sum{ 0 };
    for (const auto& card : deck_of_cards)
    {   
        //if card_value is over 10, add 10
        if (card.value >= 10)
        {
            sum += 10;
        }
        else if (card.value == 1)
        {
            sum += 14;
            ++ace_counter;
        }
        else
        {
            sum += card.value;
        }
    }

    while (sum > 21 && ace_counter > 0)
    {
        sum -= 13;
        --ace_counter;
    }

    return sum;
}

void draw_card(player& p, deck<playing_card>& deck_of_cards)
{
    p.hand.insert_card_on_top(deck_of_cards.draw());
}

bool check_if_player_folds(const player& p)
{
    return (sum_of_cards(p.hand) > 21);
}

deck<playing_card> initialize_game(std::vector<player>& players)
{
    
    int number_of_decks{ players.size() * 2 };
    if (number_of_decks > 8)
    {
        number_of_decks = 8;
    }

    deck<playing_card> deck_of_cards(number_of_decks * cards_in_deck);
    fill_deck_with_cards(deck_of_cards);

    deck_of_cards.shuffle();

    for (auto& player : players)
    {
        player.hand.insert_card_on_top(deck_of_cards.draw());
        std::cout << player.name << ": " << player.hand;
    }

    for (auto& player : players)
    {
        player.hand.insert_card_on_top(deck_of_cards.draw());
    }

    
    return deck_of_cards;
}

void players_turn(player& p)
{
    std::cout << p.name << " turn!\nCards: " << p.hand;


}


void main_game_loop(int nr_of_players)
{
    std::vector<player> players(nr_of_players + 1);

    players.back() = player{ "dealer" };
    deck<playing_card> deck_of_cards(initialize_game(players));

    for (auto& player : players)
    {
        
        if (!check_if_player_folds(player))
        {
            players_turn(player);
        }
    }

}
