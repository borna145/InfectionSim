#include <iostream>
#include <SFML/Graphics.hpp>
#include "House.hpp"
#include "Virus.hpp"
#include "Human.hpp"
#include "/home/borna/C++/imgui-sfml-2.5/imgui-SFML.h"
#include "/home/borna/C++/imgui-1.89.5/imgui.h"
#include "Watersource.hpp"
#include "Foodsource.hpp"
int main(){
        sf::RenderWindow window(sf::VideoMode(640, 480), "");
        window.setVerticalSyncEnabled(true);
        ImGui::SFML::Init(window);

        sf::Color bgColor;

        float color[3] = { 0.f, 0.f, 0.f };

        // let's use char array as buffer, see next part
        // for instructions on using std::string with ImGui
        char windowTitle[255] = "ImGui + SFML = <3";

        window.setTitle(windowTitle);
        window.resetGLStates(); // call it if you only draw ImGui. Otherwise not needed.
        sf::Clock deltaClock;

        while (window.isOpen()) 
        {
                sf::Event event;
                while (window.pollEvent(event)) 
                {
                        ImGui::SFML::ProcessEvent(event);

                        if (event.type == sf::Event::Closed) {
                                window.close();
                        }
                }

                ImGui::SFML::Update(window, deltaClock.restart());

                ImGui::Begin("Sample window"); // begin window

                                                         // Background color edit
                if (ImGui::ColorEdit3("Background color", color)) 
                {
                        // this code gets called if color value changes, so
                        // the background color is upgraded automatically!
                        bgColor.r = static_cast<sf::Uint8>(color[0] * 255.f);
                        bgColor.g = static_cast<sf::Uint8>(color[1] * 255.f);
                        bgColor.b = static_cast<sf::Uint8>(color[2] * 255.f);
                }

                // Window title text edit
                ImGui::InputText("Window title", windowTitle, 500);

                if (ImGui::Button("Update window title")) 
                {
                        // this code gets if user clicks on the button
                        // yes, you could have written if(ImGui::InputText(...))
                        // but I do this to show how buttons work :)
                        window.setTitle(windowTitle);
                }
                ImGui::End(); // end window

                window.clear(bgColor); // fill background with color
                ImGui::Render();
                window.display();
        }

        ImGui::SFML::Shutdown();
}