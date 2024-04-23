#include <ESP8266HTTPClient.h>

class HTTP {
private:
	String ip, port;
public:
	HTTP(String ip, String port);
	
	void Send(String path);
	void Send(String path, String body);
};