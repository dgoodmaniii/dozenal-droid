package com.example.dozcalendar;

import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.Date;

public class Julian {

	public static Integer jdn_to_dow_num(double jdn) {
		Integer i = (int) jdn;
		return (i+1) % 7;
	}

	public static double to_julian(Date date) {
		Double jdn = 0.0;
		Calendar cal = Calendar.getInstance();
		cal.setTime(date);
		int a = (int) Math.floor((14 - cal.get(Calendar.MONTH)) / 12);
		int y = cal.get(Calendar.YEAR) + 4800 - a;
		int m = cal.get(Calendar.MONTH) + 1 + (12 * a) - 3;
		jdn = cal.get(Calendar.DAY_OF_MONTH) + Math.floor((153*m + 2) / 5)
				+ (365 * y) + Math.floor(y / 4) - Math.floor(y / 100)
				+ Math.floor(y / 400) - 32045;
		// ugly hack to fix wrong results for March
		if (cal.get(Calendar.MONTH) == 2) {
			if (isleap_year(cal.get(Calendar.YEAR)) == 1)
				jdn -= 2;
			else
				jdn -= 1;
		}
		return jdn - 0.5;
	}
	public static Date julian_to_date(Double jdn) {
		int y = 4716; int v = 3; int j = 1401; int u = 5;
		int m = 2; int s = 153; int n = 12; int w = 2;
		int r = 4; int B = 274277; int p = 1461; int C = -38;
		int f, e, g, h; Integer J = (int) Math.ceil(jdn);
		int D; int M; int Y;
		f = J + j + (((4 * J + B) / 146097) * 3) / 4 + C;
		e = r * f + v;
		g = (e % p) / r;
		h = u * g + w;
		D = (h % s) / u + 1;
		M = (((h / s) + m) % n);
		Y = (e / p) - y + (n + m - M) / n;
		if (M == 2)
			Y--;
		Calendar cal = Calendar.getInstance();
		cal.set(Calendar.DAY_OF_MONTH,D);
		cal.set(Calendar.MONTH,M);
		cal.set(Calendar.YEAR,Y);
		return cal.getTime();
	}
	public static int dow_num(Date date) {
		Calendar cal = Calendar.getInstance();
		cal.setTime(date);
		return cal.get(Calendar.DAY_OF_WEEK) - 1;
	}
	public static int day_of_month(Date date) {
		Calendar cal = Calendar.getInstance();
		cal.setTime(date);
		cal.getTime();
		return cal.get(Calendar.DAY_OF_MONTH);
	}
	public static int len_of_month(Date date) {
		Calendar cal = Calendar.getInstance();
		cal.setTime(date);
		cal.getTime();
		int mon = cal.get(Calendar.MONTH);
		switch (mon) {
		case 3 : case 5 : case 8 : case 10: return 30;
		case 0 : case 2 : case 4 : case 6 : case 7 : case 9 : 
		case 11 : return 31;
		case 1:
			if (isleap_year(cal.get(Calendar.YEAR)) == 0)
				return 29;
			else
				return 28;
		}
		return 0;
	}
	public static int isleap_year(int year) {
		if (((year % 4) == 0) && ((year % 100) != 0)) {
				return 0;
		} else if (((year % 100) == 0) && ((year % 400) == 0)) {
			return 0;
		} else {
			return 1;
		}
	}
	public static Double parse_datestring(String s) {
		SimpleDateFormat formats[] = {
				new SimpleDateFormat("yyyy-MM-dd"),
				new SimpleDateFormat("yyyy-MMM-dd"),
				new SimpleDateFormat("yyyy/MM/dd"),
				new SimpleDateFormat("yyyy/MMM/dd"),
				new SimpleDateFormat("dd MMM yyyy"),
				new SimpleDateFormat("dd MMMM yyyy"),
				new SimpleDateFormat("MMM dd, yyyy"),
				new SimpleDateFormat("MMMM dd, yyyy"),
		};
		int i;
		for (i = 0; i <= 7; ++i) {
			try {
				if (formats[i].parse(s) != null)
					return Julian.to_julian(formats[i].parse(s));
			} catch (java.text.ParseException e) {
				//continue
			}
		}
		return 0.0;
	}
	public static String[] parse_intermitt(String inter, Integer days[],Integer months[]) {
		String[] datestrings = new String[365];
		SimpleDateFormat standard = new SimpleDateFormat("dd MMM yyyy");
		Calendar cal = Calendar.getInstance();
		int whichone = intermit_val(inter);
		int i, j; int k = 0;
		for (i = 0; months[i] != null; ++i) {
			for (j = 0; days[j] != null; ++j) {
				cal.set(Calendar.MONTH, months[i]);
				cal.set(Calendar.DAY_OF_MONTH, 1);
				while (cal.get(Calendar.DAY_OF_WEEK) != days[j])
					cal.add(Calendar.DAY_OF_MONTH,1);
				switch (whichone) {
				case 0:
					while(cal.get(Calendar.MONTH) == months[i]) {
						datestrings[k++] = standard.format(cal.getTime());
						cal.add(Calendar.DAY_OF_MONTH,7);
					}
					break;
				case 1: 
					datestrings[k++] = standard.format(cal.getTime()); 
					break;
				case 2: 
					cal.add(Calendar.DAY_OF_MONTH,7);
					datestrings[k++] = standard.format(cal.getTime());
					break;
				case 3: 
					cal.add(Calendar.DAY_OF_MONTH,14);
					datestrings[k++] = standard.format(cal.getTime());
					break;
				case 4: 
					cal.add(Calendar.DAY_OF_MONTH,21);
					datestrings[k++] = standard.format(cal.getTime());
					break;
				case 5:
					cal.add(Calendar.MONTH,1);
					while (cal.get(Calendar.DAY_OF_WEEK) != days[j])
						cal.add(Calendar.DAY_OF_MONTH,-1);
					datestrings[k++] = standard.format(cal.getTime());
					break;
				}
			}
		}
		return datestrings;
	}
	public static int intermit_val(String inter) {
		if (inter.equals("Every"))
			return 0;
		else if (inter.equals("1st"))
			return 1;
		else if (inter.equals("2nd"))
			return 2;
		else if (inter.equals("3rd"))
			return 3;
		else if (inter.equals("4th"))
			return 4;
		else
			return 5;
	}
}
