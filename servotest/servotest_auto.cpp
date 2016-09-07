#include <iostream>
#include <wiringPi.h>
#include <unistd.h>

#define GPIO18 18

using namespace std;

int main()
{
    int num = 50;

    if(wiringPiSetupGpio() == -1) {
        cout << "cannot setup gpio." << endl;
        return 1;
    }

    pinMode(GPIO18, PWM_OUTPUT);
    pwmSetMode(PWM_MODE_MS);
    pwmSetClock(192);
    pwmSetRange(250000);

    cout << "Raise between 50 and 250 by 10." << endl;

    while(num < 250){
        cout << num << endl;
        pwmWrite(GPIO18, num);
        num += 10;
        sleep(2);
    }

    pwmWrite(GPIO18, 50);

    return 0;
}


