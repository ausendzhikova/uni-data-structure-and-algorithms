#include <iostream>
#include <cmath>
using namespace std;




unsigned long long exactCube(unsigned long long num) {
    unsigned long long i = 1;
    unsigned long long cube = i*i*i;
    while (cube <= num) {
        i++;
        cube = i*i*i;
    }
    return i-1;
}

unsigned long long giftCount(unsigned long long point) {
    static unsigned long long count = 0;
    if (point == 0) {
        return count;
    }
    count++;
    unsigned long long price = exactCube(point);
    point -= price*price*price;
    giftCount(point);
    return count;

}

int main() {
    unsigned long long MimiPoint;
    cin >> MimiPoint;
    cout << giftCount(MimiPoint) << endl;

    return 0;
}