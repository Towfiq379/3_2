package com.example.practice;

public class Velocity implements Strategy {
    public double Convert(String from, String to, double input) {

        if(from=="miles/hr" && to=="Km/hr")
            return input*1.60934;
        if(from=="Km/hr" && to=="miles/hr")
            return input*0.62137;

        if(from=="miles/hr" && to=="m/s")
            return input*1609.34/3600;
        if(from=="m/s" && to=="miles/hr")
            return input*3600/1609.34;

        if(from=="miles/hr" && to=="feet/s")
            return input*5280/3600;
        if(from=="feet/s" && to=="miles/hr")
            return input*3600/5280;

        if(from=="Km/hr" && to=="m/s")
            return input*1000/3600;
        if(from=="m/s" && to=="Km/hr")
            return input*3600/1000;

        if(from=="Km/hr" && to=="feet/s")
            return input*3280.84/3600;
        if(from=="feet/s" && to=="Km/hr")
            return input*3600/3280.84;

        if(from=="m/s" && to=="feet/s")
            return input*3.28084;
        if(from=="feet/s" && to=="m/s")
            return input/3.28084;

        if(from==to)
            return input;
        return 0;
    }
}

