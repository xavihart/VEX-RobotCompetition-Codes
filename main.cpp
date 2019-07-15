#include "robot-config.h"

//----------------------------------------------------------------//
/*---------------------Introdcutions of controller----------------
   AXIS2 : the forward and backword move of the model, the speed 
is determined by the exact position of the axis;
   AXIS4 : turn left and right
   ButtonL1:  make the brusher to rotate clockwise
   ButtonL2:  make the brusher to rotate counterclockwise
   ButtonR1:  make the block_catcher to move up
   ButtonR2:  make the block_catcher to move down
---------------------------------------------------------------**/ 


//----value for modification-------//
const int turning_speed = 25;
const int rising_speed = 25;
cosnt int brushing_speed = 25;
//---------------------------------//



//------declaration of functions for the autonoumous section------------//
void autonomous_section();
  // autonomous_section actually is the combination of these sub-function:
  /* In the end of each function below we add a stop function to the certain gear, 
  that is to say,the function(operation)is set to run a finite distance */
  void moving_fwd(int ,uint_32 ); 
  void moving_bwd(int,uint_32 );
  void turning_left(int,uint_32);
  void turning_right(int,(uint_32);
  void brusher_up(int,uint_32);
  void brusher_down(int,uint_32);
  void catcher_up(int,uint_32);
  void catcher_down(int,uint_32); 
//---------------------------------------------------------------------//



//-------function of the hand-operated section---------//
void moving_part();
void turning_part();
void brusher_part();
void catcher_part();  //rising part
void stop_driver_motor(){
    motor_driver_Left1.stop();
    motor_driver_Left2.stop();
    motor_driver_Left3.stop();
    motor_driver_Right1.stop();
    motor_driver_Right2.stop();
    motor_driver_Right3.stop();
}
void stop_brusher_motor(){
    motor_brusher_left.stop();
    motor_brusher_right.stop();
}
void stop_catcher_motor(){
  motor_riser_left.stop();
  motor_riser_right.stop();
}
//-----------------------------------------------------//

int main() {
    void autonomous_section();
    
    while(1){   
       moving_part();
       turning_part();
       brusher_part();
       catcher_part();
       vex::task::sleep(20);
    }
    
}



void moving_part(){
     if(controller1.Axis3.value()>15){
            
          motor_driver_Left1.spin(vex::directionType::fwd,func(controller1.Axis2.value()));
          motor_driver_Left2.spin(vex::directionType::fwd,func(controller1.Axis2.value()));
          motor_driver_Left3.spin(vex::directionType::fwd,func(controller1.Axis2.value()));
          motor_driver_Right1.spin(vex::directionType::fwd,func(controller1.Axis2.value()));
          motor_driver_Right2.spin(vex::directionType::fwd,func(controller1.Axis2.value()));
          motor_driver_Right3.spin(vex::directionType::fwd,func(controller1.Axis2.value()));  
        
        }else if(controller1.Axis3.value()<-15){
            
          motor_driver_Left1.spin(vex::directionType::bwd,func2(controller1.Axis2.value()));
          motor_driver_Left2.spin(vex::directionType::bwd,func2(controller1.Axis2.value()));
          motor_driver_Left3.spin(vex::directionType::bwd,func2(controller1.Axis2.value()));
          motor_driver_Right1.spin(vex::directionType::bwd,func2(controller1.Axis2.value()));
          motor_driver_Right2.spin(vex::directionType::bwd,func2(controller1.Axis2.value()));
          motor_driver_Right3.spin(vex::directionType::bwd,func2(controller1.Axis2.value()));  
            
        }else{stop_driver_motor();}    
               
        
}

void turning_part(){
     //turn left and right,the deg of turning is decided by the operator
          if(controller1.Axis4.value()>100){
              motor_driver_Right1.spin(vex::directionType::fwd,turnning_speed_pct,velocityUnits::pct);
              motor_driver_Right2.spin(vex::directionType::fwd,turnning_speed_pct,velocityUnits:::pct);
              motor_driver_Right3.spin(vex::directionType::fwd,turnning_speed_pct,velocityUnits:::pct); 
			  motor_driver_Left1.spin(vex::directionType::bwd,turnning_speed_pct,velocityUnits::pct);
              motor_driver_Left2.spin(vex::directionType::bwd,turnning_speed_pct,velocityUnits:::pct);
              motor_driver_Left3.spin(vex::directionType::bwd,turnning_speed_pct,velocityUnits:::pct); 
          }
          if(controller1.Axis4.value()<-100){
              motor_driver_Left1.spin(vex::directionType::fwd,turnning_speed_pct,velocityUnits::pct);
              motor_driver_Left2.spin(vex::directionType::fwd,turnning_speed_pct,velocityUnits:::pct);
              motor_driver_Left3.spin(vex::directionType::fwd,turnning_speed_pct,velocityUnits:::pct); 
			  motor_driver_Right1.spin(vex::directionType::bwd,turnning_speed_pct,velocityUnits::pct);
              motor_driver_Right2.spin(vex::directionType::bwd,turnning_speed_pct,velocityUnits:::pct);
              motor_driver_Right3.spin(vex::directionType::bwd,turnning_speed_pct,velocityUnits:::pct); 
          }else{
              stop_driver_motor();
          }
}

/* void brusher_part(){
    if(controller1.ButtonR1.pressing()){
        motor_brusher_left.spin(vex::directionType::fwd,brushing_speed,velocityUnits::pct);
        motor_brusher_right.spin(vex:directionType::fwd,brushing_speed,velocityUnits::pct);       
    }
    
    if(controller1.ButtonR2.pressing()){
        motor_brusher_left.spin(vex::directionType::bwd,brushing_speed,velocityUnits::pct);
        motor_brusher_right.spin(vex:directionType::bwd,brushing_speed,velocityUnits::pct);       
    }
    
    if((!controller1.ButtonR1.pressing())&&(!controller1.ButtonR2.pressing()))
    {
        stop_brusher_motor();
    }
} */
void catcher_part(){
  //CATCHING UP
    if(controller1.ButtonL1.pressing()){
        motor_riser_left.spin(vex::directionType::fwd,rising_speed,velocityUnits::pct);
        motor_riser_right.spin(vex::directionType::fwd,rising_speed,velocityUnits::pct);
    }
  //PUT IT DOWN
    if(controller1.ButtonL2.pressing()){
        motor_riser_left.spin(vex::directionType::bwd,rising_speed,velocityUnits::pct);
        motor_riser_right.spin(vex::directionType::bwd,rising_speed,velocityUnits::pct);
    }
  // if no 1-Button is pressed, just stop the motor  
    if((!controller1.ButtonL1.pressing())&&(!controller1.ButtonL2.pressing()))
    {
        stop_catcher_motor();
    }
    
}

void atonomous_section(){
    /*to do operations in the 45s-
    autonomous part of the game using 
       the sub-functions below*/
    
    
}


void moving_fwd(int speed,uint_32 t){
     motor_driver_Left1.spin(directionType::fwd,speed,velocityUnits::pct);
     motor_driver_Left2.spin(directionType::fwd,speed,velocityUnits::pct);
     motor_driver_Left3.spin(directionType::fwd,speed,velocityUnits::pct);
     motor_driver_Right1.spin(directionType::fwd,speed,velocityUnits::pct);
     motor_driver_Right2.spin(directionType::fwd,speed,velocityUnits::pct);
     motor_driver_Right3.spin(directionType::fwd,speed,velocityUnits::pct);
    
    vex::task::sleep(t);
    stop_driver_motor();
}

void moving_bwd(int speed,uint_32 t){
     motor_driver_Left1.spin(directionType::bwd,speed,velocityUnits::pct);
     motor_driver_Left2.spin(directionType::bwd,speed,velocityUnits::pct);
     motor_driver_Left3.spin(directionType::bwd,speed,velocityUnits::pct);
     motor_driver_Right1.spin(directionType::bwd,speed,velocityUnits::pct);
     motor_driver_Right2.spin(directionType::bwd,speed,velocityUnits::pct);
     motor_driver_Right3.spin(directionType::bwd,speed,velocityUnits::pct);
    
    vex::task::sleep(t);
    stop_driver_motor();
}

void turning_left(int speed,uint_32 t){
    motor_driver_Right1.spin(directionType::fwd,speed,velocityUnits::pct);
    motor_driver_Right2.spin(directionType::fwd,speed,velocityUnits::pct);
    motor_driver_Right3.spin(directionType::fwd,speed,velocityUnits::pct);
    motor_driver_Left1.spin(directionType::bwd,speed,velocityUnits::pct);
    motor_driver_Left2.spin(directionType::bwd,speed,velocityUnits::pct);
    motor_driver_Left3.spin(directionType::bwd,speed,velocityUnits::pct);

    vex::task::sleep(t);
    stop_driver_motor();
}

void turning_right(int speed,uint_32 t){
    motor_driver_Left1.spin(directionType::fwd,speed,velocityUnits::pct);
    motor_driver_Left2.spin(directionType::fwd,speed,velocityUnits::pct);
    motor_driver_Left3.spin(directionType::fwd,speed,velocityUnits::pct);
    motor_driver_Right1.spin(directionType::bwd,speed,velocityUnits::pct);
    motor_driver_Right2.spin(directionType::bwd,speed,velocityUnits::pct);
    motor_driver_Right3.spin(directionType::bwd,speed,velocityUnits::pct);

    vex::task::sleep(t);
    stop_driver_motor();
}

void brusher_up(int speed,uint_32 t){
    motor_brusher_left.spin(directionType::fwd,speed,velocityUnits::pct);
    motor_brusher_right.spin(directionType::fwd,speed,velocityUints::pct);
    
    vex::task::sleep(t);
    stop_brusher_motor();
}
void brusher_down(int speed,uint_32 t){
    motor_brusher_left.spin(directionType::bwd,speed,velocityUnits::pct);
    motor_brusher_right.spin(directionType::bwd,speed,velocityUints::pct);
    
    vex::task::sleep(t);
    stop_brusher_motor();
}
void catcher_up(int speed,uint_32 t){
    motor_riser_left.spin(directionType::fwd,speed,velocityUnits::pct);
    motor_riser_right.spin(directionType::fwd,speed,velocityUnits::pct);
    
    vex::task::sleep(t);
    stop_catcher_motor();
}
void catcher_down(int speed,uint_32 t){
    motor_brusher_left.spin(directionType::bwd,speed,velocityUnits::pct);
    motor_brusher_right.spin(directionType::bwd,speed,velocityUnits::pct);
    
    vex::task::sleep(t);
    stop_catcher_motor();
}


