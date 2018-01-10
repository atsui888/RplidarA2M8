#define RoboGuard_V03

#ifdef RoboGuard_V03

  const byte LEDPin = 13;
  
  // Obstacle detection array
  const unsigned int RplidarA2M8_ObsRemoval_Treshold = 60000;
  // on first detection, it is assigned 
  const byte RplidarA2M8_ObsDir_Detected_RowLen = 4;  
  const byte RplidarA2M8_ObsDir_Detected_ColLen = 8;
  unsigned int RplidarA2M8_ObsDir_Detected[RplidarA2M8_ObsDir_Detected_RowLen][RplidarA2M8_ObsDir_Detected_ColLen] = 
                                        {
                                          {0,0,0,0,0,0,0,0},
                                          {0,0,0,0,0,0,0,0},
                                          {0,0,0,0,0,0,0,0},
                                          {0,0,0,0,0,0,0,0}                                          
                                         };


  /*
    if(RplidarA2M8_ObsDir_Detected[0][0] > 0) // obstacle is detected at Direction "Front" and Zone 1
    if(RplidarA2M8_ObsDir_Detected[0][7] > 0) // obstacle is detected at Direction "Front" and Zone 8
    if(RplidarA2M8_ObsDir_Detected[1][0] > 0) // obstacle is detected at Direction "Left" and Zone 1
    if(RplidarA2M8_ObsDir_Detected[2][0] > 0) // obstacle is detected at Direction "Right" and Zone 1
    if(RplidarA2M8_ObsDir_Detected[3][0] > 0) // obstacle is detected at Direction "Back" and Zone 1 
    
  */
#endif

