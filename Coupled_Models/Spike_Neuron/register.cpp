/*******************************************************************
*
*  DESCRIPTION: Simulator::registerNewAtomics() of 
*  Neuron coupled Model, comprising Timer and Controller
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
#include "timer.h"
#include "controller.h"

void MainSimulator::registerNewAtomics()
{
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Timer>() , "Timer" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Controller>() , "Controller" ) ;
}
