package com.example.dozcaldroid;

import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.Date;

public class Julian {

	public static Integer wkdayname_to_num(String name) {
		Integer wkdaynum = 0;
		if (name.equals("mon"))
			wkdaynum = 0;
		else if (name.equals("tue"))
			wkdaynum = 1;
		else if (name.equals("wed"))
			wkdaynum = 2;
		else if (name.equals("thu"))
			wkdaynum = 3;
		else if (name.equals("fri"))
			wkdaynum = 4;
		else if (name.equals("sat"))
			wkdaynum = 5;
		else if (name.equals("sun"))
			wkdaynum = 6;
		return wkdaynum;
	}
	
	public static Integer monname_to_num(String name) {
		Integer monnum = 0;
		if (name == "jan")
			monnum = 0;
		else if (name == "feb")
			monnum = 1;
		else if (name == "mar")
			monnum = 2;
		else if (name == "apr")
			monnum = 3;
		else if (name == "may")
			monnum = 4;
		else if (name == "jun")
			monnum = 5;
		else if (name == "jul")
			monnum = 6;
		else if (name == "aug")
			monnum = 7;
		else if (name == "sep")
			monnum = 8;
		else if (name == "oct")
			monnum = 9;
		else if (name == "nov")
			monnum = 10;
		else if (name == "dec")
			monnum = 11;
		return monnum;
	}
	
	public static Integer jdn_to_dow_num(double jdn) {
		Integer i = (int) jdn;
		return i % 7;
	}
	
	// "longshort" is 0 if you want short, 1 if long
	public static String jdn_to_dow(double jdn,Integer longshort) {
		if ((jdn % 7) == 0)
			return (longshort == 0) ? "Sun" : "Sunday";
		else if ((jdn % 7) == 1)
			return (longshort == 0) ? "Mon" : "Monday";
		else if ((jdn % 7) == 2)
			return (longshort == 0) ? "Tue" : "Tuesday";
		else if ((jdn % 7) == 3)
			return (longshort == 0) ? "Wed" : "Wednesday";
		else if ((jdn % 7) == 4)
			return (longshort == 0) ? "Thu" : "Thursday";
		else if ((jdn % 7) == 5)
			return (longshort == 0) ? "Fri" : "Friday";
		else if ((jdn % 7) == 6)
			return (longshort == 0) ? "Sat" : "Saturday";
		return "";
	}
	
	public static String jdn_to_greg(double jdn, String format) {
		Integer y = 4716;
		Integer j = 1401;
		Integer m = 2;
		Integer n = 12;
		Integer r = 4;
		Integer p = 1461;
		Integer v = 3;
		Integer u = 5;
		Integer s = 153;
		Integer w = 2;
		Integer B = 274277;
		Integer C = -38;
		Integer J = (int) Math.floor(jdn);
		Integer f, e, g, h, day, month, year;
		String startformat = "dd MM yyyy";
		SimpleDateFormat userformat = new SimpleDateFormat(format);
		SimpleDateFormat start_format = new SimpleDateFormat(startformat);
		
		f = J + j;
		f = f + (((4 * J + B) / 146097) * 3) / 4 + C;
		e = r * f + v;
		g = (e % p) / r;
		h = u * g + w;
		day = ((h % s) / u);
		month = (((h / s) + m) % n);
		year = e / p - y + (n + m - month) / n;
		month += 1;
		Date thisdate = null;
		try {
			thisdate = start_format.parse(day+" "+month+" "+year);
		} catch (ParseException e1) {
			e1.printStackTrace();
		}
		return userformat.format(thisdate);
	}
	
	public static double to_julian(String date) {
		String decdate = decimalize_date.simpdec(date);
		if (decdate.matches("^.*[A-Za-z]+.*$")) {
			decdate = decimalize_date.main(date);
		}
		SimpleDateFormat iso = new SimpleDateFormat("yyyy-MM-dd");
		try {
			Date thisdate = iso.parse(decdate);
			Calendar thiscal = Calendar.getInstance();
			thiscal.setTime(thisdate);
			Integer a = (14 - (thiscal.get(Calendar.MONTH) + 1)) / 12;
			Integer y = thiscal.get(Calendar.YEAR) + 4800 - a;
			Integer m = (thiscal.get(Calendar.MONTH) + 1) + (12 * a) - 3;
			double jdn = (thiscal.get(Calendar.DAY_OF_MONTH) + 1) +
					(((153 * m) + 2) / 5) + (365 * y) + (y / 4) - (y /
					100) + (y / 400) - 32045;
			return jdn;
		} catch (ParseException e) {
			e.printStackTrace();
		}
		return 0.0;
	}
	
	public static String isoize(String date) {
		date = decimalize_date.computerize_date(date);
		String testdate = decimalize_date.dozenalize_date(decimalize_date.main(date));
		if (testdate.contains("false"))
			return date;
		else
			return testdate;
	}
	
}
