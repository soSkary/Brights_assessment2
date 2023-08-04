#ifndef DECK_TEMPLATE_HPP
#define DECK_TEMPLATE_HPP

#include "random_funcs.hpp"

#include <algorithm>
#include <iostream>
#include <vector>

template <typename T>
class deck
{
public:
    /**
     *Using a vector as the container, as this enables creating double (or more) decks
     *as these are needed in some games. Templating the type enables for different
     *kinds of card games (for example Magic the gathering or others).
    */
    using value_type = T;
    using reference = T&;
    using const_reference = const T&;
    using iterator = std::vector<T>::iterator;
    using const_iterator = std::vector<T>::const_iterator;
    using difference_type = std::vector<T>::difference_type;
    using size_type = std::vector<T>::size_type;

    deck() = default;
    deck(size_type sz) : card_container(sz) {}
    deck(const deck& other) = default;
    deck(deck&& other) = default;

    deck& operator=(const deck& other) = default;
    deck& operator=(deck&& other) = default;

    ~deck() = default;

    iterator        begin()              { return card_container.begin(); }
    iterator        end()                { return card_container.end(); }
    const_iterator  begin()     const    { return card_container.begin(); }
    const_iterator  end()       const    { return card_container.end();  }
    const_iterator  cbegin()    const    { return card_container.cbegin(); }
    const_iterator  cend()      const    { return card_container.cend(); }

    void        swap(deck& other)   { card_container.swap(other.card_container); }

    size_type   size()          const   { return card_container.size(); }
    size_type   max_size()      const   { return card_container.max_size(); }
    bool        empty()         const   { return card_container.empty(); }

    void        shuffle();
    value_type  draw();
    reference   top()               { return card_container.back(); }
    reference   bottom()            { return card_container.front(); }
    void        insert_card_on_top(const_reference card);

private:
    std::vector<T> card_container;


};
template <typename T>
inline constexpr bool operator==(const deck<T>& lhs, const deck<T>& rhs)
{
    return (lhs.card_container == rhs.card_container);
}

template <typename T>
inline constexpr bool operator!=(const deck<T>& lhs, const deck<T>& rhs)
{
    return (lhs.card_container != rhs.card_container);
}

template <typename T>
void swap(deck<T>& lhs, deck<T>& rhs)
{
    lhs.swap(rhs);
}

template <typename T>
void deck<T>::shuffle()
{
    for (auto& card : card_container)
    {
        std::swap(card, card_container.at(random_funcs::get(0, 51)));
    }
}

template <typename T>
deck<T>::value_type deck<T>::draw()
{
    value_type return_value{ card_container.back() };
    card_container.pop_back();
    return return_value;
}

template <typename T>
void deck<T>::insert_card_on_top(const_reference card)
{
    card_container.push_back(card);
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const deck<T>& card_deck)
{
    for (std::size_t i{ 0 }; const auto& card : card_deck)
    {
        out << card << ' ';
        ++i;
        if (i == card_deck.size() / 4)
        {
            out << '\n';
            i = 0;
        }
    }
    out << '\n';
    return out;
}

#endif
