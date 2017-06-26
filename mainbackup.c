



#include <stdio.h>
int main()
{
    int m[100][100], b[100][100], solution[100][100], a, n, i, k, j, x, mismatch, position, numberofminterms, minterms[100], implicantposition[100];


    int number_of_variables = 4;
    int number_of_terms = pow(2,number_of_variables);
    int finalterms[100][100], m1[100][100], m2[100][100], m3[100][100];
    int match=0, matchedposition, numberofmatches2=0;



             for (i=0; i< numberofminterms-1; i++)              // turning the implicant positions to zero
          {
             implicantposition[i]=0;
          }



             for (j=0; j<number_of_terms; j++)                  // vertical sweep
             {
                 a=j;
                 for (i=number_of_variables-1; i>=0; i--)       // horizontal sweep, storing integers as binary in array
                    {
                        if(a%2!= 0)
                        {
                            m[j][i]=1;
                        }
                        else
                        {
                            m[j][i]=0;
                        }

                        a=a/2;

                    }
             }

             for (j=0; j<number_of_terms; j++)
             {
                 for (i=0; i<number_of_variables; i++)
                    {
                       printf("%d", m[j][i]);
                    }
                    printf("\n");
             }


             printf("Enter number of minterms = ");


             scanf("%d", &numberofminterms);

             for (i=0; i<numberofminterms; i++ )
             {
                scanf("%d", &minterms[i]);

             }

             printf("\n Scanning complete\n\n");         //tick


             for (i=0; i<numberofminterms; i++)
             {
                 for (j=0; j<number_of_variables; j++)
                 {
                     k = minterms[i];
                     finalterms[i][j] = m[k][j];
                 }

             }


          for (j=0; j<numberofminterms; j++)
             {
                 for (i=0; i<number_of_variables; i++)
                    {
                       printf("%d", finalterms[j][i]);
                    }
                    printf("\n");
             }



             //tick

          int p =0, numberofmatches=0, y=0;


          for (i=0; i<numberofminterms-1; i++)
          {
              numberofmatches2 = 0;
            for (j=i+1; j<numberofminterms; j++)
            {
                for (k=0; k<number_of_variables; k++)
                {
                    if (finalterms[i][k] != finalterms[j][k]) { match++; matchedposition = k; }
                }
                if (match==1)
                {

                    for (x=0; x< number_of_variables; x++)
                    {
                        m1[p][x] = finalterms[i][x];
                    }

                    m1[p][matchedposition] = 2;
                    p++;
                    match =0;
                    printf("%d > %d\n", i, j);
                    numberofmatches++;
                    implicantposition[i]=1;
                    implicantposition[j]=1;


                }
                else if
                (match==0)
                {
                    i++;
                }
                else
                {

                    match = 0;
                }

            }

          }


          for (i=0; i< numberofminterms-1; i++)
          {
              //printf("implicant = %d\n", implicantposition[i]); // debug
              if (implicantposition[i]==0)
              {
                  for (x=0; x< number_of_variables; x++)
                    {
                        solution[y][x] = finalterms[i][x];
                    }
                    y++;
              }

          }




           for (j=0; j<numberofmatches; j++)
             {
                 for (i=0; i<number_of_variables; i++)
                    {
                       printf("%d ", m1[j][i]);
                    }
                    printf("\n");
             }


             // 2nd iteration starts here



        numberofminterms=numberofmatches;
        numberofmatches =0;
        match=0;
        p=0;





        for (i=0; i< numberofminterms-1; i++)          // again turning everything to zero for further calculations
          {
             implicantposition[i]=0;
          }





          for (i=0; i<numberofminterms-1; i++)
          {
              numberofmatches2 = 0;
            for (j=i+1; j<numberofminterms; j++)
            {
                for (k=0; k<number_of_variables; k++)
                {
                    if (m1[i][k] != m1[j][k]) { match++; matchedposition = k; }
                }
                if (match==1)
                {

                    for (x=0; x< number_of_variables; x++)
                    {
                        m2[p][x] = m1[i][x];
                    }

                    m2[p][matchedposition] = 2;
                    p++;
                    match =0;
                    printf("%d > %d\n", i, j);
                    numberofmatches++;
                    implicantposition[i]=1;
                    implicantposition[j]=1;


                }
                else if
                (match==0)
                {
                    i++;
                }
                else
                {
                    match = 0;
                }

            }

          }


        for (i=0; i< numberofminterms-1; i++)
        {
              //printf("implicant = %d\n", implicantposition[i]);
              if (implicantposition[i]==0)
              {
                  for (x=0; x< number_of_variables; x++)
                    {
                        solution[y][x] = m1[i][x];
                    }
                    y++;
              }

          }




           for (j=0; j<numberofmatches; j++)
             {
                 for (i=0; i<number_of_variables; i++)
                    {
                       printf("%d ", m2[j][i]);
                    }
                    printf("\n");
             }


            // 3rd iteration starts here
                  printf(" NUMBER OF MATCHES %d", numberofmatches);

        numberofminterms=numberofmatches;
        numberofmatches =0;
        match=0;
        p=0;





        for (i=0; i< numberofminterms-1; i++)          // again turning everything to zero for further calculations
          {
             implicantposition[i]=0;
          }





          for (i=0; i<numberofminterms-1; i++)
          {

              printf(" XD %d\n", i);
              numberofmatches2 = 0;
            for (j=i+1; j<numberofminterms; j++)
            {
                for (k=0; k<number_of_variables; k++)
                {
                    if (m2[i][k] != m2[j][k]) { match++; matchedposition = k; }
                }
                if (match==1)
                {

                    for (x=0; x< number_of_variables; x++)
                    {
                        m3[p][x] = m2[i][x];
                    }

                    m3[p][matchedposition] = 2;
                    p++;
                    match =0;
                    printf("%d > %d\n", i, j);
                    numberofmatches++;
                    implicantposition[i]=1;
                    implicantposition[j]=1;


                }

                else
                {
                    match = 0;
                }

            }

          }


        for (i=0; i< numberofminterms-1; i++)
        {
              //printf("implicant = %d\n", implicantposition[i]);
              if (implicantposition[i]==0)
              {
                  for (x=0; x< number_of_variables; x++)
                    {
                        solution[y][x] = m2[i][x];
                    }
                    y++;
              }

          }







           for (j=0; j<numberofmatches; j++)
             {
                 for (i=0; i<number_of_variables; i++)
                    {
                       printf("%d ", m3[j][i]);
                    }
                    printf("\n");
             }



            printf("\n\n Solution \n\n");

        for (i=0; i<y; i++)
        {
              for (x=0; x<number_of_variables; x++)
          {
              printf("%d", solution[i][x]);
          }
          printf("\n");
        }


}
