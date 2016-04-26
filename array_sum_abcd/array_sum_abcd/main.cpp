//
//  main.cpp
//  array_sum_abcd
//
//  Created by Neeraj Kumbhar on 3/22/16.
//  Copyright © 2016 Neeraj Kumbhar. All rights reserved.
//

#include <iostream>
#include <map>

using namespace std;

bool findPairs(int arr[], int n)
{
    
    map<int, pair<int, int> > Hash;
    

    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            int sum = arr[i] + arr[j];
            
            if(Hash.find(sum) == Hash.end())
                Hash[sum] = make_pair(i, j);
            
            else
            {
                pair<int, int> pp = Hash[sum];
                cout << "("  << arr[pp.first] << "," << arr[pp.second] << ") and ("
                << arr[i] << "," << arr[j] << ")\n";
                return true;
                
            }
        }
    }
    
    cout << "No pairs found";
    return false;
}

int main(int argc, const char * argv[]) {

        int arr[] = {1,2,5,4,6,9};
        int n  =  sizeof arr / sizeof arr[0];
        findPairs(arr, n);
        return 0;

}
