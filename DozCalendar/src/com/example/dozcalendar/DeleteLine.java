package com.example.dozcalendar;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.atomic.AtomicBoolean;
import android.annotation.SuppressLint;
import android.os.Environment;
import android.os.Handler;
import android.os.Message;
import android.view.View;
import android.widget.ProgressBar;

@SuppressLint("HandlerLeak")
public class DeleteLine {
	ProgressBar bar;
	Handler handler = new Handler() {
		@Override
		public void handleMessage(Message msg) {
			if (msg.what == 0) {
				isRunning.set(false);
				bar.setVisibility(View.GONE);			
			}
		}
	};
	AtomicBoolean isRunning = new AtomicBoolean(false);
	
	public static void delete_opt(String option) {
		final List<String> lines = new ArrayList<String>();
		String filename = "caldata";
		final String removeopt = option;
		final File file = new File(Environment.getExternalStorageDirectory(),filename );
		final BufferedReader datafile;
		try {
			datafile = new BufferedReader(new FileReader(file));
/*			Thread background = new Thread(new Runnable() {
				public void run() {*/
					String line;
					try {
						while ((line = datafile.readLine()) != null) {
							if (line.startsWith(removeopt) == false)
								lines.add(line);
						}
					} catch (IOException e) {
						e.printStackTrace();
					}
					try {
						datafile.close();
					} catch (IOException e) {
						e.printStackTrace();
					}
					FileOutputStream fos;
					try {
						fos = new FileOutputStream(file, false);
						for (String s : lines) {
							fos.write(s.getBytes());
							fos.write("\n".getBytes());
						}
						fos.close();
					} catch (FileNotFoundException e) {
						e.printStackTrace();
					} catch (IOException e) {
						e.printStackTrace();
					}
/*				}
			});
			background.start();*/
		} catch (FileNotFoundException e1) {
			e1.printStackTrace();
		}
	}
}