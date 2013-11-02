CPP-XBMC-API
============

A simple XBMC remote using the JSON RPC API.

This was built in NetBeans IDE 7.3 so it may be easier if you import this project into a working NetBeans installation and then compile.
The project is meant to be a hobby project for myself, so I will not be providing any documentation with it.

I found it difficult to find any information on how utilize the XBMC API using c++ so feel free to use my code as a base for your own project.

Basic syntax: ./xbmcremote <config file> <signal>

<config file>: The path the settings.ini containing your XBMC information.
<signal>: Any of the commands listed below.

Signals:

play            Play the media currently active in the player.
pause           Pause the media currently active in the player.
stop            Stop the media currently active in the player.
select          Select the current menu item.
back            Go back in menu 1 step.
home            Go to home screen.
up_1            Navigate up 1 time.
up_2            Navigate up 2 times.
up_3            Navigate up 3 times.
up_4            Navigate up 4 times.
up_5            Navigate up 5 times.
up_6            Navigate up 6 times.
up_7            Navigate up 7 times.
up_8            Navigate up 8 times.
up_9            Navigate up 9 times.
up_10           Navigate up 10 times.
down_1          Navigate down 1 time.
down_2          Navigate down 2 times.
down_3          Navigate down 3 times.
down_4          Navigate down 4 times.
down_5          Navigate down 5 times.
down_6          Navigate down 6 times.
down_7          Navigate down 7 times.
down_8          Navigate down 8 times.
down_9          Navigate down 9 times.
down_10         Navigate down 10 times.
left            Navigate left.
right           Navigate right.
movies          Go to the "Movies" title screen.
tvshows         Go to the "TV Shows" title screen.
volume_up       Increate volume by 3.
volume_down     Decrease volume by 3.
mute            Mute sound.
unmute          Unmute sound.
youtube         Go to Youtube add-on.
seek_forward    Seek forward 30 seconds.
seek_backward   Seek backwards 30 seconds.
