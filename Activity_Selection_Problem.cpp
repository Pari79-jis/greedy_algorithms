#include<iostream>
#include<algorithm>
#include<vector>
#include<iomanip>

using namespace std;

struct Activity {
    string name;
    int start,finish;
};

int main() {
    int a;
    cout<<"Enter the number of activities:\n";
    cin>>a;

    vector<Activity> activities;
    for(int i=0;i<a;i++){
        Activity current;
        cout<<"Enter the name of activity"<<" "<<i+1<<":\n";
        cin>>ws;
        getline(cin,current.name);
        cout<<"Enter the start time of activity"<<" "<<i+1<<":\n";
        cin>>current.start;
        cout<<"Enter the finish time of activity"<<" "<<i+1<<":\n";
        cin>>current.finish;
        activities.push_back(current);
    }

    sort(activities.begin(),activities.end(),[](const Activity& f,const Activity& g){
        if(f.finish == g.finish){
            return f.start>g.start;
        }
        return f.finish<g.finish;
    });

    vector<Activity> selectedActivities;
    if(!activities.empty()){
        selectedActivities.push_back(activities[0]);
        cout<<activities[0].name;
        int last_finish_time = activities[0].finish;

        for(size_t i =1;i<activities.size();++i){
              if(last_finish_time<=activities[i].start){
                   cout<<"->"<<activities[i].name;
                   selectedActivities.push_back(activities[i]);
                   last_finish_time = activities[i].finish;
        }
    }

   cout<<"\n";
}
return 0;
}