
import java.io.IOException;
import java.net.Socket;


public class MyClient
{


    public static void main(String[] args)
            throws IOException
    {
        int port=Integer.parseInt(args[1]);
        Socket s=new Socket(args[0],port);
        new Thread(new ClientThread(s,args[2])).start();
    }

}
