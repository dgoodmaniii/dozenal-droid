package com.example.dozcalendar;

import java.text.SimpleDateFormat;

public class Lunar {
	public static Integer lunar_phase(Double jdn) {
		SimpleDateFormat yyyy = new SimpleDateFormat("yyyy");
		SimpleDateFormat MM = new SimpleDateFormat("MM");
		Integer year = Integer.parseInt(yyyy.format(Julian.julian_to_date(jdn)));
		Integer month = Integer.parseInt(MM.format(Julian.julian_to_date(jdn)));
		Double n = Math.floor(12.37 * (year -1900 + ((1.0 * month - 0.5)/12.0)));
		Double rad = 3.14159265 / 180.0;
		Double t = n / 1236.85;
		Double t2 = t * t;
		Double as = 359.2242 + 29.105356 * n;
		Double am = 306.0253 + 385.816918 * n + 0.010730 * t2;
		Double xtra = 0.75933 + 1.53058868 * n + ((1.178e-4) - (1.55e-7) * t) * t2;
		xtra += (0.1734 - 3.93e-4 * t) * Math.sin(rad * as) - 0.4068 * Math.sin(rad * am);
		Double i;
		if (xtra > 0.0)
			i = Math.floor(xtra);
		else
			i = Math.ceil(xtra - 1);
		Double jd = (2415020 + 28 * n) + i;
		return (int)(jdn - jd + 30) % 30;	
	}
	public static String lunar_phase_symb(Double jdn) {
		Integer phasenum = lunar_phase(jdn);
		if (phasenum == 0) {
			String x = new StringBuilder().appendCodePoint(0x1F311).toString();
			return x + "\n";
		} else if (phasenum == 15) {
			String x = new StringBuilder().appendCodePoint(0x1F315).toString();
			return x + "\n";
		} else if (phasenum == 8) {
			String x = new StringBuilder().appendCodePoint(0x1F313).toString();
			return x + "\n";
		} else if (phasenum == 22) {
			String x = new StringBuilder().appendCodePoint(0x1F317).toString();
			return x + "\n";
		} else {
			return "";
		}
	}
}