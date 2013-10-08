package com.example.dozcaldroid;

import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public abstract class decimalize_date {
	
	public static String computerize_date(String date) {
		date = date.replace('X','A');
		date = date.replace('x','A');
		date = date.replace('*','A');
		date = date.replace('#','B');
		date = date.replace('E','B');
		return date;
	}
	
	public static String dozenalize_date(String date) {
		String dozendate = "";
		String placeholder = "";
		Integer holder;
		date += " ";
		for (char c : date.toCharArray()) {
			if (Character.isDigit(c)) {
				placeholder += c;
			} else {
				if (placeholder != "") {
					holder = Integer.parseInt(placeholder);
					placeholder = Integer.toString(holder,12);
					if (placeholder.length() == 1)
						placeholder = "0"+placeholder;
					dozendate += placeholder;
					placeholder = "";
				}
				dozendate += c;
			}
		}
		dozendate.replace(" ","");
		return dozendate;
	}

	public static String simpdec(String date) {
		date = computerize_date(date);
		String decdate = "";
		String placeholder = "";
		Integer holder;
		date += " ";
		for (char c : date.toCharArray()) {
			if ((Character.isDigit(c)) || (c == 'a') || (c == 'b') 
					|| (c == 'A') || (c == 'B')) {
				placeholder += c;
			} else {
				if (placeholder != "") {
					holder = Integer.parseInt(placeholder,12);
					decdate += holder.toString();
					placeholder = "";
				}
				decdate += c;
			}
		}
		decdate.replace(" ","");
		return decdate;
	}
	
	public static String main(String date) {
		String decimaldate = "";
		date = computerize_date(date);
		String pattern1 = "([\\dABab]{1,2})\\s*(\\w+)\\s*([\\dABab]{4})";
		Pattern regex1 = Pattern.compile(pattern1);
		Matcher pat1match = regex1.matcher(date);
		SimpleDateFormat format1 = new SimpleDateFormat("dd MMM yyyy");
		format1.setLenient(false);
		String pattern2 = "(\\w+)\\s*([\\dABab]{1,2})\\s*([\\dABab]{4})";
		Pattern regex2 = Pattern.compile(pattern2);
		Matcher pat2match = regex2.matcher(date);
		SimpleDateFormat format2 = new SimpleDateFormat("MMM dd, yyyy");
		format2.setLenient(false);
		String pattern3 = "([\\dABab]{4})-([\\dABab]{1,2})-([\\dABab]{1,2})";
		Pattern regex3 = Pattern.compile(pattern3);
		Matcher pat3match = regex3.matcher(date);
		SimpleDateFormat format3 = new SimpleDateFormat("yyyy-MM-dd");
		format3.setLenient(false);
		Date testdate = null;
		if (pat1match.find()) {
			decimaldate = pat1match.replaceFirst(String.valueOf(Integer.parseInt(pat1match.group(1),12)));
			decimaldate += " ";
			decimaldate += pat1match.group(2);
			decimaldate += " ";
			decimaldate += pat1match.replaceFirst(String.valueOf(Integer.parseInt(pat1match.group(3),12)));
			try {
				testdate = format1.parse(decimaldate);
			} catch (ParseException e) {
				System.out.println("Format1");
			}
			if (testdate != null) {
				decimaldate = format3.format(testdate);
				return decimaldate;
			}
		} else if (pat2match.find()) {
			decimaldate += pat2match.group(1);
			decimaldate += " ";
			decimaldate += pat2match.replaceFirst(String.valueOf(Integer.parseInt(pat2match.group(2),12)));
			decimaldate += ", ";
			decimaldate += pat2match.replaceFirst(String.valueOf(Integer.parseInt(pat2match.group(3),12)));
			try {
				testdate = format2.parse(decimaldate);
			} catch (ParseException e) {
				System.out.println("Format2\n");
			}
			if (testdate != null)
				return decimaldate;
		} else if (pat3match.find()) {
			decimaldate = pat3match.replaceFirst(String.valueOf(Integer.parseInt(pat3match.group(1),12)));
			decimaldate += "-";
			decimaldate += pat3match.replaceFirst(String.valueOf(Integer.parseInt(pat3match.group(2),12)));
			decimaldate += "-";
			decimaldate += pat3match.replaceFirst(String.valueOf(Integer.parseInt(pat3match.group(3),12)));
			decimaldate.replaceAll("\\s","");
			try {
				testdate = format3.parse(decimaldate);
			} catch (ParseException e) {
				decimaldate.replaceAll("\\s","");
				System.out.println("Format3");
				e.printStackTrace();
			}
			if (testdate != null)
				return decimaldate;
		}
		return "false";
	}
}