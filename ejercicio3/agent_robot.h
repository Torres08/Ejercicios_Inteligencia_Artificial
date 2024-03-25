#ifndef AGENT__
#define AGENT__

#include <string>
#include <iostream>
using namespace std;

// -----------------------------------------------------------
//				class Agent
// -----------------------------------------------------------
class Environment;
class Agent
{
public:
	Agent(){
		CNY70_=false;
		BUMPER_=false;

		// INICIALIZA
		//mapa[i][j]=0;
		Brujula = 0; // AL NORTE
		pasos = 0;
		//CNY70_
		//BUMPER_
		
	}

	enum ActionType
	{
	    actFORWARD,
	    actTURN_L,
	    actTURN_R,
		actBACKWARD,
		actPUSH,
		actIDLE
	};

	void Perceive(const Environment &env);
	ActionType Think();

private:
	bool CNY70_;
	bool BUMPER_;

	// DEFINE AQUI LAS VARIABLES
	char mapa[7][7];
	int Brujula;
	int fil,pos;
	int pasos;
};

string ActionStr(Agent::ActionType);

#endif
