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
	    FEROMONA_=false;
		giro = 0;
	}

	enum ActionType
	{
	    actFORWARD,	//AV
	    actTURN_L,	//GI
	    actTURN_R,	//GD
		actIDLE		//IDLE
	};

	void Perceive(const Environment &env);
	ActionType Think();

private:
	bool FEROMONA_;	//Variable F
	int giro;
};

string ActionStr(Agent::ActionType);

#endif
