#include "Player.h"
#define PI 3.14159265359
void Player::_ready()
{
	_animated_player = get_node<AnimationPlayer>("AnimationPlayer");

	_colision = (Ref<KinematicCollision>)godot::KinematicCollision::_new;
	_input = Input::get_singleton();
	//_kinematicBody = get_node<KinematicBody>("Player");
	_pivot = get_node<Spatial>("Pivot");
	_character = get_node<Spatial>("Pivot/Character");
	_colisionShape = get_node<CollisionShape>("CollisionShape");
}

void Player::_process(const double delta)
{

}

void Player::_physics_process(float delta)
{
	
	Vector3 direction = Vector3::ZERO;
	if (_input->is_action_pressed("move_right")) {
		direction.x += (real_t)1;

	}
	if (_input->is_action_pressed("move_left")) {
		direction.x -= (real_t)1;
	}
	if (_input->is_action_pressed("move_back")) {
		direction.z += (real_t)1;
	}
	if (_input->is_action_pressed("move_forward")) {
		direction.z -= (real_t)1;
	}
	if (is_on_floor() && _input->is_action_just_pressed("jump")) {
		_velocity.y += jump_impulse;
	}
	if (direction != Vector3::ZERO) {
		direction = direction.normalized();
		_pivot->look_at(/*_pivot->get_translation() +*/ direction, Vector3::UP);
	}
	_velocity.x = direction.x * Speed;
	_velocity.z = direction.z * Speed;
	_velocity.y -= FallAcceleration * delta;
	_velocity = move_and_slide(_velocity, Vector3::UP);
	for (int i = 0; i < get_slide_count(); i++) {
		
		
		_colision = get_slide_collision(i);
		
		

		
		if (((Mob*)_colision->get_collider())->is_in_group("mob")) {
			if (Vector3::UP.dot(_colision->get_normal()) > 0.1) {
				Mob* mob = (Mob*)_colision->get_collider();
				mob->squash();
				_velocity.y = bounce_impulse;
			}
		}
	}
	if (direction != Vector3::ZERO) {
		_animated_player->set_speed_scale(4);
	}
	else
	{
		_animated_player->set_speed_scale(1);
	}
	Vector3 *pivot_rotation=&_pivot->get_rotation();
	pivot_rotation->x = PI / 6 * _velocity.y / jump_impulse;
}
void Player::_on_MobDetector_body_entered() {
	die();
}
void Player::die() {
	emit_signal("hit");
	queue_free();
}
void Player::_register_methods()
{
	register_method("_on_MobDetector_body_entered", &Player::_on_MobDetector_body_entered);
	register_method("_ready", &Player::_ready);
	register_method("_physics_process", &Player::_physics_process);
	register_method("_process", &Player::_process);
	register_signal<Player>((char*)"hit");
}
