package com.example.dozclockwidget;

import android.os.Bundle;
import android.os.Handler;
import android.app.Activity;
import android.view.Menu;
import android.widget.TextView;
import java.text.SimpleDateFormat;
import java.util.*;

public class MainActivity extends Activity {

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		final Handler handler = new Handler();
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);
    	final TextView dateview = (TextView) findViewById(R.id.dateview);
    	final TextView timeview = (TextView) findViewById(R.id.timeview);
    	Timer timer = new Timer();
		final SimpleDateFormat sdf = new SimpleDateFormat("yyyy/MM/dd/HH/mm/ss");
    	timer.scheduleAtFixedRate(new TimerTask() {
        	@Override
			public void run() {
				handler.post(new Runnable() {
		        	public void run() {
		        		String mon = "000";
						String currentdate = sdf.format(new Date());
						String dateparts[] = currentdate.split("/");
						String year = Integer.toString(Integer.parseInt(dateparts[0]),12);
						int month = Integer.parseInt(dateparts[1]);
						if (month == 1) {
							mon = "Jan";
						} else if (month == 2) {
							mon = "Feb";
						} else if (month == 3) {
							mon = "Mar";
						} else if (month == 4) {
							mon = "Apr";
						} else if (month == 5) {
							mon = "May";
						} else if (month == 6) {
							mon = "Jun";
						} else if (month == 7) {
							mon = "Jul";
						} else if (month == 8) {
							mon = "Aug";
						} else if (month == 9) {
							mon = "Sep";
						} else if (month == 10) {
							mon = "Oct";
						} else if (month == 11) {
							mon = "Nov";
						} else {
							mon = "Dec";
						}
						String day = Integer.toString(Integer.parseInt(dateparts[2]),12);
						String hour = Integer.toString(Integer.parseInt(dateparts[3]),12);
						hour = zeropadLeft(hour,2);
						int mins = Integer.parseInt(dateparts[4]);
						int secs = Integer.parseInt(dateparts[5]);
						long tims = Math.round(((mins * 60) + secs) / 0.1736111111111);
						String doztims = Long.toString(tims,12);
						doztims = zeropadLeft(doztims,4);
						String formtime = hour+";"+doztims;
						formtime = formtime.replace("a","X");
						formtime = formtime.replace("b","E");
						day = day.replace("a","X");
						day = day.replace("b","E");
						year = year.replace("a","X");
						year = year.replace("b","E");
						String formdate = day+" "+mon+" "+year;
						dateview.setTextSize(40);
						dateview.setText(formdate);
						timeview.setTextSize(60);
						timeview.setText(formtime);
					}
				});
        	}	
		},170,170);
}

	public static String zeropadLeft(String s, int n) {
		return String.format("%"+n+"s",s).replace(' ','0');
	}

	@Override
	public boolean onCreateOptionsMenu(Menu menu) {
		// Inflate the menu; this adds items to the action bar if it is present.
		getMenuInflater().inflate(R.menu.main, menu);
		return true;
	}
}
