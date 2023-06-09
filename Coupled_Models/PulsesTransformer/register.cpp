/*******************************************************************
*
*  DESCRIPTION: Atomic Model for Block of Amplifiers amp_1 and amp_2
*
*  AUTHOR: Yuri Boiko
*
*  EMAIL: yuri.boiko@rocketmail.com
*
*  DATE: 27/10/2007
*
*******************************************************************/

#include "modeladm.h" 
#include "mainsimu.h"
#include "amp_1.h"	// class Amplifier 1
#include "amp_2.h"	// class Amplifier 2


void MainSimulator::registerNewAtomics()
{
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Amp_1>() , "Amp_1" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Amp_2>() , "Amp_2" ) ;

}
