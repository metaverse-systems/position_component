#include <position_component.hpp>

position_component::position_component() 
{ 
    this->Type = "position_component";
}

position_component::position_component(Json::Value config)
{
    this->Type = "position_component";
    this->x = config["x"].asFloat();
    this->y = config["y"].asFloat();
    this->z = config["z"].asFloat();
}

Json::Value position_component::Export()
{
    Json::Value config;
    config["x"] = this->x;
    config["y"] = this->y;
    config["z"] = this->z;
    return config;
}

extern "C"
{
    ecs::Component *create_component(void *p)
    {
        if(p == nullptr)
        {
            return new position_component();
        }

        Json::Value *config = (Json::Value *)p;
        return new position_component(*config);
    }
}
