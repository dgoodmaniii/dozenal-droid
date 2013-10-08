package com.example.dozcaldroid;

import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;

public class AstronOpts {
	
	public static String lunar_phases(double jdn) {
		String phaseret = "-1";
		int thephase = 0;
		SimpleDateFormat sdf = new SimpleDateFormat("yyyy-MM-dd:HH:mm:ss");
		String currentdate = Julian.jdn_to_greg(jdn, "yyyy-MM-dd");
		
		int lp = 2551443; 
		Date now = null;
		Date new_moon = null;
		try {
			now = sdf.parse(currentdate+":"+"20:35:00");
			new_moon = sdf.parse("1970-01-07:20:35:00");
		} catch (ParseException e) {
			e.printStackTrace();
		}
		double phase = ((now.getTime() - new_moon.getTime())/1000) % lp;
		thephase = (int) Math.floor(phase /(24*3600)) + 1;
		phase = phase / (26*3600) + 1;
/*		phaseret += Double.toString(phase);
		if (phase < 2.0)
			phaseret = "New";
		else if ((phase < 8.5) && (phase > 7.5))
			phaseret = "WaxHalf";
		else if ((phase > 14.5) && (phase < 15.5))
			phaseret = "Full";
		else if ((phase > 22.5) && (phase < 23.5))
			phaseret = "WaneHalf";*/
		if (thephase == 1)
			phaseret = "New";
		else if (thephase == 15)
			phaseret = "Full";
		else if (thephase == 23)
			phaseret = "WaneHalf";
		else if (thephase == 8)
			phaseret = "WaxHalf";
		return phaseret;
	}
	
}
