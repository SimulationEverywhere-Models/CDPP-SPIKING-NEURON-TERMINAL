/*******************************************************************
*
*  DESCRIPTION: Simulator::registerNewAtomics() of Atomic Model for Controller
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
//#include "Pendulo.h"
//#include "AgujaMin.h"
//#include "AgujaHour.h"
//#include "Alarma.h"
#include "controller.h"

void MainSimulator::registerNewAtomics()
{
//	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Pendulo>() , "Pendulo" ) ;
//	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<AgujaMin>() , "AgujaMin" ) ;
//	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<AgujaHour>() , "AgujaHour" ) ;
//	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Alarma>() , "Alarma" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Controller>() , "Controller" ) ;
}
