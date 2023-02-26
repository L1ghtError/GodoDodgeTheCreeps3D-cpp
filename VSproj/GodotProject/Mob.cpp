#include "Mob.h"
#define PI 3.14159265359

void Mob::_register_methods()
{
	register_method("_ready", &Mob::_ready);
	register_method("_physics_process", &Mob::_physics_process);
	register_method("_process", &Mob::_process);
	register_method("_on_VisibilityNotifier_screen_exited", &Mob::_on_VisibilityNotifier_screen_exited);
	register_method("Initialize", &Mob::Initialize);
	register_signal<Mob>((char*)"squashed");
}
void Mob::squash() {
	emit_signal("squashed");
	queue_free();
}
void Mob::_ready() {
	_pivot = get_node<Spatial>("Pivot");
	_colisionShape = get_node<Spatial>("CollisionShape");
	
	
	

}
void Mob::_physics_process(float delta) {
	move_and_slide(_velocity);
}
void Mob::_process(const double delta) {

}

void Mob::Initialize(Vector3 startPosition, Vector3 playerPosition) {
	_random = (godot::Ref<godot::RandomNumberGenerator>)godot::RandomNumberGenerator::_new();
	look_at_from_position(startPosition, playerPosition, Vector3::UP);
	_random->randomize();
	rotate_y((float) _random->randf_range(-PI / 4.0, PI / 4.0));
	float randomSpeed = (float)_random->randf_range(minSpeed, maxSpeed);
	_velocity = Vector3::FORWARD * randomSpeed;
	_velocity = _velocity.rotated(Vector3::UP,get_rotation().y);
	get_node<AnimationPlayer>("AnimationPlayer")->set_speed_scale(randomSpeed/minSpeed);
}
void Mob::_on_VisibilityNotifier_screen_exited() {
	queue_free();
}
