package com.example.practice;

public class Power implements Strategy {

    public double Convert(String from, String to, double input) {

        if(from=="watts" && to=="horsepower")
            return 0.00134*input;
        if(from=="horsepower" && to=="watts")
            return 745.7*input;

        if(from=="watts" && to=="killowatts")
            return input/1000;
        if(from=="killowatts" && to=="watts")
            return input*1000;

        if(from=="killowatts" && to=="horsepower")
            return input*1.34102;
        if(from=="horsepower" && to=="killowatts")
            return input*0.7457;

        if(from==to)
            return input;
        return 0.0;
    }
}
