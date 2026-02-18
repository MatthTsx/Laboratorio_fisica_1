#include <prot.h>

int position_to_led(float position) {
    //given the position of the ball, it finds the led correspondent to it
    float ratio = position/BAR_SIZE;
    int led = floor(ratio*NUM_LEDS);
    if(led > 59) led = 59;
    if(led < 0) led = 0;
    return led;
}

bool initialize_mpu(mpu_sensor& mpu){
    //returns true if initializations was successfull and false if not
    if(mpu.begin() == false) return false;
    mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
    mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);
    return true;
}

bool initialize_leds(led_strip& pixels){
    //returns true if initializations was successfull and false if not
    pixels.begin();
    pixels.clear();
    pixels.show();
    return true;
}

bool initialize_serial(HardwareSerial& serial){
    //returns true if initializations was successfull and false if not
    serial.begin(115200);
    return true;
}

void button_class::atualize() {
    int read = analogRead(BUTTON_PIN);
    if(read < TOLERANCE_ANALOG_READ) {
        if(prev == 0) cnt++;
        prev = 1;
    } else {
        prev = 0;
    }
    delay(DELAY);
}

int button_class::get_mode() {
    return cnt = cnt%NUM_MODES;
}

void button_class::initialize() {
    cnt = 0, prev = 0;
    pinMode(BUTTON_PIN, INPUT_PULLUP);
}

void show_unique_led(int led, led_strip& strip, long long color) {
    //sets the value of a single led and show it
    strip.clear();
    strip.setPixelColor(led, color);
    strip.show();
}


void show_two_leds(led_strip& strip, int led1,  long long color1, int led2,  long long color2) {
    strip.clear();
    strip.setPixelColor(led1, color1);
    strip.setPixelColor(led2, color2);
    strip.show();
}