package com.example.practice;

public class Temperature implements Strategy {

    public double Convert(String from, String to, double input) {

        if(from=="Celsius" && to=="Fahrenheit")
            return input*9/5+32;
        if(from=="Fahrenheit" && to=="Celsius")
            return (input-32)*5/9;
        if(from=="Celsius" && to=="Kelvin")
            return input +  273.15;
        if(from=="Kelvin" && to=="Celsius")
            return input -  273.15;
        if(from=="Kelvin" && to=="Fahrenheit")
            return (input-273.15)*9/5+32;
        if(from=="Fahrenheit" && to=="Kelvin")
            return (input-32)*5/9 + 273.15;
        if(from==to)
            return input;
        return 0.0;
    }
}