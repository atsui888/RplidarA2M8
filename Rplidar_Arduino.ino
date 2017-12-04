#include "Rplidar_Arduino.h"

#ifdef RoboGuard_V03

  

  void setup() {    
    RplidarA2M8_ObsDir_Reset();
    Serial.begin(115200);
    pinMode(LEDPin,OUTPUT);
    digitalWrite(LEDPin,LOW);
  
  }
  
  void loop() {
    
    RplidarA2M8_Processing();
    
  }


  void RplidarA2M8_ObsDir_Reset(){
      for(byte i=0;i<RplidarA2M8_ObsDir_Detected_RowLen;++i) {
        for(byte j=0;j<RplidarA2M8_ObsDir_Detected_ColLen;++j) {
          RplidarA2M8_ObsDir_Detected[i][j] = 0;        
        }      
      }
  }
    
  void RplidarA2M8_Processing() {
  // if obstacle is detected, it is immediately recorded
  // however, if obstacle is no longer recorded, it needs to be "not recorded N times before it is 
  // deleted.        
    
    for(byte i = 0;i<RplidarA2M8_ObsDir_Detected_RowLen;++i) 
    {
      for(byte j=0;j<RplidarA2M8_ObsDir_Detected_ColLen;++j) {        
        if(RplidarA2M8_ObsDir_Detected[i][j]>0) {
            RplidarA2M8_ObsDir_Detected[i][j]--;
        }
      }
    }

    // debug code - Direction = Back, Zone = 1
    if(RplidarA2M8_ObsDir_Detected[3][0] > 0) {
      digitalWrite(LEDPin,HIGH);
    } else {
      digitalWrite(LEDPin,LOW);
    }    
      
    if(Serial.available()>0) {      
      char inByte = Serial.read();      
      // incoming byte format: 2n where
      // 2n: Front(zone n), 4n: Left(zone n), 6n: Right(zone n), 8n: Back(zone n) 
      // based on incoming byte, publish the results for Robot-Specific-CA_Sys to input into Obstacle Map
        
      switch(inByte) {
        case 21:   // Front - zone 1
                  RplidarA2M8_ObsDir_Detected[0][0] = RplidarA2M8_ObsRemoval_Treshold;     
                  break;
    
        case 22:  // Front - zone 2
                  RplidarA2M8_ObsDir_Detected[0][1] = RplidarA2M8_ObsRemoval_Treshold;     
                  break;
    
        case 23:  // Front - zone 3
                  RplidarA2M8_ObsDir_Detected[0][2] = RplidarA2M8_ObsRemoval_Treshold;     
                  break;
    
        case 24:  // Front - zone 4
                  RplidarA2M8_ObsDir_Detected[0][3] = RplidarA2M8_ObsRemoval_Treshold;     
                  break;
    
        case 25:  // Front - zone 5
                  RplidarA2M8_ObsDir_Detected[0][4] = RplidarA2M8_ObsRemoval_Treshold;
                  break;
    
        case 26:  // Front - zone 6
                  RplidarA2M8_ObsDir_Detected[0][5] = RplidarA2M8_ObsRemoval_Treshold;
                  break;
    
        case 27:  // Front - zone 7
                  RplidarA2M8_ObsDir_Detected[0][6] = RplidarA2M8_ObsRemoval_Treshold;
                  break;
        case 28:  // Front - zone 8
                  RplidarA2M8_ObsDir_Detected[0][7] = RplidarA2M8_ObsRemoval_Treshold;
                  break;
    
        case 41:  // Left - zone 1
                  RplidarA2M8_ObsDir_Detected[1][0] = RplidarA2M8_ObsRemoval_Treshold;
                  break;
    
        case 42:  // Left - zone 2
                  RplidarA2M8_ObsDir_Detected[1][1] = RplidarA2M8_ObsRemoval_Treshold;
                  break;
    
        case 43:  // Left - zone 3
                  RplidarA2M8_ObsDir_Detected[1][2] = RplidarA2M8_ObsRemoval_Treshold;
                  break;
    
        case 44:  // Left - zone 4
                  RplidarA2M8_ObsDir_Detected[1][3] = RplidarA2M8_ObsRemoval_Treshold;
                  break;
    
        case 45:  // Left - zone 5
                  RplidarA2M8_ObsDir_Detected[1][4] = RplidarA2M8_ObsRemoval_Treshold;
                  break;
    
        case 46:  // Left - zone 6
                  RplidarA2M8_ObsDir_Detected[1][5] = RplidarA2M8_ObsRemoval_Treshold;
                  break;
    
        case 47:  // Left - zone 7
                  RplidarA2M8_ObsDir_Detected[1][6] = RplidarA2M8_ObsRemoval_Treshold;
                  break;
    
        case 48:  // Left - zone 8
                  RplidarA2M8_ObsDir_Detected[1][7] = RplidarA2M8_ObsRemoval_Treshold;
                  break;                                                                                
    
        case 61:  // Right - zone 1
                  RplidarA2M8_ObsDir_Detected[2][0] = RplidarA2M8_ObsRemoval_Treshold;
                  break;
                  
        case 62:  // Right - zone 2
                  RplidarA2M8_ObsDir_Detected[2][1] = RplidarA2M8_ObsRemoval_Treshold;
                  break;
    
        case 63:  // Right - zone 3
                  RplidarA2M8_ObsDir_Detected[2][2] = RplidarA2M8_ObsRemoval_Treshold;
                  break;
    
        case 64:  // Right - zone 4
                  RplidarA2M8_ObsDir_Detected[2][3] = RplidarA2M8_ObsRemoval_Treshold;
                  break;
    
        case 65:  // Right - zone 5
                  RplidarA2M8_ObsDir_Detected[2][4] = RplidarA2M8_ObsRemoval_Treshold;
                  break;
    
        case 66:  // Right - zone 6
                  RplidarA2M8_ObsDir_Detected[2][5] = RplidarA2M8_ObsRemoval_Treshold;
                  break;
    
        case 67:  // Right - zone 7
                  RplidarA2M8_ObsDir_Detected[2][6] = RplidarA2M8_ObsRemoval_Treshold;
                  break;
    
        case 68:  // Right - zone 8
                  RplidarA2M8_ObsDir_Detected[2][7] = RplidarA2M8_ObsRemoval_Treshold;
                  break;
    
        case 81:  // Back - zone 1
                  RplidarA2M8_ObsDir_Detected[3][0] = RplidarA2M8_ObsRemoval_Treshold;                  
                  break;
    
        case 82:  // Back - zone 2
                  RplidarA2M8_ObsDir_Detected[3][1] = RplidarA2M8_ObsRemoval_Treshold;                  
                  break;
    
        case 83:  // Back - zone 3
                  RplidarA2M8_ObsDir_Detected[3][2] = RplidarA2M8_ObsRemoval_Treshold;
                  break;
    
        case 84:  // Back - zone 4
                  RplidarA2M8_ObsDir_Detected[3][3] = RplidarA2M8_ObsRemoval_Treshold;
                  break;
    
        case 85:  // Back - zone 5
                  RplidarA2M8_ObsDir_Detected[3][4] = RplidarA2M8_ObsRemoval_Treshold;
                  break;
    
        case 86:  // Back - zone 6
                  RplidarA2M8_ObsDir_Detected[3][5] = RplidarA2M8_ObsRemoval_Treshold;
                  break;
    
        case 87:  // Back - zone 7
                  RplidarA2M8_ObsDir_Detected[3][6] = RplidarA2M8_ObsRemoval_Treshold;
                  break;
    
        case 88:  // Back - zone 8
                  RplidarA2M8_ObsDir_Detected[3][7] = RplidarA2M8_ObsRemoval_Treshold;
                  break;
    
        default:              
              break;      
      }      
    }         
  }
#endif
