#ifndef COMMANDS_H
#define	COMMANDS_H

#include <string>
#include <sstream>
#include <curl/curl.h>
#include "config.h"

class commands{

public:
    void init(std::string, std::string);

private:
    std::string getURLBase();
    int screenSaverActive();
    void sendSignal(std::string, int);
    void commandPlayPause();
    void commandSelect();
    void commandStop();
    void commandBack();
    void commandHome();
    void commandUp(int);
    void commandDown(int);
    void commandLeft();
    void commandRight();
    void commandMovies();
    void commandTvShows();
    void commandVolumeUp();
    void commandVolumeDown();
    void commandMuteUnmute();
    void commandYoutube();
    void commandSeekForward();
    void commandSeekBackward();
    
    bool valid;
    std::string curlResponse;
    
    config c;
    
};

#endif	/* COMMANDS_H */
