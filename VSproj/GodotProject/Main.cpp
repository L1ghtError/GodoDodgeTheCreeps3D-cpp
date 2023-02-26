#include "Main.h"


void Main::_register_methods()
{
	register_method("_ready", &Main::_ready);
	register_method("_physics_process", &Main::_physics_process);
	register_method("_process", &Main::_process);
	register_method("_on_Player_hit", &Main::_on_Player_hit);
	register_property("mob_scene", &Main::mob_scene, (godot::Ref<godot::PackedScene>)nullptr);
	register_method("_on_MobTimer_timeout", &Main::_on_MobTimer_timeout);
	register_method("_unhandled_input", &Main::_unhandled_input);
}
void Main::_on_Player_hit() {
	_timer->stop();
	_retry->show();
	
}
void Main::_ready() {
	_random = (godot::Ref<godot::RandomNumberGenerator>)godot::RandomNumberGenerator::_new();
	_random->randomize();
	_timer = get_node<Timer>("MobTimer");
	_socre_label = (ScoreLabel*)get_node<Label>("UserInterface/ScoreLabel");
	_retry = get_node<ColorRect>("UserInterface/Retry");
	_retry->hide();
}
void Main::_physics_process(float delta) {
	
}
void Main::_process(const double delta) {

}
void Main::_unhandled_input(InputEvent* _event)
{
	
	if (_event->is_action_pressed("ui_accept") && _retry->is_visible()) {
		get_tree()->reload_current_scene();
	}
}
void Main::_on_MobTimer_timeout() {
	
	Mob* mob =cast_to<Mob> (mob_scene->instance());
	
	PathFollow* mobSpawnLocation = get_node<PathFollow>("SpawnPath/SpawnLocation");
	
	mobSpawnLocation->set_unit_offset(_random->randf());
	_player_position = get_node<Player>("Player")->get_transform().origin;
	
	mob->Initialize(mobSpawnLocation->get_translation(), _player_position);
	mob->connect("squashed",_socre_label, "_on_Mob_squashed");
	add_child(mob);

	
}
