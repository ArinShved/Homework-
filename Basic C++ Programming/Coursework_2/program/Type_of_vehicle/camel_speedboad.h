#pragma once

#include "camel.h"

class CamelSpB : public Camel {
public:
	TYPEOFVEHICLEAPI CamelSpB();
	TYPEOFVEHICLEAPI double changeOfTime(int i) override;

};