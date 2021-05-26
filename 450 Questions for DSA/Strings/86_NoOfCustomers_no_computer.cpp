#include<bits/stdc++.h>
using namespace std;


/*
runCustomerSimulation (2, “ABBAJJKZKZ”) should return 0

runCustomerSimulation (3, “GACCBDDBAGEE”) should return 1 as ‘D’ was not able to get any computer



runCustomerSimulation (3, “GACCBGDDBAEE”) should return 0

runCustomerSimulation (1, “ABCBCA”) should return 2 as ‘B’ and ‘C’ were not able to get any computer.

runCustomerSimulation(1, “ABCBCADEED”) should return 3 as ‘B’, ‘C’ and ‘E’ were not able to get any computer.

*/


int runCustomerSimulation (int n, string s){
    vector<char>did_ntget;
    set<char>fill_map;
    for(int i = 0; i<s.length();i++){
        char current_person = s[i];
        if ((fill_map.size() == n) && (fill_map.find(current_person)==fill_map.end())){ //Set is filled, and the current person is not in the set
            //So he shouldn't get a computer
            if (!(binary_search(did_ntget.begin(), did_ntget.end(), current_person))) {
                did_ntget.push_back(current_person);
            }
        }
        else if((fill_map.find(current_person)!=fill_map.end())) // if current person is in set, remove him
        {
            fill_map.erase(fill_map.find(current_person));
        }
        else if((fill_map.find(current_person)==fill_map.end())) // Current person not in set, so add him
        {
            fill_map.insert(current_person);
        }
    }
    return did_ntget.size();



}

int main(){
    
    // int n;
    // cin>>n;
    // string s;
    // cin>>s;
    
    
    cout << runCustomerSimulation(2, "ABBAJJKZKZ") << endl;
    cout << runCustomerSimulation(3, "GACCBDDBAGEE") << endl;
    cout << runCustomerSimulation(3, "GACCBGDDBAEE") << endl;
    cout << runCustomerSimulation(1, "ABCBCA") << endl;
    cout << runCustomerSimulation(1, "ABCBCADEED") << endl;
}
