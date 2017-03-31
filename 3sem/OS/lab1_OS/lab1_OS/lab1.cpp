// simple sounds via Beep(frequency_hrz, duration_ms)
#include <iostream>
#include <windows.h>   // WinApi header

using namespace std;

int main() {
    Beep(200, 300);  // 523 hertz (C5) for 500 milliseconds


    cin.get(); // wait
    return 0;
}