#ifndef SAXOPHONE_H
#define SAXOPHONE_H
#include <bits/stdc++.h>
#include "../Playable.h"
using namespace std;
namespace music{
    namespace wind{
        class Saxophone: public music::Playable{
            public:
                void play() override{
                    cout << "Playing the Saxophone: Smooth, soulful jazz wind notes.\n";
                }
        };
    }
    
}   
#endif