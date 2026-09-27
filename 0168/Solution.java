class Solution{public String convertToTitle(int n){StringBuilder s=new StringBuilder();while(n>0){n--;s.append((char)('A'+n%26));n/=26;}return s.reverse().toString();}}
