/*******************************************************************
*
*  DESCRIPTION: Atomic Model for Amplifier amp_1
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
#include "amp_1.h"	// class Amplifier



void MainSimulator::registerNewAtomics()
{
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Amp_1>() , "Amp_1" ) ;
}
