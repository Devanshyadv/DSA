class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int minFinish=INT_MAX;

         for(int i=0;i< landStartTime.size();i++){
             for(int j=0;j<waterStartTime.size();j++){
                 int sl=landStartTime[i];
                 int el=sl+landDuration[i];
                 int sw=max(waterStartTime[j],el);
                 int ew=sw+waterDuration[j];
                 int finish1=ew;


                 sw=waterStartTime[j];
                 ew=sw+waterDuration[j];
                 sl=max(landStartTime[i],ew);
                 el=sl+landDuration[i];
                 int finish2 = el;

                 minFinish= min({minFinish,finish1,finish2});
                 
                 
             }
         }
        return minFinish;
    }
};