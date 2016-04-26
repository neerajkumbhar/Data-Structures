//
//  main.cpp
//  hashmap_cpp
//
//  Created by Neeraj Kumbhar on 3/1/16.
//  Copyright © 2016 Neeraj Kumbhar. All rights reserved.
//

#include <iostream>
#include <map>
#include <iterator>
#include <cstring>


using namespace std;

int main(int argc, const char * argv[]) {
    
    
//    map <int, int> M;
//    M.insert(pair<int, int> (1,40));
//    M.insert(pair<int, int> (2,20));
//    M.insert(pair<int, int> (3,30));
//    M.insert(pair<int, int> (4,80));
//    
//    map<int, int> :: iterator i;
//    
//    for(i = M.begin(); i!= M.end(); ++i)
//    {
//        cout  <<  '\t' << i->first
//              <<  '\t' << i->second << '\n';
//    }
//
//    int a = M.find(3)->second;
//    cout << a;
    
//    string blah;
//    cout<<"Enter a sentence!!\n";
//    getline(cin, blah);
//    //cin >>blah;
//    cout<<blah;
//    int j=0;
//    int k=0,start=0;
//    string arr[100];
//    while(j<blah.length()){
//        if(blah.at(j)==' '){
//            a[k];
//            break;
//            start=0;
//            k++;
//        }
//        else{
//            arr[k].insert(start,&blah.at(j));
//            start++;
//        }
//        cout<<arr[k];
//        j++;
//    }
    
    
    const char string2[] = "words separated by spaces and punctuation!";
    char *token, *cp;
    
    cp = strdup (string2);
    token = strtok (cp, " ");
    
    map <string, int> M2;
   
    while (token != NULL)
    {
        token = strtok (NULL," ");
      //  cout << "\ntoken : "<< token << endl;

        string my_str(token);
        M2.insert(pair<string, int> (my_str,1));
        
    }
    
    for(auto& x: M2)
    {
        cout << x.first << " : " << x.second << endl;
    }

    
    return 0;
}
