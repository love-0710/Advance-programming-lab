import java.sql.*;
class MySQLCon
{
        public static void main(String args[]){
                try{
                        Class.forName("com.mysql.jdbc.Driver");
                        Connection con=DriverManager.getConnection("jdbc:mysql://localhost:3306/db_202100432","cse_202100432","CkGMUk");
                        Statement stmt=con.createStatement();
                        ResultSet rs=stmt.executeQuery("select * from emp5");
                        while(rs.next())
                                System.out.println(rs.getInt(2)+" "+rs.getString(1)+" "+rs.getString(3));
                        con.close();
                }
                catch(Exception e){
                        System.out.println("Unable to load driver");
                }
        }
}


