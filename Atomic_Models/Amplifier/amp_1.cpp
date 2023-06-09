/*******************************************************************
*
*  DESCRIPTION: Atomic Model for Amplifier Amp_1
*
*  AUTHOR: Yuri Boiko
*
*  EMAIL: yuri.boiko@rocketmail.com
*
*  DATE: 27/10/2007
*
*******************************************************************/

/** include files **/
#include "amp_1.h"     	  // class Amplifier Amp_1
#include "message.h"   	  // class ExternalMessage, InternalMessage
#include "mainsimu.h"     // MainSimulator::Instance().getParameter( ... )

/*******************************************************************
* Function Name: Amp_1 (Amplifier)
* Description: 	It serves as a weighted input of the Spiking Neuron 
* 		        (to be used for reference spikes)
********************************************************************/
Amp_1::Amp_1( const string &name )
: Atomic( name )
, in_1( addInputPort( "in_1" ) )   //message into port in_1 
, out_1( addOutputPort( "out_1" ) ) //message out port out_1 
, cycleTime( 0, 0, 0, 0 ) //Zero cycleTime
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
Model &Amp_1::initFunction()
{
//float coeff = 1.5; // setting amplification coefficient
holdIn( passive, Time::Zero );

return *this ;
}

/*******************************************************************
* Function Name: externalFunction
* Description: 
********************************************************************/
Model &Amp_1::externalFunction( const ExternalMessage &msg )
{
	if( msg.port() == in_1 )
	{	if( this->state() == passive )
		{   
			holdIn( Atomic::active, cycleTime );
			val_1 = static_cast < float > (msg.value());
//			float coeff = 1.5; // setting amplification coefficient
		}
	}

return *this;
}

/*******************************************************************
* Function Name: internalFunction
* Description: 
********************************************************************/
Model &Amp_1::internalFunction( const InternalMessage &msg )
{
 if (this->state() == active)
 {  
 holdIn( active, cycleTime );
 }
passivate();

return *this ;
}

/*******************************************************************
* Function Name: outputFunction
* Description: 
********************************************************************/

Model &Amp_1::outputFunction( const InternalMessage &msg )
{
float coeff_1 = 10.0;
sendOutput( msg.time(), out_1, val_1*coeff_1 ) ;
return *this ;
}


