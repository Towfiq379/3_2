package com.example.practice;

public class Volume implements Strategy {
    public double Convert(String from, String to, double input) {

        if(from=="litre" && to=="millilitre")
            return input*1000;
        if(from=="millilitre" && to=="litre")
            return input/1000;

        if(from=="litre" && to=="cubic m")
            return input*0.001;
        if(from=="cubic m" && to=="litre")
            return input*1000;

        if(from=="litre" && to=="cubic cm")
            return 1000*input;
        if(from=="cubic cm" && to=="litre")
            return 0.001*input;

        if(from=="litre" && to=="cubic mm")
            return input*1000000;
        if(from=="cubic mm" && to=="litre")
            return input/1000000;

        if(from=="litre" && to=="cubic feet")
            return input*0.03531;
        if(from=="cubic feet" && to=="litre")
            return input*28.31685;

        if(from=="cubic m" && to=="cubic cm")
            return input*100*100*100;
        if(from=="cubic cm" && to=="cubic m")
            return input/1000000;

        if(from=="cubic m" && to=="cubic mm")
            return input*1000*1000*1000;
        if(from=="cubic mm" && to=="cubic m")
            return input/(1000*1000*1000);

        if(from=="cubic m" && to=="millilitre")
            return input*1000000;
        if(from=="millilitre" && to=="cubic m")
            return input/1000000;

        if(from=="cubic m" && to=="cubic feet")
            return input*35.31467;
        if(from=="cubic feet" && to=="cubic m")
            return input/35.31467;

        if(from=="cubic cm" && to=="cubic mm")
            return input*1000;
        if(from=="cubic mm" && to=="cubic cm")
            return input/1000;

        if(from=="cubic cm" && to=="millilitre")
            return input;
        if(from=="millilitre" && to=="cubic cm")
            return input;

        if(from=="cubic cm" && to=="cubic feet")
            return input/28316.84659;
        if(from=="cubic feet" && to=="cubic cm")
            return input*28316.84659;

        if(from=="cubic mm" && to=="millilitre")
            return input*0.001;
        if(from=="millilitre" && to=="cubic mm")
            return input*1000;

        if(from=="cubic mm" && to=="cubic feet")
            return input/28316846.592;
        if(from=="cubic feet" && to=="cubic mm")
            return input*28316846.592;

        if(from=="cubic feet" && to=="millilitre")
            return input*28316.84659;
        if(from=="millilitre" && to=="cubic feet")
            return input/28316.84659;

        if(from==to)
            return input;
        return 0;
    }
}