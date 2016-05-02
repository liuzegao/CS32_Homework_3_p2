//
//  main.cpp
//  CS32_Homework_3_p2
//
//  Created by Zegao Liu on 16/5/1.
//  Copyright © 2016年 Zegao Liu. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;


//exam: delete
//Pridict is string s is not empty
bool somePredicate(string s)
{
    return !s.empty();
}



// Return false if the somePredicate function returns false for at
// least one of the array elements; return true otherwise.
bool allTrue(const string a[], int n)
{
    //exam: Can I do this?
    //Start with the the number n-1 string in the array a[]
    n--;
    
    //if the programs reachs out of the array, it means that the array is empty with length 0
    //exam all:Can I consider that if it is empty string array, it is always false for somPredicate?
    if (n < 0)
    return false;
    
    //Stop condition
    //If the programs reachs the bottom of the array, we do one last somePredicate and start to return back
    if(n == 0 )
    {if(somePredicate(a[n]))
        return true;
    else
        return false;
    }
    
    //if the programs does not reach the bottom of the array
    if (n > 0 )
    { if(somePredicate(a[n]))
        {
            if(allTrue(a,n))
                return true;
            else
                return false;

         }
        //if somePredicate is not true, start to return back with false all the way back
        else
            return false;
    }

    
 
    
    //Anythign wrong return false;
    return false;
    
}

// Return the number of elements in the array for which the
// somePredicate function returns false.
int countFalse(const string a[], int n)
{
    n--;
    
    //if the programs reachs out of the array, it means that the array is empty with length 0
    if (n < 0)
        return 0;
    
    if(n>0)
    { if(somePredicate(a[n]))
        return countFalse(a, n);
    else
        return countFalse(a, n)+1;
    }
    else if(n == 0)
    {
        if(somePredicate(a[n]))
            return 0;
        else
            return 1;
    }
    
    
    //Is it necessary?
    if(somePredicate(a[n]))
        return 0;
    else
        return 1;
    
}


// Return the subscript of the first element in the array for which
// the somePredicate function returns false.  If there is no such
// element, return -1.
//exam: Is it asking us to return the position of the first element that is false?
int firstFalse(const string a[], int n)
{
    n--;
    
    //if the program reaches out of the array, it means that the array is empty with length 0
    if (n < 0)
        return 0;
    
    
    if( n > 0   )
    { if(somePredicate(a[n]))
        return firstFalse(a, n);
    else
        return n;
    }
    //Base case;
    else if(n == 0)
    {
        if(somePredicate(a[n]))
            return -1;
        else
            return 0;
    }
    
    
    //exam:is it valid?
    return 0;
    
    
}

// Return the subscript of the least string in the array (i.e.,
// the smallest subscript m such that a[m] <= a[k] for all
// k from 0 to n-1).  If the array has no elements to examine,
// return -1.
int indexOfLeast(const string a[], int n)
{
    n--;
    
    
    //if the program reaches out of the array, it means that the array is empty with length 0
    if (n <  0)
        return -1;
    
    if( n > 0 )
    {
        int temp = indexOfLeast(a,n);
            //Compare the result of the previous string comparision with the next string
             if(a[temp].size() < a[n+1].size())
                 return temp;
                else
                    return n+1;
    }
    //Start to compare when the program reaches the bottom of the array
    else if ( n ==0)
    {
        //compare a[0] and a[1]
        if(a[n].size() < a[n+1].size())
            return 0;
        else
            return 1;
    }
    
        
        
    return 0;
}

// If all n2 elements of a2 appear in the n1 element array a1, in
// the same order (though not necessarily consecutively), then
// return true; otherwise (i.e., if the array a1 does not include
// a2 as a not-necessarily-contiguous subsequence), return false.
// (Of course, if a2 is empty (i.e., n2 is 0), return true.)
// For example, if a1 is the 7 element array
//    "stan" "kyle" "cartman" "kenny" "kyle" "cartman" "butters"
// then the function should return true if a2 is
//    "kyle" "kenny" "butters"
// or
//    "kyle" "cartman" "cartman"
// and it should return false if a2 is
//    "kyle" "butters" "kenny"
// or
//    "stan" "kenny" "kenny"
bool includess(const string a1[], int n1, const string a2[], int n2)
{

    
    if(n2 > 0)
    {
        n2--;
        bool temp1 = includess(a1,n1,a2,n2);
        if( temp1)
        {
        if( n1 != 0)
        {   bool temp2 = includess(a1,n1-1,a2,n2);
            if( temp2  == true)
            {
                return true;
            }
            else
            {
                if(a2[n2] == a1[n1])
                    return true;
                else
                    return false;
            }
        }
        else if(a1[n1] == a2[n2])
            return true;
        else
            return false;
  
        
        }
    }
 
    if(n2 == 0)
    {
        if( n1 != 0)
        {   bool temp2 = includess(a1,n1-1,a2,n2);
                if( temp2  == true)
                {
                       return true;
                }
                else
                {
                    //How do I record this position n1?
                    if(a2[n2] == a1[n1])
                        return true;
                    else
                        return false;
                }
        }
        else if(a1[n1] == a2[n2])
                return true;
             else
                return false;
    }
 
    
    
    return false;

}

// If all n2 elements of a2 appear in the n1 element array a1, in
// the same order (though not necessarily consecutively), then
// return true; otherwise (i.e., if the array a1 does not include
// a2 as a not-necessarily-contiguous subsequence), return false.
// (Of course, if a2 is empty (i.e., n2 is 0), return true.)
// For example, if a1 is the 7 element array
//    "stan" "kyle" "cartman" "kenny" "kyle" "cartman" "butters"
// then the function should return true if a2 is
//    "kyle" "kenny" "butters"
// or
//    "kyle" "cartman" "cartman"
// and it should return false if a2 is
//    "kyle" "butters" "kenny"
// or
//    "stan" "kenny" "kenny"
bool includes(const string a1[], int n1, const string a2[], int n2)
{
    n2--;
    
    if(n2 > n1)
        return false;
    
    if(n2 == 0)
    {
        if(a2[n2] == a1[0])
            includes(a1+1,n1-1,a2+1,n2+1);
            
    }
    else
    {
         bool temp2= includes(a1,n1,a2,n2);
    }
    
    return true;
}





//exam: delete
int main()
{
    string a[] = {"","asadasdafsd","aasdfasdfasd","as","dsasadf"};
    

        cout << sizeof(a)/sizeof(a[0]) << endl;

}
