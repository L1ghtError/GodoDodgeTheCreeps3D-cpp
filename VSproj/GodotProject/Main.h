#pragma once
#include <Godot.hpp>
#include <Spatial.hpp>
#include <KinematicBody.hpp>
#include <Node.hpp>
#include <RandomNumberGenerator.hpp>
#include <PackedScene.hpp>
#include <PathFollow.hpp>
#include <Timer.hpp>
#include "Player.h"
#include "Mob.h"
#include "ScoreLabel.h"
#include <Control.hpp>
#include <Label.hpp>
#include <ColorRect.hpp>
#include <InputEvent.hpp>
#include <SceneTree.hpp>
using namespace godot;
class Main : public godot::Node {
    GODOT_CLASS(Main, godot::Node)
        Timer* _timer;
    ScoreLabel* _socre_label;
    ColorRect* _retry;
public:
    Vector3 _player_position;
    Ref<godot::PackedScene> mob_scene;
    
    void _on_MobTimer_timeout();
    Ref<godot::RandomNumberGenerator> _random;
    void _on_Player_hit();
    void _init() {}
    void _ready();
    void _process(const double delta);
    void _unhandled_input(InputEvent *_event); //you can try: const Ref<InputEventKey> event
    void _physics_process(float delta);
   
    
    static void _register_methods();
};
#pragma once
