#pragma once
#include<iostream>
#include<string.h>
#include "Constants.h"

class Engine {
protected:
	double m_temp;
	double m_N;

public:

	Engine(int env_temp) :m_temp(env_temp) {};
	~Engine() {};

	double getTemperature() const{
		return m_temp;
	};

	double getPower() const{
		return m_N;
	}
	bool isNotOverHeated() const{
		return m_temp < Constants::ToH ? true : false;
	}
};


class CombustionEngine : public Engine {
protected:
	double m_M = 20;
	double m_V = 0;
public:

	CombustionEngine(int env_temp) : Engine(env_temp) {};

	bool isSpinning() const{
		return m_V == 0 ? false : true;
	}

	//асимптотически V приближается к 300, отсюда (V - epsilon) для конечности
	bool hasNotReachedMaxSpinSpeed() const{
		return m_V < 300-Constants::epsilon ? true : false;
	}

	double getSpinMoment() const{
		return m_M;
	}

	double getSpinSpeed() const{
		return m_V;
	}

	double getHeatingSpeed() const{
		return m_M * Constants::Hm + m_V * m_V * Constants::Hv;
	};

	double getCoolingSpeed(int env_temp) const{
		return Constants::C * (env_temp - m_temp);
	};

	double getAcceleration() const{
		return m_M / Constants::I;
	}

	void changeEngineTemp(int env_temp) {
		m_temp += (getHeatingSpeed() - getCoolingSpeed(env_temp));
	};

	void changeSpinSpeed() {
		m_V += getAcceleration();
	}

	//вычисление M-координаты точки с использованием уравнения прямой при известной V-координате
	double calculateM(int index) const{
		double result;
		result = (m_V - Constants::V[index]) * (Constants::M[index + 1] - Constants::M[index]);
		result /= (Constants::V[index + 1] - Constants::V[index]);
		result += Constants::M[index];
		return result;
	}

	void changeSpinMoment() {
		if (Constants::V[0] <= m_V && m_V < Constants::V[1]) {
			m_M = calculateM(0);
		}
		else if(Constants::V[1] <= m_V && m_V < Constants::V[2]){
			m_M = calculateM(1);
		}
		else if (Constants::V[2] <= m_V && m_V < Constants::V[3]) {
			m_M = calculateM(2);
		}
		else if (Constants::V[3] <= m_V && m_V < Constants::V[4]) {
			m_M = calculateM(3);
		}
		else if (Constants::V[4] <= m_V && m_V < Constants::V[5]) {
			m_M = calculateM(4);
		}
		else {
			throw std::exception("Out of boundaries");
		}

	}

	void changePower() {
		m_N = m_M * m_V / 1000;
	}

};
