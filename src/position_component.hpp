#pragma once

#include <libecs-cpp/ecs.hpp>

class position_component : public ecs::Component
{
  public:
    position_component(); 
    position_component(Json::Value);
    Json::Value Export();

    float x = 0.0, y = 0.0, z = 0.0;
};
