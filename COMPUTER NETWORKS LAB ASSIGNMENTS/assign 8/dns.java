import java.net.InetAddress;
import java.util.*;

class dns	
{
	public static void main(String args[])
	{
        try
        {
            int ch;
            String ipaddr,url;
            Scanner in = new Scanner(System.in);
            do
            {	
                System.out.println("Menu");
                System.out.println("1.IP to host");
                System.out.println("2.Host to IP");
                System.out.println("Enter your choice:");
                ch = in.nextInt();

                switch(ch)
                {
                    case 1:
                        System.out.println("Enter ip address:");
                        ipaddr = in.next();
                        InetAddress host = InetAddress.getByName(ipaddr);
                        System.out.println("Host name is:"+host.getHostName());
                        break;

                    case 2:
                        System.out.println("Enter host name:");
                        url = in.next();
                        InetAddress host1 = InetAddress.getByName(url);
                        System.out.println("IP is:"+host1.getHostAddress());
                        break;

                }
            }while(ch!=3);
        }
        catch(Exception e)
        {
                System.out.println(e);
                                
        }
   }
}		
