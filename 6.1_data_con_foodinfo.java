import java.sql.*;
import java.util.*;
class MySQLCon
{
        public static void main(String args[]){
                Scanner sc=new Scanner(System.in);
                int a;
                System.out.println("Enter 1 to update, 2 to display,3 to insert");
                a=sc.nextInt();

                try{
                        Class.forName("com.mysql.cj.jdbc.Driver");
                        Connection con=DriverManager.getConnection("jdbc:mysql://localhost:3306/db_202100437","cse_202100437","avHJZs");
                        Statement stmt=con.createStatement();
                        switch(a){

                        case 1: System.out.println("Enter Item No: ");
                                int no=sc.nextInt();
                                System.out.println("Enter Item Price:");
                                int price=sc.nextInt();
                                stmt.executeUpdate("update item_details set item_price="+price+" where item_no="+no);
                                break;
                        case 2: ResultSet rs=stmt.executeQuery("select * from item_details order By item_no DESC");
                                while(rs.next())
                                      System.out.println(rs.getInt(1)+" "+rs.getString(2)+" "+rs.getInt(3)+" "+rs.getString(4));
                                break;
                        case 3: System.out.println("Enter Item No: ");
                                int no1=sc.nextInt();
                                System.out.println("Enter Item Name: ");
                                String name=sc.next();
                                System.out.println("Enter Item Price:");
                                int price1=sc.nextInt();
                                System.out.println("Enter Availability:");
                                String avail=sc.next();
                                stmt.executeUpdate("Insert into item_details values("+no1+",\""+name+"\","+price1+",\""+avail+"\")");
                                break;
                        }

                        con.close();
                }
                catch(Exception e){
                        System.out.println(e);
                }
        }
}

