//
//  main.cpp
//  190622
//
//  Created by S20181105302 on 2019/6/22.
//  Copyright © 2019 S20181105302. All rights reserved.
//

#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
struct Referees
{
    string name;
    double grades[5];
}Referee[7];
struct Students
{
    string name;
    string college;
    string ID;
    double sum=0;
    double grades[7];
}student[5];
bool lsj(Students &p1,Students &p2)
{
    if(p1.sum>p2.sum)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


int main(int argc, const char * argv[]) {
    int n = 0,k = 0;
    int max,min;
    ifstream file,stu;
    ofstream Match("E:\Competition results.xlsx");
    file.open("E:\Refereeinformation.txt");
    if(!file.is_open())
    {
        cout << "Error: opening file fail" << endl;
        exit(1);
    }
    while(!file.eof() && n < 7)
    {
        file >> Referee[n].name >> Referee[n].grades[0] >> Referee[n].grades[1] >> Referee[n].grades[2] >> Referee[n].grades[3] >> Referee[n].grades[4];
        n++;
    }
    stu.open("E:\studentinformation.txt");
    if(!stu.is_open())
    {
        cout << "Error: opening file fail" << endl;
        exit(1);
    }
    while(!stu.eof() && k < 5 )
    {
        stu >> student[k].ID >> student[k].college >> student[k].name;
        k++;
    }
    for( int i=0; i<7; i++ )
    {
        for( int j=0; j<5; j++ )
        {
            student[j].grades[i] = Referee[i].grades[j];
        }
    }
    for( int i=0; i<5; i++ )
    {
        sort(student[i].grades,student[i].grades+7);
        for( int j=1; j<6; j++ )
            student[i].sum += student[i].grades[j];
        student[i].sum /= 7;
    }
    sort(student,student+5,lsj);
    
    for( int i=0; i<5; i++ )
    {
        cout << student[i].ID << " " << student[i].college << " " << student[i].name << " " << student[i].sum << endl;
    }
    for( int i=0; i<5; i++ )
    {
        Match << student[i].ID << "  " << student[i].college << "  " << student[i].name << "  " << student[i].sum << endl;
    }
    file.close();
    stu.close();


    return 0;
}
