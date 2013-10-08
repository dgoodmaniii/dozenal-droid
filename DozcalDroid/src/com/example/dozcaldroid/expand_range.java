package com.example.dozcaldroid;

import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.Date;

public class expand_range {
	public static String[][] main(String daterange, String[] theevent) {
		Calendar startrange = Calendar.getInstance();
		Calendar endrange = Calendar.getInstance();
		String decimaldate_start = "";
		String decimaldate_end = "";
		SimpleDateFormat format1 = new SimpleDateFormat("dd MM yyyy");
		SimpleDateFormat format2 = new SimpleDateFormat("MMM dd, yyyy");
		SimpleDateFormat format3 = new SimpleDateFormat("yyyy-MM-dd");
		Date startdate = null;
		Date enddate = null;
		String eventrange[][] = new String[1000][5];
		
//		if (!daterange.contains("--")) {
//			theevent[1] = theevent[3];
//			System.out.println("WHAT?:  "+theevent[3]);
//			eventrange[0] = theevent;
//			return eventrange;
//		}
		String parts[] = daterange.split("--",2);
		parts[0] = decimalize_date.main(parts[0]);
		parts[1] = decimalize_date.main(parts[1]);
		try {
			startdate = format1.parse(parts[0]);
		} catch (ParseException e) {
			e.printStackTrace();
		}
		if (startdate == null) {
			try {
				startdate = format2.parse(parts[0]);
			} catch (ParseException e) {
				e.printStackTrace();
			}
		}
		if (startdate == null) {
			try {
				startdate = format3.parse(parts[0]);
			} catch (ParseException e) {
				e.printStackTrace();
			}
		}
		try {
			enddate = format1.parse(parts[1]);
		} catch (ParseException e) {
			e.printStackTrace();
		}
		if (enddate == null) {
			try {
				enddate = format2.parse(parts[1]);
			} catch (ParseException e) {
				e.printStackTrace();
			}
		}
		if (enddate == null) {
			try {
				enddate = format3.parse(parts[1]);
			} catch (ParseException e) {
				e.printStackTrace();
			}
		}
		startrange.setTime(startdate);
		endrange.setTime(enddate);
		eventrange[0] = theevent;
		Integer i = 0;
		while (!startrange.equals(endrange)) {
			String thisdate = format3.format(startrange.getTime());
			String[] thistime = { theevent[0], decimalize_date.dozenalize_date(thisdate), theevent[2],theevent[3],theevent[4] };
			eventrange[i++] = thistime;
			startrange.add(Calendar.DAY_OF_MONTH,1);
		}
		String thisdate = format3.format(startrange.getTime());
		String[] thistime = { theevent[0], decimalize_date.dozenalize_date(thisdate), theevent[2],theevent[3],theevent[4] };
		eventrange[i++] = thistime;
		return eventrange;
	}

}