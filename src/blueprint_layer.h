#pragma once
#include <SFML/Graphics.hpp>

#include <map>
#include <vector>
#include <string>
#include <memory>
#include <array>
#include "point.h"

template<int ORDER>class blueprint_layer:public sf::Drawable,public sf::Transformable{
    protected:
    std::unique_ptr<sf::Texture> layer_texture;
    std::map<std::string,std::array<sf::Vector2f,4> > texture_mappings;
    sf::VertexArray array;
    bool needs_update=true;
    public:
    blueprint_layer();
    virtual ~blueprint_layer();
    int render_order()const{return ORDER;}
    virtual bool try_designate(point,int zlevel,const std::string&)=0;
    virtual std::vector<std::string> get_available_actions()const=0;
    protected:
    void draw(sf::RenderTarget&,sf::RenderStates)const;
};

class designation_layer:public blueprint_layer<0>{
    public:
        designation_layer();
        ~designation_layer();
        int render_order()const;
        bool try_designate(point,int zlevel,const std::string&);
        std::vector<std::string> get_available_actions()const;
        
};
class building_layer:public blueprint_layer<1>{
};
