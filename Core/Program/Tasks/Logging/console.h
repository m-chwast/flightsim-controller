/*
 * console.h
 *
 *  Created on: Oct 9, 2023
 *      Author: Mateusz Chwast
 */

#pragma once

#include "FreeRTOS.h"
#include "queue.h"

class Console {
private:

	QueueHandle_t _queue;
	constexpr static uint16_t _queueLength = 20;
	constexpr static uint16_t _queueElemSize = 50;

public:

	Console() {
		_queue = xQueueCreate(_queueLength, _queueElemSize);
	}

	QueueHandle_t GetQueue() const { return _queue; }

};
