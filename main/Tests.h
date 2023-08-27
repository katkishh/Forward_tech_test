#pragma once
#include"Engine.h"
#include<string>

class Test
{
public:
	virtual void perform() {};

};

class OverHeatTest : public Test {
protected:
	int m_worktime = 0;
public:

	OverHeatTest() : Test() {};

	void perform(CombustionEngine* engine, int env_temp) {
		while (engine->isNotOverHeated()) {
			m_worktime += 1;
			engine->changeSpinSpeed();
			engine->changeSpinMoment();
			engine->changeEngineTemp(env_temp);
		}

		std::cout << "The engine is overheated in " + std::to_string(m_worktime) + " seconds \n";
	}

	int getWorktime() const{
		return m_worktime;
	}
};

class PowerTest : public Test {
public:

	PowerTest() : Test() {};

	void perform(CombustionEngine* engine) {
		double max_power = 0, spin_speed = 0;
		do {
			engine->changeSpinSpeed();
			engine->changeSpinMoment();
			engine->changePower();

			if (max_power < engine->getPower()) {
				max_power = engine->getPower();
				spin_speed = engine->getSpinSpeed();
			}

		} while (engine->hasNotReachedMaxSpinSpeed());

		std::cout << "Maximum power of engine: " << std::to_string(max_power) << ", achieves at spin speed: " << std::to_string(spin_speed);
	}
};