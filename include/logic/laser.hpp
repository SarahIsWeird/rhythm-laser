#ifndef LASER_HPP
#define LASER_HPP

#include <stdint.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

#include <vector>

namespace laser {
	namespace wobbleDir {
		enum wobbleDir {
			left = 0,
			right = 1
		};
	};

	typedef wobbleDir::wobbleDir wobbleDir_t;

	namespace segmentPosition {
		enum segmentPosition {
			left = 0,
			center = 1,
			right = 2
		};
	};

	typedef segmentPosition::segmentPosition segmentPosition_t;

	namespace laserType {
		enum laserType {
			normal = 0,
			wobble = 1
		};
	};

	typedef laserType::laserType laserType_t;

	typedef struct {
		int8_t pos;
		size_t height;

		laserType::laserType type;
		segmentPosition_t offset;
		wobbleDir_t dir;
	} tailSegment;
};

class Laser {
private:
	uint8_t pos;

	size_t remainingWarmupTicks;

	bool active;
	bool wobble;

	size_t segments;
	laser::tailSegment *tail;

	size_t pollIndex;
public:
	Laser(uint8_t pos);

	/* Initializes the laser to fire.
	 * Arguments:
	 * - size_t length: The duration of the shot in beats
	 * - laser::laserType_t laserType: The type of the laser (whether it's a normal laser or not)
	 * OPTIONAL: laser::wobbleDir_t wobbleDirection */
	int shoot(size_t warmup, size_t length, laser::laserType_t laserType);
	int shoot(size_t warmup, size_t length, laser::laserType_t laserType, laser::wobbleDir_t wobbleDirection);

	void tick();

	int pollSegment(laser::tailSegment *destination);
};

#endif