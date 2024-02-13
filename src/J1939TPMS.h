#ifndef _J1939TYRE_H_
#define _J1939TYRE_H_

#include "N2kMsg.h"
#include "N2kTypes.h"
#include <string.h>
#include <stdint.h>


enum class tCTISensorStatus {Status1,Status2,Status3,Status4};
enum class tCTITyreStatus {Status1,Status2,Status3,Status4};
enum class tCTITerminalStatus {Status1,Status2,Status3,Status4};
enum class tCTIPressureAlertStatus {NotUsed,OverPressure,NoAlarmPressure,LowPressure,NotUsed2,NotUsed3,NoSignal,NotUsed4};

/************************************************************************//**
 * \brief Parsing J1939 PGN 65268 TyrePal TPMS"
 * \ingroup group_msgSetUp
 *
 * ???.
 *
 * \param N2kMsg                Reference to a N2kMsg Object,
 *                              Output: NMEA2000 message ready to be send.
 * \param TyrePosition          ???
 * \param TyrePressure          Tyre pressure in Pa.
 * \param TyreTemperature       Tyre temperature in K.
 * ...
 *
 */
bool ParseJ1939PGN65268(const tN2kMsg &N2kMsg,
                        uint8_t &TyrePosition,
                        double &TyrePressure,
                        double &TyreTemperature,
                        tCTISensorStatus &CTISensorStatus,
                        tCTITyreStatus &CTITyreStatus,
                        tCTITerminalStatus &CTITerminalStatus,
                        double &AirLeakageRate,
                        tCTIPressureAlertStatus &CTIPressureAlertStatus);
#endif