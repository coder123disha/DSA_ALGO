#include<iostream>
#include<vector>
using namespace std;




class bruteforcesolution {
  public:
    vector<int> search(string& pat, string& txt) {
        
        int patsize=pat.length();
        int txtsize=txt.length();
        int index=0;
        vector<int>ans;
        //travel the txt 
        for(int i=0;i<txtsize;i++){
            if(pat[0]==txt[i]){
               // cout<<"pat"<<pat[0]<<endl;
               // cout<<"txt"<<txt[i]<<endl;
                index=i;
               // cout<<"index"<<index<<endl;
                
                int j=0;
                while( j<patsize && pat[j]==txt[i+j]){
                    j++;
                   
                }
                if(j==patsize){
                   // cout<<"indexval"<<index;
                    ans.push_back(index);
                }
            }
        }
        return ans;
        
    }
};
// this the brute force where the time complexity is O(n*m)
//space is the output the array in the ans 0(vecsize)

class KMPsolution {

    
    
    void computlpsarray(vector<int>& lps,string& pat){
        int m=pat.length();
        
        lps[0]=0;
        int i=1;
        int len=0;
        while(i<m){
            
            //val match
            if(pat[len]==pat[i]){
                len++;
                lps[i]=len;
                i++;
            }else{
                //do not match
                //case 1 len==0
                //case 2 len!=0 len=pat[len-1];
                
                if(len!=0){
                    len=lps[len-1];
                }else{
                    lps[i]=0;
                    i++;
                }
                
             }
        }
        
    }
    
  public:
    vector<int> search(string& pat, string& txt) {
        
        int m=pat.length();
        int n=txt.length();
        
        vector<int>lps(m);
        vector<int>ans;
        
        computlpsarray(lps,pat);
        
        int i=0;
        int j=0;
        
        while(i<n){
            
            
           if(txt[i]==pat[j]){
               i++;
               j++;
               
               if(j==m){
                   ans.push_back(i-j);
               
               
               j=lps[j-1];
               }
               
               
        }
        
        else{
               if(j!=0){
                   j=lps[j-1];
               }else{
                   i++;
               }
           }
        }
    
        
        
        
        return ans;
        
    }
};

// this KMP algorithm which helps in pattern matching between two string  
//helps to avoid repetitive matching --> using lps (longest prefix and suffix) 
// reduce the Time complexity to linear 
// O(m+n) where the m len of the pat string 
// n len of the 
//space O(l) l stores the  number of indices in the vector


// problem related to kmp
// minimum characters to add infront for palindrome
// check if rotation of each other
//  find all the occurrences of a pattern in a string 
int main() {
    string txt = "ababcababcabc";
    string pat = "abc";

    bruteforcesolution bf;
    KMPsolution kmp;

    vector<int> res_bf = bf.search(pat, txt);
    vector<int> res_kmp = kmp.search(pat, txt);

    cout << "Brute Force Matches at indices: ";
    for (int i : res_bf) cout << i << " ";
    cout << "\n";

    cout << "KMP Matches at indices: ";
    for (int i : res_kmp) cout << i << " ";
    cout << "\n";

    return 0;
}

