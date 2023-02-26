#include "ScoreLabel.h"

void ScoreLabel::_ready()
{
}

void ScoreLabel::_process(const double delta)
{
}

void ScoreLabel::_on_Mob_squashed()
{
	
	_score++;
	set_text("Score:"+(String)(std::to_string(_score).c_str()) );
}



void ScoreLabel::_register_methods()
{
	register_method("_ready", &ScoreLabel::_ready);
	register_method("_process", &ScoreLabel::_process);
	register_method("_on_Mob_squashed", &ScoreLabel::_on_Mob_squashed);
}

