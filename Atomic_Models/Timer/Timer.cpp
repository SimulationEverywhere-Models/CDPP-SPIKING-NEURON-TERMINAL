/*******************************************************************
*
*  DESCRIPTION: Atomic Model for logic clock
*
*  AUTHOR: Yuri Boiko
*
*  EMAIL: yuri.boiko@rocketmail.com
*
*  DATE: 27/10/2007
*
*******************************************************************/

/** include files **/
#include "timer.h"     	  // class Timer
#include "message.h"   	  // class ExternalMessage, InternalMessage
#include "mainsimu.h"     // MainSimulator::Instance().getParameter( ... )

/*******************************************************************
* Function Name: Timer
* Description: 	It sets the input/output ports and the timer cycle
* 		
********************************************************************/
Timer::Timer( const string &name )
: Atomic( name )
, m_inTurnOn( addInputPort( "m_inTurnOn" ) )   //message in to Turn On
, m_inTurnOff( addInputPort( "m_inTurnOff" ) ) //message in to Turn Off
, out_clk( addOutputPort( "out_clk" ) )
, out_count( addOutputPort( "out_count" ) )
, cycleTime( 0, 0, 0, 1 )
{
	
string time( MainSimulator::Instance().getParameter( description(), "cycle" ) ) ;

if ( time != "" )
	cycleTime = time ;
}

/*******************************************************************
* Function Name: initFunction
* Description:
* 
********************************************************************/
Model& Timer::initFunction()
{
clk = -1;  // start timer with low pulse
int count = 0; // start timer with setting count to Zero
//this->state() = passive; //initial state of the Timer
//sendOutput( msg.time(), out_clk, (int) clk) ;
//sendOutput( msg.time(), out_count, (int) count) ;
holdIn( passive, Time::Zero );

return *this ;
}

/*******************************************************************
* Function Name: externalFunction
* Description: 
********************************************************************/
Model& Timer::externalFunction( const ExternalMessage &msg )
{
	if( msg.port() == m_inTurnOn )
	{
		if( this->state() == passive )
		{   
			clk = 1;
			count += 1;
			holdIn( Atomic::active, cycleTime );
		}
	}
	else if( msg.port() == m_inTurnOff )
	{
		if( this->state() != passive )
		{   
			clk *= (-1);
			count += 1;
//			holdIn( Atomic::active, cycleTime );
//			count = 0;
		}
//		holdIn( Atomic::active, cycleTime );
		passivate();
					count = 0;
	}
return *this;
}

/*******************************************************************
* Function Name: internalFunction
* Description: 
********************************************************************/
Model& Timer::internalFunction( const InternalMessage &msg )
{
 if (this->state() == active)
 {  clk *= (-1);
 	count += 1;
 	/*
	if (clk == -1)
	{	clk = 1;
		count += 1;}
	else
	{	clk = -1;
		count += 1;}
		*/
 holdIn( active, cycleTime );
 }
/* else 
 {  clk *= (-1);
 	count += 1;
 	holdIn( active, cycleTime );
 } */
// passivate();

return *this ;
}

/*******************************************************************
* Function Name: outputFunction
* Description: 
********************************************************************/

Model& Timer::outputFunction( const InternalMessage &msg )
{
sendOutput( msg.time(), out_clk, (int) clk) ;
sendOutput( msg.time(), out_count, (int) count) ;
return *this ;
}


/*
Model& Timer::outputFunction( const ExternalMessage &msg )
{
sendOutput( msg.time(), out_clk, (int) clk) ;
sendOutput( msg.time(), out_count, (int) count) ;
return *this ;
}*/
