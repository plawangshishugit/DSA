class Solution {
public:
    double angleClock(int hour, int minutes) {
        double hr = 0;
        hr = hour * 30 % 360 ;
        double min = 0;
        min = double(minutes * 6);
        hr = hr + double(minutes * 0.5);
        double res = abs(min - hr);
        if(res >= 180){
            res = 360-res;
        }
        return res;
    }
};