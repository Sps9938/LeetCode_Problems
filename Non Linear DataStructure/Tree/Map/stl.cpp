#include<iostream>
#include<unordered_map>
#include<map>
using namespace std;
int main(){

    unordered_map<string,int> mp;
    pair<string, int> pr = make_pair("satya", 10);
    mp.insert(pr);

    pair<string,int>p1("mohit",30);
    mp.insert(p1);

    mp["subash"]=40;

    map<string,int> mp1;
    mp1["rohit"]=50;
    mp1["mohit"]=80;
    mp1["ram"]=20;
    mp1["abhi"]=30;

    // for(auto i : mp1){
    //     cout<<i.first<<"="<<i.second<<endl;
    // }
    cout<<mp1["subash"]<<endl;//insert bset approach

    cout<<"size= "<<mp1.size();//find the size of the map
    cout<<endl;
      for(auto i : mp1){
        cout<<i.first<<"="<<i.second<<endl;
    }
cout<<endl;
// if(mp1.find("moht") != mp1.end()){
//     cout<<"found"<<endl;
// }
// else{
//     cout<<"Not Found"<<endl;
// }

auto it = mp1.find("mohit");//find exist or not in map
if(it != mp1.end()){
    cout<<"found: "<<it->first<<" = "<<it->second<<endl;
}
else{
    cout<<"Not Found"<<endl;
}



cout<<endl;
cout<<mp1.count("moit")<<endl;
mp1.clear();//clear the map
cout<<mp1.empty()<<endl;//check empty
    return 0;
}