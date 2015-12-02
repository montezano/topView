//============================================================================
// Name        : sfmltesta.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/Graphics/Vertex.hpp>
#include <SFML/Graphics/Shape.hpp>


using namespace std;

int main() {


	unsigned int width = 800;
	unsigned int height = 600;
	bool desenhar = true;


	sf::RenderWindow window(sf::VideoMode(width, height), "My window");
	sf::RenderTexture renderTexture;
	sf::Event event;

	sf::CircleShape player = sf::CircleShape();
	player.setRadius(15);
	player.setOrigin(15, 15);
	player.setPosition(width/2, height/2);
	player.setFillColor(sf::Color::Black);

	sf::VertexArray line = sf::VertexArray(sf::Lines, 2);

	line[0] = sf::Vector2f(width/2, height/2);
	line[1] = sf::Vector2f(width/2, height/2);

	line[0].color = sf::Color::Black;
	line[1].color = sf::Color::Black;


	sf::VertexArray light(sf::Triangles, 3);
	light.setFillColor(sf::Color::Yellow);
	light.setOrigin(light.getPoint(0));
	light.setPosition(width/2, height/2);

	sf::Vector2f vector;
	sf::Vector2i vector2;


	// run the program as long as the window is open
	while (window.isOpen())
	{
	    window.pollEvent(event);
		// "close requested" event: we close the window
		if(event.type == sf::Event::Closed){
			window.close();
		}
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
			vector2 = sf::Mouse::getPosition(window);
			 vector = sf::Vector2f(static_cast<float>(event.mouseButton.x), static_cast<float>(event.mouseButton.y));
			 std::cout << "x: " << vector2.x << " y: " << vector2.y << endl;
			line[1] = sf::Vector2f(static_cast<float>(vector2.x), static_cast<float>(vector2.y));


		}
		if(event.type == sf::Event::Closed){
			window.close();
		}
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			player.move(-1, 0);

		}
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			player.move(1, 0);
		}
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			player.move(0, -1);
		}
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			player.move(0, 1);
		}
		line[0].position = player.getPosition();
		light.setPosition(player.getPosition());
	    // clear the window with black color
	    window.clear(sf::Color::White);

	    // draw everything here...


	    // end the current frame
	    window.draw(light);
	    window.draw(player);
		window.draw(line);

	    window.display();
	}

	return 0;

}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//unsigned int width = 800;
//unsigned int height = 600;
//bool desenhar = true;
//
//
//sf::RenderWindow window(sf::VideoMode(width, height), "My window");
//sf::RenderTexture renderTexture;
//sf::Event event;
//sf::RectangleShape rectangle(sf::Vector2f(200.f, 200.f));
//rectangle.setPosition(sf::Vector2f(400.f, 300.f));
//rectangle.setFillColor(sf::Color::Black);
//sf::Rect<float> rectc(rectangle.getPosition(), rectangle.getSize());
//sf::Vector2f vector;
//sf::Vector2i vector2;
//
//
//// run the program as long as the window is open
//while (window.isOpen())
//{
//    // check all the window's events that were triggered since the last iteration of the loop
//
//
//    while (window.pollEvent(event))
//    {
//        // "close requested" event: we close the window
//        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
//        	vector2 = sf::Mouse::getPosition(window);
//        	 vector = sf::Vector2f(static_cast<float>(event.mouseButton.x), static_cast<float>(event.mouseButton.y));
//        	 std::cout << "x: " << vector2.x << " y: " << vector2.y << endl;
//        	rectangle.setPosition(sf::Vector2f(static_cast<float>(vector2.x), static_cast<float>(vector2.y)));
//
//        }
//        if(event.type == sf::Event::Closed){
//        	window.close();
//        }
//
//
//    }
//
//    // clear the window with black color
//    window.clear(sf::Color::White);
//
//    // draw everything here...
//
//    // window.draw(...);
// //   window.draw(rectangle);
//
//    // end the current frame
//	window.draw(rectangle);
//
//    window.display();
//}



//////////////////////////////////////////////////////////////////////////////////////////////////

//sf::RenderWindow window;
//window.create(sf::VideoMode(1024, 768, 32), "test");
//sf::Event event;
//sf::FloatRect rect(0, 0, 300, 300);
//sf::View view(sf::Vector2f(970, 540), sf::Vector2f(300, 300));
//sf::View view_change;
//
//sf::Texture texture;
//texture.loadFromFile("/home/montezano/workspace/sfmltesta/Debug/images/1.png");
//sf::Sprite image;
//image.setTexture(texture);
//
//window.setView(view);
//
//while(window.isOpen()){
//	while(window.pollEvent(event)){
//
//
//		if(event.type == sf::Event::MouseButtonPressed){
//			view.zoom(1.2);
//			window.setView(view);
//		}
//		if(event.type == sf::Event::Closed){
//			window.close();
//		}
//		if(event.type == sf::Event::MouseWheelMoved){
//			view.zoom(0.8);
//			window.setView(view);
//		}
//	}
//	window.clear(sf::Color(0,0,0));
//	window.draw(image);
//	window.display();
//}
//
//return 0;
