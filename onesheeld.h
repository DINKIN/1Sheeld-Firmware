﻿/*

  Project:       1Sheeld Firmware 
  File:          onesheeld.h

  Compiler:      avr-gcc 3.4.2

  Author:        Integreight
                 
  Date:          2014.5

*/

/**
 * @file onesheeld.h
 * @brief This library contains an Arduino abstraction layer to mimic Arduino methods and a set of 1Sheeld related methods.
 * @author Integreight
 * @version 1.1
 */ 

#ifndef ONESHEELD_H_
#define ONESHEELD_H_
#include "stdint.h"
#include "firmata.h"

#if (!defined(PLUS_BOARD) && !defined(CLASSIC_BOARD)) 
#error "Board not defined"
#endif
#if (defined(PLUS_BOARD) && defined(CLASSIC_BOARD))
#error "Defined PLUS_BOARD and CLASSIC_BOARD"
#endif

/**
 * @brief Send a frame to Arduino that the app is disconected  
 * @param None
 * @return  None  
 */
void sendArduinoAppDisconnected();
/**
 * @brief Initializes the Hardware peripherals and setup for communications  
 * @param None
 * @return  None  
 */
void initialization();
/**
 * @brief Grab Time using Millis timer function 
 * @param None
 * @return  None  
 */
void catchTimeForSomeVariables();
/**
 * @brief Checks digitalPorts status  
 * @param None
 * @return  None  
 */
void checkDigitalPinStatus();
/**
* @brief Process data coming from application.
* @param None.
* @return None.
*/
void processDataFromApp();
/**
* @brief Check if application responded to the Bluetooth reset request.
* @param None.
* @return None.
*/
void checkBluetoothResetResponse();
/**
* @brief Check if app responded as alive and is still connected.
* @param None.
* @return None.
*/
void checkAppConnection();
/**
* @brief Send Data to the application in 20bytes frame each 15ms.
* @param None.
* @return None.
*/
void sendDataToApp();
/**
 * @brief Send a frame to Arduino to stop sending Data  
 * @param None
 * @return  None  
 */
void sendArduinoToStopData();
/**
 * @brief Send a frame to Arduino to start sending Data  
 * @param None
 * @return  None  
 */
void sendArduinoToSendData();
/**
 * @brief Check if the Arduino Buffer is Empty  
 * @param None
 * @return  None  
 */
void checkArduinoRx0BufferSpace();
/**
* @brief Check digital ports pin state equality.
* @param oldPort state,newPort state,number of pins.
* @return None.
*/
uint16_t checkPortStateEquality(uint8_t * oldPort ,uint8_t * newPort,uint8_t numberOfPins);
/**
* @brief Put digital ports values in the 20byte buffer to be sent.
* @param None.
* @return None.
*/
void fillBufferWithPinStates(uint8_t * portArray,uint8_t portNumber);
/**
* @brief Put digital ports values in the 20byte buffer to be sent.
* @param None.
* @return None.
*/
uint8_t getSavedBaudRateFromEeprom();
/**
* @brief Check the changes of the pins and place them in the small buffer.
* @param None.
* @return None.
*/
void checkIfPinsChangedSendThem();
#endif /* 1SHEELDS_FUNCTIONS_H_ */

