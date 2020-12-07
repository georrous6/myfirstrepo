
#include "Quiz.hpp"
#include <ctime>
#include <algorithm> // shuffle
#include <random> // std::default_random_engine
#include <cstdlib>
#include <iostream>


class test {
    public:
        test();    //constructor of lives and score
        ~test();
        void score_function(int choice,Quiz *name,int i);
        int get_lives();
        int get_score();
    
    private:
        int lives;
        int score;
        int consecutive;
        int multiplier;
        int x;
};


int main () {
    int i;
    int j;
    int choice;
    int size;
    struct Quiz mine[MaxQuizSize];
    test rousomanis;
    
    do
    {
        std::cout<<"Insert the size of the QUIZ:\n";
        std::cin>>size;
    }
    while (size>MaxQuizSize || size<=0);
    

    fill(mine,MaxQuizSize);
    for (i=0;i<size;i++)
    {
        std::cout<<"\nQuestion "<<i+1<<": \n";
        std::cout<<mine[i].question;
        std::cout<<"\n==================================\n";
        for (j=0;j<4;j++)
        {
            std::cout<<j<<". ";
            std::cout<<mine[i].answers[j];
            std::cout<<"\t";
        }
        do
        {
            std::cout<<"\nChoice? ";
            std::cin>>choice;
        }
        while (choice!=0 && choice!=1 && choice!=2 && choice!=3);
        rousomanis.score_function(choice,mine,i);
    }
    std::cout<<"Your overall score is: "<<rousomanis.get_score()<<" and your lives remaining are: "<<rousomanis.get_lives();
    
    return 1;
}




test::test()
{
    lives=3;
    score=0;
    consecutive=0;
    multiplier=1;
    x=1;
}

test::~test()
{
    std::cout<<"\nRIP class test\n";
}

void test::score_function(int choice,Quiz *name,int i)
{
    if (choice==name[i].correctAns)       //correct answer
    {
        if (consecutive==0)
        {
            consecutive=consecutive+1;
            score=score+x*multiplier;
        }
        else if (consecutive==1)
        {
            score=score+x*multiplier;
            consecutive=consecutive+1;
            multiplier=multiplier*2;
        }
        else if (consecutive==2)
        {
            consecutive=1;
            score=score+x*multiplier;
        }
    }
    else      //wrong answer
    {
        if (lives>0)       //the game is not over
        {
            lives=lives-1;
            consecutive=0;
            multiplier=1;
        }
        else              //the game is over
        {
            std::cout<<"\n=====================================";
            std::cout<<"\nYou have lost all your 3 lives !!!\nGAME OVER\n";
            exit(0);
        }
        
    }
}

int test::get_score()
{
    return score;
}

int test::get_lives()
{
    return lives;
}







