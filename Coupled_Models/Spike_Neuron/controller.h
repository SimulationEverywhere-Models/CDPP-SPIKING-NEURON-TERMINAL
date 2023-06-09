/*******************************************************************
*
*  DESCRIPTION: Atomic Model for Controller
*
*  AUTHOR: Yuri Boiko
*
*  EMAIL: yuri.boiko@rocketmail.com
*
*  DATE: 27/10/2007
*
*******************************************************************/

#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "atomic.h"

class Controller : public Atomic
{
public:
	Controller( const string &name = "Controller" );
	~Controller();

	virtual string className() const { return "Controller"; }

protected:
	Model &initFunction();
	Model &externalFunction( const ExternalMessage & );
	Model &internalFunction( const InternalMessage & );
	Model &outputFunction( const InternalMessage & );

private:
	const Port &m_in, &m_inCount;
	const Port &m_outFire, &m_outOff;
	Time cycleTime;
	int count;
};

#endif   //CONTROLLER_H
