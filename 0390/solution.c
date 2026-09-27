int lastRemaining(int n){int head=1,step=1,left=n,lr=1;while(left>1){if(lr||left%2)head+=step;left/=2;step*=2;lr=!lr;}return head;}
