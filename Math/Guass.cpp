//高斯消元
bool gauss(int size) {    
    int i,j,k;    
    for (i=0;i<size;i++) {    
        k=i;    
        for (j=i+1;j<size;j++) 
            if (fabs(r[j][i])>fabs(r[k][i])) k=j;        
        if (fabs(r[k][i])<eps) return false;
        for (j=i;j<=size;j++)   
            swap(r[k][j],r[i][j]);  
        db t=r[i][i];  
        for (j=i;j<=size;j++)   
            r[i][j]/=t;  
        for (j=0;j<size;j++) {    
            if (i==j) continue;    
            db t=r[j][i];   
            for (k=i;k<=size;k++) {    
                r[j][k]-=t*r[i][k];    
            }    
        }
    }  
    return true;  
}
