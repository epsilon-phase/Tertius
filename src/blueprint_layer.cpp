#include "blueprint_layer.h"

blueprint_layer::blueprint_layer():layer_texture(nullptr){
}
blueprint_layer::~blueprint_layer(){}

void blueprint_layer::draw(sf::RenderTarget& rt,sf::RenderStates states)const{
  states.transform*=getTransform();
  if(layer_texture!=nullptr)
    states.texture=&(*layer_texture);
  rt.draw(array);
}
void blueprint_layer::designate(point p,int zlevel,const &std::string desig){
  if(try_designate(p,zlevel,desig))
    rebuild();
}
designation_layer::designation_layer():blueprint_layer(){

}
designation_layer::~designation_layer(){}

bool designation_layer::try_designate(point p,int zlevel,const std::string& i){
  auto& mp=filled[zlevel];
  mp[p]=i;
  if(i=="i"||i=="u"){
    if(filled.find(zlevel+1)==filled.end()){
      filled[zlevel+1].insert(std::make_pair(p,"I"));
    }else if(filled[zlevel+1].find(p)==filled[zlevel+1].end()){
      filled[zlevel][p]="I";
    }
  }

  return true;
}
