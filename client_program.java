import java.net.*;
import java.io.*;
class MyClient
{
public static void main(String args[]) throws Exception {
int port = 56797;
String localhost="127.0.0.1";
Socket s = new Socket(localhost, port);
DataOutputStream dos =  new DataOutputStream(s.getOutputStream());
dos.writeUTF("hello server");
dos.flush();
dos.close();
s.close();
}
}
