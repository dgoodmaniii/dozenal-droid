package com.example.dozcaldroid;

import java.util.*;

public class SortArray {

    public static void main(final String[][] data) {

        Arrays.sort(data, new Comparator<String[]>() {
            @Override
            public int compare(final String[] entry1, final String[] entry2) {
                final String col1 = entry1[0];
                final String col2 = entry2[0];
                return col1.compareTo(col2);
            }
        });

        for (final String[] s : data) {
            System.out.println(s[0] + " " + s[1]);
        }
    }
    
    public static String[][] chunk_sort (final String[][] fullevents) {
    	int i = 0; int j = 0;
    	double currdate = Julian.to_julian(fullevents[0][1]);
    	String[][] chunk = new String[1000][5];
    	String[][] whole = new String[1000][5];
    	int wholeels = 0;
    	
    	while (fullevents[i][1] != null) {
    		if (currdate == Julian.to_julian(fullevents[i][1])) {
    			chunk[j++] = fullevents[i];
    		} else {
    			tquickSort(chunk,0,j-1);
    			System.arraycopy(chunk,0,whole,wholeels,j);
    			wholeels += j;
    			j = 0;
    			Arrays.fill(chunk,null);
    			currdate = Julian.to_julian(fullevents[i][1]);
    			i--;
    		}
    		i++;
    	}
    	return whole;
    }

    //these four methods from http://www.algolist.net/Algorithms/Sorting/Quicksort, 
    //which seemed to be inviting use
    static int partition(String arr[][], int left, int right)
    {
          int i = left, j = right;
          String[] tmp = new String[5];
          double pivot = Julian.to_julian(arr[(left + right) / 2][1]);
          while (i <= j) {
                while (Julian.to_julian(arr[i][1]) < pivot)
                      i++;
                while (Julian.to_julian(arr[j][1]) > pivot)
                      j--;
                if (i <= j) {
                      tmp = arr[i];
                      arr[i] = arr[j];
                      arr[j] = tmp;
                      i++;
                      j--;
                }
          };
          return i;
    }
    
    static int tpartition(String arr[][], int left, int right)
    {
          int i = left, j = right;
          String[] tmp = new String[5];
          double pivot = doztime_to_int(arr[(left + right) / 2][2]);
          while (i <= j) {
                while (doztime_to_int(arr[i][2]) < pivot)
                      i++;
                while (doztime_to_int(arr[j][2]) > pivot)
                      j--;
                if (i <= j) {
                      tmp = arr[i];
                      arr[i] = arr[j];
                      arr[j] = tmp;
                      i++;
                      j--;
                }
          };
          return i;
    }
     
    public static void quickSort(String arr[][], int left, int right) {
          int index = partition(arr, left, right);
          if (left < index - 1)
                quickSort(arr, left, index - 1);
          if (index < right)
                quickSort(arr, index, right);
    }
    
    public static void tquickSort(String arr[][], int left, int right) {
        int index = tpartition(arr, left, right);
        if (left < index - 1)
              tquickSort(arr, left, index - 1);
        if (index < right)
              tquickSort(arr, index, right);
  }
    	
    // returns number of biquas for short TGM time
    public static Integer doztime_to_int(String time) {
    	String times[] = { time, time };
    	if (time.contains("-"))
    		times = time.split("-");
    	time = times[0];
    	if (time.trim().length() == 0)
    		return -1;
    	String split[] = time.split(";");
    	int hours = Integer.parseInt(decimalize_date.computerize_date(split[0]),12);
    	int biquas = Integer.parseInt(decimalize_date.computerize_date(split[1]),12);
    	hours *= 144;
    	biquas += hours;
    	return biquas;
    }
    
}