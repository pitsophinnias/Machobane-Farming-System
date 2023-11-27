#include <iostream>

using namespace std;
struct Date{
    int day;
    int month;
};

int harvestTime(int time, int month){
    int months =time/30;
    int harvest=month+months;
    return harvest;
}
     
struct Plot{
    int width;
    int length;
};

double expyield(double rained,double fertility, int num)
{
    double yield;
    yield = (double(num) * (fertility / 10) * (rained / 10)) ;
    return yield;

}

double fertility(int sfertility)
{
    return sfertility;
}
double rained(bool choice, int moisture)
{
    if(choice == 1)
    {
        return (moisture = moisture + 5);
    }
    else
    {
        return (moisture = moisture + 4);
    }
}
int fertility(int option,int sfertility)
{
    if(option == 1)
    {
        return(sfertility = sfertility + 4);
    }
    else if(option == 2)
    {
        return(sfertility = sfertility+ 5);
    }
    else
    {
        return (sfertility = sfertility + 0);
    }
}
int option(string choice)
{
    if (choice == "Y")
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main() {
    int opt1, opt2, currentDate,crop1, crop2, numcrop1, numcrop2,plotnum, sfertility=4, smoisture=3;
    double yield1, yield2;
    int choice, choice2;
    string rain, third;
    Plot plotsize;
    Date sown1,sown2;

    cout << "Welcome to the Machobane farming system" << endl;
    cout << "Please select the current season" << endl;
    cout << "1. Summer" << endl;
    cout << "2. Winter" << endl;
    cin >> opt1;

    if(opt1==1){
        // Getting info on the crops to be planted
        cout<<"It is Summer, the time to plant: Maize, Beans, Pumpkins and Sorghum"<<endl;
        cout<<"Please select the stalk crop you intend on planting this season"<<endl;
        cout<<"1. Maize"<<endl;
        cout<<"2. Beans"<<endl;
        cout<<"3. Pumpkins"<<endl;
        cout<<"4. Sorghum"<<endl;

        cin>>crop1;
        cout<<"Please select the running crop you intend on planting this season"<<endl;
        cout<<"1. Maize"<<endl;
        cout<<"2. Beans"<<endl;
        cout<<"3. Pumpkins"<<endl;
        cout<<"4. Sorghum"<<endl;

        cin>>crop2;
        
        cout<<"The crops to be planted this season are "<<crop1<<" and "<<crop2<<endl;

        
        cout<<"The first step is to prepare the soil appropriately for "<<crop1<<" and "<<crop2<<endl;

        //Procedures for soil preparation in accordance to the chosen crops
        cout<<"Please select an option"<<endl;
        cout<<"1. Turn soil only"<<endl;
        cout<<"2. Turn soil and add manure"<<endl;
        cin>>choice;

        cout<<"Now that your soil has been properly prepared, it is time to sow the seeds"<<endl;
        cout<<"Please give number of "<<crop1<<" 's you would like to plant"<<endl;
        cin>>numcrop1;
        cout<<"Please give number of "<<crop2<<" 's you would like to plant"<<endl;
        cin>>numcrop2;

        cout<<"Please give the number plots you plan to plant on"<<endl;
        cin>>plotnum;
        cout<<"Please give the length of each plot"<<endl;
        cin>>plotsize.length;
        cout<<"Please give the width of each plot"<<endl;
        cin>>plotsize.width;

        if(plotnum==1){
            cout<<"There is just"<<plotnum<<" plot of size "<<plotsize.length<<" by "<<plotsize.width<<endl;
        }
        else{
            cout<<"There are"<<plotnum<<" plots of size "<<plotsize.length<<" by "<<plotsize.width<<endl;
        }
        
        //Soil Moisture and crop Management
        cout<<"Now that the crops have been sown, it is time to manage them properly"<<endl;
        cout<<"Are there any chances of rain this coming week?(Y/N)"<<endl;
        cin>>rain;
        option(rain);

        //crop management and soil fertility
        cout<<"Weeds should be removed from plot once every 30 days"<<endl;
        cout<<"To improve soil fertility and help plant growth and any of the following:"<<endl;
        cout<<"1. Crawl Manure"<<endl;
        cout<<"2. Artificial Fertilizers"<<endl;
        cout<<"3. Liquid Manure"<<endl;
        cin>>choice2;
        fertility(choice2,sfertility);//we expecting a value:

        //Expected yield
        cout<<"The expected yield for these crops will be:"<<endl;
        yield1 = expyield(rained(option(rain), smoisture), fertility(choice2), numcrop1);
        cout<<yield1<<"% of the planted crops are expected to grow to harvest"<<endl;
        yield2 = expyield(rained(option(rain),smoisture),fertility(choice2),numcrop2);
        cout<<yield2<<"% of the planted crops are expected to grow to harvest"<<endl;

        cout<<"Now it is time to wait for harvesting."<<endl;
        cout<<"Give the day that the first crop was sown into the soil. DD"<<endl;
        cin>>sown1.day;
        cout<<"Give the month that the first  crop was sown into the soil MM"<<endl;
        cin>>sown1.month;
        int harvtime;
        if(crop1==1){
            cout<<"It will take 90 to 150 days to harvest the maize"<<endl;
            harvtime=90;
            harvestTime(harvtime,sown1.month);
            cout<<"The maize can be harvested from"<<sown1.day<<harvestTime;
        }
        else if(crop1==4){
            cout<<"It will take 90 to 120 days to harvest the sorghum"<<endl;
            harvtime=90;
            harvestTime(harvtime,sown1.month);
            cout<<"The sorghum can be harvested from"<<sown1.day<<harvestTime;

        }
        cout<<"Give the date that the second crop was sown into the soil. DD"<<endl;
        cin>>sown2.day;
        cout<<"Give the month that the second crop was sown into the soil. MM"<<endl;
        cin>>sown2.month;
        if(crop2==2){
            cout<<"It will take 50 to 60 days to harvest the beans"<<endl;
            harvtime=50;
            harvestTime(harvtime,sown2.month);
            cout<<"The beans can be harvested from"<<sown2.day<<harvestTime;

        }
        else if(crop2==3){
            cout<<"It will take 80 to 120 days to harvest the pumpkins"<<endl;
            harvtime=80;
            harvestTime(harvtime,sown2.month);
            cout<<"The pumpkins can be harvested from"<<sown2.day<<harvestTime;

        }
       
    }
    else if(opt1==2){
        // Getting info on the crops to be planted
        cout<<"It is Winter, the time to plant: Wheat, Peas and Rape"<<endl;
        cout<<"Please select the first crop you intend on planting this season"<<endl;
        cout<<"1. Wheat"<<endl;
        cout<<"2. Rape"<<endl;
        cout<<"3. Peas"<<endl;

        cin>>crop1;
        cout<<"Please select the other crop you intend on planting this season"<<endl;
        cout<<"1. Wheat"<<endl;
        cout<<"2. Rape"<<endl;
        cout<<"3. Peas"<<endl;
        cin>>crop2;
        //change crop1 and crop2 to strings
        cout<<"The crops to be planted this season are "<<crop1<<" and "<<crop2<<endl;

        cout<<"The first step is to prepare the soil appropriately for "<<crop1<<" and "<<crop2<<endl;
        cout<<"Please select an option"<<endl;
        cout<<"1. Turn soil only"<<endl;
        cout<<"2. Turn soil and add manure"<<endl;
        cin>>choice;


        cout<<"Now that your soil has been properly prepared, it is time to sow the seeds"<<endl;
        cout<<"Please give number of "<<crop1<<" 's you would like to plant"<<endl;
        cin>>numcrop1;
        cout<<"Please give number of "<<crop2<<" 's you would like to plant"<<endl;
        cin>>numcrop2;

        cout<<"Please give the number plots you plan to plant on"<<endl;
        cin>>plotnum;
        cout<<"Please give the length of each plot"<<endl;
        cin>>plotsize.length;
        cout<<"Please give the width of each plot"<<endl;
        cin>>plotsize.width;

        if(plotnum==1){
            cout<<"There is just"<<plotnum<<" plot of size "<<plotsize.length<<" by "<<plotsize.width;
        }
        else{
            cout<<"There are"<<plotnum<<" plots of size "<<plotsize.length<<" by "<<plotsize.width;
        }




        //Soil Moisture and crop Management
        cout<<"Now that the crops have been sown, it is time to manage them properly"<<endl;
        cout<<"Are there any chances of rain this coming week?(Y/N)"<<endl;
        cin>>rain;
        option(rain);

        //crop management and soil fertility
        cout<<"Weeds should be removed from plot once every 30 days"<<endl;
        cout<<"To improve soil fertility and help plant growth and any of the following:"<<endl;
        cout<<"1. Crawl Manure"<<endl;
        cout<<"2. Artificial Fertilizers"<<endl;
        cout<<"3. Liquid Manure"<<endl;
        cin>>choice2;
        fertility(choice2,sfertility);//we expecting a value:

        //Expected yield
        cout<<"The expected yield for these crops will be:"<<endl;
        yield1 = expyield(rained(option(rain), smoisture), fertility(choice2), numcrop1);
        cout<<yield1<<"% of the planted crops are expected to grow to harvest"<<endl;
        yield2 = expyield(rained(option(rain),smoisture),fertility(choice2),numcrop2);
        cout<<yield2<<"% of the planted crops are expected to grow to harvest"<<endl;
        
        cout<<"Now it is time to wait for harvesting."<<endl;
        cout<<"Give the day that the first crop was sown into the soil. DD"<<endl;
        cin>>sown1.day;
        cout<<"Give the month that the first  crop was sown into the soil MM"<<endl;
        cin>>sown1.month;
        int harvtime;
        if(crop1==1){
            cout<<"It will take 90 to 150 days to harvest the wheat"<<endl;
            harvtime=180;
            harvestTime(harvtime,sown1.month);
            cout<<"The maize can be harvested from"<<sown1.day<<harvestTime;
        }

        cout<<"Give the date that the second crop was sown into the soil. DD"<<endl;
        cin>>sown2.day;
        cout<<"Give the month that the second crop was sown into the soil. MM"<<endl;
        cin>>sown2.month;
        if(crop2==2){
            cout<<"It will take 60 to 90 days to harvest the rape"<<endl;
            harvtime=60;
            harvestTime(harvtime,sown2.month);
            cout<<"The beans can be harvested from"<<sown2.day<<harvestTime;

        }
        else if(crop2==3){
            cout<<"It will take 60 to 70 days to harvest the peas"<<endl;
            harvtime=60;
            harvestTime(harvtime,sown2.month);
            cout<<"The pumpkins can be harvested from"<<sown2.day<<harvestTime;

        }
        
    }
    cout<<"Congratulations!! You have successfully used the Machobane Farming System to produce your produce! "<<endl;
    return 0;

}
