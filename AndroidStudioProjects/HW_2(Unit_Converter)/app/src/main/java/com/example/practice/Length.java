package com.example.practice;

public class Length implements Strategy {

    public double Convert(String from, String to, double input) {

        if(from=="km" && to=="mile")
            return 0.62137*input;

        if(from=="mile" && to=="km")
            return 1.60934*input;

        if(from=="mile" && to=="m")
            return 1609.34*input;

        if(from=="m" && to=="mile")
            return input/1609.34;

        if(from=="mile" && to=="cm")
            return 160934*input;

        if(from=="cm" && to=="mile")
            return input/160934;

        if(from=="mile" && to=="mm")
            return input*1609340;

        if(from=="mm" && to=="mile")
            return input/1609340;

        if(from=="mile" && to=="inch")
            return 63360*input;

        if(from=="inch" && to=="mile")
            return input/63360;

        if(from=="mile" && to=="ft")
            return 5280*input;

        if(from=="ft" && to=="mile")
            return input/5280;

        if(from=="km" && to=="m")
            return input*1000;
        
        if(from=="m" && to=="km")
            return 0.001*input;


        if(from=="km" && to=="cm")
            return 100000*input;


        if(from=="cm" && to=="km")
            return input/100000;


        if(from=="km" && to=="mm")
            return 1000000*input;


        if(from=="mm" && to=="km")
            return input/1000000;


        if(from=="km" && to=="ft")
            return input*3280.84;


        if(from=="ft" && to=="km")
            return input/3280.84;


        if(from=="km" && to=="inch")
            return input*39370.1;


        if(from=="inch" && to=="km")
            return input/39370.1;


        if(from=="m" && to=="cm")
            return 100*input;


        if(from=="cm" && to=="m")
            return input/100;


        if(from=="m" && to=="mm")
            return 1000*input;


        if(from=="mm" && to=="m")
            return input/1000;


        if(from=="m" && to=="inch")
            return 100*input/2.54;


        if(from=="inch" && to=="m")
            return 2.54*input/100;


        if(from=="m" && to=="ft")
            return input*3.28084;


        if(from=="ft" && to=="m")
            return input/3.28084;


        if(from=="cm" && to=="mm")
            return 10*input;


        if(from=="mm" && to=="cm")
            return input/10;


        if(from=="inch" && to=="cm")
            return 2.54*input;


        if(from=="cm" && to=="inch")
            return input/2.54;


        if(from=="cm" && to=="ft")
            return input*0.03281;


        if(from=="ft" && to=="cm")
            return input*30.48;


        if(from=="mm" && to=="ft")
            return 0.00328*input;


        if(from=="ft" && to=="mm")
            return input*304.8;


        if(from=="mm" && to=="inch")
            return input/25.4;


        if(from=="inch" && to=="mm")
            return input*25.4;


        if(from=="ft" && to=="inch")
            return 12*input;


        if(from=="inch" && to=="ft")
            return input/12;

        if(from==to)
            return input;
        return 0.0;
    }
}



