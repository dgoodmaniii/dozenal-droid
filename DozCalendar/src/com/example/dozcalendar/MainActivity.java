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
import java.util.concurrent.atomic.AtomicBoolean;

import android.os.Bundle;
import android.os.Environment;
import android.os.Handler;
import android.os.Message;
import android.annotation.SuppressLint;
import android.app.Activity;
import android.content.Intent;
import android.graphics.Typeface;
import android.view.Menu;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.ProgressBar;
import android.widget.TextView;
import android.widget.Toast;

@SuppressLint("HandlerLeak")
public class MainActivity extends Activity {

	public static Integer curr_display = 0;
	public static String usedate = "";
	public static String date_format = "EEE, dd MMM yyyy";
	public static Date currdate = new Date();
	public static String xdig = "*";
	public static String edig = "#";
	public static Double startjdn = Julian.to_julian(currdate);
	public static Double endjdn = Julian.to_julian(currdate);
	public static int first_dow = 0;
	public static int moonphases = 0; // 1 for true
	public static ArrayList<Datelib> alldates = new ArrayList<Datelib>();
	ProgressBar bar;
	@SuppressLint("HandlerLeak")
	Handler handler = new Handler() {
		@Override
		public void handleMessage(Message msg) {
			if (msg.what == 0) {
				isRunning.set(false);
				bar.setVisibility(View.GONE);			
				Toast loading_done = Toast.makeText(getApplicationContext(),"Date loading complete",Toast.LENGTH_SHORT);
				loading_done.show();
			}
		}
	};
	AtomicBoolean isRunning = new AtomicBoolean(false);
	
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
		settingsbutton.setOnClickListener(new OnClickListener() {
			@Override
			public void onClick(View v) {
				Intent intent = new Intent(MainActivity.this,Settings.class);
				MainActivity.this.startActivity(intent);
			}
		});
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
			startjdn = startjdn - Math.abs(curr_dow - first_dow);
			endjdn = startjdn + 6;
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
		bar = (ProgressBar) findViewById(R.id.progress);
		String filename = "caldata";
		alldates = new ArrayList<Datelib>();
		final File file = new File(Environment.getExternalStorageDirectory(),filename );
		if (file.exists()) {
			content.setText("Found file " + filename + "\n");
		} else {
			try {
				file.createNewFile();
			} catch (IOException e) {
				e.printStackTrace();
			}
		}
		final BufferedReader bropts;
		final BufferedReader brdata;
		try {
			bropts = new BufferedReader(new FileReader(file));
			brdata = new BufferedReader(new FileReader(file));
			final TextView contentblock = (TextView) findViewById(R.id.dateunit_content);
			Thread background = new Thread(new Runnable() {
				public void run() {
					String line;
					try {
						while ((line = bropts.readLine()) != null) {
							if (line.startsWith("%"))
								proc_opt(line);
						}
						while ((line = brdata.readLine()) != null) {							
							proc_date(line);
							handler.sendMessage(handler.obtainMessage(1));
						}
					} catch (IOException e) {
						e.printStackTrace();
					}
					try {
						bropts.close();
						brdata.close();
					} catch (IOException e) {
						e.printStackTrace();
					}
					Collections.sort(alldates, new CompareEvents());
					handler.sendMessage(handler.obtainMessage(0));
				}
			});
			contentblock.setText("");
			print_events(contentblock);
			isRunning.set(true);
			background.start();
		} catch (FileNotFoundException e1) {
			e1.printStackTrace();
		}
	}
	public void onStop() {
		super.onStop();
		isRunning.set(false);
		bar.setVisibility(View.GONE);
	}
	@Override
	public boolean onCreateOptionsMenu(Menu menu) {
		// Inflate the menu; this adds items to the action bar if it is present.
		getMenuInflater().inflate(R.menu.main, menu);
		return true;
	}
	public void proc_opt(String s) {
		if (s.startsWith("%DATEFORM")) {
			date_format = s.substring(s.indexOf(":"));
			date_format = date_format.substring(1);
			while (date_format.startsWith(" "))
				date_format = date_format.substring(1);
		} else if (s.startsWith("%FIRSTDOW")) {
			s = s.substring(s.indexOf(":"));
			s = s.substring(1);
			while (s.startsWith(" "))
				s = s.substring(1);
			first_dow = Integer.parseInt(s);
		} else if (s.startsWith("%ASTRONOMY")) {
			s = s.substring(s.indexOf(":"));
			s = s.substring(1);
			while (s.startsWith(" "))
				s = s.substring(1);
			if (s.contains("moon") == true) {
				moonphases = 1;
			}
		}
	}
	public void proc_date(String s) {
		if (s.startsWith("%")) {
			return;
		}
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
				if ((index > 0) && alldates.get(index-1).jdn.equals(alldates.get(index).jdn)) {
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
