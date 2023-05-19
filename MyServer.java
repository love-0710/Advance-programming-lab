import java.net.*;
import java.io.*;
class MyServer
{
public static void main(String args[]) throws Exception {
int port=56797;
ServerSocket ss= new ServerSocket(port);
Socket s=ss.accept();
DataInputStream dis = new DataInputStream(s.getInputStream());
String str=(String) dis.readUTF();
System.out.println("Message="+str);
ss.close();
}
}

