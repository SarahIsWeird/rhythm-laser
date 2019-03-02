#include <logic/laser.hpp>

Laser::Laser(uint8_t pos) {
	this->pos = pos;
}

int Laser::shoot(size_t warmup, size_t length, laser::laserType_t laserType, laser::wobbleDir_t wobbleDirection) {
	Logger::log("[Laser] Shooting!");
	if (this->active)
		return 1;
	
	this->remainingWarmupTicks = warmup;
	this->segments = length;
	this->tail = (laser::tailSegment*) calloc(length, sizeof(laser::tailSegment));

	int8_t offsetOffset = wobbleDirection * 2 - 1;
	int8_t nextOffset = offsetOffset;
	for (size_t i = 0; i < length; i++) {
		this->tail[i].type = laserType;
		this->tail[i].height = i;
		this->tail[i].dir = wobbleDirection;

		this->tail[i].pos = this->pos + nextOffset;
		
		switch (nextOffset) {
			case -1:
				this->tail[i].offset = laser::segmentPosition::left;
				nextOffset = 0;
				break;
			case 0:
				this->tail[i].offset = laser::segmentPosition::center;
				nextOffset = offsetOffset;
				break;
			case 1:
				this->tail[i].offset = laser::segmentPosition::right;
				nextOffset = 0;
				break;
		}
	}
}

int Laser::shoot(size_t warmup, size_t length, laser::laserType_t laserType) {
	return Laser::shoot(warmup, length, laserType, laser::wobbleDir_t::left);
}

void Laser::tick() {
	if (this->remainingWarmupTicks) {
		this->remainingWarmupTicks--;
		return;
	}

	if (!active)
		return;
}

int Laser::pollSegment(laser::tailSegment *destination) {
	if (this->remainingWarmupTicks)
		return 0;

	if (this->pollIndex + 1 == this->segments) {
		this->pollIndex = 0;
		return 0;
	}

	memcpy(destination, &this->tail[this->pollIndex--], sizeof(laser::tailSegment));
	return 1;
}