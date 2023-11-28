#include <iostream>
#include <queue>
#include <set>
#include <map>

using namespace std;

// Diferencia de vector de conjuntos
// Eg: Si vs=[{0,1,2,3},{2,3,4,5}] , entonces s1={0,1,4,5}
void only1(vector<set<int>> &vs, set<int> &s1){
    map<int,int> num;
    set<int>::iterator j;
    for (int i = 0;  i<vs.size() ; i++) {
        set<int> conjunto = vs[i];
        for(j=conjunto.begin(); j!=conjunto.end(); ++j){
            int val = *j;
            if(num.find(val) == num.end())
                num[val] = 0;
            ++num[val];                                                     //he heq
            /*if (num.find(val) != num.end())
                num[val]++;
            else
                num[val] = 1;*/
        }
    }

    map<int,int>::iterator it;
    for(it=num.begin(); it!=num.end(); ++it )
        if(num[it->second] == 1) s1.insert(it->first);

}


int main() {
    vector<set<int>> vs;
    vs.push_back({0,1,2,3});
    vs.push_back({2,3,4,5});
    set<int> s1;

    only1(vs, s1);
    // imprimir s1
    set<int>::iterator j;
    for(j=s1.begin(); j!=s1.end(); ++j)
        cout << *j << " ";

    return 0;
}
