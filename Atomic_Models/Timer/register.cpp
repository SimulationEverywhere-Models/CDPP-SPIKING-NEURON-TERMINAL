/*******************************************************************
*
*  DESCRIPTION: Atomic Model for logic Timer
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
//#include "norGate.h"	// class norGate
//#include "andGate.h"	// class andGate
#include "timer.h"	// class Clock
//#include "queue.h"      // class Queue
//#include "generat.h"    // class Generator
//#include "cpu.h"        // class CPU
//#include "transduc.h"   // class Transducer
//#include "trafico.h"    // class Trafico


void MainSimulator::registerNewAtomics()
{
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Timer>() , "Timer" ) ;
//	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<andGate>() , "andGate" ) ;
//	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<norGate>() , "norGate" ) ;
//	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Queue>() , "Queue" ) ;
//	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Generator>() , "Generator" ) ;
//	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<CPU>() , "CPU" ) ;
//	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Transducer>() , "Transducer" ) ;
//	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Trafico>() , "Trafico" ) ;
}
