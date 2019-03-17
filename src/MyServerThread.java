import java.io.*;
import java.net.Socket;
import java.nio.ByteBuffer;

public class  MyServerThread implements Runnable
{
    Socket s=null;
    String path=null;
    public MyServerThread()
    {

    }
    public MyServerThread(Socket s,String path)
            throws IOException
    {
        this.s=s;
        this.path=path;
    }

    @Override
    public void run()
    {

        try
        {
            byte[] buffer=new byte[1024];
            BufferedInputStream bis=new BufferedInputStream(s.getInputStream());//建立流
            int nameLength;//文件名长度
            String fileName;//文件名
            long fileLength;//文件长度
            long jiamilength;//加密后文件长度；



            //读文件夹还是文件
            int FilreOr =bis.read(buffer,0,8);
            ByteBuffer n = ByteBuffer.wrap(buffer,0,8);
            int flag=0;
            flag = (int)n.getLong();
            for(int i=0;i<buffer.length;i++)
                buffer[i]=0;


            //读文件名长度
            int byteRead=bis.read(buffer,0,8);

            if(byteRead<8)

            {

                throw new Exception("");

            }
            ByteBuffer nameLengthBuffer = ByteBuffer.wrap(buffer,0,8);
            nameLength = (int)nameLengthBuffer.getLong();
            byte[] nameBuffer=new byte[nameLength];

            //读文件名
            bis.read(nameBuffer,0,nameLength);
            fileName = new String(nameBuffer);

            String name=path+"\\"+fileName;

            File file1 = new File(name);
            System.out.println(file1.getName());
            System.out.println(file1.getPath());
           FileOutputStream writer=new FileOutputStream(file1);
          // FileWriter writer=new FileWriter(name);


            //读文件长度
            for(int i=0;i<buffer.length;i++)
                buffer[i]=0;


            byteRead = bis.read(buffer,0,8);

            nameLengthBuffer = ByteBuffer.wrap(buffer,0,8);

            fileLength = nameLengthBuffer.getLong();







            //读加密后的文件长度；需要读的次数
            byteRead = bis.read(buffer,0,8);
            nameLengthBuffer = ByteBuffer.wrap(buffer,0,8);
            jiamilength = nameLengthBuffer.getLong();
            byte[] Buffer1=new byte[1040];


            //读取文件内容
            long fileelse=fileLength;
            while(jiamilength!=0)
            {
                //int bytesRead= bis.read(buffer,0,buffer.length);
               //fileSizeRead+=bytesRead;
                bis.read(Buffer1,0,Buffer1.length);
                jiamilength--;

                //byte[] decrypted=buffer;// 在这里解密 ，注意：bytesRead 可能不等于1024
                byte[]decrypted=ase1.decrypt(Buffer1);
                if(fileelse<1024)
                {
                    byte Fileconcent[]=new byte[(int)fileelse];
                    for(int i=0;i<Fileconcent.length;i++)
                    {
                        Fileconcent[i]=decrypted[i];
                    }
                    //String a=new String(Fileconcent);
                    writer.write(Fileconcent,0,Fileconcent.length);
                }
                else
                    {
                        byte Fileconcent[]=new byte[1024];
                        for(int i=0;i<Fileconcent.length;i++)
                        {
                            Fileconcent[i]=decrypted[i];
                        }
                        //String a=new String(Fileconcent);
                        writer.write(Fileconcent,0,Fileconcent.length);
                        fileelse-=1024;

                }

            }
            if(flag==1)
            {
                ZIP a=new ZIP();
                a.jieya(name,path);
            }
            writer.close();
            bis.close();
            s.close();
            if(flag==1)
            {
                deleteFile(name);
            }
        }
        catch(IOException e)
        {
            e.printStackTrace();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
    public boolean deleteFile(String sPath) {
        boolean flag = false;
        File file = new File(sPath);
        // 路径为文件且不为空则进行删除
        if (file.isFile() && file.exists()) {
            file.delete();
            flag = true;
        }
        return flag;
    }

}
