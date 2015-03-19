/*
 * systime.h
 *
 * Created: 19-03-2015 07:12:36 PM
 *  Author: Ajinkya
 */ 


#ifndef SYSTIME_H_
#define SYSTIME_H_

#include "config.h"

namespace systime{
		unsigned long getSysTime();
		unsigned long  getSysTimeRaw();
		void sysTimeInit();
		unsigned long getOverflows();
};


#endif /* SYSTIME_H_ */