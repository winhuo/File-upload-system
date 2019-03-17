import java.io.File;
import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class MyServer
{
    static public String PATH="G://abc";
    public static List<Socket> socketList= Collections.synchronizedList(new ArrayList<>());
    public static void main(String[] args)throws IOException
    {
        int port=Integer.parseInt(args[0]);
        File file=new File(args[1]);
        if(!file.exists()&& !file.isDirectory()){              //如果文件夹不存在
            file.mkdir();                //创建文件夹
        }
        ServerSocket ss=new ServerSocket(port);
        while(true)
        {
            Socket s=ss.accept();
            socketList.add(s);
            new Thread(new MyServerThread(s,args[1])).start();
        }
    }
}

