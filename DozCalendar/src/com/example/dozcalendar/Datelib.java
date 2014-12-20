package com.example.dozcalendar;

import java.text.SimpleDateFormat;
import java.util.Comparator;

public class Datelib {
	SimpleDateFormat sdf = new SimpleDateFormat(MainActivity.date_format);
	public Double jdn;
	public String eventname;
	public Integer timestart;
	public Integer timeend;
	public String eventtype;
	public static Datelib add(Double one, String two, Integer three, 
			Integer four, String five) {
		Datelib newdate = new Datelib(one,two,three,four,five);
		return newdate;
	}
	public Datelib(Double one, String two, Integer three, 
			Integer four, String five) {
		jdn = one;
		eventname = two;
		timestart = three;
		timeend = four;
		eventtype = five;
	}
	public Datelib() {
		jdn = 0.0;
		eventname = "";
		timestart = 0;
		timeend = 0;
		eventtype = "";
	}
	public String getone(int index) {
		String s = "";
		switch (index) {
		case 0: s = jdn.toString(); break;
		case 1: s = eventname; break;
		case 2: s = timestart.toString(); break;
		case 3: s = timeend.toString(); break;
		case 4: s = eventtype; break;
		}
		return s;
	}
	public String print(int currdisplay,int firsttime) {
		String s = "";
		if (currdisplay == 0) {
			if (firsttime == 0) {
				if (MainActivity.moonphases == 1)
					s += Lunar.lunar_phase_symb(jdn);
			}
			if (timestart != 0)
				s += Integer.toString(Integer.parseInt(timestart.toString()),12);
			if (timeend != 0)
				s = s+"--"+Integer.toString(Integer.parseInt(timeend.toString()),12);
			s = s + "\t" + eventname + "\n";
			return s;
		} else {
			if (firsttime == 0) {
				s = s + Numconvert.dozdatestr(sdf.format(Julian.julian_to_date(jdn))) + "\n";
				if (MainActivity.moonphases == 1)
					s += "\t"+Lunar.lunar_phase_symb(jdn);
			}
			s = s + "\t";
			if (timestart != 0)
				s += Integer.toString(Integer.parseInt(timestart.toString()),12);
			if (timeend != 0)
				s = s+"--"+Integer.toString(Integer.parseInt(timeend.toString()),12);
			s = s + "\t" + eventname + "\n";
			return s;
		}
	}
}
class CompareEvents implements Comparator<Datelib> {
	@Override
	public int compare(Datelib date1, Datelib date2) {
		if (date1.jdn > date2.jdn) {
			return 1;
		} else if (date1.jdn < date2.jdn) {
			return -1;
		} else {
			if (date1.timestart > date2.timestart) {
				return 1;
			} else if (date1.timestart < date2.timestart) {
				return -1;
			} else {
				return 0;
			}
		}
	}
}