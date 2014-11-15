import java.io.*;
class binary
{
   node root=new node();
   void preorder(node root)
   {
       if(root!=null)
       {
           System.out.print(root.key+"->");
           preorder(root.left);
           preorder(root.right);
        }
       return;
    }
    void postorder(node root)
    {
        if(root!=null)
        {
            postorder(root.left);
            postorder(root.right);
            System.out.print(root.key+"->");
        }
        return;
    }
    void inorder(node root)
    {
        if(root!=null)
        {
            inorder(root.left);
            System.out.print(root.key+"->");
            inorder(root.right);
        }
        return;
    }
    void insert(int val)
    {
        insert(root,val);
    }
    void insert(node root,int val)
    {
       if(root.right!=null && root.key<val)
                insert(root.right,val);
       else if(root.left!=null && root.key>val)
                insert(root.left,val);
     
       else
       {
            if(root.key < val)
            {
                   node r_node= new node();
                   r_node.key=val;
                   r_node.left=null;
                   r_node.right=null;
                   r_node.parent=root;
                   root.right=r_node;
            }
            else
            {
                node l_node=new node();
                l_node.key=val;
                l_node.left=null;
                l_node.right=null;
                l_node.parent=root;
                root.left=l_node;
            }
        }
    }
    public static void main(String args[])throws IOException
    {
        System.out.println("Enter the no. of nodes to be inserted");
        int n;
        InputStreamReader in = new InputStreamReader(System.in);
        BufferedReader br=new BufferedReader(in);
        n=Integer.parseInt(br.readLine());
        binary ob=new binary();
        for(int i=0;i<n;i++)
        {
            int num=Integer.parseInt(br.readLine());
            if(i==0)
            {
                ob.root.key=num;
                ob.root.right=null;
                ob.root.left=null;
                ob.root.parent=null;
            }
            else
            {
                ob.insert(num);
            }
        }
        System.out.println("PRE_ORDER TRAVERSAL");
            ob.preorder(ob.root);
        System.out.println("\nIN_ORDER TRAVERSAL");
            ob.inorder(ob.root);
        System.out.println("\nPOST_ORDER TRAVERSAL");
            ob.postorder(ob.root);
        }
    }
    
    