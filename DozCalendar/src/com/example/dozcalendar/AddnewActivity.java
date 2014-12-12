package com.example.dozcalendar;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;

import android.app.Activity;
import android.content.Context;
import android.graphics.Typeface;
import android.os.Bundle;
import android.os.Environment;
import android.view.View;
import android.view.View.OnClickListener;
import android.view.WindowManager;
import android.view.inputmethod.InputMethodManager;
import android.widget.Button;
import android.widget.CheckBox;
import android.widget.EditText;
import android.widget.RadioGroup;

public class AddnewActivity extends Activity {
	
	public static Activity activity = null;
	
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.addnew_layout);
		InputMethodManager imm = (InputMethodManager) getSystemService(Context.INPUT_METHOD_SERVICE);
		imm.toggleSoftInput(InputMethodManager.SHOW_FORCED,0);
		Typeface symbola = Typeface.createFromAsset(getAssets(),"Symbola.ttf");
		final Button submit_event = (Button) findViewById(R.id.submit_event);
		final EditText event_name = (EditText) findViewById(R.id.event_name);
		final EditText date_text = (EditText) findViewById(R.id.date_text);
		final EditText date_endrange = (EditText) findViewById(R.id.date_range_end);
		final EditText time_text = (EditText) findViewById(R.id.time_text);
		final EditText except_text = (EditText) findViewById(R.id.except_text);
		final EditText except_endrange = (EditText) findViewById(R.id.except_text_end);
		final EditText event_type = (EditText) findViewById(R.id.event_type);
		final RadioGroup intermitt = (RadioGroup) findViewById(R.id.intermitt);
		final CheckBox sun = (CheckBox) findViewById(R.id.checkbox_sun);
		final CheckBox mon = (CheckBox) findViewById(R.id.checkbox_mon);
		final CheckBox tue = (CheckBox) findViewById(R.id.checkbox_tue);
		final CheckBox wed = (CheckBox) findViewById(R.id.checkbox_wed);
		final CheckBox thu = (CheckBox) findViewById(R.id.checkbox_thu);
		final CheckBox fri = (CheckBox) findViewById(R.id.checkbox_fri);
		final CheckBox sat = (CheckBox) findViewById(R.id.checkbox_sat);
		final CheckBox jan = (CheckBox) findViewById(R.id.checkbox_jan);
		final CheckBox feb = (CheckBox) findViewById(R.id.checkbox_feb);
		final CheckBox mar = (CheckBox) findViewById(R.id.checkbox_mar);
		final CheckBox apr = (CheckBox) findViewById(R.id.checkbox_apr);
		final CheckBox may = (CheckBox) findViewById(R.id.checkbox_may);
		final CheckBox jun = (CheckBox) findViewById(R.id.checkbox_jun);
		final CheckBox jul = (CheckBox) findViewById(R.id.checkbox_jul);
		final CheckBox aug = (CheckBox) findViewById(R.id.checkbox_aug);
		final CheckBox sep = (CheckBox) findViewById(R.id.checkbox_sep);
		final CheckBox oct = (CheckBox) findViewById(R.id.checkbox_oct);
		final CheckBox nov = (CheckBox) findViewById(R.id.checkbox_nov);
		final CheckBox dec = (CheckBox) findViewById(R.id.checkbox_dec);
		activity = this;
		final File file = new File (Environment.getExternalStorageDirectory().getPath(),"caldata");
		submit_event.setOnClickListener(new OnClickListener() {
			public void onClick(View v) {
				String eventname = event_name.getText().toString();
				String datetext = date_text.getText().toString();
				String dateendtext = date_endrange.getText().toString();
				String timetext = time_text.getText().toString();
				String excepttext = except_text.getText().toString();
				String exceptendtext = except_endrange.getText().toString();
				String eventtype = event_type.getText().toString();
				if (dateendtext.trim().length() != 0)
					datetext = datetext+"--"+dateendtext;
				if (exceptendtext.trim().length() != 0)
					excepttext = excepttext+"--"+exceptendtext;
				if (datetext.trim().length() != 0) {
					String fileline = eventname+"|"+datetext+"|"+timetext+"|"+excepttext+"|"+eventtype+"|\n";
					try {
						FileOutputStream fos = new FileOutputStream(file, true);
						fos.write(fileline.getBytes());
						fos.close();
					} catch (FileNotFoundException e) {
						e.printStackTrace();
					} catch (IOException e) {
						e.printStackTrace();
					}
				}
				AddnewActivity.activity.finish();	
			}
		});
	}
	protected void onDestroy(Bundle savedInstanceState) {
		getWindow().setSoftInputMode(WindowManager.LayoutParams.SOFT_INPUT_STATE_ALWAYS_HIDDEN);
	}
}