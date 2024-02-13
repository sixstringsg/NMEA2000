#include "J1939TPMS.h"

// *****************************************************************************
bool ParseJ1939PGN65268(const tN2kMsg &N2kMsg,
                        uint8_t &TyrePosition,
                        double &TyrePressure,
                        double &TyreTemperature,
                        tCTISensorStatus &CTISensorStatus,
                        tCTITyreStatus &CTITyreStatus,
                        tCTITerminalStatus &CTITerminalStatus,
                        double &AirLeakageRate,
                        tCTIPressureAlertStatus &CTIPressureAlertStatus) {

  if(N2kMsg.PGN != 65268L) return false;
 
  int Index=0;
  TyrePosition=N2kMsg.GetByte(Index);
  TyrePressure=N2kMsg.Get1ByteUDouble(4000,Index);
  TyreTemperature=N2kMsg.Get2ByteUDouble(0.03125,Index);
  uint8_t StatusBits=N2kMsg.GetByte(Index);
  CTISensorStatus=(tCTISensorStatus)( StatusBits & 0x3 );
  CTITyreStatus=(tCTITyreStatus)( (StatusBits>>2) & 0x3 );
  CTITerminalStatus=(tCTITerminalStatus)( (StatusBits>>4) & 0x3 );
  AirLeakageRate=N2kMsg.Get2ByteUDouble(1,Index);
  CTIPressureAlertStatus=(tCTIPressureAlertStatus)( (N2kMsg.GetByte(Index)>>5) & 0x7 );
 
  return true;
}