package com.example.dozcalendar;

public class Numconvert {
	public static String dozdatestr(String s) {
		int i, n, j;
		String news = "";
		String olds = s + " ";
		n = olds.length();
		String currnum = "";
		j = 0;
		for (i = 0; i < n; ++i) {
			char c = olds.charAt(i);
			if (Character.isDigit(c)) {
				currnum = currnum + c;
				j++;
			} else {
				if (j > 0) {
					String m = "";
					m = Integer.toString(Integer.parseInt(currnum),12);
					if (m.length() < j) {
						while (j-- > m.length()) {
							news = news + "0";
						}
					}
					news = news + doz_prettify(m);
					currnum = "";
					j = 0;
					news = news + c;
				} else {
					news = news + c;
				}
			}
		}
		return news;
	}
	public static char doz_charify(char c) {
		if ((c == 'a') || (c == 'A'))
			return 'X';
		else if ((c == 'b') || (c == 'B'))
			return 'E';
		else
			return c;
	}
	public static String doz_prettify(String s) {
		s = s.replaceAll("a",MainActivity.xdig);
		s = s.replaceAll("b",MainActivity.edig);
		return s;
	}
	public static String decdatestr(String s) {
		if (s == "")
			return "";
		int i, n, j;
		String news = "";
		String olds = s + " ";
		n = olds.length();
		String currnum = "";
		j = 0;
		for (i = 0; i < n; ++i) {
			char c = olds.charAt(i);
			if (isDozDigit(c) == 0) {
				currnum = currnum + c;
				j++;
			} else {
				if (j > 0) {
					String m = "";
					currnum = currnum.replace('*','a');
					currnum = currnum.replace('#','b');
					Integer decnum = Integer.parseInt(currnum,12);
					m = Integer.toString(decnum);
					if (m.length() < j) {
						while (j-- > m.length()) {
							news = news + "0";
						}
					}
					news = news + m;
					currnum = "";
					j = 0;
					news = news + c;
				} else {
					news = news + c;
				}
			}
		}
		return news;
	}
	public static int isDozDigit(char c) {
		if (Character.isDigit(c) || (c == '*') || (c == '#'))
			return 0;
	 	else
			return 1;
	}
	public static Integer[] parse_timestring(String s) {
		Integer time[] = {0, 0};
		s = s.replace('*','a'); s = s.replace('#','b');
		s = s.replace(";","");s = s.replace(";","");
		String timeparts[] = {"",""};
		if (s.contains("--")) {
			timeparts = s.split("--");
		} else {
			timeparts[0] = s;
		}
		if (timeparts[0] != "")
			time[0] = Integer.parseInt(timeparts[0],12);
		if (timeparts[1] != "")
			time[1] = Integer.parseInt(timeparts[1],12);
		return time;
	}
}
