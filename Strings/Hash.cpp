ull seed1=26,seed2=1e9+7;  
  
ull hash() {  
    ull sum=seed1;  
    for (int i=0;i<26;i++) {  
        sum*=seed2;  
        sum+=a[i];  
    }  
    return sum;  
}  
