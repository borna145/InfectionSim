#include <iostream>
#include <SFML/Graphics.hpp>
#include "House.hpp"
#include "Virus.hpp"
#include "Human.hpp"
#include "/home/borna/C++/imgui-1.89.5/imgui.h"
#include "Watersource.hpp"
#include "Foodsource.hpp"
int main(){
    std::cout << "Type A = airborne\n";
    std::cout << "Version 1.3\n";
    class Human jeff;
    jeff.healthy = false;
    jeff.hunger = 15;
    if (jeff.hunger > 10)
        std::cout << "Jeff is starving\n";



    if (jeff.healthy == false)
        std::cout << "Jeff is not healthy";
}