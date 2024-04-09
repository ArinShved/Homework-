#pragma once

#include "camel.h"

class CamelSpB : public Camel {
public:
	TYPE_OF_VEHICLE_API CamelSpB();
	TYPE_OF_VEHICLE_API double changeOfTime(int i) override;

};