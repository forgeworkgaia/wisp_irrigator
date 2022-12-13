
// Welcome to Forge Work Gaia!
//
// The Irrigator is a wisp that runs an array of motorized 3 wire valves, like US Solid 
// JFMSV00002.
//
//
//
//



#include "Valve_3wire.h"

// Valve Object
// Valve (int incId, byte incValveOnPin, byte incValveOffPin, int incMode)
Valve compostValve(1,7,8,1);


void setup() {

  unsigned long cycleTime = compostValve.getCycleTime();
  unsigned long currentMillis = millis();
  unsigned long myCycleNum = currentMillis / cycleTime;

  compostValve.setCycle(ceil(myCycleNum));

  Serial.begin(9600);



}



void loop() {

  unsigned long currentMillis = millis();

  ValveRun(compostValve, currentMillis);

  delay(5000);

}

void ValveRun (Valve & incValve, unsigned long currentMillis){


    unsigned long cycleTime = incValve.getCycleTime();

    Serial.println("S1 Current Cycle Time: ");
    Serial.println(cycleTime);
    
    float myCycleNum = (float)currentMillis / (float)cycleTime;

    Serial.println("S1 Current Cycle Number: ");
    Serial.println(myCycleNum);

    int currentCycle = (int) myCycleNum;

    incValve.setCycle(currentCycle);

    Serial.println("S1 Current Cycle: ");
    Serial.println(currentCycle);

    float currentCyclePercentage = myCycleNum - incValve.getCycle();

    Serial.println("S1 Current Cycle Percentage: ");
    Serial.println(currentCyclePercentage, 6);


    if(currentCyclePercentage >= incValve.getValveStartPercentage() && currentCyclePercentage <= incValve.getValveStopPercentage() && ! incValve.ValveRunning()){
      
            incValve.ValveOn();

      
      }else if (!(currentCyclePercentage >= incValve.getValveStartPercentage() && currentCyclePercentage <= incValve.getValveStopPercentage()) &&  incValve.ValveRunning()  ){
        
            incValve.ValveOff();

        
        }
    


 
  
 }


  
