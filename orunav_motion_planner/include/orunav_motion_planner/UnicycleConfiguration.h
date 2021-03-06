/**
 * @file UnicycleConfiguration.h
 * @author Marcello Cirillo
 *
 *  Created on: Mar 14, 2011
 *      Author: marcello
 */

#ifndef UNICYCLECONFIGURATION_H_
#define UNICYCLECONFIGURATION_H_

#include "Configuration.h"
#include "UnicycleModel.h"

/**
 * @class UnicycleConfiguration
 * Configuration for a unicycle
 */
class UnicycleConfiguration: public Configuration {


public:
	/**
	 * Initialization of the configuration of the unicycle
	 * @param xCell The cell position of the Configuration on the x axis
	 * @param yCell The cell position of the Configuration on the y axis
	 * @param orientID The orientation angle ID of this configuration
	 * @param steerID The steering angle ID of this configuration
	 * @param vm The VehicleMission passed to the constructor must contain a UnicycleModel
	 */
	UnicycleConfiguration(unsigned short int xCell, unsigned short int yCell, uint8_t orientID, uint8_t steerID, VehicleMission* vm);

	~UnicycleConfiguration();

	/**
	 * Copy constructor
	 * @param origin The original UnicycleConfiguration
	 */
	UnicycleConfiguration(const UnicycleConfiguration& origin);

	/**
	 * Generate new Configuration starting from the current one.
	 * @deprecated Inefficient function. Use generateNewConfigurations(World* w)
	 * @returns Vector of pointers to new Configuration
	 */
	std::vector<Configuration*> generateNewConfigurations();

	/**
	 * Generates new Configuration starting from the current one.
	 * The Configuration returned by this function are guaranteed to be
	 * collision free. The generation itself is more efficient, as this
	 * function uses the MotionPrimitiveSelector data structure.
	 * @param w A pointer to the world, for collision detection
	 * @return Vector of pointers to new Configuration
	 */
	std::vector<Configuration*> generateNewConfigurations(World* w);

	/**
	 * Clone the Configuration and returns a pointer to the newly created object
	 * @returns A pointer to the newly created Configuration
	 */
	Configuration* clone();

};

#endif /* UNICYCLECONFIGURATION_H_ */
