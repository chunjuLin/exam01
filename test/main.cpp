#include "mbed.h"
#include "uLCD_4DGL.h"


uLCD_4DGL uLCD(D1, D0, D2);
DigitalIn down(D3);
DigitalIn up(D4);
DigitalIn selected(D5);

AnalogOut aout(PA_4);
AnalogIn ain(D6);

EventQueue queue(32 * EVENTS_EVENT_SIZE);


Thread thread;


float frequency = 4.166; 
int slew = 1; 
float blank = 100;
int pre_down;
int pre_up;
int done = 0;
float sample;
float ADCdata[5000];
int k = 0;



void wave(){
    float T = 0.24;
    float dt = 1000;
if(slew == 1){
       k = 0;
       while(k < 1000){
        for (float i = 0.00f; i <= 0.9f; i += 0.09f) {
                aout = i;          
                wait_us((int)dt); k++;
            }
            aout = 0.9f; wait_us((int)dt*220);
            for (float i = 0.9f; i >= 0.0f; i -= 0.09f) {
                aout = i;
                wait_us((int)dt); k++;
                //printf("Hi4\n");
            }
       }
       k = 0;
       while(k < 1000){
        for (float i = 0.00f; i <= 0.9f; i += 0.09f) {
                aout = i; 
                ADCdata[k] = aout; k++;        
                wait_us((int)dt); 
            }
        for (float i = 0; i < 220; i++){
            aout = 0.9f; 
            ADCdata[k] = aout; k++;
            wait_us((int)dt);
        }
            for (float i = 0.9f; i >= 0.0f; i -= 0.09f) {
                aout = i;
                ADCdata[k] = aout; k++;
                wait_us((int)dt); 
                //printf("Hi4\n");
            }
       }
    for (int i = 0; i < 1000; i++){
        printf("%f\r\n", ADCdata[i]);
    }
        while(1){
        for (float i = 0.00f; i <= 0.9f; i += 0.09f) {
                aout = i;          
                wait_us((int)dt); k++;
            }
            aout = 0.9f; wait_us((int)dt*220);
            for (float i = 0.9f; i >= 0.0f; i -= 0.09f) {
                aout = i;
                wait_us((int)dt); k++;
                //printf("Hi4\n");
            }
       }
   }
    else if(slew == 2){
       k = 0;
       while(k < 1000){
        for (float i = 0.00f; i <= 0.9f; i += 0.045f) {
                aout = i;          
                wait_us((int)dt); k++;
            }
            aout = 0.9f; wait_us((int)dt*200);
            for (float i = 0.9f; i >= 0.0f; i -= 0.045f) {
                aout = i;
                wait_us((int)dt); k++;
                //printf("Hi4\n");
            }
       }
       k = 0;
       while(k < 1000){
        for (float i = 0.00f; i <= 0.9f; i += 0.045f) {
                aout = i; 
                ADCdata[k] = aout; k++;        
                wait_us((int)dt); 
            }
        for (float i = 0; i < 200; i++){
            aout = 0.9f; 
            ADCdata[k] = aout; k++;
            wait_us((int)dt);
        }
            for (float i = 0.9f; i >= 0.0f; i -= 0.045f) {
                aout = i;
                ADCdata[k] = aout; k++;
                wait_us((int)dt); 
                //printf("Hi4\n");
            }
       }
    for (int i = 0; i < 1000; i++){
        printf("%f\r\n", ADCdata[i]);
    }
        while(1){
        for (float i = 0.00f; i <= 0.9f; i += 0.045f) {
                aout = i;          
                wait_us((int)dt); k++;
            }
            aout = 0.9f; wait_us((int)dt*200);
            for (float i = 0.9f; i >= 0.0f; i -= 0.045f) {
                aout = i;
                wait_us((int)dt); k++;
                //printf("Hi4\n");
            }
       }
   }
    else if(slew == 3){
       k = 0;
       while(k < 1000){
        for (float i = 0.00f; i <= 0.9f; i += 0.0225f) {
                aout = i;          
                wait_us((int)dt); k++;
            }
            aout = 0.9f; wait_us((int)dt*160);
            for (float i = 0.9f; i >= 0.0f; i -= 0.0225f) {
                aout = i;
                wait_us((int)dt); k++;
                //printf("Hi4\n");
            }
       }
       k = 0;
       while(k < 1000){
        for (float i = 0.00f; i <= 0.9f; i += 0.0225f) {
                aout = i; 
                ADCdata[k] = aout; k++;        
                wait_us((int)dt); 
            }
        for (float i = 0; i < 160; i++){
            aout = 0.9f; 
            ADCdata[k] = aout; k++;
            wait_us((int)dt);
        }
            for (float i = 0.9f; i >= 0.0f; i -= 0.0225f) {
                aout = i;
                ADCdata[k] = aout; k++;
                wait_us((int)dt); 
                //printf("Hi4\n");
            }
       }
    for (int i = 0; i < 1000; i++){
        printf("%f\r\n", ADCdata[i]);
    }
        while(1){
        for (float i = 0.00f; i <= 0.9f; i += 0.0225f) {
                aout = i;          
                wait_us((int)dt); k++;
            }
            aout = 0.9f; wait_us((int)dt*160);
            for (float i = 0.9f; i >= 0.0f; i -= 0.0225f) {
                aout = i;
                wait_us((int)dt); k++;
                //printf("Hi4\n");
            }
       }
   }
    else if(slew == 4){
       k = 0;
       while(k < 1000){
        for (float i = 0.00f; i <= 0.9f; i += 0.01125f) {
                aout = i;          
                wait_us((int)dt); k++;
            }
            aout = 0.9f; wait_us((int)dt*80);
            for (float i = 0.9f; i >= 0.0f; i -= 0.01125f) {
                aout = i;
                wait_us((int)dt); k++;
                //printf("Hi4\n");
            }
       }
       k = 0;
       while(k < 1000){
        for (float i = 0.00f; i <= 0.9f; i += 0.01125f) {
                aout = i; 
                ADCdata[k] = aout; k++;        
                wait_us((int)dt); 
            }
        for (float i = 0; i < 80; i++){
            aout = 0.9f; 
            ADCdata[k] = aout; k++;
            wait_us((int)dt);
        }
            for (float i = 0.9f; i >= 0.0f; i -= 0.01125f) {
                aout = i;
                ADCdata[k] = aout; k++;
                wait_us((int)dt); 
                //printf("Hi4\n");
            }
       }
    for (int i = 0; i < 1000; i++){
        printf("%f\r\n", ADCdata[i]);
    }
        while(1){
        for (float i = 0.00f; i <= 0.9f; i += 0.01125f) {
                aout = i;          
                wait_us((int)dt); k++;
            }
            aout = 0.9f; wait_us((int)dt*80);
            for (float i = 0.9f; i >= 0.0f; i -= 0.01125f) {
                aout = i;
                wait_us((int)dt); k++;
                //printf("Hi4\n");
            }
       }
    }
}

int main()
{

    // uLCD.line(29, 55, 99, 55, WHITE);
    // uLCD.line(29, 73, 99, 73, WHITE);
    // uLCD.line(29, 55, 29, 73, WHITE);
    // uLCD.line(99, 55, 99, 73, WHITE);

   while (done == 0)
   {
        if(selected.read() == 1) done = 1;
        if(done == 0){
            if(pre_down != down.read() && down.read() == 1){
                if(slew > 1){
                    slew -= 1;
                   // blank -= 100;
                }
            } 
            else if(pre_up != up.read() && up.read() == 1){
                if(slew < 4){
                    slew += 1;
                   // blank += 100;
                }
            }
            pre_down = down.read();
            pre_up = up.read();
        }
        switch(slew){
            case 1:  uLCD.locate(4,5); uLCD.printf(" 1/8 "); break;
            case 2:  uLCD.locate(4,5); uLCD.printf(" 1/4 "); break;
            case 3:  uLCD.locate(4,5); uLCD.printf(" 1/2 "); break;
            default:  uLCD.locate(4,5); uLCD.printf("   1"); break;
        }
        //uLCD.locate(4,5); uLCD.printf("%d  Hz",(int)frequency);

        // uLCD.filled_rectangle(30, 56, 30 + (blank)/10 - 1, 72, 0x00FF00);
        // if(frequency != 130)uLCD.filled_rectangle(30 + (blank)/10, 56, 98, 72, BLACK);
        // uLCD.line(99, 55, 99, 73, WHITE);
   }

    //printf("%d\n",4.166*240);
    thread.start(callback(&queue, &EventQueue::dispatch_forever));
    queue.call(wave);
   

}