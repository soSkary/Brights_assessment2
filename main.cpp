#include "deck.hpp"
#include "card.hpp"

void main_game_loop(int);

int main()
{
    // deck<int> test(52);
    // for (int value{ 1 }; auto & card: test)
    // {
    //     card = value;

    //     if (value == test.size() / 4)
    //         value = 0;
    //     ++value;
    // }
    // std::cout << test << '\n';

    // test.shuffle();
    // std::cout << test << '\n';

    // std::cout << "test.top(): " << test.top() << " test.bottom(): " << test.bottom() << '\n';
    
    // std::cout << std::boolalpha << "test.empty(): " << test.empty() << '\n';

    // while (!test.empty())
    // {
    //     std::cout << test.draw() << ' ';
    // }
    // std::cout << '\n';
    
    // std::cout << std::boolalpha << "test.empty(): " << test.empty() << '\n';

    main_game_loop(4);

    
    return 0;
}
