void motor_rotate( double k){
    
    double now, after;
    now = motor1.rotation(vex::rotationUnits::deg);
    
    Brain.Screen.print(motor1.rotation(vex::rotationUnits::deg));
    Brain.Screen.newLine();
    
 if (k>0)
    motor1.rotateFor(vex::directionType::fwd,k,vex::rotationUnits::deg,50,vex::velocityUnits::pct);
 if (k<0)
    motor1.rotateFor(vex::directionType::rev,-k,vex::rotationUnits::deg,50,vex::velocityUnits::pct);
   
    Brain.Screen.print(motor1.rotation(vex::rotationUnits::deg));
    Brain.Screen.newLine();
    
    after = motor1.rotation(vex::rotationUnits::deg);
    
    double delta ;
    delta = after - now ;
    
    if (delta<=s&&delta>=-s)  {motor1.stop(); return ;}
    
    if (delta > s|| delta <-s){
        motor_rotate( k - delta );
    }
  
    
}
