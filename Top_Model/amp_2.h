/*******************************************************************
*
*  DESCRIPTION: Atomic Model for Amplifier  Amp_2
*
*  AUTHOR: Yuri Boiko
*
*  EMAIL: yuri.boiko@rocketmail.com
*
*  DATE: 27/10/2007
*
*******************************************************************/

#ifndef AMP_2_H
#define AMP_2_H

#include "atomic.h"     // class Atomic

class Amp_2 : public Atomic
{
public:
	Amp_2( const string &name = "Amp_2" );	//Default constructor
	virtual string className() const ;
//	float coeff; // Amplification
	
protected:
	Model &initFunction();
	Model &externalFunction( const ExternalMessage & );
	Model &internalFunction( const InternalMessage & );
	Model &outputFunction( const InternalMessage & );
//	Model &outputFunction( const ExternalMessage & );
	
private:
    Port &in_2;
	Port &out_2;
	Time cycleTime;// Zero cycleTime
//	const float coeff = 1.5; // Amplification
    float val_2;   //input-output variable for Port in_2 -> out_2
       
};	// class Amplifier (Amp_2)

// ** inline ** // 
inline
string Amp_2::className() const
{
	return "Amp_2" ;
}

#endif   // AMP_2_H
