#include "robot-config.h"
#include <cmath>
//----------------------------------------------------------------//
//vex::competition    Competition;

/*---------------------Introdcutions of controller----------------
   AXIS3 : the forward and backword move of the model, the speed 
is determined by the exact position of the axis;
   AXIS4 : turn left and right
   ButtonL1:  make the catcher move up
   ButtonL2:  make the catcher move down 
   ButtonUp:  make the brusher rotate clockwise
   ButtonDown:  make the brusher rotate counter clockwise
---------------------------------------------------------------**/ 


//----value for modification-------//
const int turning_speed = 55;
const int rising_speed = 40;
const int low_speed = 45;
const int low_turning_speed = 30; //20
const int brushing_speed = 100;
const int turning_time = 1280;
const int low_rising_speed  = 20;
//------shift gear-----------------//
bool move_flag = true;
vex::competition Competition;




//------declaration of functions for the autonoumous section------------//

  // autonomous_section actually is the combination of these sub-function:
  /* In the end of each function below we add a stop function to the certain gear, 
  that is to say,the function(operation)is set to run a finite distance */
  void usercontrol();
  void moving_fwd(int ,int  ); 
  void moving_bwd(int,int  );
  void turning_left(int,int );
  void turning_right(int,int );
  void brusher_up(int,int );
  void brusher_down(int,int );
  void catcher_up(int,int );
  void catcher_down(int,int ); 
void putup(int, int, int, int);
void putdown(int, int, int, int);
void fetchup(int, int, int, int);
void fetchdown(int, int, int, int);
//---------------------------------------------------------------------//
//  automonmous part 
void autonomous(){
  /*moving_fwd(60, 290);
    catcher_up(15, 600);
    moving_fwd(60, 650);
    
    fetchup(35, 70, 1300, 1500);
    catcher_up(30,700);
	moving_fwd(60,760);
    
    turning_left(80, 770);
    
    moving_fwd(60, 970);
    
    moving_fwd(60,550);
    
    fetchup(35, 70, 1300, 1800);
    catcher_up(30,600);
    turning_left(50,600);
   
    
    
    moving_fwd(85,1800);
    fetchdown(25, 50, 1500, 2000);
    
    moving_bwd(90,1600);*/
    
    moving_fwd(60, 210);
    catcher_up(15, 600);
    moving_fwd(60, 700);
    
    fetchup(35, 70, 1300, 1500);
    catcher_up(30,700);
	moving_fwd(60,750);
    
    turning_left(80, 780);
    
    moving_fwd(60, 1500);
    
    //moving_fwd(60,650);
    
    fetchup(40, 70, 1300, 1800); //35
    catcher_up(30,600);
    turning_left(50,600);
   
    
    
    moving_fwd(85,1800);
    fetchdown(25, 75, 1500, 2000);
    
    moving_bwd(90,1600);
    
  
};

void autonomous_section2(){
    
  /* moving_fwd(60, 280);
    catcher_up(15, 800);
    moving_fwd(60, 655);
    
    fetchup(40, 70, 1000, 1500);
	moving_fwd(60,760);
    catcher_up(30,650);
    turning_right(50, turning_time);
    
    moving_fwd(60, 950);
    
    moving_fwd(60,450);
    
    fetchup(40, 70, 1400, 1500);
    catcher_up(30,600);
    turning_right(50,600);
    
    moving_fwd(70,2000);
    putdown(30,40,1000,1500);
    fetchdown(40,30,1000,1500);
    
    moving_bwd(70,1600);
    
    
    moving_fwd(60, 280);
    catcher_up(15, 800);
    moving_fwd(60, 655);
    
    fetchup(30, 70, 1000, 1500);
	moving_fwd(60,760);
    catcher_up(30,650);
    turning_right(50, turning_time);
    
    moving_fwd(60, 950);
    
    moving_fwd(60,450);
    
    fetchup(30, 70, 1400, 1500);
    catcher_up(30,600);
    turning_left(50,600);
    
    
    
    moving_fwd(70,2000);
    //putdown(30,40,1000,1500);
    fetchdown(40,30,1000,1500);
    
    moving_bwd(70,1600); */
    
    moving_fwd(60, 210);
    catcher_up(15, 600);
    moving_fwd(60, 700);
    
    fetchup(35, 70, 1300, 1500);
    catcher_up(30,700);
	moving_fwd(60,750);
    
    turning_right(80, 780);
    
    moving_fwd(60, 1500);
    
    //moving_fwd(60,650);
    
    fetchup(40, 70, 1300, 1800); //35
    catcher_up(30,600);
    turning_right(50,600);
   
    
    
    moving_fwd(85,1800);
    fetchdown(25, 75, 1500, 2000);
    
    moving_bwd(90,1600);
    
    
    
   
}








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
  motor_riser_left.stop( vex::brakeType::hold);
  motor_riser_right.stop( vex::brakeType::hold);
}

void gearshift(){
	move_flag = controller1.ButtonR1.pressing()?false:true;
}



//-----------------------------------------------------//

  void pre_auto(void){
      
  }


int main(){
 //turning_left(80,750);
    // autonomous_section1();
   Competition.autonomous(autonomous);
    Competition.drivercontrol(usercontrol);
    pre_auto();
    while(1){
        vex::task::sleep(100);
    }
    
   /* while(1){   
	   gearshift();
       moving_part();
       turning_part();
       brusher_part();
       catcher_part();
        
       vex::task::sleep(10);
    }*/
  
}








int func(int a){
    return a+3;
}

int func2(int a){
    return -a+3; //73
}

/* int move_func(int a){
    return a + 23;
}

int move_func2(int a){
    return -a + 23;
} */

int raiser_func(int a){
    return int(sqrt(a)*4);
}

int raiser_func2(int a){
    return int(sqrt(-a)*4);
}



void moving_part(){
    
     if(controller1.Axis3.value()>15){
         
          motor_driver_Left1.spin(vex::directionType::rev,move_flag?low_speed:func(controller1.Axis3.value()),velocityUnits::rpm);
         motor_driver_Left2.spin(vex::directionType::fwd,move_flag?low_speed:func(controller1.Axis3.value()),velocityUnits::rpm);
         motor_driver_Left3.spin(vex::directionType::rev,move_flag?low_speed:func(controller1.Axis3.value()),velocityUnits::rpm);
          motor_driver_Right1.spin(vex::directionType::fwd,move_flag?low_speed:func(controller1.Axis3.value()),velocityUnits::rpm);
          motor_driver_Right2.spin(vex::directionType::rev,move_flag?low_speed:func(controller1.Axis3.value()),velocityUnits::rpm);
         motor_driver_Right3.spin(vex::directionType::fwd,move_flag?low_speed:func(controller1.Axis3.value()),velocityUnits::rpm);  
        
        }else if(controller1.Axis3.value()<-15){
            
          motor_driver_Left1.spin(vex::directionType::fwd,move_flag?low_speed:func2(controller1.Axis3.value()),velocityUnits::rpm);
         motor_driver_Left2.spin(vex::directionType::rev,move_flag?low_speed:func2(controller1.Axis3.value()),velocityUnits::rpm);
          motor_driver_Left3.spin(vex::directionType::fwd,move_flag?low_speed:func2(controller1.Axis3.value()),velocityUnits::rpm);
          motor_driver_Right1.spin(vex::directionType::rev,move_flag?low_speed:func2(controller1.Axis3.value()),velocityUnits::rpm);
          motor_driver_Right2.spin(vex::directionType::fwd,move_flag?low_speed:func2(controller1.Axis3.value()),velocityUnits::rpm);
          motor_driver_Right3.spin(vex::directionType::rev,move_flag?low_speed:func2(controller1.Axis3.value()),velocityUnits::rpm);  
            
        }else{
         stop_driver_motor();}    
               
        
}

void turning_part(){
    
     //turn left and right,the deg of turning is decided by the operator
    
          if(controller1.Axis4.value()>125){
              motor_driver_Right1.spin(vex::directionType::rev,move_flag?low_turning_speed:turning_speed,velocityUnits::pct);
              motor_driver_Right2.spin(vex::directionType::fwd,move_flag?low_turning_speed:turning_speed,velocityUnits::pct);
              motor_driver_Right3.spin(vex::directionType::rev,move_flag?low_turning_speed:turning_speed,velocityUnits::pct); 
              motor_driver_Left1.spin(vex::directionType::rev,move_flag?low_turning_speed:turning_speed,velocityUnits::pct);
              motor_driver_Left2.spin(vex::directionType::fwd,move_flag?low_turning_speed:turning_speed,velocityUnits::pct);
              motor_driver_Left3.spin(vex::directionType::rev,move_flag?low_turning_speed:turning_speed,velocityUnits::pct); 
              
          }
         else if(controller1.Axis4.value()<-126){
              motor_driver_Left1.spin(vex::directionType::fwd,move_flag?low_turning_speed:turning_speed,velocityUnits::pct);
              motor_driver_Left2.spin(vex::directionType::rev,move_flag?low_turning_speed:turning_speed,velocityUnits::pct);
              motor_driver_Left3.spin(vex::directionType::fwd,move_flag?low_turning_speed:turning_speed,velocityUnits::pct); 
             motor_driver_Right1.spin(vex::directionType::fwd,move_flag?low_turning_speed:turning_speed,velocityUnits::pct);
              motor_driver_Right2.spin(vex::directionType::rev,move_flag?low_turning_speed:turning_speed,velocityUnits::pct);
              motor_driver_Right3.spin(vex::directionType::fwd,move_flag?low_turning_speed:turning_speed,velocityUnits::pct);
          }else{
              if (controller1.Axis3.value()>-15 && controller1.Axis3.value()<15)
                  
                 stop_driver_motor();
          }
}



void brusher_part(){
    
    if(controller1.ButtonUp.pressing()){
        motor_brusher_left.spin(vex::directionType::rev,brushing_speed,velocityUnits::pct);
        motor_brusher_right.spin(vex::directionType::fwd,brushing_speed,velocityUnits::pct);       
    }
    
    else if(controller1.ButtonDown.pressing()){
        motor_brusher_left.spin(vex::directionType::fwd,brushing_speed,velocityUnits::pct);
        motor_brusher_right.spin(vex::directionType::rev,brushing_speed,velocityUnits::pct);       
    }
    
	else
    {  
        stop_brusher_motor();
    }
}
void catcher_part(){
  //CATCHING DOWN
    if(controller1.Axis2.value()<-35){
        motor_riser_left.spin(vex::directionType::rev,rising_speed,velocityUnits::rpm);
        motor_riser_right.spin(vex::directionType::fwd,rising_speed,velocityUnits::rpm);
    }
  //PUT IT UP
    else if(controller1.Axis2.value()>35){
        motor_riser_left.spin(vex::directionType::fwd,rising_speed,velocityUnits::rpm);
        motor_riser_right.spin(vex::directionType::rev,rising_speed,velocityUnits::rpm);
    }
  // if no 1-Button is pressed, just stop the motor  
    /* if((!controller1.ButtonL1.pressing())&&(!controller1.ButtonL2.pressing())) */
    else if(controller1.ButtonX.pressing()){
        motor_riser_left.spin(vex::directionType::fwd,low_rising_speed,velocityUnits::rpm);
        motor_riser_right.spin(vex::directionType::rev,low_rising_speed,velocityUnits::rpm);
    }
    else if(controller1.ButtonB.pressing()){
        motor_riser_left.spin(vex::directionType::rev,low_rising_speed,velocityUnits::rpm);
        motor_riser_right.spin(vex::directionType::fwd,low_rising_speed,velocityUnits::rpm);
    }
    
    
	else
    {  
        stop_catcher_motor();
    }
    
}

void usercontrol(){
	while(1){   
	   gearshift();
       moving_part();
       turning_part();
       brusher_part();
       catcher_part();
        
       vex::task::sleep(10);
    }
}



void moving_fwd(int speed,int t){
     motor_driver_Left1.spin(vex::directionType::rev,speed,velocityUnits::pct);
     motor_driver_Left2.spin(vex::directionType::fwd,speed,velocityUnits::pct);
     motor_driver_Left3.spin(vex::directionType::rev,speed,velocityUnits::pct);
     motor_driver_Right1.spin(vex::directionType::fwd,speed,velocityUnits::pct);
     motor_driver_Right2.spin(vex::directionType::rev,speed,velocityUnits::pct);
     motor_driver_Right3.spin(vex::directionType::fwd,speed,velocityUnits::pct);
    
    vex::task::sleep(t);
    stop_driver_motor();
}

void moving_bwd(int speed,int t){
     motor_driver_Left1.spin(vex::directionType::fwd,speed,velocityUnits::pct);
     motor_driver_Left2.spin(vex::directionType::rev,speed,velocityUnits::pct);
     motor_driver_Left3.spin(vex::directionType::fwd,speed,velocityUnits::pct);
     motor_driver_Right1.spin(vex::directionType::rev,speed,velocityUnits::pct);
     motor_driver_Right2.spin(vex::directionType::fwd,speed,velocityUnits::pct);
     motor_driver_Right3.spin(vex::directionType::rev,speed,velocityUnits::pct);
    
    vex::task::sleep(t);
    stop_driver_motor();
}

void turning_right(int speed,int t){
	motor_driver_Left1.spin(vex::directionType::rev,speed,velocityUnits::pct);
	motor_driver_Left2.spin(vex::directionType::fwd,speed,velocityUnits::pct);
	motor_driver_Left3.spin(vex::directionType::rev,speed,velocityUnits::pct);
    motor_driver_Right1.spin(vex::directionType::rev,speed,velocityUnits::pct);
    motor_driver_Right2.spin(vex::directionType::fwd,speed,velocityUnits::pct);
    motor_driver_Right3.spin(vex::directionType::rev,speed,velocityUnits::pct);
    
    vex::task::sleep(t);
    stop_driver_motor();
}

void turning_left(int speed,int t){
    motor_driver_Left1.spin(vex::directionType::fwd,speed,velocityUnits::pct);
    motor_driver_Left2.spin(vex::directionType::rev,speed,velocityUnits::pct);
    motor_driver_Left3.spin(vex::directionType::fwd,speed,velocityUnits::pct);
    motor_driver_Right1.spin(vex::directionType::fwd,speed,velocityUnits::pct);
    motor_driver_Right2.spin(vex::directionType::rev,speed,velocityUnits::pct);
    motor_driver_Right3.spin(vex::directionType::fwd,speed,velocityUnits::pct);
    vex::task::sleep(t);
    stop_driver_motor();
}

void brusher_up(int speed,int t){
    motor_brusher_left.spin(vex::directionType::rev,speed,velocityUnits::pct);
    motor_brusher_right.spin(vex::directionType::fwd,speed,velocityUnits::pct);
    
    vex::task::sleep(t);
    stop_brusher_motor();
}
void brusher_down(int speed,int t){
    motor_brusher_left.spin(vex::directionType::fwd,speed,velocityUnits::pct);
    motor_brusher_right.spin(vex::directionType::rev,speed,velocityUnits::pct);
    
    vex::task::sleep(t);
    stop_brusher_motor();
}
void catcher_up(int speed,int t ){
    motor_riser_left.spin(vex::directionType::fwd,speed,velocityUnits::pct);
    motor_riser_right.spin(vex::directionType::rev,speed,velocityUnits::pct);
    
    vex::task::sleep(t);
    stop_catcher_motor();
}
void catcher_down(int speed,int t){
    motor_brusher_left.spin(vex::directionType::rev,speed,velocityUnits::pct);
    motor_brusher_right.spin(vex::directionType::fwd,speed,velocityUnits::pct);
    
    vex::task::sleep(t);
    stop_catcher_motor();
}

void putup(int catchspeed, int brushspeed,int catcht, int t){
	motor_brusher_left.spin(vex::directionType::rev,brushspeed,velocityUnits::pct);
    motor_brusher_right.spin(vex::directionType::fwd,brushspeed,velocityUnits::pct);
    vex::task::sleep(10);
	motor_riser_left.spin(vex::directionType::fwd,catchspeed,velocityUnits::pct);
    motor_riser_right.spin(vex::directionType::rev,catchspeed,velocityUnits::pct);
	vex::task::sleep(catcht);
    stop_catcher_motor();
    vex::task::sleep(t-catcht);
	stop_brusher_motor();
}

void  putdown(int catchspeed, int brushspeed,int catcht, int t){
	motor_brusher_left.spin(vex::directionType::fwd,brushspeed,velocityUnits::pct);
    motor_brusher_right.spin(vex::directionType::rev,brushspeed,velocityUnits::pct);
    vex::task::sleep(10);
	motor_riser_left.spin(vex::directionType::rev,catchspeed,velocityUnits::pct);
    motor_riser_right.spin(vex::directionType::fwd,catchspeed,velocityUnits::pct);
	vex::task::sleep(catcht);
    stop_catcher_motor();
    motor_riser_left.spin(vex::directionType::fwd,catchspeed,velocityUnits::pct);
    motor_riser_right.spin(vex::directionType::rev,catchspeed,velocityUnits::pct);
	vex::task::sleep(t-catcht);
	stop_brusher_motor();
    stop_catcher_motor();
}

void fetchup(int catchspeed, int brushspeed, int catcht, int t){
    
    
    motor_brusher_right.spin(vex::directionType::fwd,brushspeed,velocityUnits::pct);
    motor_brusher_left.spin(vex::directionType::rev,brushspeed,velocityUnits::pct);
    vex::task::sleep(10);
    motor_riser_left.spin(vex::directionType::rev,catchspeed,velocityUnits::pct);
    motor_riser_right.spin(vex::directionType::fwd,catchspeed,velocityUnits::pct);
    vex::task::sleep(catcht);
    stop_catcher_motor();
   //motor_riser_left.spin(vex::directionType::fwd,catchspeed,velocityUnits::pct);
   // motor_riser_right.spin(vex::directionType::rev,catchspeed,velocityUnits::pct);
	vex::task::sleep(t-catcht);
	stop_brusher_motor();
   // stop_catcher_motor();
}

void fetchdown(int catchspeed, int brushspeed, int catcht, int t){
    motor_brusher_left.spin(vex::directionType::fwd,brushspeed,velocityUnits::pct);
    motor_brusher_right.spin(vex::directionType::rev,brushspeed,velocityUnits::pct);
    vex::task::sleep(10);
   // motor_riser_left.spin(vex::directionType::rev,catchspeed,velocityUnits::pct);
    //motor_riser_right.spin(vex::directionType::fwd,catchspeed,velocityUnits::pct);
    vex::task::sleep(catcht);
    //stop_catcher_motor();
    motor_riser_left.spin(vex::directionType::fwd,catchspeed,velocityUnits::pct);
    motor_riser_right.spin(vex::directionType::rev,catchspeed,velocityUnits::pct);
	vex::task::sleep(t-catcht);
	stop_brusher_motor();
    stop_catcher_motor();
}
