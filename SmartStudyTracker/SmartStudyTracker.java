//////////////////////////////////////////////////////////
//
//  Project Name :    Smart Study Tracker
//  File Name    :    SmartStudyTracker.java
//  Description  :    Console based application used to maintain daily
//                    study logs of students. The system allows the user
//                    to insert, view and export study records.
//
//  Author       :    Pallavi Kishanrao Hivrale
//  Date         :    07/03/2026
//
//////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////
//
//  Header File Inclusion
//
//////////////////////////////////////////////////////////
/// 
import java.util.*;

import javax.xml.crypto.Data;

import java.time.LocalDate;
import java.time.LocalDateTime;
import java.io.*;

//////////////////////////////////////////////////////////
//
//  Class Name : StudyLog
//  Description : This class represents a single study log.
//                It stores date, subject, duration and
//                description of the study session.
//
//  Author : Pallavi Kishanrao Hivrale
//
//////////////////////////////////////////////////////////

class StudyLog
{
    private LocalDate Date;
    private String Subject;
    private double Duration;
    private String Description;

    public StudyLog(LocalDate a, String b, double c, String d)
    {
        this.Date = a;
        this.Subject = b;
        this.Duration = c;
        this.Description = d;
    }

    public LocalDate getDate()
    {
        return this.Date;
    }

    public String getSubject()
    {
        return this.Subject;
    }

    public double getDuration()
    {
        return this.Duration;
    }

    public String getDescription()
    {
        return this.Description;
    }
    
    @Override
    public String toString()
    {
        return Date+ " | "+Subject+" | "+Duration+" | "+Description;
    }
}

//////////////////////////////////////////////////////////
//
//  Class Name : StudyTracker
//  Description : This class manages the study logs.
//                It stores logs using ArrayList and
//                performs operations like insert,
//                display, export and summary.
//
//  Author : Pallavi Kishanrao Hivrale
//
//////////////////////////////////////////////////////////

class StudyTracker
{
    public ArrayList <StudyLog>Database = new ArrayList<StudyLog>();

    //////////////////////////////////////////////////////////
    //
    //  Function Name : InsertLog()
    //  Description : It accepts study details from user
    //                and stores them into the database.
    //
    //////////////////////////////////////////////////////////

    public void InsertLog()
    {
        Scanner sobj = new Scanner(System.in);

        System.out.println("-------------------------------------------");
        System.out.println("---- Enter valid details of your study ----");
        System.out.println("-------------------------------------------");

        LocalDate Dateobj = LocalDate.now();
        
        System.out.println("Please enter the name of subject like C/C++/Java/Python");
        String sub = sobj.nextLine();

        System.out.println("Enter the time period of your study in hours");
        double dur = sobj.nextDouble();
        sobj.nextLine();

        System.out.println("Please provide the description of your study");
        String desc= sobj.nextLine();

        StudyLog studyobj = new StudyLog(Dateobj, sub, dur, desc);

        Database.add(studyobj);

        System.out.println("Study log gets stored succesfully");
        System.out.println("-----------------------------------------------");
    }

    //////////////////////////////////////////////////////////
    //
    //  Function Name : DisplayLog()
    //  Description : It displays all study logs
    //                stored in the database.
    //
    //////////////////////////////////////////////////////////

    public void DisplayLog()
    {
        System.out.println("-----------------------------------------------");

        if(Database.isEmpty())
        {
            System.out.println("----------- Nothing to display ------------");
            System.out.println("-------------------------------------------");
            return;
        }

        System.out.println("------ Log report of Smart Study Tracker ------");
        System.out.println("-----------------------------------------------");

        for(StudyLog s : Database)
        {
            System.out.println(s);
        }

        System.out.println("-----------------------------------------------");
    }

    //////////////////////////////////////////////////////////
    //
    //  Function Name : ExportCSV()
    //  Description : It exports the study logs into
    //                a CSV file.
    //
    //////////////////////////////////////////////////////////

    public void ExportCSV()
    {
        if(Database.isEmpty())
        {
            System.out.println("-------------------------------------------");
            System.out.println("------------ Nothing to export ------------");
            System.out.println("-------------------------------------------");
            return;
        }
        
        String Filename = "SmartStudyTracker.csv";

        try(FileWriter fwobj = new FileWriter(Filename))
        {
            fwobj.write("Date,Subject,Duration,Description\n");

            for(StudyLog s : Database)
            {
                fwobj.write(s.getDate()+","+
                            s.getSubject().replace(",", " ")+","+
                            s.getDuration()+","+
                            s.getDescription().replace(",", " ")+"\n");
            }

            System.out.println("Data gets exported in CSV : "+Filename);
        }
        catch(Exception eobj)
        {
            System.out.println("Exception occured in CSV handling");
        }
    }

    ////////////////////////////////////////////////////////////////////
    //
    //  Function Name : SummaryByDate()
    //  Description : It displays total study duration grouped by date.
    //
    ////////////////////////////////////////////////////////////////////

    public void SummaryByDate()
    {
        System.out.println("-------------------------------------------");
        
        if(Database.isEmpty())
        {
            System.out.println("Nothing to display as database is empty");
            System.out.println("-------------------------------------------");

            return;
        }

        System.out.println("----Summary by Date from study tracker-----");
        System.out.println("-------------------------------------------");

        TreeMap <LocalDate, Double>tobj = new TreeMap<LocalDate, Double>();

        LocalDate lobj = null;
        double d = 0.0, old = 0.0;

        for(StudyLog sobj : Database)
        {
            lobj = sobj.getDate();
            d = sobj.getDuration();

            if(tobj.containsKey(lobj))
            {
                old = tobj.get(lobj);
                tobj.put(lobj,d+old);
            }
            else
            {
                tobj.put(lobj,d);
            }
        }

        // Display the details as per date
        for(LocalDate l : tobj.keySet())
        {
            System.out.println("Date : "+l+"Total study duration : "+tobj.get(l));
        }

        System.out.println("-------------------------------------------");
    }

    ////////////////////////////////////////////////////////////////////
    //
    //  Function Name : SummaryBySubject()
    //  Description : It displays total study duration grouped by subject.
    //
    ////////////////////////////////////////////////////////////////////
    
    public void SummaryBySubject()
    {
        System.out.println("-------------------------------------------");
        
        if(Database.isEmpty())
        {
            System.out.println("Nothing to display as database is empty");
            System.out.println("---------------------------------------");

            return;
        }

            System.out.println("--Summary by Subject from study tracker--");
            System.out.println("-----------------------------------------");

            TreeMap <String, Double>tobj = new TreeMap<String, Double>();

            String s = null;
            double d = 0.0, old = 0.0;

            for(StudyLog sobj : Database)
            {
                s = sobj.getSubject();
                d = sobj.getDuration();

                if(tobj.containsKey(s))
                {
                    old = tobj.get(s);
                    tobj.put(s,d+old);
                }
                else
                {
                    tobj.put(s,d);
                }
            }

            // Display the details as per subject
            for(String str : tobj.keySet())
            {
                System.out.println("Subject : "+str+"Total study duration : "+tobj.get(str));
            }

            System.out.println("-------------------------------------------");
        }
}

//////////////////////////////////////////////////////////
//
//  Class Name : SmartStudyTracker
//  Description : Entry point of the application.
//                Displays menu and performs operations.
//
//  Author : Pallavi Kishanrao Hivrale
//
//////////////////////////////////////////////////////////

class SmartStudyTracker
{
    public static void main(String A[])
    {
        Scanner sobj = new Scanner(System.in);
        StudyTracker stobj = new StudyTracker();

        System.out.println("-------------------------------------------");
        System.out.println("------ Welcome to Smart Study Tracker -----");
        System.out.println("-------------------------------------------");

        int iChoice = 0;

        do
        {
            System.out.println("Please select appropriate option");
            System.out.println("1 : Insert new study log");
            System.out.println("2 : View all study log");
            System.out.println("3 : Export study log to CSV file");
            System.out.println("4 : Summary of study log by date");
            System.out.println("5 : Summary of study log by subject");
            System.out.println("6 : Exit the application");
            
            iChoice = sobj.nextInt();

            switch(iChoice)
            {
                // Insert new study log
                case 1 : 
                    stobj.InsertLog();
                    break;

                // View all study log
                case 2:
                    stobj.DisplayLog();
                    break;

                // Export study log to CSV file
                case 3 : 
                    stobj.ExportCSV();
                    break;

                // Summary of study log by date
                case 4 : 
                    stobj.SummaryByDate();
                    break;

                // Summary of study log by subject
                case 5:
                    stobj.SummaryBySubject();
                    break;

                // Exit the application
                case 6:
                    System.out.println("-------------------------------------------");
                    System.out.println("--Thank you for using Smart Study Tracker--");
                    System.out.println("-------------------------------------------");

                    break;

                default:
                    System.out.println("Please enter valid option");
                    break;
            }   
            
        }while(iChoice != 6);   // End of do while
        
    }  // End of main
}   // End of starter class

//////////////////////////////////////////////////////////
//
//  End of Smart Study Tracker Application
//
//  Developed By : Pallavi Kishanrao Hivrale
//  Language     : Java
//  Type         : Console Based Application
//
//////////////////////////////////////////////////////////