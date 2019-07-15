void brusher_part(){ 
	if(controller1.Axis2.value()>15){
          motor_brusher_Left.spin(vex::directionType::fwd,brusher_func(controller1.Axis2.value()));
          motor_driver_Right.spin(vex::directionType::fwd,brusher_func(controller1.Axis2.value()));  
        
        }else if(controller1.Axis2.value()<-15){
          motor_brusher_Left.spin(vex::directionType::bwd,brusher_func(controller1.Axis2.value()));
          motor_driver_Right.spin(vex::directionType::bwd,brusher_func(controller1.Axis2.value()));  
            
        }else
			stop_brusher_motor();
}

//brusher_func is not compeleted

double brusher_func{
	double velocity;
	
	return velocity;
}