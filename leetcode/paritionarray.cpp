class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
      


        // //sort the array
        // sort(nums.begin(),nums.end());

        // int maxele=nums[0];
        // int minele=nums[0];
        // int count=1;
        // int n=nums.size();
        // for(int i=1;i<n;i++){
        //     int currentele=nums[i];
        //     maxele=max(currentele,maxele);
        //     minele=min(currentele,minele);
        //     if(maxele-minele>k){
        //         count++;
        //         maxele=currentele;
        //         minele=currentele;
        //     }

        // }

        // return count;

        /**
        -->parition array into minimum subsequences
        -->difference between two elements in subsequence<=k
        **/
        
        if(nums.empty())return 0;

        sort(nums.begin(),nums.end());

        int count=1; //we assuming that we are getting one group at least
        int greaternum=nums[0];

        for(int i=1;i<nums.size();i++){
            if(nums[i]-greaternum>k){
                count++;
                greaternum=nums[i];
            }
        }

        return count;
        
    }
};
