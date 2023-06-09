/*******************************************************************
*
*  DESCRIPTION: Atomic Model for Amplifier Amp_2
*
*  AUTHOR: Yuri Boiko
*
*  EMAIL: yuri.boiko@rocketmail.com
*
*  DATE: 27/10/2007
*
*******************************************************************/

/** include files **/
#include "amp_2.h"     	  // class Amplifier Amp_2
#include "message.h"   	  // class ExternalMessage, InternalMessage
#include "mainsimu.h"     // MainSimulator::Instance().getParameter( ... )

/*******************************************************************
* Function Name: Amp_2 (Amplifier)
* Description: 	It serves as a weighted input of the Spiking Neuron 
* 		        (to be used for reference spikes)
********************************************************************/
Amp_2::Amp_2( const string &name )
: Atomic( name )
, in_2( addInputPort( "in_2" ) )   //message into port in_2 
, out_2( addOutputPort( "out_2" ) ) //message out port out_2 
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
Model &Amp_2::initFunction()
{
//float coeff = 1.5; // setting amplification coefficient
holdIn( passive, Time::Zero );

return *this ;
}

/*******************************************************************
* Function Name: externalFunction
* Description: 
********************************************************************/
Model &Amp_2::externalFunction( const ExternalMessage &msg )
{
	if( msg.port() == in_2 )
	{	if( this->state() == passive )
		{   
			holdIn( Atomic::active, cycleTime );
			val_2 = static_cast < float > (msg.value());
//			float coeff = 1.5; // setting amplification coefficient
		}
	}

return *this;
}

/*******************************************************************
* Function Name: internalFunction
* Description: 
********************************************************************/
Model &Amp_2::internalFunction( const InternalMessage &msg )
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

Model &Amp_2::outputFunction( const InternalMessage &msg )
{
float coeff_2 = 5.0;
sendOutput( msg.time(), out_2, val_2*coeff_2 ) ;
return *this ;
}


