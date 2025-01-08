#include <iostream>
using namespace std;

namespace dp {
    /// @brief Behavioral Pattern examples
    namespace behavioral {
        namespace template_dp {
            /// @brief  Template pattern example for Game
            class Game {
            public:
                void run() {
                    start();
                    while(have_winner() == false) {
                        take_turns();
                    }    
                }
                virtual int get_winner() = 0;

            protected:
                explicit Game(int number_of_players): number_of_players(number_of_players) {}
                virtual void start() = 0;
                virtual void take_turns() = 0;
                virtual bool have_winner() = 0;

                int number_of_players;
                int current_player{0};
            };

            class Chess : public Game {
            public:
                explicit Chess() : Game {2}{}
                int get_winner() override
                {
                    return current_player;
                }
            protected:
                void start() override
                {
                    cout << "Starting chess game with " << number_of_players << "and current player is " << current_player << endl;
                    turns = 0;
                }
                void take_turns() override
                {
                    current_player = (current_player + 1) % number_of_players;
                    cout << "Turn change to player " << current_player << endl;
                    turns++;
                }
                bool have_winner() override
                {
                    return (turns >= max_turns) ? true : false;
                }
            private:
                int turns{0}, max_turns{15};
            };

            void test_template_dp_game() 
            {
                Chess chess;
                chess.run();

                cout << "Press any key to get winner" << endl;
                getchar();
                cout << "Winner is " << chess.get_winner()<< endl;
                cout << "press any key to exit" << endl;
                getchar();

                cout << endl;
                cout << "USING DYNAMIC POLIMORPHISM" << endl;
                cout << endl;
                //Using pointers
                Game* game = new(dp::behavioral::template_dp::Chess);
                game->run();

                cout << "Press any key to get winner" << endl;
                getchar();
                cout << "Winner is " << game->get_winner()<< endl;
                cout << "press any key to exit" << endl;
                getchar();
            }
        }
    }
}