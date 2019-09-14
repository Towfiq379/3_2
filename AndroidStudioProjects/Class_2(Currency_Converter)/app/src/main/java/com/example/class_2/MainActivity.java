package com.example.class_2;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.RadioButton;

public class MainActivity extends AppCompatActivity {

    EditText value;
    Button btn;
    Button btn2;
    RadioButton bu;
    RadioButton ub;
    RadioButton bi;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        value = findViewById(R.id.val);
        btn = findViewById(R.id.clk);
        btn2 = findViewById(R.id.clr);
        bu = findViewById(R.id.btn1);
        ub = findViewById(R.id.btn2);
        bi = findViewById(R.id.btn3);
        btn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                double input = new Double(value.getText().toString());
                double res=new Double(0);
                if(bu.isChecked())
                    res=Converter.btou(input);
                else if(ub.isChecked())
                    res = Converter.utob(input);
                else if(bi.isChecked())
                    res = Converter.btoi(input);
                value.setText(new Double(res).toString());

            }
        });
        btn2.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                value.setText("");
            }
        });
    }
}
