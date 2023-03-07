#include <bits/stdc++.h>
using namespace std;


vector<pair<int, string>> get_top_n_collections(multiset<pair<int, string>, greater<pair<int, string>>> top_collections)
{
    vector<pair<int, string>> top;
    for (auto it : top_collections)
    {
        top.push_back(it);
    }
    return top;
}


void display_top_n(vector<pair<int, string>> top)
{
    for (auto entry : top)
    {
        cout << "total size " << entry.first << " belonging to collection " << entry.second << endl;
    }
}

int main()
{
    int n;
    cin >> n;
    int n_files;
    cin >> n_files;
    vector<vector<string>> input;
    unordered_map<string, int> collection_size;
    int tot_size = 0;

    input.push_back({"file1", "100", "collection1"});
    input.push_back({"file2", "200"});
    input.push_back({"file3", "300", "collection3"});
    input.push_back({"file4", "400", "collection3"});
    input.push_back({"file5", "300", "collection2"});
    multiset < pair<int, string>, greater<pair<int, string>>> top_collections;
    for (auto inp : input)
    {
        if (inp.size() == 3)
        {
            int siz = stoi(inp[1]);
            string collection = inp[2];
            string file = inp[0];
            collection_size[collection] += siz;
            tot_size += siz;
        }
        if (inp.size() == 2)
        {
            int siz = stoi(inp[1]);
            string file = inp[0];
            tot_size += siz;
        }
    }
    for (auto it : collection_size)
    {
        //pair<int, string> inp = make_pair{it.second, it.first};
        top_collections.insert(make_pair(it.second, it.first));
    }

    cout << " total size of files in the system is " << tot_size << endl;
    display_top_n(get_top_n_collections(top_collections));

    return 0;
}

// n is the number of files
//m is the number of collections
//O(n+m(log(m)))

