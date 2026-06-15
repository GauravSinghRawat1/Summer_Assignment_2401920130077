#ifndef VEENA_H
#define VEENA_H
#endif
#include <bits/stdc++.h>
#include "../Playable.h"
using namespace std;
namespace music{
    namespace string{
        class Veena : public music::Playable{
            public:
                void play() override{
                    cout << "Playing the Veena: Rich, classical string vibrations.\n";
                } 
        };
    }
    
}

