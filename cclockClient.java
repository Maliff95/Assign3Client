import java.io.*;

import java.net.*;

import java.util.*;

import java.text.SimpleDateFormat;



public class clockClient



{

  public static void main(String[] args) throws Exception

  {

     Calendar cal = Calendar.getInstance();

     SimpleDateFormat sdf = new SimpleDateFormat("HH.mm");

     Socket sock = new Socket("192.168.101.131", 5541);

     BufferedReader keyRead = new BufferedReader(new 
InputStreamReader(System.in));

     OutputStream ostream = sock.getOutputStream();

     PrintWriter pwrite = new PrintWriter(ostream, true);

     InputStream istream = sock.getInputStream();



     BufferedReader receiveRead = new BufferedReader(new 
InputStreamReader(istream));

     System.out.println("Connected!!!");



     String receiveMessage, sendMessage;

     //System.out.println(hours);

     while(true)

     {

	receiveMessage = receiveRead.readLine();



	if(receiveMessage.equalsIgnoreCase("time"))

	{ 

	  System.out.println(sdf.format(cal.getTime()));

	  pwrite.println(sdf.format(cal.getTime()));

	  pwrite.flush();

	}

	else

	{

	  System.out.println(receiveMessage);

	  //sendMessage= keyRead.readLine();

	  //pwrite.println(sendMessage);

	  //pwrite.flush();

	}

        }

  }

}
