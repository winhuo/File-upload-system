import java.io.BufferedOutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.net.Socket;
import java.nio.ByteBuffer;



public class ClientThread implements Runnable

{



    public Socket s;

    String name=null;

    public ClientThread(Socket s,String name)

    {

        this.s=s;

        this.name=name;

    }

    @Override
    public void run()
    {
        try {


            BufferedOutputStream os = new BufferedOutputStream(s.getOutputStream());//字节流传文件内容


            ByteBuffer buff = ByteBuffer.allocate(Long.BYTES);
            String fileName = name.substring(name.lastIndexOf("\\")+1);
            if(fileName.length()==0)
            {
                 // 第一种方法：
                //new Thread(new fileset(name,this.s)).start();
                //return;
                //第二种方法：
                //传递是否要传一个文件夹
                buff.putLong(1);
                byte[] a1=new byte[Long.BYTES];
                for(int i=0;i<Long.BYTES;i++)
                {
                    a1[i] =buff.get(i);
                }
                os.write(a1);


                ZIP a=new ZIP();
                try
                {
                    a.zip("G:\\ziptest.zip",new File(this.name));
                    this.name="G:\\ziptest.zip";
                    fileName = name.substring(name.lastIndexOf("\\")+1);
                }
                catch (Exception e)
                {
                    e.printStackTrace();
                }
            }
            else
            {
                //传递文件
                buff.putLong(0);
                byte[] a2=new byte[Long.BYTES];
                for(int i=0;i<Long.BYTES;i++)
                {
                    a2[i] =buff.get(i);
                }
                os.write(a2);
            }




            //写文件名长度（一个长整数）
            buff = ByteBuffer.allocate(Long.BYTES);
            buff.putLong(fileName.length());
            byte[] a=new byte[Long.BYTES];
            for(int i=0;i<Long.BYTES;i++)
            {
                a[i] =buff.get(i);
            }
            os.write(a);



            //写文件名
            byte[] sb = fileName.getBytes();
            os.write(sb);


            //写文件长度

            File f = new File(name);
            buff = ByteBuffer.allocate(Long.BYTES);
            buff.putLong(f.length());
            a=null;
            a=new byte[Long.BYTES];
            for(int i=0;i<Long.BYTES;i++)
            {
                a[i] =buff.get(i);
            }
            os.write(a);




            //加密后长度(次数）
            long jiamilength=(f.length()/1024)+1;
            buff = ByteBuffer.allocate(Long.BYTES);
            buff.putLong(jiamilength);
            a=null;
            a=new byte[Long.BYTES];
            for(int i=0;i<Long.BYTES;i++)
            {
                a[i] =buff.get(i);
            }
            os.write(a);



            //写文件
            int bytesRead = 0;
            FileInputStream fis = new FileInputStream(name);//文件流读文件
            byte[] buff1 = new byte[1024];
            while ((bytesRead = fis.read(buff1)) > 0)
            {

                byte[] encrypted=ase1.encrypt(buff1);
                //byte[] encrypted=buff1;// 在这里加密：注意：bytesRead 可能不等于1024
                os.write(encrypted, 0, encrypted.length);
            }


                os.close();
                fis.close();
                s.close();

            System.out.println("上传成功！");

        }
        catch (IOException e)
        {
            e.printStackTrace();
        }
    }


}
