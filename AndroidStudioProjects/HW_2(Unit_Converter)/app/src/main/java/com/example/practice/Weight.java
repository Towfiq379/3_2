package com.example.practice;

public class Weight implements Strategy {

    public double Convert(String from, String to, double input) {

        if(from=="Kg" && to=="gm")
            return (double)(1000*input);
        if(from=="gm" && to=="Kg")
            return (double)(input/1000);

        if(from=="Kg" && to=="lb")
            return 2.2046*input;
        if(from=="lb" && to=="Kg")
            return 0.454*input;

        if(from=="Kg" && to=="ounce")
            return input*35.27396;
        if(from=="ounce" && to=="Kg")
            return input*0.02835;

        if(from=="Kg" && to=="mg")
            return input*1000000;
        if(from=="mg" && to=="Kg")
            return input/1000000;

        if(from=="gm" && to=="lb")
            return 0.0022*input;
        if(from=="lb" && to=="gm")
            return 453.6*input;

        if(from=="gm" && to=="mg")
            return input*1000;
        if(from=="mg" && to=="gm")
            return input/1000;

        if(from=="gm" && to=="ounce")
            return input*0.03527;
        if(from=="ounce" && to=="gm")
            return input*28.34952;

        if(from=="lb" && to=="mg")
            return input*453592.37;
        if(from=="mg" && to=="lb")
            return input/453592.37;

        if(from=="ounce" && to=="mg")
            return input*28349.52313;
        if(from=="mg" && to=="ounce")
            return input/28349;

        if(from=="lb" && to=="ounce")
            return 16*input;
        if(from=="ounce" && to=="lb")
            return input/16;

        if(from==to)
            return input;
        return 0.0;
    }
}