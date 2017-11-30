#ifndef CHAILOVE_JOYSTICK_H
#define CHAILOVE_JOYSTICK_H

#include "../Types/Input/Joystick.h"
#include "SDL.h"
#include <string>

using Types::Input::Joystick;

namespace Modules {
	/**
	 * @brief Provides an interface to connected joysticks.
	 */
	class joystick {
	public:
		void load();
		void update();

		/**
		 * @brief Gets a list of connected Joysticks.
		 */
		Joystick* getJoysticks();
		Joystick* joysticks;

		/**
		 * @brief Gets the number of connected joysticks.
		 */
		int getJoystickCount();
		int numJoysticks = 0;

		/**
		 * @brief Checks if the joystick is open.
		 */
		bool isOpen(int index);

		/**
		 * @brief Closes a joystick.
		 */
		void close(int index);

		void unload();
		/**
		 * @brief Checks if a button number is pressed on a joystick.
		 */
		bool isDown(int index, int button);

		/**
		 * @brief Checks if a button is pressed on a joystick.
		 */
		bool isDown(int index, const std::string& button);

		int getButtonKey(const std::string& name);
		std::string getButtonName(int key);
		int16_t joystick_cache[4][14];

		Joystick& operator[](int i);
	};
}

#endif
