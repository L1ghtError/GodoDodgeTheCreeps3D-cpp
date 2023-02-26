#pragma once
#include <Godot.hpp>
#include <Spatial.hpp>
#include <KinematicBody.hpp>
#include <CollisionShape.hpp>
#include <Math.hpp>
#include <RandomNumberGenerator.hpp>
#include <GDScript.hpp>
#include <AnimationPlayer.hpp>
using namespace godot;
class Mob : public godot::KinematicBody {
    GODOT_CLASS(Mob, godot::KinematicBody)
        Spatial* _pivot;
        Spatial* _colisionShape;
        
public:
    int minSpeed=10;
    int maxSpeed=18;
    Vector3 _velocity;
    void _init() {}
    void _ready();
    void squash();
    void Initialize(Vector3 startPosition, Vector3 playerPosition);
    Ref<godot::RandomNumberGenerator> _random;
    
    void callPrint();
    void _process(const double delta);
    void _on_VisibilityNotifier_screen_exited();
    void _physics_process(float delta);
    static void _register_methods();
};
