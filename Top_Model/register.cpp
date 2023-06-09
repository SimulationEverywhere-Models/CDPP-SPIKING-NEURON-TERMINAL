/*******************************************************************
*
*  DESCRIPTION: Coupled Model of Spiking Neuron Terminal
* Consisting of Spike Supplier with Block of Amplifiers amp_1 and amp_2
* and Spiking Neuron, which in turn include Timer and Controller
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
#include "timer.h"
#include "controller.h"

void MainSimulator::registerNewAtomics()
{
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Amp_1>() , "Amp_1" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Amp_2>() , "Amp_2" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Timer>() , "Timer" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Controller>() , "Controller" ) ;
//	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Source>() , "Source" ) ;
//	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Neuron>() , "Neuron" ) ;

}
