// main.cpp
#include "./music/string/Veena.h"
#include "./music/wind/Saxophone.h"
#include <iostream>
namespace live {
    void runTest() {
        music::string::Veena blueVeena;
        blueVeena.play();
        music::wind::Saxophone BlueSaxophone;
        BlueSaxophone.play();
        cout << "\n--- Polymorphism ---\n";
        music::Playable* interfaceVariable;
        interfaceVariable = &blueVeena;
        interfaceVariable->play();
        interfaceVariable = &BlueSaxophone;
        interfaceVariable->play();
    }
}

int main() {
    live::runTest();
    return 0;
}