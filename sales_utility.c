// SALES ENCORE UTILITY USING C & DATA STRUCTURE

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

void add_First_Admin ( void ) ;
void add_Employee ( void ) ;
void login ( void ) ;

void add_Employee ( void ) ;
void view_All_Monitors ( void ) ;
void view_All_Prospects ( void ) ;
void delete_Prospect ( void ) ;
void add_New_Prospect( void ) ;


struct Prospect				// Prospect List using Double Linked-List : Nodes of 'struct Prospect' type 
{
	char p_FullName[21]	;
 	char p_Phone[11] 	;	                   
  	char p_Address[41] 	;	
  	char p_Email[31] 	;
	char p_Status[5]	;                   		   
  	char e_LoginName[11] ;
	struct Prospect *pnext ;
	struct Prospect *pprev ;		
} ;

struct Employee				// Employee List using Double Linked List : Nodes of 'struct Employee' type
{
	char e_LoginName[11] ;
  	char e_Pass[11]		;
    char e_Role[15]  	;
	char e_FullName[21] ;
	char e_Phone[11]	;
 	char e_Email[31]	;
 	struct Employee *enext ;
 	struct Employee *eprev ;
}  ;

void e_Home (struct Employee *) ;
void change_Password ( struct Employee * ) ;
void search_Prospect ( struct Employee * ) ;
void update_Phone_Number ( struct Employee * ) ;
void view_Prospects ( struct Employee * ) ;
void search_By_Name ( struct Employee * ) ;
void search_By_Status ( struct Employee * ) ;


struct Prospect *ps = NULL ; 	// for pointing to the start of the Prospect List.
struct Prospect *pe = NULL ; 	// for pointing to the end of the Prospect List.
struct Prospect *ptemp = NULL ; // a temporary pointer for the Prospect List.

struct Employee *es = NULL ; 	// for pointing to the start of the Employee List.
struct Employee *ee = NULL ; 	// for pointing to the end of the Employee List.
struct Employee *etemp = NULL ; // a temporary pointer for the Employee List.


int main ( int argc , char *argv )  // start of main() function.
{
	printf("\n\t\t\tWELCOME TO SALES ENCORE UTILITY\n\t\t\t*******************************\n\n");
	add_First_Admin() ;				
	login() ;
	return ( 0 ) ;
}									// end of main() body.


void add_First_Admin()				// adds the first admin to the List when program starts.
{
	
	etemp = (struct Employee *) malloc ( sizeof ( struct Employee )) ;
	
	es = ee = etemp ;
	es -> enext = es -> eprev = NULL ;
	
	strcpy(es -> e_LoginName , "HP") ;	// Username set to "HP".
	strcpy(es -> e_Pass , "password") ;	// Password set to "password".
	strcpy(es -> e_Role , "Admin") ;	// Role set to "Admin". 
	
	printf( "\n\nWELCOME, YOU ARE THE FIRST ADMINISTROTOR.\nYOUR LOGIN NAME IS \t:\t HP\nYOUR PASSWORD IS \t:\t password\n\n" ) ;	
	printf( "\nNOW ENTER YOUR OTHER DETAILS AND LOGIN AGAIN :-\n\n" ) ;
	printf( "\nEnter Your Full Name :\n" );	// Inputting other details.
	gets( es -> e_FullName) ;
	printf( "\nEnter your Email-ID :\n" );
	gets( es -> e_Email ) ;
	printf( "\nEnter your Phone Number :\n" ) ;
	gets( es -> e_Phone ) ;
	
}

void login()		// Logs in an Employee after checking his username, password and role  
{
	char role[15] = {0};
	char logpwd[11] = {0};
	char lognm[11] = {0};
	int trial = 0;
	system( "cls" ) ;
	
	do				// permits three trials for Logging in.
	{
		printf( "\n\n\t\t\t\t LOGIN-SCREEN\n" ) ;
		printf( "\t\t\t\t**************\n\n" ) ;
		
		printf( "\n#####\tYOU HAVE 3 CHANCES TO LOGIN\t#####\n" );
		
		printf( "\nEnter your Role :\n" );
		gets(role);
	
		printf( "\nEnter your Login-Name :\n" );
		gets(lognm);	
	
		printf( "\nEnter your Login-Password :\n" );
		{
			int i = 0;
			char ch ;
			do
			{
				ch = getch() ;
				if( ch != 13)
				{
					logpwd[i] = ch ;
					printf( "*" ) ;
					i++;
				}
			} while ( ch != 13 && i < 11 ) ;
		}
	
		puts ( logpwd ) ;
		
	
		for( etemp = es ; etemp != NULL ; etemp = etemp -> enext)
		{		
			if ( !strcmpi(etemp -> e_LoginName , lognm) )
				break ;
		}
	
		if ( etemp == NULL )
		{
			printf( "\n##### Sorry : No Match Found : Login Name #####\n" );
			trial ++ ;
			continue ;
		}
		else if ( strcmp( etemp -> e_Pass , logpwd ) )
		{
			printf( "\n##### Sorry : No Match Found : Password #####\n" );
			trial ++ ;
			continue ;
		}
		else if ( strcmpi( etemp -> e_Role , role ) )
		{
			printf( "\n##### Sorry : No Match Found : Role #####\n" );
			trial ++ ;
			continue ;
		}
		else
		{
			break ;
		}
		trial++ ;	
	} while( trial < 3) ;
	
	if ( trial < 3)			// On successful Log-in, calls the e_Home() function.
		e_Home ( etemp ) ;
		
		return;
}



void e_Home ( struct Employee *e )  // Displays the Home Screen for a Logged-in Employee.
{
	system( "cls" ) ;
	printf("\nWELCOME, YOU HAVE LOGGED IN SUCCESSFULLY AS ") ;
	puts( e -> e_Role );
	
	printf( "\n\nYOUR DETAILS ARE :\n-----------------\n" );	// Displays the details of the Employee.
	printf( "\nYour Full Name :\n" );
	puts( e -> e_FullName ) ;
	printf( "\nYour Phone Number :\n" );
	puts( e -> e_Phone ) ;
	printf( "\nYour Email-Id :\n" );
	puts( e -> e_Email ) ;
	
	if( ! strcmpi( e -> e_Role , "Admin" ) )	// Checks if the Employee is an Admin
	{
		char ch_Admin = 0 ;
		
		do				// Displays the available options until Admin signs-out.
		{
		
			//char ch_Admin = 0 ;
			printf( "\nEnter Your Choice (1,2,3,4,5): \n" ) ;
			printf( "\n1. ADD A NEW ADMINISTRATOR OR PROSPECT MONITOR\n" ) ;
			printf( "\n2. VIEW ALL PROSPECT MONITORS\n" ) ;
			printf( "\n3. VIEW ALL PROSPECTS\n" ) ;
			printf( "\n4. CHANGE YOUR PASSWORD\n" ) ;
			printf( "\n5. DELETE PROSPECT DETAILS\n" ) ;
			printf( "\n6. SIGN OUT\n") ;
			ch_Admin = getch () ;
			
			switch ( ch_Admin )
			{
				case '1' : {
					add_Employee() ;
					break ;
				}
				case '2' : {
					view_All_Monitors() ;
					break ;
				}
				case '3' : {
					view_All_Prospects() ;
					break ;
				}
				case '4' : {
					change_Password( e ) ;
					break ;
				}
				case '5' : {
					delete_Prospect() ;
					break ;
				}
				case '6' : {
					login () ;
					break;
				}
				
			}
		} while( ch_Admin != '6' ) ;
	}
	else if( ! strcmpi ( e -> e_Role , "monitor" ) ) 	// Checks if the Employee is an Monitor
	{
		char ch_Monitor = 0 ;
		
		do					// Displays the available options until Monitor signs out.
		{
		
			//char ch_monitor = 0 ;
			printf( "\nEnter your choice (1,2,3,4,5):\n" ) ;
			printf( "\n1. ADD NEW PROSPECT\n" ) ;
			printf( "\n2. VIEW ALL PROSPECTS\n" ) ;
			printf( "\n3. SEARCH PROSPECT\n" ) ;
			printf( "\n4. UPDATE PROSPECT PHONE NUMBER\n" ) ;
			printf( "\n5. CHANGE PASSWORD\n" ) ;
			printf( "\n6. SIGN OUT\n" ) ;
		
			ch_Monitor = getch () ;
		
			switch( ch_Monitor )
			{
				case '1' : {
					add_New_Prospect() ;
					break ;
				}
				case '2' : {
					view_Prospects( e ) ;
					break ;
				}
				case '3' : {
					search_Prospect( e );
					break ;
				}
				case '4' : {
					update_Phone_Number( e ) ;
					break ;
				}
				case '5' : {
					change_Password( e ) ;
					break ;
				}
				case '6' : {
					login () ;
					break;
				}
			}
		} while ( ch_Monitor != '6') ;
	} 
}

void add_Employee()		// called if an Admin wants to add a new Employee in the List. 
{
	system( "cls" ) ;
	etemp = ( struct Employee * ) malloc ( sizeof ( struct Employee ) ) ;
	
	if( etemp == NULL )
	{
		printf("\nOVERFLOW : NO MORE EMPLOYEE CAN BE ADDED\n") ;
		return ;
	}
	else
	{
		char ch_Role = 0 ;
		char pwd [11] = {0} ;
		
		printf("\nEnter Employee's Login Name :\n") ;	// Inputting Details of the new Employee.
		gets ( etemp -> e_LoginName ) ;
		printf("\nEnter Employees's Password :\n") ;
		//gets ( etemp -> e_Pass ) ;
		
		{
			
			int i = 0;
			char ch ;
			do
			{
				ch = getch() ;
				if( ch != 13)
				{
					pwd [i] = ch ;
					printf("*") ;
					i++;
				}
			} while ( ch != 13 && i < 11 ) ;
		}
	
		puts ( pwd ) ;
		strcpy ( etemp -> e_Pass , pwd ) ;
		
		do
		{
		
			printf("\nSelect Role :\n1. Admin\n2. Monitor\n") ;
			ch_Role = getch() ;
			if ( ch_Role == '1' )
			{
				strcpy( etemp -> e_Role , "Admin" );
			}
			else if ( ch_Role == '2' )
			{
				strcpy ( etemp -> e_Role , "Monitor" ) ;
			}
			else
			{
				printf("\n#####\tWrong Choice : Enter again\t#####\n") ;
				
			}
		} while( ch_Role != '1' && ch_Role != '2' ) ;
		
		printf("\nEnter Employee's Full Name :\n") ;
		gets( etemp -> e_FullName ) ;
		printf("\nEnter Employee's Phone-Number :\n") ;
		gets( etemp -> e_Phone ) ;
		printf("\nEnter Employee's Email-Id :\n") ;
		gets( etemp -> e_Email ) ;
		
		ee -> enext = etemp ;
		etemp -> eprev = ee ;
		etemp -> enext = NULL ;
		ee = etemp ;
		
		printf( "\n#####\tNEW EMPLOYEE ADDED\t#####\n" ) ;
	
	}
	
}

void view_All_Monitors ()		// called if an Admin wants to see the List of all Monitors.
{
	int i = 1 , ctrM = 0 ;
	system( "cls" ) ;
	
	for( etemp = es ; etemp != NULL ; etemp = etemp -> enext )
	{
		if( ! strcmpi( etemp -> e_Role , "MONITOR" ) )
			ctrM ++ ;
	}
	
	if( ctrM == 0 )
	{
		printf("\n\n#####\tThrere is no Prospect Monitor in the List.\t#####\n\n");
	}
	else
	{
		// Traverses the Employee List & displays Employee Details if Role == "Monitor".
	
		printf("\n\nThe List of All Prospect Monitors with details :\n\n\n");
		
		for ( etemp = es ; etemp != NULL ; etemp = etemp -> enext )
		{
			if ( ! strcmpi( etemp -> e_Role , "Monitor" ) )
			{
				printf( "%d.\t\tFULL NAME\t\t:\t\t%s\n" , i , etemp -> e_FullName ) ;
				printf( "  \t\tLOGIN NAME\t\t:\t\t%s\n", etemp -> e_LoginName );
				printf( "  \t\tLOGIN PASSWORD\t\t:\t\t%s\n" , etemp -> e_Pass );
				printf( "  \t\tPHONE NUMBER\t\t:\t\t%s\n" , etemp -> e_Phone );
				printf( "  \t\tEMAIL ID\t\t:\t\t%s\n" , etemp -> e_Email );
				printf( "\n\n\n" ) ;
				i++ ;
			}
		}
	}
}


void view_All_Prospects()	// called if an Admin wants to see All the Prospects in the List.
{
	int i ;
	system( "cls" ) ;
	if ( ps == NULL )
	{
		printf("\n#####\tPROSPECT LIST EMPTY : THERE IS NO PROSPECT NOW.\t#####\n") ;
	}
	else
	{
		// Traverses the Prospect List & displays Details of all the Prospects. 
		
		printf ( "\nThe List of All Prospects with Details :\n" ) ;
		for( i = 1 , ptemp = ps ; ptemp != NULL ; i++ , ptemp = ptemp -> pnext )
		{
			printf( "%d.\t\tFULL NAME\t\t:\t\t%s\n" , i , ptemp -> p_FullName ) ;
			printf( "  \t\tADDRESS\t\t\t:\t\t%s\n" , ptemp -> p_Address ) ;
			printf( "  \t\tPHONE NUMBER\t\t:\t\t%s\n" , ptemp -> p_Phone ) ;
			printf( "  \t\tEMAIL ID\t\t:\t\t%s\n" , ptemp -> p_Email ) ;
			printf( "  \t\tMONITOR\t\t:\t\t%s\n" , ptemp -> e_LoginName) ; 
			printf( "  \t\tSTATUS\t\t\t:\t\t%s\n" , ptemp -> p_Status ) ;
			printf( "\n\n\n" ) ;
		}
	}
}

void change_Password ( struct Employee *eptr ) // called if any Logged-in Employee wants to change his password.
{
	char pwd_current[11] = { 0 } ;
	char pwd_new[11] = { 0 } ; 
	char ch = 0 ;
	int i = 0 ;
	system( "cls" ) ;
	
	// Asking for Existing Password : if incorrect, then signs out immediately, 
	// if correct, asks for the new password.
	
	printf( "\nEnter Your Current Password\t:\t" ) ;
	
	do
	{
		ch = getch () ;
		if ( ch != 13 )
		{
			pwd_current[ i ] = ch ;
			printf( "*" ) ;
			i++ ;
		}
		
	} while ( ( ch != 13 ) && ( i < 11 ) ) ;
	
	if( !strcmp( eptr -> e_Pass , pwd_current ))
	{
		printf( "\nEnter Your New Password\t:\t" ) ;
		i = 0 ;
		do
		{
			ch = getch () ;
			if ( ch != 13 )
			{
				pwd_new[i] = ch ;
				printf( "*" ) ;
				i++ ;
			}
		} while ( ch != 13 && i < 11 ) ;
		
		strcpy ( eptr -> e_Pass , pwd_new ) ;
		
		printf ("\n#####\tPASSWORD CHANGED\t#####\n") ;
	}
	else
	{
		printf ( "\n#####\tINCORRECT PASSWORD\t#####\n" ) ;
		login () ;
	}
}

void delete_Prospect()		// called if an Admin wants to delete Details of any Prospect in the List.
{
	system( "cls" ) ;
	
	if( ps == NULL )
	{
		printf("\n\n#####\tTHERE IS NO PROSPECT DETAILS IN THE LIST\t#####\n\n") ;
		return ;
	}
	else
	{
		// Deletes a Prospect by inputting his/her Full-Name . 
		
		char name[21] = {0} ;
		printf("\nENTER THE FULL NAME OF THE PROSPECT :\n") ;
		gets( name ) ;
		for ( ptemp = ps ; ptemp != NULL ; ptemp = ptemp -> pnext )
		{
			if( ! (strcmpi ( name , ptemp -> p_FullName )))
			{
				break ;
			}
		}
		if ( ptemp == NULL )
		{
			printf("\n#####\tSORRY, NO MATCH FOUND\t#####\n") ;
		}
		else
		{
			printf( "\n#####\tMATCH FOUND\t#####\n" ) ;
			printf( "\nDETAILS OF THE PROSPECT TO BE DELETED :\n" ) ;
			printf( "\nFULL NAME\t\t:\t%s\n" , ptemp -> p_FullName ) ;
			printf( "\nADDRESS\t\t:\t%s\n" , ptemp -> p_Address ) ;
			printf( "\nPHONE NUMBER\t\t:\t%s\n" , ptemp -> p_Phone ) ;
			printf( "\nEMAIL ID\t\t:\t%s\n" , ptemp -> p_Email ) ;
			printf( "\nPROSPECT MONITOR\t\t:\t%s\n" , ptemp -> e_LoginName ) ;
			printf( "\nPROSPECT STATUS\t\t:\t%s\n" , ptemp -> p_Status ) ;
			printf( "\n\n\n" ) ;


			if ( ptemp == ps )
			{
				( ptemp -> pnext ) -> pprev = NULL ;
				ps = ptemp -> pnext ;
				
			}
			else if ( ptemp == pe )
			{
				( ptemp -> pprev ) -> pnext = NULL ;
				pe = ptemp -> pprev ;
			}
			else
			{
				( ptemp -> pprev ) -> pnext = ptemp -> pnext ;
				( ptemp -> pnext ) -> pprev = ptemp -> pprev ;
			}
			
			free( ptemp ) ;
			printf("\n\n#####\tPROSPECT DELETED\t#####\n");
		}
	}
}

void add_New_Prospect ()
{
	ptemp = ( struct Prospect * ) malloc ( sizeof ( struct Prospect ) ) ;
	if( ptemp == NULL )
	{
		printf( "\nSORRY, NO MORE PROSPECT CAN BE ADDED\n" ) ;
	}
	else
	{
		char ch = 0 ;
		printf( "\nENTER PROSPECT'S FULL NAME\t :\t" ) ;
		gets( ptemp -> p_FullName ) ;
		printf( "\nENTER PROSPECT'S PHONE NUMBER\t :\t" ) ;
		gets( ptemp -> p_Phone ) ;
		printf( "\nENTER PROSPECT'S ADDRESS\t :\t" ) ;
		gets ( ptemp -> p_Address ) ;
		printf( "\nENTER PROSPECT'S EMAIL ID\t :\t" ) ;
		gets( ptemp -> p_Email ) ;
		printf( "\nENTER PROSPECT'S MONITOR\t :\t" ) ;
		gets( ptemp -> e_LoginName ) ;
		do
		{
			ch = 0;
			printf( "\nSELECT PROSPECT'S STATUS\t :\n1.\tCOLD\n2.\tWARM\n3.\tHOT\n" ) ;
			ch = getch () ;
			if ( ch == '1' )
			{
				strcpy ( ptemp -> p_Status , "COLD" ) ;
			}
			else if ( ch == '2' )
			{
				strcpy ( ptemp -> p_Status , "WARM" ) ;
			}
			else if ( ch == '3' )
			{
				strcpy ( ptemp -> p_Status , "HOT" ) ;
			}
			else
			{
				printf( "#####\tWRONG CHOICE : ENTER AGAIN\t#####" ) ;
			}
		} while ( ch != '1' && ch != '2' && ch != '3' ) ;
				
		if ( ps == NULL )
		{
			ps = pe = ptemp ;
			ptemp -> pprev = ptemp -> pnext = NULL ;
		}
		else
		{
			pe -> pnext = ptemp ;
			ptemp -> pprev = pe ;
			ptemp -> pnext = NULL ;
			pe = ptemp ;
		}
		printf( "\n\n#####\tNEW PROSPECT ADDED\t#####\n" ) ;
	}
}

void view_Prospects ( struct Employee *pm )
{
	system( "cls" ) ;
	if( ps == NULL )
	{
		printf( "\n#####\tTHERE ARE NO PROSPECTS IN THE LIST\t#####\n" ) ;
	}
	else
	{
		int i = 0 ;
		printf ( "\nDETAILS OF THE PROSPECTS UNDER THIS MONITOR :\n\n" ) ;
		for ( ptemp = ps ; ptemp != NULL ; ptemp = ptemp -> pnext )
		{
			if( ! ( strcmpi ( ptemp -> e_LoginName , pm -> e_LoginName ) ) )
			{
				i++ ;
				printf( " \n%d.\tFULL NAME\t\t:\t%s " , i , ptemp -> p_FullName ) ;
				printf( " \n  \tADDRESS\t\t:\t%s " , ptemp -> p_Address ) ;
				printf( " \n  \tPHONE NUMBER\t\t:\t%s " , ptemp -> p_Phone ) ;
				printf( " \n  \tEMAIL ID\t\t:\t%s " , ptemp -> p_Email ) ;
				printf( " \n  \tSTATUS\t\t:\t%s " , ptemp -> p_Status ) ;
			}
		}
		if( i == 0 )
		{
			printf( "\n#####\tNO PROSPECT UNDER THIS MONITOR\t#####\n" ) ;
		}
	}
}


void update_Phone_Number ( struct Employee *pm )
{
	system( "cls" ) ;
	if( ps == NULL )
	{
		printf( "\n#####\tTHERE ARE NO PROSPECTS IN THE LIST\t#####\n" ) ;
	}
	else
	{
		char name[21] = {0} ;
		int i = 0 ;
		printf( "\nENTER THE PROSPECT'S FULL NAME :\t" );
		gets( name ) ;
		for ( ptemp = ps ; ptemp != NULL ; ptemp = ptemp -> pnext )
		{
			if( ( ! ( strcmpi ( ptemp -> p_FullName , name ) ) ) && ( ! ( strcmpi ( pm -> e_LoginName , ptemp -> e_LoginName ) ) ) )
			{
				printf( "\nENTER THE NEW PHONE NUMBER :\t" ) ;
				gets( ptemp -> p_Phone ) ;
				i++ ;
			}
		}
		if( i == 0 )
		{
			printf( "\n#####\tNO MATCH FOUND\t#####\n" );
		}
	}
}


void search_Prospect( struct Employee *pm )
{
	system( "cls" ) ;
	if ( ps == NULL )
	{
		printf( "\n#####\tTHERE ARE NO PROSPECTS IN THE LIST\t#####\n" ) ;
	}
	else
	{
		char ch = 0 ;
		 
		do
		{
			printf( "\nSEARCH BY :\n1.\tNAME\n2.\tSTATUS\nENTER YOUR CHOICE (1,2) :\n" );
			ch = getch () ;
			if ( ch != '1' || ch != '2' )
			{
				printf( "\n#####\tWRONG CHOICE : ENTER AGAIN\t#####\n" );
			}
			
		} while ( ch != '1' && ch != '2' ) ;
		
		switch( ch )
		{
			case '1' : {
				search_By_Name( pm ) ;
				break;
			}
			case '2' : {
				search_By_Status( pm );
				break;
			}
		}
		
	}
}

void search_By_Name ( struct Employee *pm )
{
	char name[ 21 ] = { 0 } ;
	int ctr = 0 ;
	system( "cls" ) ;
	printf( "\nSEARCHING BY NAME :\n\nENTER THE PROSPECT'S FULL NAME :\n" ) ;
	gets( name ) ;
	
	for( ptemp = ps ; ptemp != NULL ; ptemp = ptemp -> pnext )
	{
		if ( ( ! strcmpi ( ptemp -> p_FullName , name ) ) && ( ! strcmpi ( pm -> e_LoginName , ptemp -> e_LoginName ) ) )
		{
				ctr++ ;
				printf( " \n%d.\tFULL NAME\t\t:\t%s " , ctr , ptemp -> p_FullName ) ;
				printf( " \n  \tADDRESS\t\t:\t%s " , ptemp -> p_Address ) ;
				printf( " \n  \tPHONE NUMBER\t\t:\t%s " , ptemp -> p_Phone ) ;
				printf( " \n  \tEMAIL ID\t\t:\t%s " , ptemp -> p_Email ) ;
				printf( " \n  \tSTATUS\t\t:\t%s " , ptemp -> p_Status ) ;
			
		}
	}
	if( ctr == 0 )
	{
		printf( "\n#####\tNO PROSPECT WITH THIS NAME UNDER THIS MONITOR\t#####\n" ) ;
	}
}

void search_By_Status ( struct Employee *pm )
{
	char ch = 0 ;
	char status [5] = {0} ;
	int ctr = 0 ;
	system( "cls" ) ;
	
	printf ( "\nSEARCHING BY STATUS :\n" ) ;
	
	do
		{
			ch = 0;
			printf( "\nSELECT PROSPECTS WITH STATUS\t :\n1.\tCOLD\n2.\tWARM\n3.\tHOT\n" ) ;
			ch = getch () ;
			if ( ch == '1' )
			{
				strcpy ( status , "COLD" ) ;
			}
			else if ( ch == '2' )
			{
				strcpy ( status , "WARM" ) ;
			}
			else if ( ch == '3' )
			{
				strcpy ( status , "HOT" ) ;
			}
			else
			{
				printf( "#####\tWRONG CHOICE : ENTER AGAIN\t#####" ) ;
			}
		} while ( ch != '1' && ch != '2' && ch != '3' ) ;
		
		
	for( ptemp = ps ; ptemp != NULL ; ptemp = ptemp -> pnext )
	{
		if ( ( ! strcmpi ( ptemp -> e_LoginName , pm -> e_LoginName ) ) && ( ! strcmpi ( ptemp -> p_Status , status ) )  )
		{
			ctr++ ;
			printf( " \n%d.\tFULL NAME\t\t:\t%s " , ctr , ptemp -> p_FullName ) ;
			printf( " \n  \tADDRESS\t\t:\t%s " , ptemp -> p_Address ) ;
			printf( " \n  \tPHONE NUMBER\t\t:\t%s " , ptemp -> p_Phone ) ;
			printf( " \n  \tEMAIL ID\t\t:\t%s " , ptemp -> p_Email ) ;
			printf( " \n  \tSTATUS\t\t:\t%s " , ptemp -> p_Status ) ;
		
		}
	}
		
	if( ctr == 0 )
	{
		printf( "\n#####\tNO PROSPECT WITH THIS STATUS UNDER THIS MONITOR\t#####\n" ) ;
	}
}
