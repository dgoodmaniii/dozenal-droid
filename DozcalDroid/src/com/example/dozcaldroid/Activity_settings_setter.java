package com.example.dozcaldroid;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.util.Calendar;

import android.os.Bundle;
import android.os.Environment;
import android.app.Activity;
import android.content.Intent;
import android.view.Menu;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.CheckBox;
import android.widget.EditText;
import android.widget.Spinner;

public class Activity_settings_setter extends Activity {

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.settings_layout);
		final Intent backagain = new Intent(this, MainActivity.class);
		final Button save_settings_button = (Button) findViewById(R.id.save_settings_button);
		final EditText date_form_text = (EditText) findViewById(R.id.date_form_text);
		final Spinner first_dow_spinner = (Spinner) findViewById(R.id.first_dow);
		final CheckBox lunar_phases = (CheckBox) findViewById(R.id.moonphase_opt);
		final CheckBox nolunar_phases = (CheckBox) findViewById(R.id.nomoonphase_opt);
//		final CheckBox solar = (CheckBox) findViewById(R.id.solar_opt);
//		final CheckBox nosolar = (CheckBox) findViewById(R.id.nosolar_opt);
		save_settings_button.setOnClickListener(new OnClickListener() {
			public void onClick(View v) {
				String all_opts = "";
				final String dateformtext = date_form_text.getText().toString();
				final String first_dow = String.valueOf(first_dow_spinner.getSelectedItem());
			    File file = new File (Environment.getExternalStorageDirectory().getPath(),"caldata");
			    if(!file.exists()) {
			    	try {
						file.createNewFile();
					} catch (IOException e) {
						e.printStackTrace();
					}
			    }
			    // open the file
			    FileOutputStream fos = null;
			    try {
					fos = new FileOutputStream(file,true);
				} catch (FileNotFoundException e1) {
					e1.printStackTrace();
				}
			    // deal with date format option
			    if (dateformtext.trim().length() != 0) {
			    	all_opts = all_opts+"%DATEFORM: "+dateformtext+"\n";
			    }
			    // deal with first_dow option
			    if (!first_dow.equals("No Change")) {
			    	all_opts = all_opts+"%FIRSTDAY:  "+first_dow+"\n";
			    }
			    // deal with astronomy options
			    if (lunar_phases.isChecked()) {
			    	all_opts = all_opts+"%ASTRONOMY:  moon\n";
			    }
			    if (nolunar_phases.isChecked()) {
			    	all_opts = all_opts+"%ASTRONOMY:  nomoon\n";
			    }
/*			    if (solar.isChecked()) {
			    	all_opts = all_opts+"%ASTRONOMY:  sun\n";
			    }
			    if (nosolar.isChecked()) {
			    	all_opts = all_opts+"%ASTRONOMY:  nosun\n";
			    }*/
			    // save options to file
			    try {
					fos.write(all_opts.getBytes());
					fos.close();
			    } catch (IOException e) {
					e.printStackTrace();
				}
				// Done handling options
				Bundle databundle = new Bundle();
				Calendar cal = (Calendar) databundle.getSerializable("caldata");
				Integer curr_display = databundle.getInt("curr_display");
				databundle.putSerializable("caldata",cal);
				databundle.putInt("curr_display", curr_display);
				databundle.putInt("dontinitialize",0);
				backagain.putExtra("saveddata",databundle);
				startActivity(backagain);
			}
		});
	}

	@Override
	public boolean onCreateOptionsMenu(Menu menu) {
		// Inflate the menu; this adds items to the action bar if it is present.
		getMenuInflater().inflate(R.menu.activity_settings_setter, menu);
		return true;
	}

}
