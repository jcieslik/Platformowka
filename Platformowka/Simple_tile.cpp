#include <SFML/Graphics.hpp>
#include <iostream>
#include "Simple_tile.h"
#include "Rat.h"

using namespace std;

const string Simple_tile::texture_filename = "images/Simple_tile.png";

void Simple_tile::collision_up(Unit* object)
{
	object->set_velocity_y(10.f);
	object->set_position(sf::Vector2f(object->get_position().x, this->get_size().y + this->get_position().y));
}
void Simple_tile::collision_down(Unit* object)
{
    object->set_velocity_y(0.f);
	object->set_position(sf::Vector2f(object->get_position().x, this->get_position().y - object->get_size().y));
	object->allow_jump(true);
}
void Simple_tile::collision_left(Unit* object)
{
	object->set_velocity_x(0.f);
	object->set_position(sf::Vector2f(this->get_position().x + this->get_size().x + 0.1f, object->get_position().y));
	object->change_direction(direction::right);
}
void Simple_tile::collision_right(Unit* object)
{
	object->set_velocity_x(0.f);
	object->set_position(sf::Vector2f(this->get_position().x - object->get_size().x - 0.1f, object->get_position().y));
	object->change_direction(direction::left);
}