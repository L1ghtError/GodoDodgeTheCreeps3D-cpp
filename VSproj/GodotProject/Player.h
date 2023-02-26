#pragma once
#include <Spatial.hpp>
#include <KinematicBody.hpp>
#include <CollisionShape.hpp>
#include <KinematicCollision.hpp>
#include <Godot.hpp>
#include <Input.hpp>
#include <Object.hpp>
#include <AnimationPlayer.hpp>
#include "Mob.h"
using namespace godot;
class Player : public godot::KinematicBody {
    GODOT_CLASS(Player, godot::KinematicBody)
        Input* _input;
    AnimationPlayer* _animated_player;
    Spatial* _pivot;
    Spatial* _character;
    CollisionShape* _colisionShape;

public:
    void _on_MobDetector_body_entered();
    void die();
    Ref<KinematicCollision> _colision;
    int bounce_impulse = 16;
    int jump_impulse = 20;
    int Speed = 14;
    int FallAcceleration = 75;
    Vector3 _velocity = Vector3::ZERO;
    void _init() {}
    void _ready();
    void _process(const double delta);
    void _physics_process(float delta);
    
    
    static void _register_methods();
};
