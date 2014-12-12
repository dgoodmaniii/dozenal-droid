package com.example.dozcalendar;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Calendar;
import java.util.Collections;
import java.util.Date;

import android.os.Bundle;
import android.os.Environment;
import android.app.Activity;
import android.content.Intent;
import android.graphics.Typeface;
import android.view.Menu;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.TextView;

public class MainActivity extends Activity {

	public static Integer curr_display = 0;
	public static String usedate = "";
	public static String date_format = "EEE, dd MMM yyyy";
	public static Date currdate = new Date();
	public static String xdig = "X";
	public static String edig = "E";
	public static Double startjdn = Julian.to_julian(currdate);
	public static Double endjdn = Julian.to_julian(currdate);
	public static int first_dow = 0;
	public static ArrayList<Datelib> alldates = new ArrayList<Datelib>();
	
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);
		Typeface symbola = Typeface.createFromAsset(getAssets(),"Symbola.ttf");
		final TextView contentblock = (TextView) findViewById(R.id.dateunit_content);
		contentblock.setTypeface(symbola);
		final Button dailybutton = (Button) findViewById(R.id.button_daily);
		dailybutton.setTypeface(symbola);
		final Button weeklybutton = (Button) findViewById(R.id.button_weekly);
		final TextView datebox = (TextView) findViewById(R.id.curr_dateunit);
		weeklybutton.setTypeface(symbola);
		final Button monthlybutton = (Button) findViewById(R.id.button_monthly);
		monthlybutton.setTypeface(symbola);
		final Button settingsbutton = (Button) findViewById(R.id.button_settings);
		settingsbutton.setTypeface(symbola);
		final Button leftarrow = (Button) findViewById(R.id.left_arrow);
		leftarrow.setTypeface(symbola);
		final Button rightarrow = (Button) findViewById(R.id.right_arrow);
		rightarrow.setTypeface(symbola);
		final Button addnew = (Button) findViewById(R.id.addnew);
		addnew.setTypeface(symbola);
		String y = new StringBuilder().appendCodePoint(0x1F4C5).toString();
		String x = new StringBuilder().appendCodePoint(0x1F4C6).toString();
		monthlybutton.setText(y);
		dailybutton.setText(x);
		addnew.setOnClickListener(new OnClickListener() {
			@Override
			public void onClick(View v) {
				Intent intent = new Intent(MainActivity.this,AddnewActivity.class);
				MainActivity.this.startActivity(intent);
			}
		});
		dailybutton.setOnClickListener(new OnClickListener() {
			public void onClick(View v) {
				curr_display = 0;
				pick_display(dailybutton,weeklybutton,monthlybutton,datebox);
				setstartend(currdate,curr_display);
				print_events(contentblock);
			}
		});
		weeklybutton.setOnClickListener(new OnClickListener() {
			public void onClick(View v) {
				curr_display = 1;
				pick_display(dailybutton,weeklybutton,monthlybutton,datebox);
				setstartend(currdate,curr_display);
				print_events(contentblock);
			}
		});
		monthlybutton.setOnClickListener(new OnClickListener() {
			public void onClick(View v) {
				curr_display = 2;
				pick_display(dailybutton,weeklybutton,monthlybutton,datebox);
				setstartend(currdate,curr_display);
				print_events(contentblock);
			}
		});
		leftarrow.setOnClickListener(new OnClickListener() {
			public void onClick(View v) {
				sub_one_from_date(currdate,datebox);
				setstartend(currdate,curr_display);
				print_events(contentblock);
			}
		});
		rightarrow.setOnClickListener(new OnClickListener() {
			public void onClick(View v) {
				add_one_to_date(currdate,datebox);
				setstartend(currdate,curr_display);
				print_events(contentblock);
			}
		}); 
		pick_display(dailybutton,weeklybutton,monthlybutton,datebox);
		set_datestring(currdate,datebox);
		process_file(contentblock);
	}
	
	public void initialize_range(Date date) {
		startjdn = Julian.to_julian(date);
		endjdn = Julian.to_julian(date);
	}
	
	public void setstartend(Date date,int disp_mode) {
		initialize_range(date);
		if (disp_mode == 0) {
			return;
		} else if (disp_mode == 1) {
			Integer curr_dow = Julian.dow_num(date);
			startjdn -= curr_dow;
			endjdn = endjdn + (6 - curr_dow);			
		} else if (disp_mode == 2) {
			Integer day_month = Julian.day_of_month(date);
			Integer len_month = Julian.len_of_month(date);
			startjdn -= (day_month - 1);
			endjdn = endjdn + (len_month - day_month);
		}
	}
	
	public void sub_one_from_date(Date date,TextView datebox) {
		Calendar cal = Calendar.getInstance();
		cal.setTime(date);
		if (curr_display == 0)
			cal.add(Calendar.DATE,-1);
		else if (curr_display == 1)
			cal.add(Calendar.DATE,-7);
		else if (curr_display == 2)
			cal.add(Calendar.MONTH,-1);
		currdate = cal.getTime();
		set_datestring(currdate,datebox);
	}
	public void add_one_to_date(Date date,TextView datebox) {
		Calendar cal = Calendar.getInstance();
		cal.setTime(date);
		if (curr_display == 0)
			cal.add(Calendar.DATE,1);
		else if (curr_display == 1)
			cal.add(Calendar.DATE,7);
		else if (curr_display == 2)
			cal.add(Calendar.MONTH,1);
		currdate = cal.getTime();
		set_datestring(currdate,datebox);
	}
	public void set_datestring(Date currdate,TextView datebox) {
		SimpleDateFormat dateformat = new SimpleDateFormat(date_format);
		if (curr_display == 0) {
			datebox.setText(Numconvert.dozdatestr(dateformat.format(currdate)));
		} else if (curr_display == 1) {
			datebox.setText("Week of "+Numconvert.dozdatestr(dateformat.format(currdate)));
		} else if (curr_display == 2) {
			dateformat = new SimpleDateFormat("MMM yyyy");
			datebox.setText(Numconvert.dozdatestr(dateformat.format(currdate)));
		}
	}
	
	public void pick_display(Button daily,Button weekly,Button monthly,TextView datebox) {
		if (curr_display == 0) {
			daily.setBackgroundColor(0xFFFFCC00);
			weekly.setBackgroundColor(0xFF800000);
			monthly.setBackgroundColor(0xFF800000);
		} else if (curr_display == 1) {
			daily.setBackgroundColor(0xFF800000);
			weekly.setBackgroundColor(0xFFFFCC00);
			monthly.setBackgroundColor(0xFF800000);
		} else if (curr_display == 2) {
			daily.setBackgroundColor(0xFF800000);
			weekly.setBackgroundColor(0xFF800000);
			monthly.setBackgroundColor(0xFFFFCC00);
		}
		set_datestring(currdate,datebox);
	}
	
	public void process_file(TextView content) {
		String filename = "caldata";
		alldates = new ArrayList<Datelib>();
		File file = new File(Environment.getExternalStorageDirectory(),filename );
		if (file.exists()) {
			content.setText("Found file " + filename + "\n");
		} else {
			try {
				file.createNewFile();
			} catch (IOException e) {
				e.printStackTrace();
			}
		}
		BufferedReader br;
		final TextView contentblock = (TextView) findViewById(R.id.dateunit_content);
		try {
			br = new BufferedReader(new FileReader(file));
			String line;
			while ((line = br.readLine()) != null) {
				proc_date(line);
			}
			br.close();
			contentblock.setText("");
			Collections.sort(alldates, new CompareEvents());
			print_events(contentblock);
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
	@Override
	public boolean onCreateOptionsMenu(Menu menu) {
		// Inflate the menu; this adds items to the action bar if it is present.
		getMenuInflater().inflate(R.menu.main, menu);
		return true;
	}
	public void proc_date(String s) {
		s = s.replace("||","| |"); s = s.replace("||","| |");
		String dateline[] = s.split("\\|");
		for (int i = 2; i < 3; ++i)
			dateline[i] = dateline[i].replace(" ","");
		String datestring = Numconvert.decdatestr(dateline[1]);
		String exceptstring = Numconvert.decdatestr(dateline[3]);
		Double datestart = 0.0;
		Integer times[] = Numconvert.parse_timestring(dateline[2]);
		Double dates[] = get_daterange(datestring);
		datestart = dates[0];
		Double exceptions[] = get_daterange(exceptstring);
		int i = 0; int numdates = dates.length;
		for (i = 0; i < numdates; ++i) {
			if (!Arrays.asList(exceptions).contains(dates[i])) {
				alldates.add(Datelib.add(datestart,dateline[0],times[0],times[1],dateline[4]));
			}
			datestart++;
		}
	}
	public static Double[] get_daterange(String s) {
		Double datestart = 0.0; Double dateend = 0.0;
		if (s.contains("--")) {
			String dateparts[] = s.split("--");
			datestart = Julian.parse_datestring(dateparts[0]);
			dateend = Julian.parse_datestring(dateparts[1]);
		} else {
			datestart = Julian.parse_datestring(s);
			dateend = datestart;
		}
		Double range[] = new Double[(int) (dateend-datestart) + 1];
		int i = 0;
		do {
			range[i++] = datestart++;
		} while (datestart <= dateend);
		return range;
	}
	public static void print_events(TextView contentblock) {
		int index = 0; Integer numentries = alldates.size();
		contentblock.setText("");
		for (index = 0; index < numentries; ++index) {
			if ((alldates.get(index).jdn >= startjdn) && (alldates.get(index).jdn <= endjdn)) {
				if (alldates.get(index-1).jdn.toString().equals(alldates.get(index).jdn.toString())) {
					contentblock.append(alldates.get(index).print(curr_display, 1));
				} else {
					contentblock.append(alldates.get(index).print(curr_display, 0));
				}
			}
		}
	}
	protected void onResume(Bundle savedInstanceState) {
/*		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);
		Typeface symbola = Typeface.createFromAsset(getAssets(),"Symbola.ttf");
		final TextView contentblock = (TextView) findViewById(R.id.dateunit_content);
		process_file(contentblock);*/
	}
}
