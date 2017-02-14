#pragma once
#include <SFML/Graphics.hpp>

#include <map>
#include <vector>
#include <string>
#include <memory>
#include <array>
#include "point.h"

class blueprint_layer:public sf::Drawable,public sf::Transformable{
    protected:
    std::unique_ptr<sf::Texture> layer_texture;
    std::map<std::string,std::array<sf::Vector2f,4> > texture_mappings;
    sf::VertexArray array;
    bool needs_update=true;
    public:
    blueprint_layer();
    virtual ~blueprint_layer();
    virtual int render_order()const=0;
    virtual std::vector<std::string> get_available_actions()const=0;
    void designate(point,int zlevel,const std::string& desig);
    protected:
    virtual bool try_designate(point,int zlevel,const std::string&)=0;
    virtual void rebuild()=0;
    void draw(sf::RenderTarget&,sf::RenderStates)const;
};

class designation_layer:public blueprint_layer{
  std::map<int,std::map<point,std::string> > filled;
    public:
        designation_layer();
        ~designation_layer();
        std::vector<std::string> get_available_actions()const;
      int render_order()const{return 0;} 
    protected:
        bool try_designate(point,int zlevel,const std::string&);
};
class building_layer:public blueprint_layer{
  public:
    building_layer();
    ~building_layer();
    int render_order()const{return 1;}
    bool try_designate(point,int zlevel,const std::string&);
    std::vector<std::string> get_available_actions()const;

};
