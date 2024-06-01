// Muhammad Noor 
// I23-2520
// AI-B

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <sstream>

using namespace std;

void Print_Menu ();                                                      //  prints the menu for the user to choose.  

int User_Choice() ;                                                       // enables user to pick his option .

void  reading_file(const string &);                                       // reads and writes data to file.
 
void Makegrid( int ) ;                                                  // make grid initializes the grid to 0 .

void UpdateGrid ( int , int ) ;                                             // update grid transfroms the grid to 0 or 1 checking if its alive or not.
    
void start () {                                                            // called within main , start begins the game.


  Print_Menu();
  
  int option = 0;
  
  option = User_Choice();                                                 // option is choosen from the user choices.
  
  if (option == 2) {                                                         // if user picks 2 , game ends.
  
  cout<< setw(10)<<"\t"<<"Exiting from the Game . "<<endl<<endl;
  }
    
  else if (option == 1) {                                                      // if user picks 1 , game starts.
    string file_name ;
    cout<<endl<<endl;
	cout << "Enter the name of your file : " ;
	cin >> file_name ;                                                    // allows the user to make a file of his own choice.
  reading_file(file_name);
  cout<<endl;                                                              // reading file func called to writing or reading.
  
  }
  
  else {
  cout<<setw(10)<<"\t"<<"Error in Running . "<<endl;
  }

  }
  
  int main () {
  
  start();                                                                    // called within main . only start used to make it look simple.
    
  return 0;
  
  }
  
  void Print_Menu() {
  
  cout<<setw(25)<<"//////////////////GAME OF LIFE ///////////////////"<<endl<<endl;
  
  cout<<setw(25)<< " 1) START THE GAME  "<<endl<<endl;                            // menu printed to the user to pick his choice.
  
  cout<<setw(25)<< " 2) QUIT THE GAME   "<<endl<<endl;
  
  }
  
   int Number_of_generations = 0;
       int num_coordinate = 0; 
     const  int rows = 10 ;
     const int columns = 10 ;
      const int max_size = 20 ;                                                      // variable initialization to be used after here.
      int grid[max_size][max_size];
      int Grid2[max_size][max_size];                                                //second grid to store updated array
    const int secondary_arr_size = 20;
	int secondary_arr[secondary_arr_size][2];
	const int neighbouring_arr_size = 80 ;
	bool Alive_arr [secondary_arr_size][2] ; 
    int Neighbour_Array[neighbouring_arr_size][2]  = {};
      int i , j = 1 ;

  void reading_file(const string& file_name ) {
     
    ofstream out_file(file_name);
    if (!out_file.is_open()) {                                                      // for writing purposes.
    
      cout << " Error in opening file . " <<endl;
  }
    cout<<endl<<endl;
    cout<<"Enter the number of generations you want in the game : ";
    cin>>Number_of_generations;
    
    cout<<endl<<endl;
    
    
   
    cout<<"How many coordinates you want to check : " ; 
    
    cin>>num_coordinate;
    
    cout << endl<<endl;
    
    out_file << Number_of_generations <<endl;                                      // writes the generations and coordinates onto the file.
    out_file << num_coordinate << endl;
    
    int arr[num_coordinate][2] ;
    
    for ( int i = 0 ; i < num_coordinate ; i++ ) { 
    
       cout<<"Enter coordinates (x,y) : " ; 
          
       cin>>arr[i][0] ;                                                             // coordinates entered in a loop.
	   cin >> arr[i][1] ;
    
    //cout<<endl<<endl;
        
        out_file << arr[i][0]  << " " << arr[i][1] << endl;
    
    }
   
   
    void Makegrid( int grid[max_size][max_size]    ) ;                                         //  prototypes.

 void UpdateGrid ( int grid[max_size][max_size] ,int num_coordinate , int arr[][2] , int Grid2[][max_size] ) ;           //  prototypes.
    
   void Check_Live ( int grid[max_size][max_size] , int num_coordinate, int arr[][2] ) ;          //  prototypes.
    
   void Copycells ( int num_coordinate ,  int grid[][max_size] , int arr[][2] , int Grid2[][max_size] , bool Alive_arr[][2]) ;          //  prototypes.
   
     int countL (int grid[][max_size] , int max_size , int i , int j , int rows , int columns ) ;             //  prototypes.
     
     int countS (int grid[][max_size] , int max_size , int i , int j , int rows , int columns ) ;            // prototypes.
   
     void Neighbours(int Grid2[max_size][max_size] , int grid[max_size][max_size] , int secondary_arr[][2] , int  secondary_arr_size  , bool Alive_arr[][2]) ; //  prototypes.
    
    void transform (  int grid [][max_size] , int Grid2[][max_size] ) ;                               // prototypes.
     
     void Clear ( int max_size    ) ;                // prototypes .
   
      Makegrid( grid ) ;   
	  
	   UpdateGrid (  grid , num_coordinate ,  arr , Grid2 ) ;                           // func called after intiliazing grid.                                                      
       
    
    for ( int i = 0 ; i <  Number_of_generations ;  i++ )  {  
	                                                          
     
      Copycells ( num_coordinate   ,  grid  , arr , Grid2 , Alive_arr ) ;             // func called after updating grid.
       
      countL ( grid , max_size , i , j , rows , columns ) ;                             // func called to check live neighbour count (sec)
	                          
	                          
	  countS ( grid , max_size , i , j , rows , columns ) ;                            // func called to check live neighbor count (nei)
	  
      
      Neighbours ( Grid2 , grid , secondary_arr  , secondary_arr_size  , Alive_arr ) ;   // func called to check neighbours.
      
   
       transform (  grid , Grid2 ) ;                                                   // copying grid2 to grid1.
        
      Clear (   max_size   ) ;                                                        // again decreasing the size of neighbour arr to 0.
 }
    out_file.close();                                                                // closes the file after writing.

   
   
    ifstream in_file(file_name) ;
      if (!in_file.is_open()) {
        cout <<" Error in reading file . " ;
 }
      
      in_file >> Number_of_generations >> num_coordinate ;                                // reads the contents of the file.
      	
      cout << endl << endl;
      cout << "Number of generations are : " << Number_of_generations <<endl<<endl;

      int c = 0 ;
      for (int i = 0 ; i <= num_coordinate ; i++) {
      	int x  , y ; 
      	string line  ;
      	getline (in_file , line ) ;                                                         // getline used to read a string from an input stream.
      	istringstream iss(line) ;                                                           // used to stream string into different variables
      	iss >> x >> y ;                                                                     // iss does not read whitespace " " .
      	
      if ( i > 0) {
      	cout << " Coordinates  " << c+1 << " : " <<  x   << " " << y <<endl;
      	c++ ;
	  }
      }
       in_file.close();                                                                     // closes the file after reading.
      }


      
     int User_Choice() {
     
     int choice = 0;
     
     cout<<setw(25)<< "^^^^^^^^^^^^CHOOSE YOUR PICK^^^^^^^^^^^^" ;
     
     cin>>choice;
     
     switch(choice) {
     
     case 1 :   
      return 1 ;                                                           // option is returned and user_choice func begins.
       
      break ;
      
     case 2 : 
     return 2 ;
     
      break ;
      
     default : 
     return -1;                                                            // on any other option other than 1 or 2 , program doesn't work.
     }
     
    }
    
     
   void Makegrid( int grid[max_size][max_size]   ) {  

      for (int i = 0 ; i <  max_size   ; i++ )                      // both i,j go from 0 to grid size and makes the grid.
      {
          for ( int j = 0  ; j < max_size ; j++ ) { 
             grid[i][j] =  0  ;                                     // grid intialised with val 0 .
     
           }
         }
      }
      
	      void UpdateGrid (  int grid[max_size][max_size] , int num_coordinate , int arr[][2] , int Grid2[][max_size] ) {
	          
	              for ( int i = 0 ; i < num_coordinate  ; i++ ) { 
	                        int x = arr[i][0] ; 
	                        int y = arr[i][1] ;                                       // x and y is updated with the coordinates entered by user.
	                    
	                       if ( x >= 0 && x < max_size && y >= 0 && y <max_size ) { 
	                                      grid[x][y] = 1 ;                                 // if x and y are >0 and <20 (size of row , column) , then grid is transformed to 1 .
	                       }
	                }
	                                  
	                      for ( int i = 0 ; i < max_size  ; i++ ) { 
	                      
	                            for ( int j = 0 ; j < max_size ; j++ ) { 
	                                  
	                           if (grid[i][j] == 1 ) { 
	                           
	                           cout<<" "<<"1" ;                                    // on those places , the coordinates of which were entered by user are transformed to 1 . 
	                           }
	                           
	                           else 
	                           cout<<" "<<"0" ;
	                         
	                        }
	                      
	                        cout<<endl;
	                      }
	                   
	           }
   
         
     
     int countL (int grid[][max_size] , int max_size , int i , int j , int rows , int columns ) {
    	int count = 0 ; 
    	for ( int k = i ; k <= rows ; k ++ ) {
    	        for ( int l = j ; l <= columns ; l++ ) {                      // checks its neighbouring 8 .
    	            if ( grid[k][l] == 1 ) {
    	            count++ ;                                                // for example in 3x3 matrix , we have 8 neighbours around cell itself.
    	         }
	      }
	    }
    	return count ;
     }
     
     
     int countS (int grid[][max_size] , int max_size , int i , int j , int rows , int columns ) {
    	int count = 0 ; 
    	for ( int k = i ; k <= rows ; k ++ ) {
    	        for ( int l = j ; l <= columns ; l++ ) {                      // checks its neighbouring 8 .
    	            if ( grid[k][l] == 1 ) {                                 // for example in 3x3 matrix , we have 8 neighbours around cell itself.
    	            count++ ;
    	         }
	      }
	    }
    	return count-1 ;
     }
     
     
     
     
     
      
     void Copycells(int num_coordinate, int grid[][max_size], int arr[][2],int Grid2[][max_size] , bool Alive_arr[][2])
	 {
	    int  counts=0;
	    const int secondary_arr_size = 20;
	    int secondary_arr[secondary_arr_size][2];
	     cout <<endl<<endl;
	     cout << "This is the Secondary Array For the Active Cells:";
	      cout<<endl; 
	    for (int i = 0; i < max_size; i++)
	    {
	        for (int j = 0; j < max_size; j++)
	        {
	            if (grid[i][j] == 1)                                         // if cell is alive , then countS is called.
	            {
	            	counts=countS(grid,max_size,i-1,j-1,i+1,j+1);
	
	            	if(counts<2){
	            		Grid2[i][j]=0;
	            		Alive_arr[i][j] = false ;                            // if count is less than 2 , then cell die.
					}
					else if(counts==3 || counts ==2 ){                                     // if count is 3 or 2 , then cell live.
						Grid2[i][j]=1;
						Alive_arr[i][j] = true ; 
						secondary_arr[counts][0] = i ;
						secondary_arr[counts][1] = j ;
					}
				
					else if(counts>3){                                       // if count is > 3 , then cell die.
						Grid2[i][j]=0;
						Alive_arr [i][j] = false ; 
					}
					cout<<endl;
	               secondary_arr[counts][0] = i;
	                secondary_arr[counts][1] = j;
	                 
	                 cout << "(" << secondary_arr[counts][0] << ", " << secondary_arr[counts][1] << ") ";
	        cout << " live cell : " << counts << " " ; 
	            }
	            else
	            grid[i][j] = 0;                                    // if grid is 0 , then it remains 0.
	        }
	    }
	
	    cout << endl << endl;
   
}

    void Neighbours(int Grid2[max_size][max_size] , int grid[][max_size] , int secondary_arr[][2] , int secondary_arr_size  , bool Alive_arr [][2])  
    
{
	const int neighbouring_arr_size = 80 ;
    int Neighbour_Array[neighbouring_arr_size][2]  = {};
    int count = 0 ;
 
    cout<<" Neighbouring Array For the Dead Cells : " ;
    cout <<endl;
    
    for (int i = 0; i < max_size; i++)
    {
        for (int j = 0; j < max_size; j++)
        {
            int neighborCount = 0;
           

            for (int m = -1; m <= 1; m++)
            {
                for (int k = -1; k <= 1; k++)                                    // goes from -1 to 1 to check condition for neighbours.
                {
                    if (m == 0 && k == 0)                                      // if cell is itself  , then it doesn't count itself. 
                        continue;

                    int x = i + m;
                    int y = j + k;

                    if (x >= 0 && x < max_size && y >= 0 && y < max_size)
                    {
                        if (grid[x][y] == 1)
                            neighborCount++;
                    }
                }
            }

            if (neighborCount > 0 && grid[i][j] != 1 ) {
                cout<<endl;
                cout << "(" << i << ", " << j << ") ";        
                count = countL ( grid , max_size , i-1 , j-1 , i+1 , j+1 ) ;                // countL called to count neighbours for dead cell.      
                cout<<" live cell : " << count <<" ";                          // prints count . 
                if(count==3){
                	Grid2[i][j]=1;
                	Alive_arr[i][j] = true ;                                       // if count is 3 , then dead become alive.
                	
                	
				}
				else if(count<3){
                	Grid2[i][j]=0;
                	Alive_arr[i][j] = false ;                                     // if count is <3 , then dead remains dead.
                	
				}
				else if(count>3){
					Grid2[i][j]=0; 
					Alive_arr[i][j] = false ;                                    // if count is >3 , then dead remains dead.
				}
	  } 
    }
   }
         cout<<endl<<endl;
         cout<<"Printing updating Grid : "<<endl<<endl;
         for(int i=0;i<max_size;i++){
         	for(int j=0;j<max_size;j++){                                            // prints updated grid on screen.
         		cout<<" "<<Grid2[i][j];
			 }
			 cout<<endl;
	 }
 		    
}

          void transform ( int grid[][max_size] , int Grid2[][max_size] ) {
          	const int secondary_arr_size = 20 ;
          	int secondary_arr[secondary_arr_size][2] ; 
          	int disc = 0 ;
          	cout<<endl<<endl;
          	cout << " This is the Secondary Array for the Active Cells : " ;
          	for (int i = 0 ; i < max_size ; i++) {
          		  for (int j = 0  ; j < max_size ; j++) {                                // copies the coordinates from updated grid and stores them in sec array.
          		  	    grid[i][j] = Grid2[i][j] ;
          		  	    if ( grid[i][j] == 1 ) {
          		  	    cout << " ( " << i << " , " << j << " ) " ;
          		  	    disc ++ ;
					}
			  }
		  }
		   if ( disc == 0 ) {
		   	cout << endl<<endl;
		   	cout << " The count for Secondary Array is Zero . " << endl;
		   	cout << endl ;
		   }
	}
       
          void Clear (  int max_size   ) { 
                cout << endl <<endl;
                 const  int neighbouring_arr_size = 0 ;                              // Neighbour Array size becomes 0 .
                 int Neighbour_Array[secondary_arr_size][2] ;           
                 cout << " The Neighbour Array is : " << neighbouring_arr_size ;     
				 cout<<endl;  
		}    
	
		 


