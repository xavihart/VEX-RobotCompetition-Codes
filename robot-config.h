using namespace vex;
vex::brain Brain;

vex::motor motor_driver_Left1(vex::PORT1,vex::gearSetting::ratio18_1,false);
vex::motor motor_driver_Left2(vex::PORT2,vex::gearSetting::ratio18_1,false);
vex::motor motor_driver_Left3(vex::PORT3,vex::gearSetting::ratio18_1,false);
vex::motor motor_driver_Right1(vex::PORT4,vex::gearSetting::ratio18_1,false);
vex::motor motor_driver_Right2(vex::PORT5,vex::gearSetting::ratio18_1,false);
vex::motor motor_driver_Right3(vex::PORT6,vex::gearSetting::ratio18_1,false);

vex::controller controller1 controller1 = vex::controller();

vex::motor motor_brusher_left(vex::PORT8,vex::gearSetting::ratio18_1,false);
vex::motor motor_brusher_right(vex::PORT9,vex::gearSetting::ratio18_1,false);

vex::motor motor_brusher_left(vex::PORT10,vex::gearSetting::ratio18_1,false);
vex::motor motor_brusher_right(vex::PORT11,vex::gearSetting::ratio18_1,false);

vex::motor motor_riser_left(vex::PORT11,vex::gearSetting::ratio18_1,false);
vex::motor motor_riser_right(vex::PORT12,vex::gearSetting::ratio18_1,false);

