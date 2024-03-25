#include "agent_hormiga.h"
#include "environment.h"
#include <iostream>
#include <cstdlib>
#include <vector>
#include <utility>

using namespace std;

// -----------------------------------------------------------
Agent::ActionType Agent::Think()
{
	ActionType accion = actTURN_L;
	
	/* ESCRIBA AQUI LAS REGLAS */
	
	if (FEROMONA_ && giro != 2){
		accion = actFORWARD; // Si hay feromona nos movemos hacia ella
		giro = 0;			 // si he girado 2 veces es porque ya he pasado por ahi hace poco, 
							 // me lo salto y giro otra vez
	} else  {
		giro++;
		accion = actTURN_R; // si no giramos a la derecha
		
	}

	return accion;

}
// -----------------------------------------------------------
void Agent::Perceive(const Environment &env)
{
	FEROMONA_ = env.isFeromona();
}
// -----------------------------------------------------------
string ActionStr(Agent::ActionType accion)
{
	switch (accion)
	{
	case Agent::actFORWARD: return "FORWARD";
	case Agent::actTURN_L: return "TURN LEFT";
	case Agent::actTURN_R: return "TURN RIGHT";
	case Agent::actIDLE: return "IDLE";
	default: return "????";
	}
}
