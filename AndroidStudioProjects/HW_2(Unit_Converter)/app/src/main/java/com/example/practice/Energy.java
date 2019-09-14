package com.example.practice;

public class Energy implements Strategy {

    public double Convert(String from, String to, double input) {

        if(from=="calories" && to=="kilocalories")
            return input/1000;
        if(from=="kilocalories" && to=="calories")
            return input*1000;

        if(from=="calories" && to=="joules")
            return input*4.1868;
        if(from=="joules" && to=="calories")
            return input*0.23885;

        if(from=="kilocalories" && to=="joules")
            return input*4186.8;
        if(from=="joules" && to=="kilocalories")
            return input/4186.8;

        if(from==to)
            return input;
        return 0.0;
    }
}

