package com.example.dozcalendar;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import android.app.Activity;
import android.os.Bundle;
import android.os.Environment;
import android.widget.Button;
import android.widget.CheckBox;
import android.widget.EditText;
import android.widget.Spinner;
import android.widget.TextView;
import android.view.View;
import android.view.View.OnClickListener;

public class Settings extends Activity {
	
	public static Activity activity = null;
	int lunarchange = 0;
	
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.settings_layout);
		final EditText dateformat = (EditText) findViewById(R.id.date_form_text);
		dateformat.setHint(MainActivity.date_format);
		dateformat.requestFocus();
		final TextView firstdow_exp = (TextView) findViewById(R.id.first_dow_exp);
		firstdow_exp.setText(firstdow_exp.getText() + "  Currently set as \"" + Julian.downum_to_name(MainActivity.first_dow) + "\".");
		final Spinner first_dow = (Spinner) findViewById(R.id.first_dow);
		final CheckBox lunar = (CheckBox) findViewById(R.id.moonphase_opt);
		if (MainActivity.moonphases == 1)
			lunar.setChecked(true);
		final Button save_settings_button = (Button) findViewById(R.id.save_settings_button);
		lunar.setOnClickListener(new OnClickListener() {
			public void onClick(View v) {
				MainActivity.moonphases = 0;
				lunarchange = 1;
			}
		});
		save_settings_button.setOnClickListener(new OnClickListener() {
			public void onClick(View v) {
				String addopts = "";
				if (dateformat.getText().toString().trim().length() != 0) {
					DeleteLine.delete_opt("%DATEFORM");
					addopts = addopts + "%DATEFORM:  " + dateformat.getText().toString() + "\n";
				}
				final String new_firstdow = String.valueOf(first_dow.getSelectedItem());
				if (!new_firstdow.equals("No Change")) {
					DeleteLine.delete_opt("%FIRSTDOW");
					addopts = addopts + "%FIRSTDOW:  " + Julian.downame_to_downum(new_firstdow).toString() + "\n";
				}
				if (!lunar.isChecked()) {
					DeleteLine.delete_opt("%ASTRONOMY");
					MainActivity.moonphases = 0;
				} else {
					MainActivity.moonphases = 1;
					addopts = addopts + "%ASTRONOMY:  moon\n";
				}
				try {
					final File file = new File (Environment.getExternalStorageDirectory().getPath(),"caldata");
					FileWriter fos = new FileWriter(file, true);
					fos.append(addopts);
					fos.close();
				} catch (FileNotFoundException e) {
					e.printStackTrace();
				} catch (IOException e) {
					e.printStackTrace();
				}
				finish();
			}
		});
	}
}