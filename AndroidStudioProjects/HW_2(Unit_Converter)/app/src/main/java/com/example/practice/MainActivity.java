package com.example.practice;

import androidx.appcompat.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Spinner;

public class MainActivity extends AppCompatActivity implements View.OnClickListener,AdapterView.OnItemSelectedListener{

    private Spinner SpinnerUnit, SpinnerFrom, SpinnerTo;
    private EditText inputValue;
    private Button ButtonConvert;
    private EditText ResultView;
    ArrayAdapter<String> unitarray, unitarrayadapter;
    private Strategy currentStrategy;
    private String unitfrom, unitto;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        SpinnerUnit = findViewById(R.id.SpinnerUnit);
        SpinnerUnit.setOnItemSelectedListener(this);

        unitarray=new ArrayAdapter<String>(this,android.R.layout.simple_spinner_item);
        unitarray.setDropDownViewResource(android.R.layout.simple_spinner_dropdown_item);
        SpinnerUnit.setAdapter(unitarray);

        unitarray.add("Tempereture");
        unitarray.add("Weight");
        unitarray.add("Length");
        unitarray.add("Power");
        unitarray.add("Energy");
        unitarray.add("Velocity");
        unitarray.add("Area");
        unitarray.add("Volume");
        unitarray.add("Currency");
        unitarray.add("Time");

        SpinnerFrom = findViewById(R.id.SpinnerFrom);
        SpinnerFrom.setOnItemSelectedListener(this);
        SpinnerTo = findViewById(R.id.SpinnerTo);
        SpinnerTo.setOnItemSelectedListener(this);

        unitarrayadapter = new ArrayAdapter<String>(this,android.R.layout.simple_spinner_item);
        unitarrayadapter.setDropDownViewResource(android.R.layout.simple_spinner_dropdown_item);
        SpinnerFrom.setAdapter(unitarrayadapter);
        SpinnerTo.setAdapter(unitarrayadapter);

        unitarrayadapter.setNotifyOnChange(true);

        ResultView = findViewById(R.id.TextViewResult);

        ButtonConvert = findViewById(R.id.Button01);
        ButtonConvert.setOnClickListener(this);

        inputValue = findViewById(R.id.EditTextValue);

        currentStrategy = new Temperature();
    }

    public void onNothingSelected(AdapterView<?> parent){
    }

    public void onItemSelected(AdapterView<?> parent, View v, int position, long id){

        if(v.getParent() == SpinnerUnit){
            unitarrayadapter.clear();
            if(position==0){
                currentStrategy = new Temperature();
                unitarrayadapter.add("Celsius");
                unitarrayadapter.add("Fahrenheit");
                unitarrayadapter.add("Kelvin");
            }
            else if(position==1){
                currentStrategy = new Weight();
                unitarrayadapter.add("Kg");
                unitarrayadapter.add("gm");
                unitarrayadapter.add("lb");
                unitarrayadapter.add("ounce");
                unitarrayadapter.add("mg");
            }

            else if(position==2){
                currentStrategy = new Length();
                unitarrayadapter.add("mile");
                unitarrayadapter.add("km");
                unitarrayadapter.add("m");
                unitarrayadapter.add("cm");
                unitarrayadapter.add("mm");
                unitarrayadapter.add("inch");
                unitarrayadapter.add("ft");
            }
            else if(position==3){
                currentStrategy = new Power();
                unitarrayadapter.add("watts");
                unitarrayadapter.add("horsepower");
                unitarrayadapter.add("kilowatts");
            }
            else if(position==4){
                currentStrategy = new Energy();
                unitarrayadapter.add("calories");
                unitarrayadapter.add("joules");
                unitarrayadapter.add("kilocalories");
            }
            else if(position==5){
                currentStrategy = new Velocity();
                unitarrayadapter.add("Km/hr");
                unitarrayadapter.add("miles/hr");
                unitarrayadapter.add("m/s");
                unitarrayadapter.add("feet/s");
            }
            else if(position==6){
                currentStrategy = new Area();
                unitarrayadapter.add("square km");
                unitarrayadapter.add("square miles");
                unitarrayadapter.add("square m");
                unitarrayadapter.add("square cm");
                unitarrayadapter.add("square mm");
                unitarrayadapter.add("square yards");
            }
            else if(position==7){
                currentStrategy = new Volume();
                unitarrayadapter.add("litre");
                unitarrayadapter.add("millilitre");
                unitarrayadapter.add("cubic m");
                unitarrayadapter.add("cubic cm");
                unitarrayadapter.add("cubic mm");
                unitarrayadapter.add("cubic feet");
            }
            else if(position==8){
                currentStrategy = new Currency();
                unitarrayadapter.add("USD");
                unitarrayadapter.add("INR");
                unitarrayadapter.add("BDT");
                unitarrayadapter.add("EUR");
            }
            else if(position==9){
                currentStrategy = new Timee();
                unitarrayadapter.add("sec");
                unitarrayadapter.add("min");
                unitarrayadapter.add("hour");
                unitarrayadapter.add("day");
            }
            SpinnerFrom.setSelection(0);
            SpinnerTo.setSelection(0);

            unitfrom = SpinnerFrom.getItemAtPosition(0).toString();
            unitto = SpinnerTo.getItemAtPosition(0).toString();
        }
        else if(v.getParent() == SpinnerFrom)
            unitfrom = SpinnerFrom.getSelectedItem().toString();

        else if(v.getParent() == SpinnerTo)
            unitto = SpinnerTo.getSelectedItem().toString();
    }

    public void onClick(View v){
        if(v == ButtonConvert){
            if(!(inputValue.getText().toString()=="")){
                double in = new Double(inputValue.getText().toString());
                double result = currentStrategy.Convert(unitfrom, unitto, in);
                ResultView.setText(Double.toString(result));
            }
            else
                ResultView.setText("");
        }
    }
}