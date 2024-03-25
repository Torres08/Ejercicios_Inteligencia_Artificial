#include "agent_robot.h"
#include "environment.h"
#include <iostream>
#include <cstdlib>
#include <vector>
#include <utility>

using namespace std;

// -----------------------------------------------------------
Agent::ActionType Agent::Think()
{
	ActionType accion = actFORWARD;
	
	/* ESCRIBA AQUI SUS REGLAS */
	//CNY70_
	//BUMPER_
	if (CNY70_== true){
		accion = actTURN_L;
	}

	if (pasos == 3 && CNY70_== false){
		pasos = 0;
		accion = actTURN_L;
	}
	
	

	if (accion == actFORWARD)
		pasos++;

	if (BUMPER_ )
		accion=actPUSH;
		
		//cout << pasos << endl;

	return static_cast<ActionType> (accion);

}
// -----------------------------------------------------------
void Agent::Perceive(const Environment &env)
{
	CNY70_ = env.isFrontier();
	BUMPER_ = env.isBump();
}
// -----------------------------------------------------------
string ActionStr(Agent::ActionType accion)
{
	switch (accion)
	{
	case Agent::actFORWARD: return "FORWARD";
	case Agent::actTURN_L: return "TURN LEFT";
	case Agent::actTURN_R: return "TURN RIGHT";
	case Agent::actBACKWARD: return "BACKWARD";
	case Agent::actPUSH: return "PUSH";
	case Agent::actIDLE: return "IDLE";
	default: return "???";
	}
}
