package com.example.dozcaldroid;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStream;
import java.io.OutputStreamWriter;
import java.io.PrintStream;
import java.nio.charset.Charset;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

import android.os.Bundle;
import android.os.Environment;
import android.app.Activity;
import android.app.AlertDialog;
import android.app.AlertDialog.Builder;
import android.content.Context;
import android.content.DialogInterface;
import android.content.Intent;
import android.util.Log;
import android.view.Menu;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.CheckBox;
import android.widget.EditText;
import android.widget.RadioButton;
import android.widget.RadioGroup;

public class Addnew_activity extends Activity {

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.addnew_layout);
		final AlertDialog.Builder alert = new AlertDialog.Builder(this);
        final AlertDialog.Builder timealert = new AlertDialog.Builder(this);
		alert.setTitle("Error:  Bad date format");
        alert.setPositiveButton("Okay", new DialogInterface.OnClickListener() {
                    @Override
                    public void onClick(DialogInterface dialog, int which) {
                        dialog.cancel();
                    }
                });
        timealert.setTitle("Error:  Bad time format");
        timealert.setPositiveButton("Okay", new DialogInterface.OnClickListener() {
            @Override
            public void onClick(DialogInterface dialog,int which) {
                dialog.cancel();
            }
        });
		final Intent mainactivity = new Intent(this, MainActivity.class);
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
		submit_event.setOnClickListener(new OnClickListener() {
			public void onClick(View v) {
				SimpleDateFormat sdf = new SimpleDateFormat("dd MMM yyyy");
				String eventname = event_name.getText().toString();
				String datetext = date_text.getText().toString();
				String dateendtext = date_endrange.getText().toString();
				String timetext = time_text.getText().toString();
				String excepttext = except_text.getText().toString();
				String exceptendtext = except_endrange.getText().toString();
				String eventtype = event_type.getText().toString();
				    File file = new File (Environment.getExternalStorageDirectory().getPath(),"caldata");
				    if(!file.exists()) {
				    	try {
							file.createNewFile();
						} catch (IOException e) {
							e.printStackTrace();
						}
				    }
				    try {
				    	if (!validate(datetext) && (datetext.trim().length() != 0)) {
				    		String date_warning_text = "The date you entered ";
				    		date_warning_text += "is not in a format recognized ";
				    		date_warning_text += "by this program; please put it ";
				    		date_warning_text += "in one of the following formats:\n";
				    		date_warning_text += "    dd MMM yyyy\n";
				    		date_warning_text += "    yyyy-MM-dd\n";
				    		alert.setMessage(date_warning_text);
				    		alert.show();
				    	} else if ((dateendtext.trim().length() != 0) && (!validate(dateendtext))) {
				    		String date_warning_text = "The range end date you entered ";
				    		date_warning_text += "is not in a format recognized ";
				    		date_warning_text += "by this program; please put it ";
				    		date_warning_text += "in one of the following formats:\n";
				    		date_warning_text += "    dd MMM yyyy\n";
				    		date_warning_text += "    yyyy-MM-dd\n";
				    		alert.setMessage(date_warning_text);
				    		alert.show();
				    	} else if (!tvalidate(timetext) && (timetext.trim().length() != 0)) {
						   	String time_warning_text = "The time you entered ";
						   	time_warning_text += "is not in a format recognized ";
						    time_warning_text += "by this program; please enter it ";
						    time_warning_text += "in the form:\n";
						    time_warning_text += "    HH;mm\n";
						    time_warning_text += "always using all four digits, ";
						    time_warning_text += "using zeroes if necessary.";
						    timealert.setMessage(time_warning_text);
						    timealert.show();	
				    	} else {
				    		if (dateendtext.trim().length() != 0)
				    			datetext = datetext+"--"+dateendtext;
				    		if (exceptendtext.trim().length() != 0)
				    			excepttext = excepttext+"--"+exceptendtext;
				    		if (datetext.trim().length() != 0) {
				    			String total_line = eventname+"|"+datetext+"|"+timetext+"|"+excepttext+"|"+eventtype+"\n";
				    			FileOutputStream fos = new FileOutputStream(file,true);
				    			fos.write(total_line.getBytes());
					    		fos.close();
				    		} else {
				    			RadioButton checked_intermitt = (RadioButton) intermitt.findViewById(intermitt.getCheckedRadioButtonId());
				    			String checked_inter = checked_intermitt.getText().toString();
				    			String[] inter_days = new String[7];
				    			String[] inter_mons = new String[12];
				    			Integer i = 0;
				    			if (sun.isChecked())
				    				inter_days[i++] = "sun";
				    			if (mon.isChecked())
				    				inter_days[i++] = "mon";
				    			if (tue.isChecked())
				    				inter_days[i++] = "tue";
				    			if (wed.isChecked())
				    				inter_days[i++] = "wed";
				    			if (thu.isChecked())
				    				inter_days[i++] = "thu";
				    			if (fri.isChecked())
				    				inter_days[i++] = "fri";
				    			if (sat.isChecked())
				    				inter_days[i++] = "sat";
				    			i = 0;
				    			if (jan.isChecked())
				    				inter_mons[i++] = "jan";
				    			if (feb.isChecked())
				    				inter_mons[i++] = "feb";
				    			if (mar.isChecked())
				    				inter_mons[i++] = "mar";
				    			if (apr.isChecked())
				    				inter_mons[i++] = "apr";
				    			if (may.isChecked())
				    				inter_mons[i++] = "may";
				    			if (jun.isChecked())
				    				inter_mons[i++] = "jun";
				    			if (jul.isChecked())
				    				inter_mons[i++] = "jul";
				    			if (aug.isChecked())
				    				inter_mons[i++] = "aug";
				    			if (sep.isChecked())
				    				inter_mons[i++] = "sep";
				    			if (oct.isChecked())
				    				inter_mons[i++] = "oct";
				    			if (nov.isChecked())
				    				inter_mons[i++] = "nov";
				    			if (dec.isChecked())
				    				inter_mons[i++] = "dec";
				    			Integer j = 0;
				    			for (i = 0; inter_mons[i] != null; i++) {
				    				Integer monnum = Julian.monname_to_num(inter_mons[i]) + 1;
				    				int year = Calendar.getInstance().get(Calendar.YEAR);
				    				double frst_day_mon = Julian.to_julian(Integer.toString(year,12)+"-"+Integer.toString(monnum,12)+"-1");
				    				for (j = 0; inter_days[j] != null; j++) {
				    					double frst_wday = frst_day_mon;
				    					while ((Julian.jdn_to_dow_num(frst_wday)-1) != Julian.wkdayname_to_num(inter_days[j])) {
				    						System.out.println(Julian.jdn_to_dow_num(frst_wday));
				    						System.out.println(Julian.jdn_to_greg(frst_wday, "yyyy-MM-dd"));
				    						frst_wday++;
				    					}
				    					FileOutputStream fos = new FileOutputStream(file,true);
				    					if (checked_inter.trim().equals("Every")) {
				    						while (Julian.jdn_to_greg(frst_wday,"MM").equals(String.format("%02d",monnum))) {
				    							String total_line = eventname+"|"+decimalize_date.dozenalize_date(Julian.jdn_to_greg(frst_wday,"yyyy-MM-dd"))+"|"+timetext+"|"+excepttext+"|"+eventtype+"\n";
				    							fos.write(total_line.getBytes());
				    							frst_wday += 7;
				    						}
				    					} else if (checked_inter.trim().equals("1st")) {
				    						String total_line = eventname+"|"+decimalize_date.dozenalize_date(Julian.jdn_to_greg(frst_wday,"yyyy-MM-dd"))+"|"+timetext+"|"+excepttext+"|"+eventtype+"\n";
				    						fos.write(total_line.getBytes());
				    					} else if (checked_inter.trim().equals("2nd")) {
				    						frst_wday += 7;
				    						String total_line = eventname+"|"+decimalize_date.dozenalize_date(Julian.jdn_to_greg(frst_wday,"yyyy-MM-dd"))+"|"+timetext+"|"+excepttext+"|"+eventtype+"\n";
				    						fos.write(total_line.getBytes());
				    					} else if (checked_inter.trim().equals("3rd")) {
				    						frst_wday += 14;
				    						String total_line = eventname+"|"+decimalize_date.dozenalize_date(Julian.jdn_to_greg(frst_wday,"yyyy-MM-dd"))+"|"+timetext+"|"+excepttext+"|"+eventtype+"\n";
				    						fos.write(total_line.getBytes());
				    					} else if (checked_inter.trim().equals("4th")) {
				    						frst_wday += 21;
				    						if (Julian.jdn_to_greg(frst_wday,"MM").equals(String.format("%02d",monnum))) {
				    							String total_line = eventname+"|"+decimalize_date.dozenalize_date(Julian.jdn_to_greg(frst_wday,"yyyy-MM-dd"))+"|"+timetext+"|"+excepttext+"|"+eventtype+"\n";
				    							fos.write(total_line.getBytes());
				    						}
				    					} else if (checked_inter.trim().equals("5th")) {
				    						frst_wday += 28;
				    						if (Julian.jdn_to_greg(frst_wday,"MM").equals(String.format("%02d",monnum))) {
				    							String total_line = eventname+"|"+decimalize_date.dozenalize_date(Julian.jdn_to_greg(frst_wday,"yyyy-MM-dd"))+"|"+timetext+"|"+excepttext+"|"+eventtype+"\n";
				    							fos.write(total_line.getBytes());
				    						}
				    					} else if (checked_inter.trim().equals("Last")) {
				    						frst_wday += 28;
				    						while (!Julian.jdn_to_greg(frst_wday,"MM").equals(String.format("%02d",monnum)))
				    							frst_wday -= 7;
				    						String total_line = eventname+"|"+decimalize_date.dozenalize_date(Julian.jdn_to_greg(frst_wday,"yyyy-MM-dd"))+"|"+timetext+"|"+excepttext+"|"+eventtype+"\n";
			    							fos.write(total_line.getBytes());
				    					}
				    					fos.close();
				    				}
				    			}
				    		}
							startActivity(mainactivity);
				    	}
					} catch (FileNotFoundException e1) {
						e1.printStackTrace();
					} catch (IOException e) {
						e.printStackTrace();
					}
			}
		});
	}

	public boolean tvalidate(String time) {
		String[] times = { time, time };
		if (time.contains("-"))
			times = time.split("-");
		if (times[0].matches("^[0-9XE*#ABab]{2};[0-9XE*#ABab]{2}"))
			return true;
		else
			return false;
	}
	
	public boolean validate(String date)
	{
		String decimaldate = "";
		decimaldate = decimalize_date.main(date);
		if (decimaldate == "false")
			return false;
		else
			return true;
	}

	@Override
	public boolean onCreateOptionsMenu(Menu menu) {
		// Inflate the menu; this adds items to the action bar if it is present.
		getMenuInflater().inflate(R.menu.addnew_activity, menu);
		return true;
	}

}
