CPP-XBMC-API
============

A simple XBMC remote using the JSON RPC API.

This was built in NetBeans IDE 7.3 so it may be easier if you import this project into a working NetBeans installation and then compile.
The project is meant to be a hobby project for myself, so I will not be providing any documentation with it.

I found it difficult to find any information on how utilize the XBMC API using c++ so feel free to use my code as a base for your own project.

<b>Basic syntax:</b> ./xbmcremote "config file" "signal"

<b>Config file:</b> The path the settings.ini containing your XBMC information.<br />
<b>Signal:</b> Any of the commands listed below.

<b>Signals:</b><br />
<b>play</b> - Play the media currently active in the player.<br />
<b>pause</b> - Pause the media currently active in the player.<br />
<b>stop</b> - Stop the media currently active in the player.<br />
<b>select</b> - Select the current menu item.<br />
<b>back</b> - Go back in menu 1 step.<br />
<b>home</b> - Go to home screen.<br />
<b>up_1</b> - Navigate up 1 time.<br />
<b>up_2</b> - Navigate up 2 times.<br />
<b>up_3</b> - Navigate up 3 times.<br />
<b>up_4</b> - Navigate up 4 times.<br />
<b>up_5</b> - Navigate up 5 times.<br />
<b>up_6</b> - Navigate up 6 times.<br />
<b>up_7</b> - Navigate up 7 times.<br />
<b>up_8</b> - Navigate up 8 times.<br />
<b>up_9</b> - Navigate up 9 times.<br />
<b>up_10</b> - Navigate up 10 times.<br />
<b>down_1</b> - Navigate down 1 time.<br />
<b>down_2</b> - Navigate down 2 times.<br />
<b>down_3</b> - Navigate down 3 times.<br />
<b>down_4</b> - Navigate down 4 times.<br />
<b>down_5</b> - Navigate down 5 times.<br />
<b>down_6</b> - Navigate down 6 times.<br />
<b>down_7</b> - Navigate down 7 times.<br />
<b>down_8</b> - Navigate down 8 times.<br />
<b>down_9</b> - Navigate down 9 times.<br />
<b>down_10</b> - Navigate down 10 times.<br />
<b>left</b> - Navigate left.<br />
<b>right</b> - Navigate right.<br />
<b>movies</b> - Go to the "Movies" title screen.<br />
<b>tvshows</b> - Go to the "TV Shows" title screen.<br />
<b>volume_up</b> - Increate volume by 3.<br />
<b>volume_down</b> - Decrease volume by 3.<br />
<b>mute</b> - Mute sound.<br />
<b>unmute</b> - Unmute sound.<br />
<b>youtube</b> - Go to Youtube add-on.<br />
<b>seek_forward</b> - Seek forward 30 seconds.<br />
<b>seek_backward</b> - Seek backward 30 seconds.<br />
