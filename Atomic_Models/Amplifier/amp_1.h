/*******************************************************************
*
*  DESCRIPTION: Atomic Model for Amplifier  Amp_1
*
*  AUTHOR: Yuri Boiko
*
*  EMAIL: yuri.boiko@rocketmail.com
*
*  DATE: 27/10/2007
*
*******************************************************************/

#ifndef AMP_1_H
#define AMP_1_H

#include "atomic.h"     // class Atomic

class Amp_1 : public Atomic
{
public:
	Amp_1( const string &name = "Amp_1" );	//Default constructor
	virtual string className() const ;
//	float coeff; // Amplification
	
protected:
	Model &initFunction();
	Model &externalFunction( const ExternalMessage & );
	Model &internalFunction( const InternalMessage & );
	Model &outputFunction( const InternalMessage & );
//	Model &outputFunction( const ExternalMessage & );
	
private:
    Port &in_1;
	Port &out_1;
	Time cycleTime;// Zero cycleTime
//	const float coeff = 1.5; // Amplification
    float val_1;   //input-output variable for Port in_1 -> out_1
       
};	// class Amplifier (Amp_1)

// ** inline ** // 
inline
string Amp_1::className() const
{
	return "Amp_1" ;
}

#endif   // AMP_1_H
