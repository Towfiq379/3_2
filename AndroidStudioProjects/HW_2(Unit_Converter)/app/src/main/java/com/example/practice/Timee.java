package com.example.practice;

public class Timee implements Strategy {
    @Override
    public double Convert(String from, String to, double input) {
        if(from=="sec" && to=="min")
            return input/60;
        if(from=="sec" && to=="hour")
            return input/3600;
        if(from=="sec" && to=="day")
            return input/86400;

        if(from=="min" && to=="sec")
            return input*60;
        if(from=="min" && to=="hour")
            return input/60;
        if(from=="min" && to=="day")
            return input/1440;

        if(from=="hour" && to=="sec")
            return input*3600;
        if(from=="hour" && to=="min")
            return input*60;
        if(from=="hour" && to=="day")
            return input/24;

        if(from=="day" && to=="sec")
            return input/86400;
        if(from=="day" && to=="min")
            return input*1440;
        if(from=="day" && to=="hour")
            return input*24;

        if(from==to)
            return input;
        return 0;
    }
}
