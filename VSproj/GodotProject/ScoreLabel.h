#pragma once
#include <Label.hpp>
#include <Godot.hpp>
#include <string>
using namespace godot;
class ScoreLabel : public godot::Label {
    GODOT_CLASS(ScoreLabel, godot::Label)
        int _score = 0;
   
public:
    void _init() {}
    void _ready();
    void _process(const double delta);
    void _on_Mob_squashed();
    
    static void _register_methods();
};