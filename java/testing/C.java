import java.io.*;
class C extends B
{
    C()
    {
        System.out.println("C");
    }
    C(int a)
    {
        super(5,3);
        System.out.println("C1");
    }
    C(int a,int b)
    {
        System.out.println("C2");
    }
    public static void main(String args[])throws IOException
    {
           C ob=new C(5);
    }
}