package com.example.practice;

public class Area implements Strategy {

    public double Convert(String from, String to, double input) {

        if(from=="square miles" && to=="square km")
            return 1.60934*1.60934*input;
        if(from=="square km" && to=="square miles")
            return 0.62137*0.62137*input;

        if(from=="square miles" && to=="square m")
            return 1609.34*1609.34*input;
        if(from=="square m" && to=="square miles")
            return input/(1609.34*1609.34);

        if(from=="square miles" && to=="square cm")
            return input*160934*160934;
        if(from=="square cm" && to=="square miles")
            return input/(160934*160934);

        if(from=="square miles" && to=="square mm")
            return input*1609340*input;
        if(from=="square mm" && to=="square miles")
            return input/(1609340*1609340);

        if(from=="square miles" && to=="square yards")
            return input*1760*1760;
        if(from=="square yards" && to=="square miles")
            return input/(1760*1760);

        if(from=="square km" && to=="square m")
            return input*1000*1000;
        if(from=="square m" && to=="square km")
            return input/(1000*1000);

        if(from=="square km" && to=="square cm")
            return input*100000*100000;
        if(from=="square cm" && to=="square km")
            return input/(100000*100000);

        if(from=="square km" && to=="square mm")
            return input*1000000*1000000;
        if(from=="square mm" && to=="square km")
            return input/(1000000*1000000);

        if(from=="square km" && to=="square yards")
            return 1093.6133*1093.6133*input;
        if(from=="square yards" && to=="square km")
            return input/(1093.6133*1093.6133);

        if(from=="square m" && to=="square cm")
            return input*100*100;
        if(from=="square cm" && to=="square m")
            return input/(100*100);

        if(from=="square m" && to=="square mm")
            return input*1000*1000;
        if(from=="square mm" && to=="square m")
            return input/(1000*1000);

        if(from=="square m" && to=="square yards")
            return 1.09361*1.09361*input;
        if(from=="square yards" && to=="square m")
            return input/(1.09361*1.09361);

        if(from=="square cm" && to=="square mm")
            return (input*10*10);
        if(from=="square mm" && to=="square cm")
            return input/(10*10);

        if(from=="square cm" && to=="square yards")
            return 0.01094*0.01094*input;
        if(from=="square yards" && to=="square cm")
            return input/(0.01094*0.01094);

        if(from=="square mm" && to=="square yards")
            return 0.001094*0.001094*input;
        if(from=="square yards" && to=="square mm")
            return input/(0.001094*0.001094);

        if(from==to)
            return input;
        return 0.0;
    }
}