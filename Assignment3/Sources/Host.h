#ifndef SETUP_H
#define SETUP_H

using namespace std;


class Host
{
	private:
		string Mode;
		int Players;
		string IP;
		vector<string> ConnectedIPs;
		double FPS;

	public:
		Host();
		void setMode(string mode);
		void setPlayers(int players);
		void setIP(string ip);
		void setConnectedIPs(vector<string> connips);
		void setFPS(double fps);

		string getMode();
		int getPlayers();
		string getIP();
		vector<string> getConnectedIPs();
		double getFPS();

		//void CreateBoard();		//Creates board with certain no. of players.	
};
#endif