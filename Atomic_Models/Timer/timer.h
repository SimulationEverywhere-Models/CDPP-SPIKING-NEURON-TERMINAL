/*******************************************************************
*
*  DESCRIPTION: Atomic Model for logic Timer
*
*  AUTHOR: Yuri Boiko
*
*  EMAIL: yuri.boiko@rocketmail.com
*
*  DATE: 27/10/2007
*
*******************************************************************/

#ifndef __TIMER_H
#define __TIMER_H

#include "atomic.h"     // class Atomic

class Timer : public Atomic
{
public:
	Timer( const string &name = "Timer" );	//Default constructor
	virtual string className() const ;

protected:
	Model &initFunction();
	Model &externalFunction( const ExternalMessage & );
	Model &internalFunction( const InternalMessage & );
	Model &outputFunction( const InternalMessage & );
//	Model &outputFunction( const ExternalMessage & );
	
private:
    Port &m_inTurnOn;
    Port &m_inTurnOff;
	Port &out_clk;
	Port &out_count;
	Time cycleTime;
	int clk;
	int count;


};	// class Timer

// ** inline ** // 
inline
string Timer::className() const
{
	return "Timer" ;
}

#endif   //__TIMER_H
