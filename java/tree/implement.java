import java.io.*;
class implement
{
    node L1=null;
    node L2=null;
    node Head=null;
    public void func(int a)
    {
        if(L1==null)
        {
            L1=new node();
            L1.val=a;
            L1.ptr=null;
            Head=new node();
            Head=L1;
        }
        else
        {
            L2=new node();
            L2.val=a;
            L2.ptr=null;
            L1.ptr=L2;
            L1=L2;
        }
    }
    void display()
    {
        node temp=new node();
        temp=Head;
        while(temp!=null)
        {
            System.out.print(temp.val+ "-->");
            temp=temp.ptr;
        }
        System.out.print("NULL");
    }
    public static void main(String args[])throws IOException
    {
        implement ob=new implement();
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        for(int i=0;i<10;i++)
        {
            int a=Integer.parseInt(br.readLine());
            ob.func(a);
        }
        ob.display();
    }
}
            
            
            
            
            
            
            