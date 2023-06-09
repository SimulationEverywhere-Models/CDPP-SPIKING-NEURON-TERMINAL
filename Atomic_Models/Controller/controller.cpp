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

#include "controller.h"
#include "message.h"
#include "mainsimu.h"     // MainSimulator::Instance().getParameter( ... )

Controller::Controller( const string &name ) :
	Atomic( name )
	, m_in ( addInputPort( "m_in" ) ) // turn on by incoming message 
	, m_inCount( addInputPort( "m_inCount" ) )
	, m_outFire( addOutputPort( "m_outFire" ))//Neuron_Fires
	, m_outOff( addOutputPort( "m_outOff" )) // TIMER_OFF
	, cycleTime( 0, 0, 0, 1 )
	
{
string time( MainSimulator::Instance().getParameter( description(), "cycleTime" ) ) ;
if ( time != "" )
	cycleTime = time ;
}

Controller::~Controller()
{
}

Model& Controller::initFunction()
{
//	this-> passivate();
	holdIn( passive, Time::Zero );
    count = 0;
	return *this;
}

Model& Controller::externalFunction( const ExternalMessage &msg )
{
	if( msg.port() == m_in)
	{
		if(  this->state() == passive )
		{
			holdIn( Atomic::active, cycleTime );
		}
		else passivate();
	}
	else if( msg.port() == m_inCount)
	{
		if(  this->state() == active )
		{
		count = static_cast < int > (msg.value());
		holdIn( active, Time::Zero );
		}
		else count = 0;
	}
	return *this;
}

Model& Controller::internalFunction( const InternalMessage &msg )
{
	passivate();
	return *this;
}

Model& Controller::outputFunction( const InternalMessage &msg )
{
	if( this->state() == active )
	{
	sendOutput( msg.time(), m_outOff, 1.0 ); 
	   if (count <= 8 && count >= 5 )
	   {sendOutput( msg.time(), m_outFire, 1.0 ); 
	   	count = 0;}
	   else 
	   {sendOutput( msg.time(), m_outFire, 0.0 ); 
	   	count = 0;}
	passivate();
	}

	return *this;
}
