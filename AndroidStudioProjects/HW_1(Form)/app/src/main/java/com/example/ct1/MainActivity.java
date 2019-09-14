package com.example.ct1;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    EditText name;
    EditText hall;
    EditText home;
    TextView nm;
    TextView hl;
    TextView hd;
    Button clk;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        name=findViewById(R.id.name);
        hall=findViewById(R.id.hall);
        home=findViewById(R.id.home);
        nm=findViewById(R.id.txt1);
        hl=findViewById(R.id.txt2);
        hd=findViewById(R.id.txt3);
        clk=findViewById(R.id.btn);
        clk.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                String s1=name.getText().toString();
                String s2=hall.getText().toString();
                String s3=home.getText().toString();
                nm.append(s1);
                hl.append(s2);
                hd.append(s3);
            }
        });
    }
}