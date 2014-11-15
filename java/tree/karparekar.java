import java.io.*;
import java.math.*;
class karparekar
{
    public static void main(String args[])throws IOException
    {
        int num;
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        num=Integer.parseInt(br.readLine());
        int sqr=num*num;
        int flag=0;
        int check=0;
        int k=0;
        while(sqr>0)
        {
             k=sqr%10*(int)Math.pow(10,flag)+k;
            sqr=sqr/10;
            if(k+sqr==num)
            {
                check=1;
                break;
            }
            flag++;
        }
        if(check==1)
        System.out.println("karparekar");
        else
        System.out.println("Not Karparekar");
    }
}
            
            
    