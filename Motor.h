#ifndef MOTOR_H
#define MOTOR_H

#include <Arduino.h>

const uint8_t FORWARD = 1;
const uint8_t BACKWARD = 0;

class Motor {

	public:

		// === Конструктор ===
		Motor(uint8_t pin_a = 0, uint8_t pin_b = 0);

		// === Методы ===

		// Установка пинов мотора
		void setPins(uint8_t pin_a, uint8_t pin_b);

		// Движение (DC)
		void move(uint8_t direction);

		// Движение (PWM)
		void movePWM(uint8_t speed, uint8_t direction);

		// Отключение мотора (плавный)
		void stop();

		// Тормоза (резко)
		void breaks();

	private:

		// Пины мотора
		uint8_t _pinA;
		uint8_t _pinB;

		// === Служебные методы ===

		// Ограничение значения в диапазоне
		inline uint8_t clamp(int value, uint8_t min, uint8_t max) {
	        if (value < min) return min;
	        if (value > max) return max;
        	return static_cast <uint8_t> (value);
    	}

};

#endif