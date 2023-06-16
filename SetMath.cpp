#include<iostream>
#include<vector>
#include<unordered_map>
#include<math.h>
#include<algorithm>
using namespace std;
class MathSet{
    public:
    bool isSingualr(vector<int> &arr){
        if(arr.size()==1) return true;
        return false;
    }
    bool isEqualSet(vector<int> &arr1,vector<int> &arr2){
        unordered_map<int,int> HashMap;//using unordered map to map the arr1

        for(int i=0;i<arr1.size();i++) HashMap[arr1[i]]++;//frequecy

        for(int i=0;i<arr2.size();i++) if(HashMap.find(arr2[i])==HashMap.end()) return false;//finding the element of second array in first array 

        return true;
    }
    bool isEquivalentSet(vector<int>&arr1,vector<int>&arr2){

        if(arr1.size()==arr2.size()) return true;//compairing size of both array.
        
        return false;
    }
    int PowerSet(vector<int>&arr){
        return pow(2,arr.size());
    }
    void ShowUnion(vector<int> &arr1,vector<int> &arr2){
        unordered_map<int,int> freq;
        vector<int> res;
        for(int num: arr1) freq[num]++;
        for(int num: arr2) freq[num]++;
        for(const auto& i:freq) res.push_back(i.first);

        sort(res.begin(),res.end());
        
        for(int num: res) cout<<num<<" ";
    }
    void ShowIntersection(vector<int>&arr1,vector<int>&arr2){
        unordered_map<int,int> freq;
        vector<int> res;
        for(auto i: arr1) freq[i]++;
        for(auto i: arr2){
            if(freq[i]>0){
                res.push_back(i);
                freq[i]--;
            }
        }
        for(auto i:res) cout<<i<<" ";
    }
    void Compliment(vector<int>&arr1,vector<int>&arr2){
        unordered_map<int,int> freq;
        for(auto i:arr2) freq[i]++;
        for(auto i: arr1){
            if(freq.find(i)==freq.end()){
                cout<<i<<" ";
            }
        }
    }
};

int main(){
    vector<int> arr1={1,2,3,4,5,6,7,8};
    vector<int> arr2={2,4,6,8};
    MathSet s01;
    // cout<<s01.isSingualr(arr1)<<endl;
    cout << (s01.isSingualr(arr1) ? "True" : "False")<<endl;
    cout << (s01.isEqualSet(arr1,arr2) ? "True" : "False")<<endl;
    cout << (s01.isEquivalentSet(arr1,arr2) ? "True" : "False")<<endl;
    cout<<"Element of set is "<<s01.PowerSet(arr2)<<endl;
    cout<<"union = ";
    s01.ShowUnion(arr1,arr2);
    cout<<endl;
    cout<<"intersection = ";
    s01.ShowIntersection(arr1,arr2);
    cout<<endl;
    cout<<"compliment = ";
    s01.Compliment(arr1,arr2);
    return 0;
}
