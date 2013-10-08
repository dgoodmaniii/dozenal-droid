package com.example.dozcaldroid;

import java.io.File;
import java.lang.StringBuilder;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.Calendar;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

import android.os.Bundle;
import android.os.Environment;
import android.os.Handler;
import android.os.Message;
import android.text.Html;
import android.text.method.ScrollingMovementMethod;
import android.view.View;
import android.view.View.OnClickListener;
import android.annotation.SuppressLint;
import android.app.Activity;
import android.app.ProgressDialog;
import android.content.Context;
import android.content.Intent;
import android.graphics.Typeface;
import android.view.Menu;
import android.widget.Button;
import android.widget.TextView;

public class MainActivity extends Activity {

	public static Integer curr_display = 1;
	public static String usedate = "";
	public static String default_date_format = "EEE, dd MMM yyyy";
	public static String fullevents[][] = new String[1000][5];
	public static Integer first_day_week = 0;
	public static Integer moon_opt = 0;
	private static Context context;
	private ProgressDialog progress;
	
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		MainActivity.context = getApplicationContext();
		setContentView(R.layout.activity_main);
		context = MainActivity.this;
		progress = new ProgressDialog(this);
		progress.setTitle("Loading");
		progress.setMessage("Loading your calendar data...");
		progress.setCancelable(false);
		progress.setProgressStyle(ProgressDialog.STYLE_SPINNER);
		String font_path = "Symbola.ttf";
		Typeface symbola = Typeface.createFromAsset(getAssets(), font_path);
		final Button button_settings = (Button) findViewById(R.id.button_settings);
		final Button monthly_button = (Button) findViewById(R.id.button_monthly);
		final Button daily_button = (Button) findViewById(R.id.button_daily);
		final Button weekly_button = (Button) findViewById(R.id.button_weekly);
		button_settings.setTypeface(symbola);
		monthly_button.setTypeface(symbola);
		daily_button.setTypeface(symbola);
		weekly_button.setTypeface(symbola);
		String y = new StringBuilder().appendCodePoint(0x1F4C5).toString();
		String x = new StringBuilder().appendCodePoint(0x1F4C6).toString();
		monthly_button.setText(y);
		daily_button.setText(x);
		final Button sub_one = (Button) findViewById(R.id.left_arrow);
		final Button add_one = (Button) findViewById(R.id.right_arrow);
		final Button addnew = (Button) findViewById(R.id.addnew);
		final Intent addnew_activity = new Intent(this, Addnew_activity.class);
		final Intent set_settings = new Intent(this, Activity_settings_setter.class);
		final TextView curr_date = (TextView) findViewById(R.id.curr_dateunit);
		final TextView dateunit_content = (TextView) findViewById(R.id.dateunit_content);
		dateunit_content.setMovementMethod(new ScrollingMovementMethod());
		final Calendar cal = Calendar.getInstance();
		pick_display(daily_button,weekly_button,monthly_button);
		String thedate = get_datestring(cal);
		String[] thelist;
		curr_date.setText(thedate);
		Intent call_intent = getIntent();
		if (call_intent.hasExtra("dontinitialize")) {
			System.out.println("HERE IT IS");
			Calendar cal2 = Calendar.getInstance();
			cal2 = (Calendar) call_intent.getSerializableExtra("caldata");
			cal.set(Calendar.YEAR,cal2.YEAR);
			cal.set(Calendar.MONTH,cal2.MONTH);
			cal.set(Calendar.DAY_OF_MONTH,cal2.DAY_OF_MONTH);
			pick_display(daily_button,weekly_button,monthly_button);
			thedate = get_datestring(cal);
			curr_date.setText(thedate);
		} else {
			File cal_file = new File(Environment.getExternalStorageDirectory().getPath()+"/caldata");
		    if(!cal_file.exists()) {
		    	try {		    		
					cal_file.createNewFile();
				} catch (IOException e) {
					e.printStackTrace();
				}
		    }
			FileReader cal_data = null;
			try {
				cal_data = new FileReader(cal_file.toString());
			} catch (FileNotFoundException e1) {
				e1.printStackTrace();
			}
			int i;
			String file_contents = "";
			String events[][] = new String[50000][5];
			Integer j = 0; Integer k = 0;
			try {
				while ((i = cal_data.read()) != -1) {
					if (((char) i) == '|') {
						events[j][k] = file_contents;
						k++;
						file_contents = "";
					} else if (((char) i) == '\n') {
						if (k == 0) {
							String pattern = "^%([A-Z]+):\\s*(.*)$";
							Pattern regex = Pattern.compile(pattern);
							Matcher patmatch = regex.matcher(file_contents);
							if (patmatch.find()) {
								if (patmatch.group(1).equals("DATEFORM")) {
									default_date_format = patmatch.group(2);
								} else if (patmatch.group(1).equals("ASTRONOMY")) {
									String theastron = patmatch.group(2);
									if (theastron.equals("moon")) {
										moon_opt = 1;
									} else if (theastron.equals("nomoon")) {
										moon_opt = 0;
									}
								} else if (patmatch.group(1).equals("FIRSTDAY")) {
									String thefirstdow = patmatch.group(2);
									System.out.println("FIRSTDOW:  "+thefirstdow);
									if (thefirstdow.equals("Sunday"))
											first_day_week = 6;
									else if (thefirstdow.equals("Monday"))
										first_day_week = 0;
									else if (thefirstdow.equals("Tuesday"))
										first_day_week = 1;
									else if (thefirstdow.equals("Wednesday"))
										first_day_week = 2;
									else if (thefirstdow.equals("Thursday"))
										first_day_week = 3;
									else if (thefirstdow.equals("Friday"))
										first_day_week = 4;
									else if (thefirstdow.equals("Saturday"))
										first_day_week = 5;
								}
							} else {
								System.out.println("NOT FOUND");
							}
						} else {
							events[j][k] = file_contents;
							k = 0;
							j++;
						}
						file_contents = "";
					} else {
						file_contents += (char) i;
					}
				}
			} catch (IOException e) {
				e.printStackTrace();
			}
			i = 0; k = 0;
			for (j = 0; events[j][0] != null; j++) {
				if (events[j][1].contains("--")) {
					String temp[][] = expand_range.main(events[j][1],events[j]);
					String except[][] = new String[1000][5];
					double except_jdns[] = new double[1000];
					if (events[j][3].contains("--")) {
						except = expand_range.main(events[j][3], events[j]);
						for (String[] item : except) {
							if (item[1] != null)
								except_jdns[k++] = Julian.to_julian(item[1]);
						}
					}
					for (String[] item : temp) {
						Integer isexcept = 0;
						if (item[0] != null) {
							for (k = 0; except_jdns[k] != 0.0; k++) {
								if (except_jdns[k] == Julian.to_julian(item[1])) {
									isexcept = 1;
								}
							}
							if (isexcept == 0)
								if ((Julian.to_julian(item[1]) != Julian.to_julian(item[3])))
									fullevents[i++] = item;
							isexcept = 0;
						}
					}
				} else {
					fullevents[i++] = events[j];
				}
			}
			final Handler handler = new Handler() {
				@Override
				public void handleMessage(Message msg) {
					progress.dismiss();
					set_content(dateunit_content);
				}
			};//if we have a problem, it's here FFF
			progress.show();
			Thread waitforit = new Thread() { public void run() {
				int i;
				for (i = 0; fullevents[i][1] != null; i++);
				SortArray.quickSort(fullevents,0,i-1);
				fullevents = SortArray.chunk_sort(fullevents);
				handler.sendEmptyMessage(0);
			}};
			waitforit.start();
		}
		sub_one.setOnClickListener(new OnClickListener() {
			public void onClick(View v) {
				if (curr_display == 1) {
					usedate = decimalize_date.dozenalize_date(Julian.jdn_to_greg(Julian.to_julian(usedate) - 1,"yyyy-MM-dd"));
					cal.add(Calendar.DAY_OF_MONTH,-1);
				} else if (curr_display == 2) {
					usedate = decimalize_date.dozenalize_date(Julian.jdn_to_greg(Julian.to_julian(usedate) - 7,"yyyy-MM-dd"));
					cal.add(Calendar.DAY_OF_MONTH,-7);
				} else if (curr_display == 3) {
					usedate = decimalize_date.dozenalize_date(Julian.jdn_to_greg(Julian.to_julian(usedate) - 30,"yyyy-MM-dd"));
					cal.add(Calendar.MONTH,-1);
				}
				curr_date.setText(get_datestring(cal));
				set_content(dateunit_content);
			}
		});
		add_one.setOnClickListener(new OnClickListener() {
			public void onClick(View v) {
				if (curr_display == 1) {
					cal.add(Calendar.DAY_OF_MONTH,1);
					usedate = decimalize_date.dozenalize_date(Julian.jdn_to_greg(Julian.to_julian(usedate) + 1,"yyyy-MM-dd"));
				} else if (curr_display == 2) {
					cal.add(Calendar.DAY_OF_MONTH,7);
					usedate = decimalize_date.dozenalize_date(Julian.jdn_to_greg(Julian.to_julian(usedate) + 7,"yyyy-MM-dd"));
				} else if (curr_display == 3) {
					cal.add(Calendar.MONTH,1);
					usedate = decimalize_date.dozenalize_date(Julian.jdn_to_greg(Julian.to_julian(usedate) + 30,"yyyy-MM-dd"));
				}
				curr_date.setText(get_datestring(cal));
				set_content(dateunit_content);
			}
		});
		daily_button.setOnClickListener(new OnClickListener() {
			public void onClick(View v) {
				curr_display = 1;
				pick_display(daily_button,weekly_button,monthly_button);
				curr_date.setText(get_datestring(cal));
				set_content(dateunit_content);
			}
		});
		weekly_button.setOnClickListener(new OnClickListener() {
			public void onClick(View v) {
				curr_display = 2;
				pick_display(daily_button,weekly_button,monthly_button);
				curr_date.setText(get_datestring(cal));
				set_content(dateunit_content);
			}
		});
		monthly_button.setOnClickListener(new OnClickListener() {
			public void onClick(View v) {
				curr_display = 3;
				pick_display(daily_button,weekly_button,monthly_button);
				curr_date.setText(get_datestring(cal));
				set_content(dateunit_content);
			}
		});
		button_settings.setOnClickListener(new OnClickListener() {
			public void onClick(View v) {
				Bundle databundle = new Bundle();
				databundle.putSerializable("caldata",cal);
				databundle.putInt("curr_display", curr_display);
				set_settings.putExtra("saveddata",databundle);
				startActivity(set_settings);
			}
		});
		addnew.setOnClickListener(new OnClickListener() {
			public void onClick(View v) {
				startActivity(addnew_activity);
			}
		});
	}
	
	@SuppressLint("DefaultLocale")
	public String get_datestring(Calendar cal)
	{
		String year = Integer.toString(cal.get(Calendar.YEAR),12);
		String month = Integer.toString(cal.get(Calendar.MONTH)+1,12);
		String day = Integer.toString(cal.get(Calendar.DAY_OF_MONTH),12);
		month = String.format("%2s",month).replace(' ','0');
		day = String.format("%2s",day).replace(' ','0');
		Integer weekday = cal.get(Calendar.DAY_OF_WEEK);
		String dayweek = "";
		String thedate = "";
		if (weekday == 1) {
			dayweek = "Sun";
		} else if (weekday == 2) {
			dayweek = "Mon";
		} else if (weekday == 3) {
			dayweek = "Tue";
		} else if (weekday == 4) {
			dayweek = "Wed";
		} else if (weekday == 5) {
			dayweek = "Thu";
		} else if (weekday == 6) {
			dayweek = "Fri";
		} else if (weekday == 7) {
			dayweek = "Sat";
		}
		usedate = year+"-"+month+"-"+day;
		if (curr_display == 1) {
			thedate = dayweek+", "+year+"-"+month+"-"+day;
		} else if (curr_display == 2) {
			thedate = "Week of "+year+"-"+month+"-"+day;
		} else if (curr_display == 3) {
			thedate = year+"-"+month;
		}
		return doz_chars(thedate);
	}
	public void pick_display(Button daily, Button weekly, Button monthly) {
		if (curr_display == 1) {
			daily.setBackgroundColor(0xFFFFCC00);
			weekly.setBackgroundColor(0xFF800000);
			monthly.setBackgroundColor(0xFF800000);
		} else if (curr_display == 2) {
			daily.setBackgroundColor(0xFF800000);
			weekly.setBackgroundColor(0xFFFFCC00);
			monthly.setBackgroundColor(0xFF800000);
		} else if (curr_display == 3) {
			daily.setBackgroundColor(0xFF800000);
			weekly.setBackgroundColor(0xFF800000);
			monthly.setBackgroundColor(0xFFFFCC00);
		}
	}

	public static String[] get_cal_items() {
		Integer i = 0; Integer j = 0;
		String file_contents[] = new String[1000];
		String phase = "";
		if (curr_display == 1) {
			Double jdn = Julian.to_julian(usedate);
			if (moon_opt == 1) {
				phase = AstronOpts.lunar_phases(jdn);
				if (!phase.equals("") && !phase.equals("-1"))
					file_contents[j++] = "Moon Phase:  "+phase+"<br />";
			}
			for (i = 0; fullevents[i][1] != null; i++) {
				if (fullevents[i][0] != null) {
					if (Julian.to_julian(fullevents[i][1]) == jdn) {
						if (fullevents[i][2].trim().length() != 0) {
							file_contents[j] = timestrip(fullevents[i][2])+"&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp;"+fullevents[i][0]+"<br />";
						} else {
							file_contents[j] = fullevents[i][0]+"<br />";
						}
						j++;
					}
				}
			}
		} else if (curr_display > 1) {
			Double jdn = Julian.to_julian(usedate);
			Double startrange = 0.0;
			Double endrange = 0.0;
			if (curr_display == 2) {
				while (Julian.jdn_to_dow_num(jdn) != first_day_week)
					jdn--;
				startrange = jdn + 1;
				endrange = startrange + 7;
			} else {
				while (Integer.parseInt(Julian.jdn_to_greg(jdn,"dd")) != 1)
					jdn--;
				startrange = jdn;
				jdn++;
				while (Integer.parseInt(Julian.jdn_to_greg(jdn,"dd")) != 1)
					jdn++;
				endrange = jdn;
			}
			Double currdate = startrange;
			for (i = 0; fullevents[i][1] != null; i++) {
				if ((Julian.to_julian(fullevents[i][1]) >= startrange) && (Julian.to_julian(fullevents[i][1]) < endrange)) {
					if ((currdate != Julian.to_julian(fullevents[i][1])) || (j == 0)) {
						file_contents[j++] = "<b>"+doz_chars(decimalize_date.dozenalize_date(Julian.jdn_to_greg(Julian.to_julian(fullevents[i][1]),default_date_format)))+"</b>";
						if (moon_opt == 1) {
							phase = AstronOpts.lunar_phases(currdate+1);
							if (!phase.equals("") && !phase.equals("-1"))
								file_contents[j-1] += "<br />&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp<b>Moon Phase:</b>  "+phase;
						}
						if (fullevents[i][2].trim().length() != 0)
							file_contents[j-1] = file_contents[j-1]+"<br />&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp;"+timestrip(fullevents[i][2])+"&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp;"+fullevents[i][0]+"<br />";
						else
							file_contents[j-1] = file_contents[j-1]+"<br />&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp;"+fullevents[i][0]+"<br />";
					} else {
						if (fullevents[i][2].trim().length() != 0)
							file_contents[j++] = "&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp;"+doz_chars(timestrip(fullevents[i][2]))+"&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp;"+fullevents[i][0]+"<br />";
						else
							file_contents[j++] = "&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp;"+fullevents[i][0]+"<br />";
					}
					currdate = Julian.to_julian(fullevents[i][1]);
				}
			}
		}/* else if (curr_display == 3) {
			Double jdn = Julian.to_julian(usedate);
			while (Integer.parseInt(Julian.jdn_to_greg(jdn,"dd")) != 1)
				jdn--;
			Double startrange = jdn;
			jdn++;
			while (Integer.parseInt(Julian.jdn_to_greg(jdn,"dd")) != 1)
				jdn++;
			Double endrange = jdn - 1;
			Double currdate = startrange;
			for (i = 0; fullevents[i][1] != null; i++) {
				if ((Julian.to_julian(fullevents[i][1]) >= startrange) && (Julian.to_julian(fullevents[i][1]) <= endrange)) {
					if ((currdate != Julian.to_julian(fullevents[i][1])) || (j == 0)) {
						file_contents[j++] = "<b>"+doz_chars(decimalize_date.dozenalize_date(Julian.jdn_to_greg(Julian.to_julian(fullevents[i][1]),default_date_format)))+"</b>";
						if (moon_opt == 1) {
							phase = AstronOpts.lunar_phases(currdate+1);
							if (!phase.equals("") && !phase.equals("-1"))
								file_contents[j-1] += "<br />&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp<b>Moon Phase:</b>  "+phase;
						}
						if (fullevents[i][2].trim().length() != 0)
							file_contents[j-1] = file_contents[j-1]+"<br />&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp;"+timestrip(fullevents[i][2])+"&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp;"+fullevents[i][0]+"<br />";
						else
							file_contents[j-1] = file_contents[j-1]+"<br />&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp;"+fullevents[i][0]+"<br />";
					} else {
						if (fullevents[i][2].trim().length() != 0)
							file_contents[j++] = "&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp;"+timestrip(fullevents[i][2])+"&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp;"+fullevents[i][0]+"<br />";
						else
							file_contents[j++] = "&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp;"+fullevents[i][0]+"<br />";
					}
					currdate = Julian.to_julian(fullevents[i][1]);
				}
			}
		}*/
		return file_contents;
	}
	
	public static void set_content(TextView contentview) {
		Integer i = 0;
		String file_contents = "";
		String[] thelist = new String[1000];
		thelist = get_cal_items();
		for (i = 0; i < thelist.length; i++) {
			if (thelist[i] != null) {
				file_contents += thelist[i];
				file_contents += "\n";
			}
		}
		contentview.setText(Html.fromHtml(file_contents));
		contentview.scrollTo(0,0);
	}

	public static String doz_chars(String string) {
		string = string.replaceAll("([0-9a])a","$1X");
		string = string.replaceAll("([0-9\\*])\\*","$1X");
		string = string.replaceAll("aX","XX");
		string = string.replaceAll("\\*X","XX");
		string = string.replaceAll("([0-9b])b","$1E");
		string = string.replaceAll("([0-9#])#","$1E");
		string = string.replaceAll("bE","EE");
		string = string.replaceAll("#E","EE");
		return string;
	}
	
	public static String timestrip(String time) {
		if (!time.contains("-")) {
			return time;
		} else {
			String[] times = time.split("-");
			return times[0];
		}
	}
	
	@Override
	public boolean onCreateOptionsMenu(Menu menu) {
		// Inflate the menu; this adds items to the action bar if it is present.
		getMenuInflater().inflate(R.menu.main, menu);
		return true;
	}

}
