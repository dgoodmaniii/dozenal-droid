package com.example.dozenaldigitalclock;

import android.os.Bundle;
import android.annotation.SuppressLint;
import android.app.Activity;
import android.content.Context;
import android.view.Menu;
import android.webkit.WebView;

@SuppressLint("SetJavaScriptEnabled")
public class MainActivity extends Activity {
    private static final String Your = null;
	private Context timefield;
	@Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
		  WebView webview = new WebView(this);
		  setContentView(webview);
		  webview.getSettings().setJavaScriptEnabled(true);
		  webview.loadUrl("file:///android_asset/dozclock.html");
		  webview.setBackgroundColor(0x00000000);
    }
    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        // Inflate the menu; this adds items to the action bar if it is present.
        getMenuInflater().inflate(R.menu.main, menu);
        return true;
    }
}
