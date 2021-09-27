#include <bits/stdc++.h>
using namespace std;
int main()
{

    map<string, int> varMap;
    string command;

    while (getline(cin, command))
    {

        stringstream sstream(command);
        string instruction, variable, value, optr;

        getline(sstream, instruction, ' ');

        if (instruction == "def")
        {

            getline(sstream, variable, ' ');
            getline(sstream, value, ' ');
            varMap[variable] = stoi(value);
            //    stringstream (value) >>varMap[variable];
        }
        else if (instruction == "calc")
        {
            bool unknown = false;
            int total = 0;
            getline(sstream, variable, ' ');
            getline(sstream, optr, ' ');

            if (varMap.count(variable) == 0)
                unknown = true;
            else
            {
                total = varMap[variable];
                while (optr != "=")
                {
                    getline(sstream, variable, ' ');
                    if (varMap.count(variable) == 0)
                    {
                        unknown = true;
                        break;
                    }
                    if (optr == "+")
                        total = total + varMap[variable];
                    else
                        total = total - varMap[variable];
                    getline(sstream, optr, ' ');
                } 
            }
            cout << command.substr(5, command.length());
            if (unknown)
                cout << " unknown" << endl;
            else
            {
                unknown = true;
                for (auto it : varMap)
                    if (it.second == total)
                    {
                        cout << " " << it.first << endl;
                        unknown = false;
                    }
                if (unknown)
                    cout << " unknown" << endl;
            }
        }
        else if (instruction == "clear")
            varMap.clear();
    }

    return 0;
}
