class Solution {
public:
    int compareVersion(string version1, string version2) {
        int nv1=version1.size(),nv2=version2.size(),i=0,j=0;
        while(i<nv1 || j<nv2){
            string s1="",s2="";
            while(i<nv1 && version1[i]!='.') s1+=version1[i++];
            while(j<nv2 && version2[j]!='.') s2+=version2[j++];
            if(s1.size()==0) s1="0";
            if(s2.size()==0) s2="0";
            int num1=stoi(s1);
            int num2=stoi(s2);
            if(num1>num2) return 1;
            if(num1<num2) return -1;
            i++,j++;
        }
        return 0;
    }
};
