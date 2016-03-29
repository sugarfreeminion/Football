/*************************************************************************
 * Author:          sugarfreeoh
 * Date:            19 March 2016
 * Description:     Each input row includes a test case with lists of
 *                  countries. print a list of countries where people
 *                  root for the team.
 *************************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <map>

using namespace std;

int main(int argc, char *argv[])
{
    ifstream inputFile;

    inputFile.open(argv[1]);

    if(inputFile.is_open())
    {
        string line;

        while(getline(inputFile,line))
        {
            stringstream ss;

            string temp;

            unsigned int countryIndex = 1;

            map< unsigned int,vector<unsigned int> > teamCountries;

            ss << line;

            while(getline(ss,temp,'|'))
            {
                stringstream teamSS;
                string tempTeam;

                if(temp[0] == ' ')
                    temp = temp.substr(1);
                
                if(temp[temp.size()-1] == ' ')
                    temp = temp.substr(0,temp.size()-1);

                //cout << "TEAMS: " << temp << endl;

                teamSS << temp;

                while(getline(teamSS,tempTeam,' '))
                {
                    stringstream temp;
                    unsigned int team;

                    temp << tempTeam;
                    temp >> team;

                    //cout << "Team: " << team << endl;

                    teamCountries[team].push_back(countryIndex);
                }

                ++countryIndex;
            }
            
            countryIndex = 0;

            for(map< unsigned int, vector<unsigned int> >::const_iterator it=teamCountries.begin();
                it != teamCountries.end();
                ++it)
            {
                cout << it->first << ":";

                for(vector<unsigned int>::const_iterator itr=it->second.begin();
                    itr != it->second.end();
                    ++itr)
                {
                    if(itr == it->second.end()-1)
                        cout << *itr << ";";
                    else
                        cout << *itr << ",";

                }

                if(countryIndex == teamCountries.size()-1)
                    cout << endl;
                else
                    cout << " ";

                ++countryIndex;
            }
        }
    }

    return 0;
}
