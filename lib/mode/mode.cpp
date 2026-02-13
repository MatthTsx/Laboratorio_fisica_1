#include <mode.h>

void mode0(mpu_sensor& mpu, led_strip& pixels, ball_class& ball) {
    //This mode is the main mode. it is basically the ball

    //get data from the sensor
    sensors_event_t acc, gyro, temp;
    if(!mpu.getEvent(&acc, &gyro, &temp)) {
    Serial.println("uncessefull reading");
    }


    //atualize the ball position
    ball.atualize(acc.acceleration.y);

    //get the led referent to the current position and light it
    show_unique_led(position_to_led(ball.get_position()), pixels);

}
void mode1(mpu_sensor& mpu, led_strip& pixels, ball_class& ball) {
    //This mode is the second main mode, it is basically the ball, but as a bubble.

    //get data from the sensor
    sensors_event_t acc, gyro, temp;
    if(!mpu.getEvent(&acc, &gyro, &temp)) {
    Serial.println("uncessefull reading");
    }


    //atualize the ball position
    ball.atualize(-acc.acceleration.y);

    //get the led referent to the current position and light it
    show_unique_led(position_to_led(ball.get_position()), pixels);
}
void mode2(){
    //This mode should be the collision
}
void mode3(){
    //This mode should be all the balls (just the led strip fully colored)
}