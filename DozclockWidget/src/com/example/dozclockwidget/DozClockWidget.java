package com.example.dozclockwidget;

import java.text.SimpleDateFormat;
import java.util.Date;
import android.app.AlarmManager;
import android.app.PendingIntent;
import android.appwidget.AppWidgetProvider;
import com.example.dozclockwidget.R;
import android.appwidget.AppWidgetManager;
import android.content.ComponentName;
import android.content.Context;
import android.content.Intent;
import android.content.IntentFilter;
import android.net.Uri;
import android.os.Handler;
import android.view.View;
import android.widget.LinearLayout;
import android.widget.RemoteViews;
import android.os.Bundle;

public class DozClockWidget extends AppWidgetProvider {
		@Override
		 public void onUpdate( final Context context, final AppWidgetManager appWidgetManager, int[] appWidgetIds ) {
			final Handler handler = new Handler();  
			final RemoteViews remoteViews;
			RemoteViews widget_timeview;
			final ComponentName dozclockwidget;
			remoteViews = new RemoteViews( context.getPackageName(), R.layout.main_widget );
			dozclockwidget = new ComponentName( context, DozClockWidget.class );
			widget_timeview = new RemoteViews( context.getPackageName(), R.layout.main_widget );
/*			Runnable runnable = new Runnable() {
				public void run() {
					updateClock(context, appWidgetManager, remoteViews, dozclockwidget);
					handler.postDelayed(this,25000);
				}
			};*/
			Intent intent = new Intent(context, DozClockWidget.class);
			intent.setAction(appWidgetManager.ACTION_APPWIDGET_UPDATE);
			intent.putExtra(appWidgetManager.EXTRA_APPWIDGET_IDS, appWidgetIds);
			PendingIntent pendingIntent = PendingIntent.getBroadcast(context, 
				0, intent, PendingIntent.FLAG_UPDATE_CURRENT);
			remoteViews.setOnClickPendingIntent(R.id.widget_timeview,pendingIntent);
			appWidgetManager.updateAppWidget(dozclockwidget,remoteViews);
/*			handler.postDelayed(runnable,25000);*/
		 	updateClock(context,appWidgetManager,remoteViews,dozclockwidget);
		 	appWidgetManager.updateAppWidget(dozclockwidget,remoteViews);
		}
		
		public void updateClock(Context context, AppWidgetManager appWidgetManager, RemoteViews remoteViews, ComponentName dozclockwidget) {
			SimpleDateFormat sdf = new SimpleDateFormat("yyyy/MM/dd/HH/mm/ss/E");
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
			String wday = dateparts[6];
			hour = zeropadLeft(hour,2);
			int mins = Integer.parseInt(dateparts[4]);
			int secs = Integer.parseInt(dateparts[5]);
			long tims = Math.round(((mins * 60) + secs) / 0.1736111111111);
			String doztims = Long.toString(tims,12);
			doztims = zeropadLeft(doztims,4);
			doztims = doztims.substring(0,2);
			String formtime = hour+";"+doztims;
			formtime = formtime.replace("a","X");
			formtime = formtime.replace("b","E");
			year = year.replace("a","X");
			year = year.replace("b","E");
			day = day.replace("a","X");
			day = day.replace("b","E");
			String formdate = wday+" "+day+" "+mon+" "+year;
			remoteViews.setTextViewText( R.id.widget_timeview, formtime);
			remoteViews.setTextViewText( R.id.widget_dateview, formdate);
			appWidgetManager.updateAppWidget(dozclockwidget, remoteViews);
	}

	public static String zeropadLeft(String s, int n) {
		return String.format("%"+n+"s",s).replace(' ','0');
	}
}
