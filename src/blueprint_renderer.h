#pragma once

#include <SFML/Graphics.hpp>
#include <array>
#include <vector>

class blueprint_layer;
/**
 * Renders a blueprint a level at a time, one z-level at once
 * Contains blueprint interaction code, display level code,
 * generally handles moving around the blueprint and dealing 
 * with the input that falls into it.
 */
class blueprint_container:public sf::Drawable{
    std::array<std::unique_ptr<blueprint_layer>,3> layers;
    int m_z_level;
    int m_layer;
    
};
