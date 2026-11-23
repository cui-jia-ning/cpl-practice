    #include <stdio.h>
    char est[16]={0};
    int menu[16][4]={{0,0,0,0},{0,0,0,1},{0,0,1,0},{0,0,1,1},{0,1,0,0},{0,1,0,1},{0,1,1,0},{0,1,1,1},{1,0,0,0},{1,0,0,1},{1,0,1,0},{1,0,1,1},{1,1,0,0},{1,1,0,1},{1,1,1,0},{1,1,1,1}};
    int ok=1;
    int cacl(int i){
        int cnt=0;
        
            for(int j=0;j<16;j++){if(j==i){continue;}
                if(menu[j][0]!=menu[i][0]&&
                    menu[j][1]==menu[i][1]&&
                    menu[j][2]==menu[i][2]&&
                    menu[j][3]==menu[i][3]){
                        if(est[j]=='1'){
                            cnt++;
                        }
                    }
            
            }
            for(int j=0;j<16;j++){if(j==i){continue;}
                if(menu[j][0]==menu[i][0]&&
                    menu[j][1]!=menu[i][1]&&
                    menu[j][2]==menu[i][2]&&
                    menu[j][3]==menu[i][3]){
                        if(est[j]=='1'){
                            cnt++;
                        }
                    }
            
            }for(int j=0;j<16;j++){if(j==i){continue;}
                if(menu[j][0]==menu[i][0]&&
                    menu[j][1]==menu[i][1]&&
                    menu[j][2]!=menu[i][2]&&
                    menu[j][3]==menu[i][3]){
                        if(est[j]=='1'){
                            cnt++;
                        }
                    }
            
            }for(int j=0;j<16;j++){
                if(j==i){continue;}
                if(menu[j][0]==menu[i][0]&&
                    menu[j][1]==menu[i][1]&&
                    menu[j][2]==menu[i][2]&&
                    menu[j][3]!=menu[i][3]){
                        if(est[j]=='1'){
                            cnt++;
                        }
                    }
            
            }
            return cnt;
        
        
    }
    int rst=-1;
    int main(){
        scanf("%s",est);
        for(int i=0;i<16;i++){
            if(est[i]=='0'){
                ok=0;
                if(rst==-1){
                    rst=i;      
                }
                if(cacl(i)>cacl(rst)){
                    rst=i;
                }
            }
        }




        if(ok==1){
            printf("-1");
        }
        else{
            printf("%d",rst);
        }


        return 0;
    }