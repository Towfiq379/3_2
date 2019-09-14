package com.example.practice;

public class Currency implements Strategy {

    public double Convert(String from, String to, double input) {

        if(from=="USD" && to=="INR")
            return (double)(input*71.97);
        if(from=="USD" && to=="BDT")
            return (double)(input*84.68);
        if(from=="USD" && to=="EUR")
            return (double)(input*0.91);


        if(from=="INR" && to=="USD")
            return (double)(input*0.014);
        if(from=="INR" && to=="BDT")
            return (double)(input*1.18);
        if(from=="INR" && to=="EUR")
            return (double)(input*0.013);

        if(from=="BDT" && to=="USD")
            return (double)(input*0.012);
        if(from=="BDT" && to=="INR")
            return (double)(input*0.85);
        if(from=="BDT" && to=="EUR")
            return (double)(input*0.011);

        if(from=="EUR" && to=="USD")
            return (double)(input*1.10);
        if(from=="EUR" && to=="INR")
            return (double)(input*78.95);
        if(from=="EUR" && to=="BDT")
            return (double)(input*92.89);

        if(from==to)
            return input;
        return 0.0;
    }
}