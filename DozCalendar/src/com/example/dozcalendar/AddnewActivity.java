package com.example.dozcalendar;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;

import android.app.Activity;
import android.app.AlertDialog;
import android.content.DialogInterface;
import android.os.Bundle;
import android.os.Environment;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.CheckBox;
import android.widget.EditText;
import android.widget.RadioButton;
import android.widget.RadioGroup;

public class AddnewActivity extends Activity {
	
	public static Activity activity = null;
	int error = 0;
	
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.addnew_layout);
		final Button submit_event = (Button) findViewById(R.id.submit_event);
		final EditText event_name = (EditText) findViewById(R.id.event_name);
		event_name.requestFocus();
		final EditText date_text = (EditText) findViewById(R.id.date_text);
		final EditText date_endrange = (EditText) findViewById(R.id.date_range_end);
		final EditText time_text = (EditText) findViewById(R.id.time_text);
		final EditText except_text = (EditText) findViewById(R.id.except_text);
		final EditText except_endrange = (EditText) findViewById(R.id.except_text_end);
		final EditText event_type = (EditText) findViewById(R.id.event_type);
		event_name.requestFocus();
		event_name.setNextFocusDownId(R.id.date_text);
		date_text.setNextFocusDownId(R.id.date_range_end);
		date_endrange.setNextFocusDownId(R.id.time_text);
		time_text.setNextFocusDownId(R.id.except_text);
		except_text.setNextFocusDownId(R.id.except_text_end);
		except_endrange.setNextFocusDownId(R.id.event_type);
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
				if (datetext.trim().length() != 0) {
					if (validate_date(datetext) == 0) {
						showAlert(getWindow().getDecorView().findViewById(android.R.id.content),getString(R.string.error_title),getString(R.string.date_error));
						error = 1;
					} else {
						error = 0;
					}
				}
				if (dateendtext.trim().length() != 0) {
					if (validate_date(dateendtext) == 0) {
						showAlert(getWindow().getDecorView().findViewById(android.R.id.content),getString(R.string.error_title),getString(R.string.date_end_error));
						error = 1;
					} else {
						error = 0;
					}
				}
				if (excepttext.trim().length() != 0) {
					if (validate_date(dateendtext) == 0) {
						showAlert(getWindow().getDecorView().findViewById(android.R.id.content),getString(R.string.error_title),getString(R.string.date_excp_error));
						error = 1;
					} else {
						error = 0;
					}
				}
				if (exceptendtext.trim().length() != 0) {
					if (validate_date(dateendtext) == 0) {
						showAlert(getWindow().getDecorView().findViewById(android.R.id.content),getString(R.string.error_title),getString(R.string.date_end_excp_error));
						error = 1;
					} else {
						error = 0;
					}
				}
				if (dateendtext.trim().length() != 0)
					datetext = datetext+"--"+dateendtext;
				if (exceptendtext.trim().length() != 0)
					excepttext = excepttext+"--"+exceptendtext;
				if (datetext.trim().length() != 0) {
					if (error == 0) {
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
						AddnewActivity.activity.finish();
					}
				} else {
					RadioButton checked_intermit = (RadioButton) intermitt.findViewById(intermitt.getCheckedRadioButtonId());
					String checked_inter = checked_intermit.getText().toString();
					Integer[] inter_days = new Integer[8];
					Integer[] inter_mons = new Integer[13];
					int i = 0;
					if (sun.isChecked())
						inter_days[i++] = 1;
					if (mon.isChecked())
						inter_days[i++] = 2;
					if (tue.isChecked())
						inter_days[i++] = 3;
					if (wed.isChecked())
						inter_days[i++] = 4;
					if (thu.isChecked())
						inter_days[i++] = 5;
					if (fri.isChecked())
						inter_days[i++] = 6;
					if (sat.isChecked())
						inter_days[i++] = 7;
					i = 0;
					if (jan.isChecked())
						inter_mons[i++] = 0;
					if (feb.isChecked())
						inter_mons[i++] = 1;
					if (mar.isChecked())
						inter_mons[i++] = 2;
					if (apr.isChecked())
						inter_mons[i++] = 3;
					if (may.isChecked())
						inter_mons[i++] = 4;
					if (jun.isChecked())
						inter_mons[i++] = 5;
					if (jul.isChecked())
						inter_mons[i++] = 6;
					if (aug.isChecked())
						inter_mons[i++] = 7;
					if (sep.isChecked())
						inter_mons[i++] = 8;
					if (oct.isChecked())
						inter_mons[i++] = 9;
					if (nov.isChecked())
						inter_mons[i++] = 10;
					if (dec.isChecked())
						inter_mons[i++] = 11;
					String datestrings[] = Julian.parse_intermitt(checked_inter, inter_days, inter_mons);
					if (error == 0) {
						FileOutputStream fos;
						try {
							fos = new FileOutputStream(file, true);
							for (i = 0; datestrings[i] != null; ++i) {
								String fileline = eventname+"|"+Numconvert.dozdatestr(datestrings[i])+"|"+timetext+"|"+excepttext+"|"+eventtype+"|\n";
								fos.write(fileline.getBytes());
							}
							fos.close();
						} catch (FileNotFoundException e1) {
							e1.printStackTrace();
						} catch (IOException e) {
							e.printStackTrace();
						}
						AddnewActivity.activity.finish();
					}
				}
			}
		});
	}
	public int validate_date(String s) {
		if (Julian.parse_datestring(Numconvert.decdatestr(s)) == 0.0) {
			return 0;
		} else {
			return 1;
		}
	}
	public void showAlert(View view,String title,String message) {
		new AlertDialog.Builder(this)
			.setTitle(title)
			.setMessage(message)
			.setNeutralButton("Okay",new DialogInterface.OnClickListener() {
				public void onClick(DialogInterface dlg, int sumthin) {
				}
			})
			.show();
	}
}
