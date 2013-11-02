#include "commands.h"

using namespace std;

//Global string stream to store the cURL data
std::ostringstream stream;

//Process the signal
void commands::init(std::string signal, std::string config){

    c.setConfig(config);
    valid = false;
    
    //Check is screen is sleeping, is it is, wake it up
    if(screenSaverActive() == 1){
        commandUp(1);
    }
    
    //Play/Pause
    if(signal == "play" || signal == "pause"){
        commandPlayPause();
    }
    //Stop
    if(signal == "stop"){
        commandStop();
    }
    //Select
    if(signal == "select"){
        commandSelect();
    }
    //Back
    if(signal == "back"){
        commandBack();
    }
    //Home
    if(signal == "home"){
        commandHome();
    }
    //Up 1
    if(signal == "up_1"){
        commandUp(1);
    }
    //Up 2
    if(signal == "up_2"){
        commandUp(2);
    }
    //Up 3
    if(signal == "up_3"){
        commandUp(3);
    }
    //Up 4
    if(signal == "up_4"){
        commandUp(4);
    }
    //Up 5
    if(signal == "up_5"){
        commandUp(5);
    }
    //Up 6
    if(signal == "up_6"){
        commandUp(6);
    }
    //Up 7
    if(signal == "up_7"){
        commandUp(7);
    }
    //Up 8
    if(signal == "up_8"){
        commandUp(8);
    }
    //Up 9
    if(signal == "up_9"){
        commandUp(9);
    }
    //Up 10
    if(signal == "up_10"){
        commandUp(10);
    }
    //Down 1
    if(signal == "down_1"){
        commandDown(1);
    }
    //Down 2
    if(signal == "down_2"){
        commandDown(2);
    }
    //Down 3
    if(signal == "down_3"){
        commandDown(3);
    }
    //Down 4
    if(signal == "down_4"){
        commandDown(4);
    }
    //Down 5
    if(signal == "down_5"){
        commandDown(5);
    }
    //Down 6
    if(signal == "down_6"){
        commandDown(6);
    }
    //Down 7
    if(signal == "down_7"){
        commandDown(7);
    }
    //Down 8
    if(signal == "down_8"){
        commandDown(8);
    }
    //Down 9
    if(signal == "down_9"){
        commandDown(9);
    }
    //Down 10
    if(signal == "down_10"){
        commandDown(10);
    }
    //Left
    if(signal == "left"){
        commandLeft();
    }
    //Right
    if(signal == "right"){
        commandRight();
    }
    //Movies
    if(signal == "movies"){
        commandMovies();
    }
    //Tv Shows
    if(signal == "tvshows"){
        commandTvShows();
    }
    //Volume up
    if(signal == "volume_up"){
        commandVolumeUp();
    }
    //Volume down
    if(signal == "volume_down"){
        commandVolumeDown();
    }
    //Mute/Unmute
    if(signal == "mute" || signal == "unmute"){
        commandMuteUnmute();
    }
    //Youtube
    if(signal == "youtube"){
        commandYoutube();
    }
    
    //If method isn't found
    if(valid == false){
        cout << "No matching method found for: " << signal << endl;
    }
    
}

//Check is screensaver is running
int commands::screenSaverActive(){
    int running = 0;
    std::string active;
    
    sendSignal("{\"jsonrpc\": \"2.0\", \"method\": \"XBMC.GetInfoBooleans\", \"params\": { \"booleans\": [\"System.ScreenSaverActive \"] }, \"id\": 1}", 1);
    active = curlResponse.substr(62, curlResponse.length() - 62);
    active = active.substr(0, active.length() - 2);
    
    if(active == "true"){
        running = 1;
    }
    
    return running;
}

//Get the base URL for the XBMC API
std::string commands::getURLBase(){
    std::string base = "http://" +
        c.getValue("General", "XBMCUsername") + 
        ":" +
        c.getValue("General", "XBMCPassword") +
        "@" +
        c.getValue("General", "XBMCHostname") +
        ":" +
        c.getValue("General", "XBMCPort") +
        c.getValue("General", "XBMCAPIBase");
    
    return base;
}

//Catch the cURL output
size_t write_data(char *ptr, size_t size, size_t nmemb, void *userdata) {
    
    std::ostringstream *stream = (std::ostringstream*)userdata;
    size_t count = size * nmemb;
    stream->write(ptr, count);
    
    return count;
}

//Send the cURL signal
void commands::sendSignal(std::string query, int times){
    
    CURL *curl;
    CURLcode res;
 
    curl = curl_easy_init();
    if(curl){
 
        struct curl_slist *chunk = NULL;
        chunk = curl_slist_append(chunk, "Content-Type: application/json");
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, chunk);

        curl_easy_setopt(curl, CURLOPT_POST, 1);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, query.c_str());
        curl_easy_setopt(curl, CURLOPT_URL, getURLBase().c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &stream);

        for(int x = 1; x <= times; x++){
            res = curl_easy_perform(curl);
            if(res != CURLE_OK){
                fprintf(stderr, "curl_easy_perform() failed: %s\n",
                curl_easy_strerror(res));
            }
            curlResponse = stream.str();
        }
        
        /* always cleanup */ 
        curl_easy_cleanup(curl);
    }
}

//Play/Pause command
void commands::commandPlayPause(){
    sendSignal("{\"jsonrpc\": \"2.0\", \"method\": \"Player.PlayPause\", \"params\": { \"playerid\": 1}, \"id\": 0}", 1);
    valid = true;
}

//Stop command
void commands::commandStop(){
    sendSignal("{\"jsonrpc\": \"2.0\", \"method\": \"Player.Stop\", \"params\": { \"playerid\": 1}, \"id\": 0}", 1);
    valid = true;
}

//Select command
void commands::commandSelect(){
    sendSignal("{\"jsonrpc\": \"2.0\", \"method\": \"Input.Select\"}", 1);
    valid = true;
}

//Back command
void commands::commandBack(){
    sendSignal("{\"jsonrpc\": \"2.0\", \"method\": \"Input.Back\"}", 1);
    valid = true;
}

//Home command
void commands::commandHome(){
    sendSignal("{\"jsonrpc\": \"2.0\", \"method\": \"Input.Home\"}", 1);
    valid = true;
}

//Up command
void commands::commandUp(int times){
    sendSignal("{\"jsonrpc\": \"2.0\", \"method\": \"Input.Up\"}", times);
    valid = true;
}

//Down command
void commands::commandDown(int times){
    sendSignal("{\"jsonrpc\": \"2.0\", \"method\": \"Input.Down\"}", times);
    valid = true;
}

//Left command
void commands::commandLeft(){
    sendSignal("{\"jsonrpc\": \"2.0\", \"method\": \"Input.Left\"}", 1);
    valid = true;
}

//Right command
void commands::commandRight(){
    sendSignal("{\"jsonrpc\": \"2.0\", \"method\": \"Input.Right\"}", 1);
    valid = true;
}

//Movies command
void commands::commandMovies(){
    sendSignal("{\"jsonrpc\": \"2.0\", \"method\": \"GUI.ActivateWindow\", \"params\": {\"window\": \"video\", \"parameters\": [ \"MovieTitles\" ]}}", 1);
    valid = true;
}

//Tv Shows command
void commands::commandTvShows(){
    sendSignal("{\"jsonrpc\": \"2.0\", \"method\": \"GUI.ActivateWindow\", \"params\": {\"window\": \"video\", \"parameters\": [ \"TvShowTitles\" ]}}", 1);
    valid = true;
}

//Volume up command
void commands::commandVolumeUp(){
    int volume;
    int newVolume;
    std::string volumeStr;
    
    sendSignal("{\"jsonrpc\":\"2.0\",\"method\":\"Application.GetProperties\",\"params\":{\"properties\":[\"volume\"]}, \"id\": 1}", 1);
    
    //Get the value
    volumeStr = curlResponse.substr(43, curlResponse.length() - 43);
    volumeStr = volumeStr.substr(0, volumeStr.length() - 2);
    
    //Convert volume string to int
    std::istringstream ssi(volumeStr);
    ssi >> volume;
    
    //Check volume for max value
    if(volume < 97){
        newVolume = volume + 3;
    }else{
        newVolume = 100;
    }
    
    //Convert back to string
    std::stringstream sss;
    sss << newVolume;
    
    //Send signal to change volume
    sendSignal("{\"jsonrpc\":\"2.0\",\"method\":\"Application.SetVolume\",\"params\": {\"volume\": " + sss.str() + "}, \"id\": 1}", 1);

    valid = 1;
}

//Volume down command
void commands::commandVolumeDown(){
    int volume;
    int newVolume;
    std::string volumeStr;
    
    sendSignal("{\"jsonrpc\":\"2.0\",\"method\":\"Application.GetProperties\",\"params\":{\"properties\":[\"volume\"]}, \"id\": 1}", 1);
    
    //Get the value
    volumeStr = curlResponse.substr(43, curlResponse.length() - 43);
    volumeStr = volumeStr.substr(0, volumeStr.length() - 2);
    
    //Convert volume string to int
    std::istringstream ssi(volumeStr);
    ssi >> volume;
    
    //Check volume for min value
    if(volume > 3){
        newVolume = volume - 3;
    }else{
        newVolume = 0;
    }
    
    //Convert back to string
    std::stringstream sss;
    sss << newVolume;
    
    //Send signal to change volume
    sendSignal("{\"jsonrpc\":\"2.0\",\"method\":\"Application.SetVolume\",\"params\": {\"volume\": " + sss.str() + "}, \"id\": 1}", 1);

    valid = 1;
}

//Mute/Unmute command
void commands::commandMuteUnmute(){
    sendSignal("{\"jsonrpc\": \"2.0\", \"method\": \"Application.SetMute\", \"params\": {\"mute\": \"toggle\"}, \"id\": \"1\"}", 1);
    valid = 1;
}

//Youtube command
void commands::commandYoutube(){
    sendSignal("{\"jsonrpc\": \"2.0\",\"method\": \"Addons.ExecuteAddon\",\"params\": {\"wait\": false,\"addonid\": \"plugin.video.youtube\"},\"id\": 1}", 1);
    valid = 1;
}

//Get volume   {"jsonrpc":"2.0","method":"Application.GetProperties","params":{"properties":["volume"]}, id": 1}

// {"jsonrpc": "2.0", "method": "GUI.ActivateWindow", "params": {"window": "video", "parameters": [ "MovieTitles" ]}}

//Get addons {"jsonrpc": "2.0", "method": "Addons.GetAddons", "id": 0}
//Youtube id-> plugin.video.youtube

// {"jsonrpc": "2.0", "method": "GUI.ActivateWindow", "params": {"window": "plugin.video.youtube"}}
// Video 10006
// ActivateWindow(Videos,MovieTitles)