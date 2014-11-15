
import java.io.*;
class stack_ar
{
    int stk[]=new int[5];
    int top=-1;
    void push(int a)
    {
        stk[++top]=a;
    }
    int pop()
    {
        int val=stk[top];
        top--;
        return val;
    }
    boolean isEmpty()
    {
        if(top<=-1)
        return true;
        else
        return false;
    }
    boolean isFull()
    {
        if(top>=4)
            return true;
         else 
            return false;
     }
     public static void main(String args[])throws IOException
     {
         System.out.println("1:Continue\n2:Exit");
         int a=0;
         stack_ar ob=new stack_ar();
         BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
         a=Integer.parseInt(br.readLine());
         while(a==1)
         {
             
             System.out.println("1:Push\n2:Pop");
             int ch=Integer.parseInt(br.readLine());
             switch(ch)
             {
                 case 1:
                 {
                     boolean ff=ob.isFull();
                     if(ff==true)
                     System.out.println("OverFlow");
                     else
                     {
                         int num_to_be_pushed=Integer.parseInt(br.readLine());
                         ob.push(num_to_be_pushed);
                     }
                     break;
                    }
                 case 2:
                 {
                     boolean ff=ob.isEmpty();
                     if(ff==true)
                     System.out.println("UnderFlow");
                     else
                     {
                         int poped_value=ob.pop();
                         System.out.println("Poped Value:"+poped_value);
                     }
                     break;
                 }
                 default:
                 System.out.println("Wrong Choice");
             }
             System.out.println("1:Continue\n2:Exit");
             a=Integer.parseInt(br.readLine());
         }
     }
}
             
             
             
             
             
             
             
             
         
         
         
         
         
         
         
         
         
         