#ifndef PLAYABLE_H
#define PLAYABLE_H
#include <bits/stdc++.h>
using namespace std;
namespace music{
    class Playable{
        public: 
            virtual ~Playable() = default;
            virtual void play() = 0;
    };
}
#endif