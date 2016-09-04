#include <iostream>
#include <wiringPi.h>

#define GPIO18 18

using namespace std;

int main()
{
    if(wiringPiSetupGpio() == -1) {
        cout << "cannot setup gpio." << endl;
        return 1;
    }

    pinMode(GPIO18, PWM_OUTPUT);
    pwmSetMode(PWM_MODE_MS);
    pwmSetClock(192);
    pwmSetRange(250000);

    cout << "50~250 the input" << endl;
    cout << "-1 the stop" << endl;

    while(true){
        int num;
        cin >> num;

        if(num == -1)
            break;

        if(num < 50)
            num = 50;
        if(num > 250)
            num = 250;

        pwmWrite(GPIO18, num);
    }

    return 0;
}


