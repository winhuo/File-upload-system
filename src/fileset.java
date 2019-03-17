import java.io.File;
import java.net.Socket;

public class fileset implements Runnable
{
    File[] fs;
    String[] filenames=new String[20];
    int filecount=0;
    String name="";
    private Socket s;
    fileset(String name,Socket s)
    {
        this.name=name;
        this.s=s;
    }

    public void run()
    {
        File file=new File(name);
        func(file);
        for(int i=0;i<filecount;i++)
        {
            System.out.println(MyServer.PATH+filenames[i].substring(2));
            createNewFile(MyServer.PATH+filenames[i].substring(2));

        }

    }
    private void func(File file){
        fs = file.listFiles();
        for(File f:fs)
        {
            if(f.isDirectory())
                func(f);
            if(f.isFile())
            {
                filenames[filecount]=f.getPath();
                filecount++;
            }
        }
    }

    //createNewFile("c:\\a\\b\\a.txt");一次创建多层目录；
    private static void CreateFile(String dir)
    {
        try {
            File dirPath = new File(dir);
            if (!dirPath.exists()) {
                dirPath.mkdir();
            }
        } catch (Exception e) {
            System.out.println("创建目录操作出错: "+e.getMessage());
            e.printStackTrace();
        }
    }
    //创建文件夹--多层
    private static boolean CreateMultilayerFile(String dir)
    {
        try {
            File dirPath = new File(dir);
            if (!dirPath.exists()) {
                dirPath.mkdirs();
            }
        } catch (Exception e) {
            System.out.println("创建多层目录操作出错: "+e.getMessage());
            e.printStackTrace();
            return false;
        }
        return true;
    }

    //新建文件
    public static void createNewFile(String path) {
        try {
            String[] lists=path.split("\\.");
            int lastLength=lists[0].lastIndexOf("\\");
            //得到文件夹目录
            String dir=lists[0].substring(0, lastLength);
            //得到文件名称
            String fileName=lists[0].substring(lastLength);
            //得到路径e:\a\b之后,先创建文件夹
            if(CreateMultilayerFile(dir)==true)
            {
                File filePath = new File(path);
                if (!filePath.exists()) {
                    filePath.createNewFile();
                }
            }
        } catch (Exception e) {
            System.out.println("新建文件操作出错: "+e.getMessage());
            e.printStackTrace();
        }


    }
}
