#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <GL/gl.h>

#include <iostream>
#include <string>
#include <stdlib.h>     /* srand, rand */

#include "../header_files/sfml_variables_header.h"
#include "../class_files/class_mouse.h"
#include "../class_files/shape_class.h"

using namespace std;

sf::VertexArray cameraline(sf::Lines, 4);// the line from the current point to the camera

sf::Clock time_elapsed; //main_clock

sf::RectangleShape background;

void old_draw()
{

    window.clear();


    //window.draw(background);
    window.draw(X_hair.body);


    window.display();
    //window.setView(camera);



}

void draw()
{
    window.clear();
        window.popGLStates();

        window.pushGLStates();

        ///...[code_goes_here]...///
///
        triangle.render(3);
///
        ///...[^^^^^^^^^^^^^^]...///

        window.draw(X_hair.body);

        window.display();

        X_hair.pos_apply();
        window.setView(camera);
        draw();
}


int main()
{
//camera.zoom(0.02);

background.setFillColor(sf::Color::White);
background.setSize(sf::Vector2f(window.getSize()));

window.setMouseCursorVisible(false);
X_hair.sprite_load_apply();


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        /// ////////////////////////////////////////////

        draw();

        /// ////////////////////////////////////////////
    }

    return 0;
}
